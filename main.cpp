#include "mainwindow.h"
// #include <iostream>
// #include "PseudoSensor.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    // PseudoSensor sensor;

    // for (int i = 0; i < 10; i++) {
    //     auto values = sensor.generateValues();
    //     std::cout << "Humidity: " << values.first << " Temperature: " << values.second << std::endl;
    // }

    MainWindow w;
    w.show();
    return a.exec();
}
