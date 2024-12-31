#include "mainwindow.h"
#include "pseudosensor.h"
#include "alarmdialog.h"
#include <QThread>
#include <QDateTime>
#include <QSqlQuery>
#include <QSqlError>
#include <QMessageBox>
#include <CalculateDialog.h>
#include <algorithm>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    setupUi(this);
    initTableWidget();

    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("D:\\uni\\qt\\final\\table.db");

    bool ok = db.open();

    if (!ok) {
        qDebug() << "Error: could not open database." << db.lastError();
        return;
    } else {
        qDebug() << "Database opened successfully.";
        if (!createTableDB()) {
            qDebug() << "Error: could not create table.";
        }
        if (!loadDatabase()) {
            qDebug() << "Error: could not load data.";
        }
    }

    initChart();

    connect(&generatePseudo, &GeneratePseudo::sendValues, this, &MainWindow::updateValues);
}

MainWindow::~MainWindow() {}

void MainWindow::showTemperature(double temperature)
{
    if (labelUpperTempValue->text().isEmpty() || labelLowerTempValue->text().isEmpty()) {
        // return;
    } else {
        if (isFahrenheit) {
            labelUpperTempValue->setText(QString::number(upperTemperature));
            labelLowerTempValue->setText(QString::number(lowerTemperature));
        } else {
            labelUpperTempValue->setText(QString::number((upperTemperature - 32) * 5 / 9, 'f', 0));
            labelLowerTempValue->setText(QString::number((lowerTemperature - 32) * 5 / 9, 'f', 0));
        }
    }

    if (temperatureList.isEmpty()) {
        return;
    }

    rawTemperature = temperature;

    if (isFahrenheit) {
        lcdTemperature->display(temperature);
    } else {
        lcdTemperature->display((temperature - 32) * 5 / 9);
    }
}

void MainWindow::on_pushButtonSingle_clicked()
{
    auto values = sensor.generateValues();

    humidityList.append(values.first);
    temperatureList.append(values.second);

    lcdHumidity->display(values.first);
    showTemperature(values.second);

    qDebug() << "Humidity: " << values.first << " Temperature: " << values.second;

    //TODO: Add to database
    insertData(values.first, values.second);

    alarmWarning();
}


void MainWindow::on_pushButtonMultiple_clicked()
{
    generatePseudo.start();

    // get the values from the pseudo sensor




    // for (int i = 0; i < 10; i++) {
    //     auto values = sensor.generateValues();

    //     humidityList.append(values.first);
    //     temperatureList.append(values.second);

    //     lcdHumidity->display(values.first);
    //     showTemperature(values.second);

    //     //timestamp
    //     QDateTime dateTime = QDateTime::currentDateTime();
    //     QString timestamp = dateTime.toString("yyyy-MM-dd hh:mm:ss");

    //     qDebug() << "Humidity: " << values.first << " Temperature: " << values.second << " Timestamp: " << timestamp;

    //     insertData(values.first, values.second);

    //     alarmWarning();

    //     QCoreApplication::processEvents();

    //     QThread::sleep(1);
    // }
}


void MainWindow::on_comboBox_currentIndexChanged(int index)
{
    if (index == 0) {
        isFahrenheit = true;
        labelTemp->setText("°F");
    } else {
        isFahrenheit = false;
        labelTemp->setText("°C");
    }

    showTemperature(rawTemperature);
    convertTableTemperature();
}


