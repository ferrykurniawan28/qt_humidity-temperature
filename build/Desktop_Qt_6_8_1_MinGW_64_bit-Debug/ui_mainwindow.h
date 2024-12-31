/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLCDNumber>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QGridLayout *gridLayout_6;
    QLabel *label;
    QHBoxLayout *horizontalLayout_4;
    QGroupBox *groupBox_3;
    QGridLayout *gridLayout_4;
    QLabel *label_7;
    QLabel *labelUpperHumValue;
    QLabel *labelHum;
    QLabel *label_8;
    QLabel *labelLowerHumValue;
    QGroupBox *groupBox;
    QGridLayout *gridLayout;
    QLabel *label_2;
    QLabel *label_3;
    QFrame *frameHumidity;
    QHBoxLayout *horizontalLayout;
    QLCDNumber *lcdHumidity;
    QLabel *label_4;
    QFrame *frameTemperature;
    QHBoxLayout *horizontalLayout_2;
    QLCDNumber *lcdTemperature;
    QComboBox *comboBox;
    QGroupBox *groupBox_2;
    QGridLayout *gridLayout_3;
    QLabel *label_5;
    QLabel *labelUpperTempValue;
    QLabel *labelTemp;
    QLabel *label_6;
    QLabel *labelLowerTempValue;
    QVBoxLayout *verticalLayout;
    QFrame *frameButton;
    QHBoxLayout *horizontalLayout_3;
    QPushButton *pushButtonSingle;
    QPushButton *pushButtonMultiple;
    QPushButton *pushButtonCalculate;
    QPushButton *pushButtonAlarm;
    QPushButton *pushButtonClose;
    QTabWidget *tabWidget;
    QWidget *tabHistory;
    QGridLayout *gridLayout_2;
    QTableWidget *tableWidget;
    QWidget *tabChart;
    QGridLayout *gridLayout_5;
    QFrame *chartFrame;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(493, 521);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        gridLayout_6 = new QGridLayout(centralwidget);
        gridLayout_6->setObjectName("gridLayout_6");
        label = new QLabel(centralwidget);
        label->setObjectName("label");
        QFont font;
        font.setPointSize(24);
        font.setBold(true);
        label->setFont(font);
        label->setAlignment(Qt::AlignmentFlag::AlignCenter);

        gridLayout_6->addWidget(label, 0, 0, 1, 1);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName("horizontalLayout_4");
        groupBox_3 = new QGroupBox(centralwidget);
        groupBox_3->setObjectName("groupBox_3");
        groupBox_3->setAlignment(Qt::AlignmentFlag::AlignCenter);
        gridLayout_4 = new QGridLayout(groupBox_3);
        gridLayout_4->setObjectName("gridLayout_4");
        label_7 = new QLabel(groupBox_3);
        label_7->setObjectName("label_7");

        gridLayout_4->addWidget(label_7, 0, 0, 1, 1);

        labelUpperHumValue = new QLabel(groupBox_3);
        labelUpperHumValue->setObjectName("labelUpperHumValue");

        gridLayout_4->addWidget(labelUpperHumValue, 0, 1, 1, 1);

        labelHum = new QLabel(groupBox_3);
        labelHum->setObjectName("labelHum");
        QFont font1;
        font1.setPointSize(17);
        labelHum->setFont(font1);

        gridLayout_4->addWidget(labelHum, 0, 2, 2, 1);

        label_8 = new QLabel(groupBox_3);
        label_8->setObjectName("label_8");

        gridLayout_4->addWidget(label_8, 1, 0, 1, 1);

        labelLowerHumValue = new QLabel(groupBox_3);
        labelLowerHumValue->setObjectName("labelLowerHumValue");

        gridLayout_4->addWidget(labelLowerHumValue, 1, 1, 1, 1);


        horizontalLayout_4->addWidget(groupBox_3);

        groupBox = new QGroupBox(centralwidget);
        groupBox->setObjectName("groupBox");
        groupBox->setAlignment(Qt::AlignmentFlag::AlignCenter);
        gridLayout = new QGridLayout(groupBox);
        gridLayout->setObjectName("gridLayout");
        label_2 = new QLabel(groupBox);
        label_2->setObjectName("label_2");
        label_2->setAlignment(Qt::AlignmentFlag::AlignCenter);

        gridLayout->addWidget(label_2, 0, 0, 1, 1);

        label_3 = new QLabel(groupBox);
        label_3->setObjectName("label_3");
        label_3->setAlignment(Qt::AlignmentFlag::AlignCenter);

        gridLayout->addWidget(label_3, 0, 1, 1, 1);

        frameHumidity = new QFrame(groupBox);
        frameHumidity->setObjectName("frameHumidity");
        frameHumidity->setFrameShape(QFrame::Shape::StyledPanel);
        frameHumidity->setFrameShadow(QFrame::Shadow::Raised);
        horizontalLayout = new QHBoxLayout(frameHumidity);
        horizontalLayout->setObjectName("horizontalLayout");
        lcdHumidity = new QLCDNumber(frameHumidity);
        lcdHumidity->setObjectName("lcdHumidity");
        lcdHumidity->setMinimumSize(QSize(0, 0));
        lcdHumidity->setFont(font1);
        lcdHumidity->setDigitCount(2);

        horizontalLayout->addWidget(lcdHumidity);

        label_4 = new QLabel(frameHumidity);
        label_4->setObjectName("label_4");
        label_4->setAlignment(Qt::AlignmentFlag::AlignCenter);

        horizontalLayout->addWidget(label_4);


        gridLayout->addWidget(frameHumidity, 1, 0, 1, 1);

        frameTemperature = new QFrame(groupBox);
        frameTemperature->setObjectName("frameTemperature");
        frameTemperature->setFrameShape(QFrame::Shape::StyledPanel);
        frameTemperature->setFrameShadow(QFrame::Shadow::Raised);
        horizontalLayout_2 = new QHBoxLayout(frameTemperature);
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        lcdTemperature = new QLCDNumber(frameTemperature);
        lcdTemperature->setObjectName("lcdTemperature");
        lcdTemperature->setMinimumSize(QSize(0, 0));
        lcdTemperature->setFont(font1);
        lcdTemperature->setDigitCount(3);

        horizontalLayout_2->addWidget(lcdTemperature);

        comboBox = new QComboBox(frameTemperature);
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->setObjectName("comboBox");

        horizontalLayout_2->addWidget(comboBox);


        gridLayout->addWidget(frameTemperature, 1, 1, 1, 1);


        horizontalLayout_4->addWidget(groupBox);

        groupBox_2 = new QGroupBox(centralwidget);
        groupBox_2->setObjectName("groupBox_2");
        groupBox_2->setAlignment(Qt::AlignmentFlag::AlignCenter);
        gridLayout_3 = new QGridLayout(groupBox_2);
        gridLayout_3->setObjectName("gridLayout_3");
        label_5 = new QLabel(groupBox_2);
        label_5->setObjectName("label_5");

        gridLayout_3->addWidget(label_5, 0, 0, 1, 1);

        labelUpperTempValue = new QLabel(groupBox_2);
        labelUpperTempValue->setObjectName("labelUpperTempValue");

        gridLayout_3->addWidget(labelUpperTempValue, 0, 1, 1, 1);

        labelTemp = new QLabel(groupBox_2);
        labelTemp->setObjectName("labelTemp");
        QFont font2;
        font2.setPointSize(17);
        font2.setBold(false);
        labelTemp->setFont(font2);

        gridLayout_3->addWidget(labelTemp, 0, 2, 2, 1);

        label_6 = new QLabel(groupBox_2);
        label_6->setObjectName("label_6");

        gridLayout_3->addWidget(label_6, 1, 0, 1, 1);

        labelLowerTempValue = new QLabel(groupBox_2);
        labelLowerTempValue->setObjectName("labelLowerTempValue");

        gridLayout_3->addWidget(labelLowerTempValue, 1, 1, 1, 1);


        horizontalLayout_4->addWidget(groupBox_2);


        gridLayout_6->addLayout(horizontalLayout_4, 1, 0, 1, 1);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName("verticalLayout");
        frameButton = new QFrame(centralwidget);
        frameButton->setObjectName("frameButton");
        frameButton->setFrameShape(QFrame::Shape::StyledPanel);
        frameButton->setFrameShadow(QFrame::Shadow::Raised);
        horizontalLayout_3 = new QHBoxLayout(frameButton);
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        pushButtonSingle = new QPushButton(frameButton);
        pushButtonSingle->setObjectName("pushButtonSingle");

        horizontalLayout_3->addWidget(pushButtonSingle);

        pushButtonMultiple = new QPushButton(frameButton);
        pushButtonMultiple->setObjectName("pushButtonMultiple");

        horizontalLayout_3->addWidget(pushButtonMultiple);

        pushButtonCalculate = new QPushButton(frameButton);
        pushButtonCalculate->setObjectName("pushButtonCalculate");

        horizontalLayout_3->addWidget(pushButtonCalculate);

        pushButtonAlarm = new QPushButton(frameButton);
        pushButtonAlarm->setObjectName("pushButtonAlarm");

        horizontalLayout_3->addWidget(pushButtonAlarm);

        pushButtonClose = new QPushButton(frameButton);
        pushButtonClose->setObjectName("pushButtonClose");

        horizontalLayout_3->addWidget(pushButtonClose);


        verticalLayout->addWidget(frameButton);

        tabWidget = new QTabWidget(centralwidget);
        tabWidget->setObjectName("tabWidget");
        tabHistory = new QWidget();
        tabHistory->setObjectName("tabHistory");
        gridLayout_2 = new QGridLayout(tabHistory);
        gridLayout_2->setObjectName("gridLayout_2");
        tableWidget = new QTableWidget(tabHistory);
        tableWidget->setObjectName("tableWidget");

        gridLayout_2->addWidget(tableWidget, 0, 0, 1, 1);

        tabWidget->addTab(tabHistory, QString());
        tabChart = new QWidget();
        tabChart->setObjectName("tabChart");
        gridLayout_5 = new QGridLayout(tabChart);
        gridLayout_5->setObjectName("gridLayout_5");
        chartFrame = new QFrame(tabChart);
        chartFrame->setObjectName("chartFrame");

        gridLayout_5->addWidget(chartFrame, 0, 0, 1, 1);

        tabWidget->addTab(tabChart, QString());

        verticalLayout->addWidget(tabWidget);


        gridLayout_6->addLayout(verticalLayout, 2, 0, 1, 1);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 493, 21));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "Humidity & Temperature", nullptr));
        groupBox_3->setTitle(QCoreApplication::translate("MainWindow", "Alarm Humidity", nullptr));
        label_7->setText(QCoreApplication::translate("MainWindow", "Upper: ", nullptr));
        labelUpperHumValue->setText(QString());
        labelHum->setText(QCoreApplication::translate("MainWindow", "%", nullptr));
        label_8->setText(QCoreApplication::translate("MainWindow", "Lower: ", nullptr));
        labelLowerHumValue->setText(QString());
        groupBox->setTitle(QCoreApplication::translate("MainWindow", "Current Value", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "Humidity", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "Temperature", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "%", nullptr));
        comboBox->setItemText(0, QCoreApplication::translate("MainWindow", "\302\260F", nullptr));
        comboBox->setItemText(1, QCoreApplication::translate("MainWindow", "\302\260C", nullptr));

        groupBox_2->setTitle(QCoreApplication::translate("MainWindow", "Alarm Temperature", nullptr));
        label_5->setText(QCoreApplication::translate("MainWindow", "Upper: ", nullptr));
        labelUpperTempValue->setText(QString());
        labelTemp->setText(QCoreApplication::translate("MainWindow", "\302\260F", nullptr));
        label_6->setText(QCoreApplication::translate("MainWindow", "Lower: ", nullptr));
        labelLowerTempValue->setText(QString());
        pushButtonSingle->setText(QCoreApplication::translate("MainWindow", "Get Single!", nullptr));
        pushButtonMultiple->setText(QCoreApplication::translate("MainWindow", "Get 10!", nullptr));
        pushButtonCalculate->setText(QCoreApplication::translate("MainWindow", "Calculate!", nullptr));
        pushButtonAlarm->setText(QCoreApplication::translate("MainWindow", "Set Alarm!", nullptr));
        pushButtonClose->setText(QCoreApplication::translate("MainWindow", "Close", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tabHistory), QCoreApplication::translate("MainWindow", "History", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tabChart), QCoreApplication::translate("MainWindow", "Chart", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
