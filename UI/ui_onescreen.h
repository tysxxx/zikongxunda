/********************************************************************************
** Form generated from reading UI file 'onescreen.ui'
**
** Created by: Qt User Interface Compiler version 4.8.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ONESCREEN_H
#define UI_ONESCREEN_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHeaderView>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_oneScreen
{
public:

    void setupUi(QWidget *oneScreen)
    {
        if (oneScreen->objectName().isEmpty())
            oneScreen->setObjectName(QString::fromUtf8("oneScreen"));
        oneScreen->resize(1740, 1000);

        retranslateUi(oneScreen);

        QMetaObject::connectSlotsByName(oneScreen);
    } // setupUi

    void retranslateUi(QWidget *oneScreen)
    {
        oneScreen->setWindowTitle(QApplication::translate("oneScreen", "Form", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class oneScreen: public Ui_oneScreen {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ONESCREEN_H
