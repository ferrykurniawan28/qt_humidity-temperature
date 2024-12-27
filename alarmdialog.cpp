#include "alarmdialog.h"
#include <QMessageBox>

AlarmDialog::AlarmDialog(QWidget *parent)
    : QDialog(parent)
{
    setupUi(this);
}

void AlarmDialog::on_buttonBox_accepted()
{
    if(spinBoxLowerHum->value() > spinBoxUpperHum->value()) {
        QMessageBox::warning(this, "Error", "Lower humidity value cannot be greater than upper humidity value.");
        return;
    } else if(spinBoxLowerTemp->value() > spinBoxUpperTemp->value()) {
        QMessageBox::warning(this, "Error", "Lower temperature value cannot be greater than upper temperature value.");
        return;
    }
    accept();
}


void AlarmDialog::on_comboBox_activated(int index)
{
    if (index == 0) {
        fahrenheit = true;
    } else {
        fahrenheit = false;
    }
}

