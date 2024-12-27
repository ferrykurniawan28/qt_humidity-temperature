#include "calculatedialog.h"

CalculateDialog::CalculateDialog(QWidget *parent,
                                 double minHumidity,
                                 double maxHumidity,
                                 double avgHumidity,
                                 double minTemperature,
                                 double maxTemperature,
                                 double avgTemperature)
    : QDialog(parent)
{
    setupUi(this); // Set up the UI

    // Set the values to the LCDs
    setupLCDValues(minHumidity, maxHumidity, avgHumidity,
                   minTemperature, maxTemperature, avgTemperature);
}

void CalculateDialog::setupLCDValues(double minHumidity, double maxHumidity, double avgHumidity, double minTemperature, double maxTemperature, double avgTemperature)
{
    lcdHumMin->display(minHumidity);
    lcdHumMax->display(maxHumidity);
    lcdHumAvg->display(avgHumidity);
    lcdTempMin->display(minTemperature);
    lcdTempMax->display(maxTemperature);
    lcdTempAvg->display(avgTemperature);
}