void MainWindow::on_pushButtonCalculate_clicked()
{
    //get min, max, avg values from the database based on max last 10 values
    QSqlQuery query(db);

    QString sql = "SELECT MIN(humidity), MAX(humidity), AVG(humidity), MIN(temperature), MAX(temperature), AVG(temperature) FROM sensor_data ORDER BY id DESC LIMIT 10";

    bool ok = query.exec(sql);

    if (!ok) {
        qDebug() << "Error: could not fetch data." << query.lastError();
        return;
    } else {
        if (query.next()) {
            minHumidity = query.value(0).toDouble();
            maxHumidity = query.value(1).toDouble();
            avgHumidity = query.value(2).toDouble();
            minTemperature = query.value(3).toDouble();
            maxTemperature = query.value(4).toDouble();
            avgTemperature = query.value(5).toDouble();
        }

        CalculateDialog calculateDialog(this, minHumidity, maxHumidity, avgHumidity, minTemperature, maxTemperature, avgTemperature);
        calculateDialog.exec();
    }
}


void MainWindow::on_pushButtonAlarm_clicked()
{
    AlarmDialog alarmDialog(this);

    if(alarmDialog.exec() == QDialog::Accepted) {
        if (alarmDialog.fahrenheit) {
            upperTemperature = alarmDialog.spinBoxUpperTemp->value();
            lowerTemperature = alarmDialog.spinBoxLowerTemp->value();
        } else {
            upperTemperature = (alarmDialog.spinBoxUpperTemp->value() * (9.0/5)) + 32;
            lowerTemperature = (alarmDialog.spinBoxLowerTemp->value() * (9.0/5)) + 32;
        }
        upperHumidity = alarmDialog.spinBoxUpperHum->value();
        lowerHumidity = alarmDialog.spinBoxLowerHum->value();
    }

    labelUpperHumValue->setText(QString::number(upperHumidity));
    labelLowerHumValue->setText(QString::number(lowerHumidity));

    if (isFahrenheit) {
        labelUpperTempValue->setText(QString::number(upperTemperature, 'f', 2));
        labelLowerTempValue->setText(QString::number(lowerTemperature, 'f', 2));
    } else {
        labelUpperTempValue->setText(QString::number((upperTemperature - 32) * 5.0 / 9, 'f', 0));
        labelLowerTempValue->setText(QString::number((lowerTemperature - 32) * 5.0 / 9, 'f', 0));
    }

    insertAlarmData(upperHumidity, lowerHumidity, upperTemperature, lowerTemperature);
}

void MainWindow::updateValues(double temperature, double humidity)
{
    qDebug() << "Temperature: " << temperature << " Humidity: " << humidity;

    humidityList.append(humidity);
    temperatureList.append(temperature);

    lcdHumidity->display(humidity);
    showTemperature(temperature);

    insertData(humidity, temperature);

    alarmWarning();
}



void MainWindow::initTableWidget()
{
    QStringList headers = {"Humidity", "Temperature", "Timestamp"};
    tableWidget->setColumnCount(headers.size());
    tableWidget->setHorizontalHeaderLabels(headers);
    tableWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    tableWidget->verticalHeader()->hide();
    tableWidget->horizontalScrollMode();
}

