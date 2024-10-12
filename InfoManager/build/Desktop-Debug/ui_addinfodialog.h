/********************************************************************************
** Form generated from reading UI file 'addinfodialog.ui'
**
** Created by: Qt User Interface Compiler version 5.15.15
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADDINFODIALOG_H
#define UI_ADDINFODIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_AddInfoDialog
{
public:
    QPushButton *confirmButton;
    QPushButton *cancelButton;
    QLabel *label_3;
    QWidget *widget;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLineEdit *lineName;
    QWidget *widget1;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_2;
    QLineEdit *lineId;
    QWidget *widget2;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_4;
    QComboBox *cmbSex;

    void setupUi(QDialog *AddInfoDialog)
    {
        if (AddInfoDialog->objectName().isEmpty())
            AddInfoDialog->setObjectName(QString::fromUtf8("AddInfoDialog"));
        AddInfoDialog->resize(400, 300);
        confirmButton = new QPushButton(AddInfoDialog);
        confirmButton->setObjectName(QString::fromUtf8("confirmButton"));
        confirmButton->setGeometry(QRect(60, 230, 80, 25));
        cancelButton = new QPushButton(AddInfoDialog);
        cancelButton->setObjectName(QString::fromUtf8("cancelButton"));
        cancelButton->setGeometry(QRect(210, 230, 80, 25));
        label_3 = new QLabel(AddInfoDialog);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(50, 130, 53, 17));
        widget = new QWidget(AddInfoDialog);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(40, 100, 321, 27));
        horizontalLayout = new QHBoxLayout(widget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(widget);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout->addWidget(label);

        lineName = new QLineEdit(widget);
        lineName->setObjectName(QString::fromUtf8("lineName"));

        horizontalLayout->addWidget(lineName);

        widget1 = new QWidget(AddInfoDialog);
        widget1->setObjectName(QString::fromUtf8("widget1"));
        widget1->setGeometry(QRect(40, 50, 321, 27));
        horizontalLayout_2 = new QHBoxLayout(widget1);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        label_2 = new QLabel(widget1);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        horizontalLayout_2->addWidget(label_2);

        lineId = new QLineEdit(widget1);
        lineId->setObjectName(QString::fromUtf8("lineId"));

        horizontalLayout_2->addWidget(lineId);

        widget2 = new QWidget(AddInfoDialog);
        widget2->setObjectName(QString::fromUtf8("widget2"));
        widget2->setGeometry(QRect(40, 150, 101, 27));
        horizontalLayout_3 = new QHBoxLayout(widget2);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
        label_4 = new QLabel(widget2);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        horizontalLayout_3->addWidget(label_4);

        cmbSex = new QComboBox(widget2);
        cmbSex->setObjectName(QString::fromUtf8("cmbSex"));

        horizontalLayout_3->addWidget(cmbSex);


        retranslateUi(AddInfoDialog);

        QMetaObject::connectSlotsByName(AddInfoDialog);
    } // setupUi

    void retranslateUi(QDialog *AddInfoDialog)
    {
        AddInfoDialog->setWindowTitle(QCoreApplication::translate("AddInfoDialog", "Dialog", nullptr));
        confirmButton->setText(QCoreApplication::translate("AddInfoDialog", "\347\241\256\345\256\232", nullptr));
        cancelButton->setText(QCoreApplication::translate("AddInfoDialog", "\345\217\226\346\266\210", nullptr));
        label_3->setText(QString());
        label->setText(QCoreApplication::translate("AddInfoDialog", "Name", nullptr));
        label_2->setText(QCoreApplication::translate("AddInfoDialog", "  ID     ", nullptr));
        label_4->setText(QCoreApplication::translate("AddInfoDialog", "Sex", nullptr));
    } // retranslateUi

};

namespace Ui {
    class AddInfoDialog: public Ui_AddInfoDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADDINFODIALOG_H
