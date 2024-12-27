/********************************************************************************
** Form generated from reading UI file 'calculatedialog.ui'
**
** Created by: Qt User Interface Compiler version 6.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CALCULATEDIALOG_H
#define UI_CALCULATEDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAbstractButton>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLCDNumber>
#include <QtWidgets/QLabel>

QT_BEGIN_NAMESPACE

class Ui_CalculateDialog
{
public:
    QGridLayout *gridLayout_3;
    QGroupBox *groupBox;
    QGridLayout *gridLayout_2;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLCDNumber *lcdHumMin;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_2;
    QLCDNumber *lcdHumMax;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_3;
    QLCDNumber *lcdHumAvg;
    QGroupBox *groupBox_2;
    QGridLayout *gridLayout;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_4;
    QLCDNumber *lcdTempMin;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_5;
    QLCDNumber *lcdTempMax;
    QHBoxLayout *horizontalLayout_6;
    QLabel *label_6;
    QLCDNumber *lcdTempAvg;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *CalculateDialog)
    {
        if (CalculateDialog->objectName().isEmpty())
            CalculateDialog->setObjectName("CalculateDialog");
        CalculateDialog->resize(274, 178);
        gridLayout_3 = new QGridLayout(CalculateDialog);
        gridLayout_3->setObjectName("gridLayout_3");
        groupBox = new QGroupBox(CalculateDialog);
        groupBox->setObjectName("groupBox");
        groupBox->setAlignment(Qt::AlignmentFlag::AlignCenter);
        gridLayout_2 = new QGridLayout(groupBox);
        gridLayout_2->setObjectName("gridLayout_2");
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        label = new QLabel(groupBox);
        label->setObjectName("label");

        horizontalLayout->addWidget(label);

        lcdHumMin = new QLCDNumber(groupBox);
        lcdHumMin->setObjectName("lcdHumMin");

        horizontalLayout->addWidget(lcdHumMin);


        gridLayout_2->addLayout(horizontalLayout, 0, 0, 1, 1);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        label_2 = new QLabel(groupBox);
        label_2->setObjectName("label_2");

        horizontalLayout_2->addWidget(label_2);

        lcdHumMax = new QLCDNumber(groupBox);
        lcdHumMax->setObjectName("lcdHumMax");

        horizontalLayout_2->addWidget(lcdHumMax);


        gridLayout_2->addLayout(horizontalLayout_2, 1, 0, 1, 1);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        label_3 = new QLabel(groupBox);
        label_3->setObjectName("label_3");

        horizontalLayout_3->addWidget(label_3);

        lcdHumAvg = new QLCDNumber(groupBox);
        lcdHumAvg->setObjectName("lcdHumAvg");

        horizontalLayout_3->addWidget(lcdHumAvg);


        gridLayout_2->addLayout(horizontalLayout_3, 2, 0, 1, 1);


        gridLayout_3->addWidget(groupBox, 0, 0, 1, 1);

        groupBox_2 = new QGroupBox(CalculateDialog);
        groupBox_2->setObjectName("groupBox_2");
        groupBox_2->setAlignment(Qt::AlignmentFlag::AlignCenter);
        gridLayout = new QGridLayout(groupBox_2);
        gridLayout->setObjectName("gridLayout");
        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName("horizontalLayout_4");
        label_4 = new QLabel(groupBox_2);
        label_4->setObjectName("label_4");

        horizontalLayout_4->addWidget(label_4);

        lcdTempMin = new QLCDNumber(groupBox_2);
        lcdTempMin->setObjectName("lcdTempMin");

        horizontalLayout_4->addWidget(lcdTempMin);


        gridLayout->addLayout(horizontalLayout_4, 0, 0, 1, 1);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName("horizontalLayout_5");
        label_5 = new QLabel(groupBox_2);
        label_5->setObjectName("label_5");

        horizontalLayout_5->addWidget(label_5);

        lcdTempMax = new QLCDNumber(groupBox_2);
        lcdTempMax->setObjectName("lcdTempMax");

        horizontalLayout_5->addWidget(lcdTempMax);


        gridLayout->addLayout(horizontalLayout_5, 1, 0, 1, 1);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName("horizontalLayout_6");
        label_6 = new QLabel(groupBox_2);
        label_6->setObjectName("label_6");

        horizontalLayout_6->addWidget(label_6);

        lcdTempAvg = new QLCDNumber(groupBox_2);
        lcdTempAvg->setObjectName("lcdTempAvg");

        horizontalLayout_6->addWidget(lcdTempAvg);


        gridLayout->addLayout(horizontalLayout_6, 2, 0, 1, 1);


        gridLayout_3->addWidget(groupBox_2, 0, 1, 1, 1);

        buttonBox = new QDialogButtonBox(CalculateDialog);
        buttonBox->setObjectName("buttonBox");
        buttonBox->setOrientation(Qt::Orientation::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::StandardButton::Cancel|QDialogButtonBox::StandardButton::Ok);

        gridLayout_3->addWidget(buttonBox, 1, 0, 1, 2);


        retranslateUi(CalculateDialog);
        QObject::connect(buttonBox, &QDialogButtonBox::accepted, CalculateDialog, qOverload<>(&QDialog::accept));
        QObject::connect(buttonBox, &QDialogButtonBox::rejected, CalculateDialog, qOverload<>(&QDialog::reject));

        QMetaObject::connectSlotsByName(CalculateDialog);
    } // setupUi

    void retranslateUi(QDialog *CalculateDialog)
    {
        CalculateDialog->setWindowTitle(QCoreApplication::translate("CalculateDialog", "Dialog", nullptr));
        groupBox->setTitle(QCoreApplication::translate("CalculateDialog", "Humidity", nullptr));
        label->setText(QCoreApplication::translate("CalculateDialog", "Min :", nullptr));
        label_2->setText(QCoreApplication::translate("CalculateDialog", "Max :", nullptr));
        label_3->setText(QCoreApplication::translate("CalculateDialog", "Avg :", nullptr));
        groupBox_2->setTitle(QCoreApplication::translate("CalculateDialog", "Temperature", nullptr));
        label_4->setText(QCoreApplication::translate("CalculateDialog", "Min :", nullptr));
        label_5->setText(QCoreApplication::translate("CalculateDialog", "Max :", nullptr));
        label_6->setText(QCoreApplication::translate("CalculateDialog", "Avg :", nullptr));
    } // retranslateUi

};

namespace Ui {
    class CalculateDialog: public Ui_CalculateDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CALCULATEDIALOG_H