void MainWindow::initChart()
{
    QChart *chart = new QChart();
    QChartView *chartView = new QChartView(chart);
    chartView->setRenderHint(QPainter::Antialiasing);

    // Chart configuration
    chart->setTitle("Sensor Data (Temperature & Humidity)");
    chart->legend()->setVisible(true);
    chart->legend()->setAlignment(Qt::AlignBottom);

    // Configure series
    seriesFahrenheit->setName("Fahrenheit");
    seriesCelsius->setName("Celsius");
    seriesHumidity->setName("Humidity");

    chart->addSeries(seriesFahrenheit);
    chart->addSeries(seriesCelsius);
    chart->addSeries(seriesHumidity);

    // Define axes
    QValueAxis *axisX = new QValueAxis();
    axisX->setTitleText("Index");

    QValueAxis *axisY = new QValueAxis();
    axisY->setTitleText("Values");

    chart->addAxis(axisX, Qt::AlignBottom);
    chart->addAxis(axisY, Qt::AlignLeft);

    seriesFahrenheit->attachAxis(axisX);
    seriesFahrenheit->attachAxis(axisY);
    seriesCelsius->attachAxis(axisX);
    seriesCelsius->attachAxis(axisY);
    seriesHumidity->attachAxis(axisX);
    seriesHumidity->attachAxis(axisY);

    // Layout for stretching
    QVBoxLayout *layout = new QVBoxLayout(chartFrame);
    layout->setContentsMargins(0, 0, 0, 0);
    layout->addWidget(chartView);

    // Load data from the database
    QSqlQuery query(db);
    QString sql = "SELECT timestamp, temperature, humidity FROM sensor_data ORDER BY id DESC LIMIT 10";

    if (!query.exec(sql)) {
        qDebug() << "Error: could not fetch data." << query.lastError();
        return;
    }

    double minY = std::numeric_limits<double>::max();
    double maxY = std::numeric_limits<double>::lowest();
    QList<QDateTime> timestamps;
    QList<double> temperaturesFahrenheit;
    QList<double> temperaturesCelsius;
    QList<double> humidities;

    // Fetch the most recent data and store it
    while (query.next()) {
        QString timestampString = query.value(0).toString();
        QDateTime timestamp = QDateTime::fromString(timestampString, "yyyy-MM-dd HH:mm:ss");

        if (!timestamp.isValid()) {
            qDebug() << "Invalid timestamp format:" << timestampString;
            continue;
        }

        double temperatureF = query.value(1).toDouble();
        double temperatureC = (temperatureF - 32) * 5.0 / 9.0; // Convert Fahrenheit to Celsius
        double humidity = query.value(2).toDouble();

        // Store the data in lists
        timestamps.append(timestamp);
        temperaturesFahrenheit.append(temperatureF);
        temperaturesCelsius.append(temperatureC);
        humidities.append(humidity);

        // Track range for Y-axis
        minY = std::min({minY, temperatureF, temperatureC, humidity});
        maxY = std::max({maxY, temperatureF, temperatureC, humidity});
    }

    // Now reverse the order of the lists and plot the data
    int index = 0;
    for (int i = timestamps.size() - 1; i >= 0; --i) {
        addChartValue(seriesFahrenheit, index, temperaturesFahrenheit[i]);
        addChartValue(seriesCelsius, index, temperaturesCelsius[i]);
        addChartValue(seriesHumidity, index, humidities[i]);
        // seriesFahrenheit->append(index, temperaturesFahrenheit[i]);
        // seriesCelsius->append(index, temperaturesCelsius[i]);
        // seriesHumidity->append(index, humidities[i]);

        index++; // Increment index for each data point
    }

    // Adjust axis ranges
    axisX->setRange(0, index); // Set the X axis range based on the data count
    if (minY <= maxY) {
        axisY->setRange(minY - 1, maxY + 1); // Add padding for better visualization
    }

    // Refresh chart view
    chartView->update();

    // Enable tooltips on hover
    auto showTooltip = [](QLineSeries *series, QChart *chart) {
        QObject::connect(series, &QLineSeries::hovered, [chart](const QPointF &point, bool state) {
            if (state) {
                chart->setToolTip(QString("Value: %1").arg(point.y(), 0, 'f', 0));
            } else {
                chart->setToolTip("");
            }
        });
    };

    showTooltip(seriesFahrenheit, chart);
    showTooltip(seriesCelsius, chart);
    showTooltip(seriesHumidity, chart);
}

void MainWindow::addTableWidgetRow(const QString &humidity, const QString &temperature, const QString &timestamp)
{
    // int row = tableWidget->rowCount();
    // tableWidget->setRowCount(row);
    tableWidget->insertRow(0);
    int row = 0;
    double humiditydouble = humidity.toDouble();
    double temperaturedouble = temperature.toDouble();
    rawTemperatures.append(temperaturedouble);
    tableWidget->setItem(row, 0, new QTableWidgetItem(QString::number(humiditydouble,'f', 0) + "%"));
    if (isFahrenheit) {
        tableWidget->setItem(row, 1, new QTableWidgetItem(QString::number(temperaturedouble, 'f', 0) + "°F"));
    } else {
        tableWidget->setItem(row, 1, new QTableWidgetItem(QString::number((temperaturedouble - 32) * 5.0 / 9.0, 'f', 0) + "°C"));
    }
    tableWidget->setItem(row, 2, new QTableWidgetItem(timestamp));
}

