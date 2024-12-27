/********************************************************************************
** Form generated from reading UI file 'alarmdialog.ui'
**
** Created by: Qt User Interface Compiler version 6.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ALARMDIALOG_H
#define UI_ALARMDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAbstractButton>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QSpinBox>

QT_BEGIN_NAMESPACE

class Ui_AlarmDialog
{
public:
    QGridLayout *gridLayout_3;
    QLabel *label;
    QGroupBox *groupBox;
    QGridLayout *gridLayout;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_3;
    QFrame *frameUpperHum;
    QHBoxLayout *horizontalLayout;
    QSpinBox *spinBoxUpperHum;
    QLabel *label_2;
    QHBoxLayout *horizontalLayoutLower;
    QLabel *label_5;
    QFrame *frameUpperHum_2;
    QHBoxLayout *horizontalLayout_5;
    QSpinBox *spinBoxLowerHum;
    QLabel *label_6;
    QGroupBox *groupBox_2;
    QGridLayout *gridLayout_2;
    QComboBox *comboBox;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_7;
    QFrame *frameUpperHum_3;
    QHBoxLayout *horizontalLayout_6;
    QSpinBox *spinBoxUpperTemp;
    QHBoxLayout *horizontalLayoutLower_2;
    QLabel *label_9;
    QFrame *frameUpperHum_4;
    QHBoxLayout *horizontalLayout_7;
    QSpinBox *spinBoxLowerTemp;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *AlarmDialog)
    {
        if (AlarmDialog->objectName().isEmpty())
            AlarmDialog->setObjectName("AlarmDialog");
        AlarmDialog->resize(611, 310);
        gridLayout_3 = new QGridLayout(AlarmDialog);
        gridLayout_3->setObjectName("gridLayout_3");
        label = new QLabel(AlarmDialog);
        label->setObjectName("label");
        QFont font;
        font.setPointSize(14);
        font.setBold(true);
        label->setFont(font);
        label->setAlignment(Qt::AlignmentFlag::AlignCenter);

        gridLayout_3->addWidget(label, 0, 0, 1, 2);

        groupBox = new QGroupBox(AlarmDialog);
        groupBox->setObjectName("groupBox");
        groupBox->setAlignment(Qt::AlignmentFlag::AlignCenter);
        gridLayout = new QGridLayout(groupBox);
        gridLayout->setObjectName("gridLayout");
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        label_3 = new QLabel(groupBox);
        label_3->setObjectName("label_3");
        QFont font1;
        font1.setPointSize(9);
        label_3->setFont(font1);

        horizontalLayout_2->addWidget(label_3);

        frameUpperHum = new QFrame(groupBox);
        frameUpperHum->setObjectName("frameUpperHum");
        frameUpperHum->setFrameShape(QFrame::Shape::StyledPanel);
        frameUpperHum->setFrameShadow(QFrame::Shadow::Raised);
        horizontalLayout = new QHBoxLayout(frameUpperHum);
        horizontalLayout->setObjectName("horizontalLayout");
        spinBoxUpperHum = new QSpinBox(frameUpperHum);
        spinBoxUpperHum->setObjectName("spinBoxUpperHum");
        spinBoxUpperHum->setMinimum(-100);
        spinBoxUpperHum->setMaximum(200);

        horizontalLayout->addWidget(spinBoxUpperHum);

        label_2 = new QLabel(frameUpperHum);
        label_2->setObjectName("label_2");
        label_2->setFont(font1);

        horizontalLayout->addWidget(label_2);


        horizontalLayout_2->addWidget(frameUpperHum);


        gridLayout->addLayout(horizontalLayout_2, 0, 0, 1, 1);

        horizontalLayoutLower = new QHBoxLayout();
        horizontalLayoutLower->setObjectName("horizontalLayoutLower");
        label_5 = new QLabel(groupBox);
        label_5->setObjectName("label_5");
        label_5->setFont(font1);

        horizontalLayoutLower->addWidget(label_5);

        frameUpperHum_2 = new QFrame(groupBox);
        frameUpperHum_2->setObjectName("frameUpperHum_2");
        frameUpperHum_2->setFrameShape(QFrame::Shape::StyledPanel);
        frameUpperHum_2->setFrameShadow(QFrame::Shadow::Raised);
        horizontalLayout_5 = new QHBoxLayout(frameUpperHum_2);
        horizontalLayout_5->setObjectName("horizontalLayout_5");
        spinBoxLowerHum = new QSpinBox(frameUpperHum_2);
        spinBoxLowerHum->setObjectName("spinBoxLowerHum");
        spinBoxLowerHum->setMinimum(-100);
        spinBoxLowerHum->setMaximum(200);

        horizontalLayout_5->addWidget(spinBoxLowerHum);

        label_6 = new QLabel(frameUpperHum_2);
        label_6->setObjectName("label_6");
        label_6->setFont(font1);

        horizontalLayout_5->addWidget(label_6);


        horizontalLayoutLower->addWidget(frameUpperHum_2);


        gridLayout->addLayout(horizontalLayoutLower, 1, 0, 1, 1);


        gridLayout_3->addWidget(groupBox, 1, 0, 1, 1);

        groupBox_2 = new QGroupBox(AlarmDialog);
        groupBox_2->setObjectName("groupBox_2");
        groupBox_2->setAlignment(Qt::AlignmentFlag::AlignCenter);
        gridLayout_2 = new QGridLayout(groupBox_2);
        gridLayout_2->setObjectName("gridLayout_2");
        comboBox = new QComboBox(groupBox_2);
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->setObjectName("comboBox");

        gridLayout_2->addWidget(comboBox, 0, 0, 1, 1);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName("horizontalLayout_4");
        label_7 = new QLabel(groupBox_2);
        label_7->setObjectName("label_7");
        label_7->setFont(font1);

        horizontalLayout_4->addWidget(label_7);

        frameUpperHum_3 = new QFrame(groupBox_2);
        frameUpperHum_3->setObjectName("frameUpperHum_3");
        frameUpperHum_3->setFrameShape(QFrame::Shape::StyledPanel);
        frameUpperHum_3->setFrameShadow(QFrame::Shadow::Raised);
        horizontalLayout_6 = new QHBoxLayout(frameUpperHum_3);
        horizontalLayout_6->setObjectName("horizontalLayout_6");
        spinBoxUpperTemp = new QSpinBox(frameUpperHum_3);
        spinBoxUpperTemp->setObjectName("spinBoxUpperTemp");
        spinBoxUpperTemp->setMinimum(-100);
        spinBoxUpperTemp->setMaximum(200);

        horizontalLayout_6->addWidget(spinBoxUpperTemp);


        horizontalLayout_4->addWidget(frameUpperHum_3);


        gridLayout_2->addLayout(horizontalLayout_4, 1, 0, 1, 1);

        horizontalLayoutLower_2 = new QHBoxLayout();
        horizontalLayoutLower_2->setObjectName("horizontalLayoutLower_2");
        label_9 = new QLabel(groupBox_2);
        label_9->setObjectName("label_9");
        label_9->setFont(font1);

        horizontalLayoutLower_2->addWidget(label_9);

        frameUpperHum_4 = new QFrame(groupBox_2);
        frameUpperHum_4->setObjectName("frameUpperHum_4");
        frameUpperHum_4->setFrameShape(QFrame::Shape::StyledPanel);
        frameUpperHum_4->setFrameShadow(QFrame::Shadow::Raised);
        horizontalLayout_7 = new QHBoxLayout(frameUpperHum_4);
        horizontalLayout_7->setObjectName("horizontalLayout_7");
        spinBoxLowerTemp = new QSpinBox(frameUpperHum_4);
        spinBoxLowerTemp->setObjectName("spinBoxLowerTemp");
        spinBoxLowerTemp->setMinimum(-100);
        spinBoxLowerTemp->setMaximum(200);

        horizontalLayout_7->addWidget(spinBoxLowerTemp);


        horizontalLayoutLower_2->addWidget(frameUpperHum_4);


        gridLayout_2->addLayout(horizontalLayoutLower_2, 2, 0, 1, 1);


        gridLayout_3->addWidget(groupBox_2, 1, 1, 1, 1);

        buttonBox = new QDialogButtonBox(AlarmDialog);
        buttonBox->setObjectName("buttonBox");
        buttonBox->setOrientation(Qt::Orientation::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::StandardButton::Cancel|QDialogButtonBox::StandardButton::Ok);

        gridLayout_3->addWidget(buttonBox, 2, 0, 1, 2);


        retranslateUi(AlarmDialog);
        QObject::connect(buttonBox, &QDialogButtonBox::accepted, AlarmDialog, qOverload<>(&QDialog::accept));
        QObject::connect(buttonBox, &QDialogButtonBox::rejected, AlarmDialog, qOverload<>(&QDialog::reject));

        QMetaObject::connectSlotsByName(AlarmDialog);
    } // setupUi

    void retranslateUi(QDialog *AlarmDialog)
    {
        AlarmDialog->setWindowTitle(QCoreApplication::translate("AlarmDialog", "Dialog", nullptr));
        label->setText(QCoreApplication::translate("AlarmDialog", "Alarm Thresholds", nullptr));
        groupBox->setTitle(QCoreApplication::translate("AlarmDialog", "Humidity", nullptr));
        label_3->setText(QCoreApplication::translate("AlarmDialog", "Upper", nullptr));
        label_2->setText(QCoreApplication::translate("AlarmDialog", "%", nullptr));
        label_5->setText(QCoreApplication::translate("AlarmDialog", "Lower", nullptr));
        label_6->setText(QCoreApplication::translate("AlarmDialog", "%", nullptr));
        groupBox_2->setTitle(QCoreApplication::translate("AlarmDialog", "Temperature", nullptr));
        comboBox->setItemText(0, QCoreApplication::translate("AlarmDialog", "\302\260F", nullptr));
        comboBox->setItemText(1, QCoreApplication::translate("AlarmDialog", "\302\260C", nullptr));

        label_7->setText(QCoreApplication::translate("AlarmDialog", "Upper", nullptr));
        label_9->setText(QCoreApplication::translate("AlarmDialog", "Lower", nullptr));
    } // retranslateUi

};

namespace Ui {
    class AlarmDialog: public Ui_AlarmDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ALARMDIALOG_H
