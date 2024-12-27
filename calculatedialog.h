#ifndef CALCULATEDIALOG_H
#define CALCULATEDIALOG_H

#include "ui_calculatedialog.h"

class CalculateDialog : public QDialog, public Ui::CalculateDialog
{
    Q_OBJECT

public:
    explicit CalculateDialog(QWidget *parent = nullptr,
                             double minHumidity = 0,
                             double maxHumidity = 0,
                             double avgHumidity = 0,
                             double minTemperature = 0,
                             double maxTemperature = 0,
                             double avgTemperature = 0);
private:
    void setupLCDValues(double minHumidity, double maxHumidity, double avgHumidity,
                        double minTemperature, double maxTemperature, double avgTemperature);
};

#endif // CALCULATEDIALOG_H
