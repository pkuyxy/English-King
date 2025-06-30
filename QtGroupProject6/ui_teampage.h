/********************************************************************************
** Form generated from reading UI file 'teampage.ui'
**
** Created by: Qt User Interface Compiler version 6.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TEAMPAGE_H
#define UI_TEAMPAGE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_TeamPage
{
public:

    void setupUi(QWidget *TeamPage)
    {
        if (TeamPage->objectName().isEmpty())
            TeamPage->setObjectName("TeamPage");
        TeamPage->resize(400, 300);

        retranslateUi(TeamPage);

        QMetaObject::connectSlotsByName(TeamPage);
    } // setupUi

    void retranslateUi(QWidget *TeamPage)
    {
        TeamPage->setWindowTitle(QCoreApplication::translate("TeamPage", "Form", nullptr));
    } // retranslateUi

};

namespace Ui {
    class TeamPage: public Ui_TeamPage {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TEAMPAGE_H
