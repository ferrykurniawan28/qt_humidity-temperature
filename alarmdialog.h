#ifndef ALARMDIALOG_H
#define ALARMDIALOG_H

#include "ui_alarmdialog.h"

class AlarmDialog : public QDialog, public Ui::AlarmDialog
{
    Q_OBJECT


public:
    explicit AlarmDialog(QWidget *parent = nullptr);
    bool fahrenheit = true;
private slots:
    void on_buttonBox_accepted();
    void on_comboBox_activated(int index);
};

#endif // ALARMDIALOG_H
