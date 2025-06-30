/********************************************************************************
** Form generated from reading UI file 'mode.ui'
**
** Created by: Qt User Interface Compiler version 6.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MODE_H
#define UI_MODE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Mode
{
public:

    void setupUi(QWidget *Mode)
    {
        if (Mode->objectName().isEmpty())
            Mode->setObjectName("Mode");
        Mode->resize(400, 300);

        retranslateUi(Mode);

        QMetaObject::connectSlotsByName(Mode);
    } // setupUi

    void retranslateUi(QWidget *Mode)
    {
        Mode->setWindowTitle(QCoreApplication::translate("Mode", "Form", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Mode: public Ui_Mode {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MODE_H
