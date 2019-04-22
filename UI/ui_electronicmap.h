/********************************************************************************
** Form generated from reading UI file 'electronicmap.ui'
**
** Created by: Qt User Interface Compiler version 4.8.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ELECTRONICMAP_H
#define UI_ELECTRONICMAP_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QHeaderView>

QT_BEGIN_NAMESPACE

class Ui_electronicMap
{
public:

    void setupUi(QDialog *electronicMap)
    {
        if (electronicMap->objectName().isEmpty())
            electronicMap->setObjectName(QString::fromUtf8("electronicMap"));
        electronicMap->resize(1108, 741);
        electronicMap->setStyleSheet(QString::fromUtf8(""));

        retranslateUi(electronicMap);

        QMetaObject::connectSlotsByName(electronicMap);
    } // setupUi

    void retranslateUi(QDialog *electronicMap)
    {
        electronicMap->setWindowTitle(QApplication::translate("electronicMap", "Dialog", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class electronicMap: public Ui_electronicMap {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ELECTRONICMAP_H
