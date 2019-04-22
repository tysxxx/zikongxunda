/********************************************************************************
** Form generated from reading UI file 'vediomeeting.ui'
**
** Created by: Qt User Interface Compiler version 4.8.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_VEDIOMEETING_H
#define UI_VEDIOMEETING_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QHeaderView>

QT_BEGIN_NAMESPACE

class Ui_vedioMeeting
{
public:

    void setupUi(QDialog *vedioMeeting)
    {
        if (vedioMeeting->objectName().isEmpty())
            vedioMeeting->setObjectName(QString::fromUtf8("vedioMeeting"));
        vedioMeeting->resize(1225, 782);
        vedioMeeting->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 0, 0);"));

        retranslateUi(vedioMeeting);

        QMetaObject::connectSlotsByName(vedioMeeting);
    } // setupUi

    void retranslateUi(QDialog *vedioMeeting)
    {
        vedioMeeting->setWindowTitle(QApplication::translate("vedioMeeting", "Dialog", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class vedioMeeting: public Ui_vedioMeeting {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_VEDIOMEETING_H
