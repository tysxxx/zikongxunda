/********************************************************************************
** Form generated from reading UI file 'twoscreen.ui'
**
** Created by: Qt User Interface Compiler version 4.8.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TWOSCREEN_H
#define UI_TWOSCREEN_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QFrame>
#include <QtGui/QGridLayout>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_twoScreen
{
public:
    QGridLayout *gridLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label_win0;
    QFrame *line;
    QLabel *label_win1;

    void setupUi(QWidget *twoScreen)
    {
        if (twoScreen->objectName().isEmpty())
            twoScreen->setObjectName(QString::fromUtf8("twoScreen"));
        twoScreen->resize(1212, 793);
        gridLayout = new QGridLayout(twoScreen);
        gridLayout->setSpacing(0);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(0);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label_win0 = new QLabel(twoScreen);
        label_win0->setObjectName(QString::fromUtf8("label_win0"));

        horizontalLayout->addWidget(label_win0);

        line = new QFrame(twoScreen);
        line->setObjectName(QString::fromUtf8("line"));
        line->setFrameShape(QFrame::VLine);
        line->setFrameShadow(QFrame::Sunken);

        horizontalLayout->addWidget(line);

        label_win1 = new QLabel(twoScreen);
        label_win1->setObjectName(QString::fromUtf8("label_win1"));

        horizontalLayout->addWidget(label_win1);


        gridLayout->addLayout(horizontalLayout, 0, 0, 1, 1);


        retranslateUi(twoScreen);

        QMetaObject::connectSlotsByName(twoScreen);
    } // setupUi

    void retranslateUi(QWidget *twoScreen)
    {
        twoScreen->setWindowTitle(QApplication::translate("twoScreen", "Form", 0, QApplication::UnicodeUTF8));
        label_win0->setText(QString());
        label_win1->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class twoScreen: public Ui_twoScreen {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TWOSCREEN_H
