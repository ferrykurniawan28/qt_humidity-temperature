#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "ui_mainwindow.h"
#include "pseudosensor.h"

#include <QSqlDatabase>
#include <QMainWindow>
#include<QtCharts>
#include<QChartView>
#include<QLineSeries>

class MainWindow : public QMainWindow, public Ui::MainWindow
{
    Q_OBJECT

    QSqlDatabase db;

    bool isFahrenheit = true;

    double upperHumidity = 0;
    double lowerHumidity = 0;

    double upperTemperature = 0;
    double lowerTemperature = 0;

    double minHumidity = 0;
    double maxHumidity = 0;
    double avgHumidity = 0;

    double minTemperature = 0;
    double maxTemperature = 0;
    double avgTemperature = 0;

public:
    MainWindow(QWidget *parent = nullptr);
    PseudoSensor sensor;
    ~MainWindow();
private:
    double rawTemperature = 0;
    QVector<double> rawTemperatures;
    QList<int> humidityList;
    QList<int> temperatureList;
    QLineSeries *seriesFahrenheit = new QLineSeries();
    QLineSeries *seriesCelsius = new QLineSeries();
    QLineSeries *seriesHumidity = new QLineSeries();

    void showTemperature(double temperature);
    void initTableWidget();
    void initChart();
    void addTableWidgetRow(const QString &humidity, const QString &temperature, const QString &timestamp);
    void addChartValue(QLineSeries *series, int index, double value);
    void convertTableTemperature();
    bool createTableDB();
    bool insertData(const int &humidity, const int &temperature);
    bool insertAlarmData(const int &upperHumidity, const int &lowerHumidity, const double &upperTemperature, const double &lowerTemperature);
    bool loadDatabase();
    void alarmWarning();
private slots:
    void on_pushButtonSingle_clicked();
    void on_pushButtonMultiple_clicked();
    void on_comboBox_currentIndexChanged(int index);
    void on_pushButtonCalculate_clicked();
    void on_pushButtonAlarm_clicked();
};
#endif // MAINWINDOW_H