void MainWindow::addChartValue(QLineSeries *series, int index, double value)
{
    // check if the series is 10 points long
    // if (series->count() >= 10) {
    //     series->remove(0);
    // }

    series->append(index, value);

    // Update X-axis to show the new range
    QValueAxis *axisX = static_cast<QValueAxis*>(series->chart()->axisX());
    int newRangeMax = index + 1; // Increment the X-axis range dynamically
    axisX->setRange(0, newRangeMax);

    // Update Y-axis to show the new range
    QValueAxis *axisY = static_cast<QValueAxis*>(series->chart()->axisY());
    double minY = std::numeric_limits<double>::max();
    double maxY = std::numeric_limits<double>::lowest();
    for (int i = 0; i < series->count(); i++) {
        minY = std::min(minY, series->at(i).y());
        maxY = std::max(maxY, series->at(i).y());
    }
    axisY->setRange(minY - 1, maxY + 1); // Add padding for better visualization

    // Refresh the chart view
    series->chart()->update();
}

void MainWindow::convertTableTemperature()
{
    // Iterate over the table rows in reverse order to swap the temperatures
    for (int i = 0; i < tableWidget->rowCount() / 2; i++) {
        // Swap temperatures between row i and row (rowCount - i - 1)
        int j = tableWidget->rowCount() - i - 1;

        // Get raw temperatures for the rows to be swapped
        double temp1 = rawTemperatures[i];
        double temp2 = rawTemperatures[j];

        // Convert to appropriate units based on `isFahrenheit` flag
        QString newTemp1, newTemp2;

        if (isFahrenheit) {
            newTemp1 = QString::number(temp1, 'f', 0) + "°F";
            newTemp2 = QString::number(temp2, 'f', 0) + "°F";
        } else {
            newTemp1 = QString::number((temp1 - 32) * 5.0 / 9.0, 'f', 0) + "°C";
            newTemp2 = QString::number((temp2 - 32) * 5.0 / 9.0, 'f', 0) + "°C";
        }

        // Swap the temperature values in the table (column 1)
        tableWidget->item(i, 1)->setText(newTemp2);
        tableWidget->item(j, 1)->setText(newTemp1);
    }
}



bool MainWindow::createTableDB()
{
    QSqlQuery query(db);

    QString sql = "CREATE TABLE IF NOT EXISTS sensor_data (id INTEGER PRIMARY KEY AUTOINCREMENT, humidity INTEGER, temperature REAL, timestamp TEXT)";

    bool ok = query.exec(sql);

    if (!ok) {
        qDebug() << "Error: could not create table." << query.lastError();
        return false;
    }

    QString sql2 = "CREATE TABLE IF NOT EXISTS alarm_data (id INTEGER PRIMARY KEY AUTOINCREMENT, upper_humidity INTEGER, lower_humidity INTEGER, upper_temperature REAL, lower_temperature REAL)";

    bool ok2 = query.exec(sql2);

    if (!ok2) {
        qDebug() << "Error: could not create table." << query.lastError();
        return false;
    }

    return true;
}

bool MainWindow::insertData(const int &humidity, const int &temperature)
{
    QSqlQuery query(db);

    QString sql = "INSERT INTO sensor_data (humidity, temperature, timestamp) VALUES (:humidity, :temperature, :timestamp)";

    query.prepare(sql);
    query.bindValue(":humidity", humidity);
    query.bindValue(":temperature", temperature);
    query.bindValue(":timestamp", QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss"));

    bool ok = query.exec();

    if (!ok) {
        qDebug() << "Error: could not insert data." << query.lastError();
        return false;
    }

    addTableWidgetRow(QString::number(humidity), QString::number(temperature), QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss"));

    // Add data to chart
    int index = tableWidget->rowCount() - 1; // The last inserted row index
    double tempFahrenheit = temperature;
    double tempCelsius = (tempFahrenheit - 32) * 5.0 / 9.0; // Convert to Celsius
    addChartValue(seriesFahrenheit, index, tempFahrenheit);
    addChartValue(seriesCelsius, index, tempCelsius);
    addChartValue(seriesHumidity, index, humidity);

    return true;
}

bool MainWindow::insertAlarmData(const int &upperHumidity, const int &lowerHumidity, const double &upperTemperature, const double &lowerTemperature)
{
    QSqlQuery query(db);

    QString sql = "INSERT INTO alarm_data (upper_humidity, lower_humidity, upper_temperature, lower_temperature) VALUES (:upper_humidity, :lower_humidity, :upper_temperature, :lower_temperature)";

    query.prepare(sql);
    query.bindValue(":upper_humidity", upperHumidity);
    query.bindValue(":lower_humidity", lowerHumidity);
    query.bindValue(":upper_temperature", upperTemperature);
    query.bindValue(":lower_temperature", lowerTemperature);

    bool ok = query.exec();

    if (!ok) {
        qDebug() << "Error: could not insert data." << query.lastError();
        return false;
    }

    return true;
}



bool MainWindow::loadDatabase()
{
    QSqlQuery query(db);

    QString sql = "SELECT humidity, temperature, timestamp FROM sensor_data ORDER BY id DESC LIMIT 10";

    bool ok = query.exec(sql);

    if (!ok) {
        qDebug() << "Error: could not fetch data." << query.lastError();
        return false;
    }

    QVector<QStringList> rows;

    while (query.next()) {
        int humidity = query.value(0).toInt();
        double temperature = query.value(1).toDouble();
        QString timestamp = query.value(2).toString();

        rows.prepend({QString::number(humidity), QString::number(temperature), timestamp});

        // addTableWidgetRow(QString::number(humidity), QString::number(temperature), timestamp);
    }

    for (const auto &row : rows) {
        addTableWidgetRow(row[0], row[1], row[2]);
    }

    QString sql2 = "SELECT upper_humidity, lower_humidity, upper_temperature, lower_temperature FROM alarm_data";

    bool ok2 = query.exec(sql2);

    if (!ok2) {
        qDebug() << "Error: could not fetch data." << query.lastError();
        return false;
    }

    if (query.next()) {
        upperHumidity = query.value(0).toInt();
        lowerHumidity = query.value(1).toInt();
        upperTemperature = query.value(2).toDouble();
        lowerTemperature = query.value(3).toDouble();

        labelUpperHumValue->setText(QString::number(upperHumidity));
        labelLowerHumValue->setText(QString::number(lowerHumidity));
        labelUpperTempValue->setText(QString::number(upperTemperature));
        labelLowerTempValue->setText(QString::number(lowerTemperature));
    }

    return true;
}

void MainWindow::alarmWarning()
{
    if (humidityList.isEmpty() || temperatureList.isEmpty()) {
        return;
    }

    if (upperHumidity == 0 && lowerHumidity == 0 && upperTemperature == 0 && lowerTemperature == 0) {
        return;
    }

    double humidity = humidityList.last();
    double temperature = temperatureList.last();

    if (humidity > upperHumidity || humidity < lowerHumidity) {
        qDebug() << "Humidity alarm!";
        //open warning dialog
        QMessageBox::warning(this, "Warning", "Humidity alarm!");
    }

    if (temperature > upperTemperature || temperature < lowerTemperature) {
        qDebug() << "Temperature alarm!";
        //open warning dialog
        QMessageBox::warning(this, "Warning", "Temperature alarm!");
    }
}

