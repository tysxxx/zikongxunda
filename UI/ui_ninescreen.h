/********************************************************************************
** Form generated from reading UI file 'ninescreen.ui'
**
** Created by: Qt User Interface Compiler version 4.8.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_NINESCREEN_H
#define UI_NINESCREEN_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QFrame>
#include <QtGui/QGridLayout>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_nineScreen
{
public:
    QGridLayout *gridLayout;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label_win0;
    QFrame *line;
    QLabel *label_win1;
    QFrame *line_2;
    QLabel *label_win2;
    QFrame *line_3;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_win3;
    QFrame *line_4;
    QLabel *label_win4;
    QFrame *line_5;
    QLabel *label_win5;
    QFrame *line_8;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_win6;
    QFrame *line_6;
    QLabel *label_win7;
    QFrame *line_7;
    QLabel *label_win8;

    void setupUi(QWidget *nineScreen)
    {
        if (nineScreen->objectName().isEmpty())
            nineScreen->setObjectName(QString::fromUtf8("nineScreen"));
        nineScreen->resize(1167, 741);
        gridLayout = new QGridLayout(nineScreen);
        gridLayout->setSpacing(0);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(0);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label_win0 = new QLabel(nineScreen);
        label_win0->setObjectName(QString::fromUtf8("label_win0"));

        horizontalLayout->addWidget(label_win0);

        line = new QFrame(nineScreen);
        line->setObjectName(QString::fromUtf8("line"));
        line->setFrameShape(QFrame::VLine);
        line->setFrameShadow(QFrame::Sunken);

        horizontalLayout->addWidget(line);

        label_win1 = new QLabel(nineScreen);
        label_win1->setObjectName(QString::fromUtf8("label_win1"));

        horizontalLayout->addWidget(label_win1);

        line_2 = new QFrame(nineScreen);
        line_2->setObjectName(QString::fromUtf8("line_2"));
        line_2->setFrameShape(QFrame::VLine);
        line_2->setFrameShadow(QFrame::Sunken);

        horizontalLayout->addWidget(line_2);

        label_win2 = new QLabel(nineScreen);
        label_win2->setObjectName(QString::fromUtf8("label_win2"));

        horizontalLayout->addWidget(label_win2);


        verticalLayout->addLayout(horizontalLayout);

        line_3 = new QFrame(nineScreen);
        line_3->setObjectName(QString::fromUtf8("line_3"));
        line_3->setFrameShape(QFrame::HLine);
        line_3->setFrameShadow(QFrame::Sunken);

        verticalLayout->addWidget(line_3);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(0);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        label_win3 = new QLabel(nineScreen);
        label_win3->setObjectName(QString::fromUtf8("label_win3"));

        horizontalLayout_2->addWidget(label_win3);

        line_4 = new QFrame(nineScreen);
        line_4->setObjectName(QString::fromUtf8("line_4"));
        line_4->setFrameShape(QFrame::VLine);
        line_4->setFrameShadow(QFrame::Sunken);

        horizontalLayout_2->addWidget(line_4);

        label_win4 = new QLabel(nineScreen);
        label_win4->setObjectName(QString::fromUtf8("label_win4"));

        horizontalLayout_2->addWidget(label_win4);

        line_5 = new QFrame(nineScreen);
        line_5->setObjectName(QString::fromUtf8("line_5"));
        line_5->setFrameShape(QFrame::VLine);
        line_5->setFrameShadow(QFrame::Sunken);

        horizontalLayout_2->addWidget(line_5);

        label_win5 = new QLabel(nineScreen);
        label_win5->setObjectName(QString::fromUtf8("label_win5"));

        horizontalLayout_2->addWidget(label_win5);


        verticalLayout->addLayout(horizontalLayout_2);

        line_8 = new QFrame(nineScreen);
        line_8->setObjectName(QString::fromUtf8("line_8"));
        line_8->setFrameShape(QFrame::HLine);
        line_8->setFrameShadow(QFrame::Sunken);

        verticalLayout->addWidget(line_8);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(0);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        label_win6 = new QLabel(nineScreen);
        label_win6->setObjectName(QString::fromUtf8("label_win6"));

        horizontalLayout_3->addWidget(label_win6);

        line_6 = new QFrame(nineScreen);
        line_6->setObjectName(QString::fromUtf8("line_6"));
        line_6->setFrameShape(QFrame::VLine);
        line_6->setFrameShadow(QFrame::Sunken);

        horizontalLayout_3->addWidget(line_6);

        label_win7 = new QLabel(nineScreen);
        label_win7->setObjectName(QString::fromUtf8("label_win7"));

        horizontalLayout_3->addWidget(label_win7);

        line_7 = new QFrame(nineScreen);
        line_7->setObjectName(QString::fromUtf8("line_7"));
        line_7->setFrameShape(QFrame::VLine);
        line_7->setFrameShadow(QFrame::Sunken);

        horizontalLayout_3->addWidget(line_7);

        label_win8 = new QLabel(nineScreen);
        label_win8->setObjectName(QString::fromUtf8("label_win8"));

        horizontalLayout_3->addWidget(label_win8);


        verticalLayout->addLayout(horizontalLayout_3);


        gridLayout->addLayout(verticalLayout, 0, 0, 1, 1);


        retranslateUi(nineScreen);

        QMetaObject::connectSlotsByName(nineScreen);
    } // setupUi

    void retranslateUi(QWidget *nineScreen)
    {
        nineScreen->setWindowTitle(QApplication::translate("nineScreen", "Form", 0, QApplication::UnicodeUTF8));
        label_win0->setText(QString());
        label_win1->setText(QString());
        label_win2->setText(QString());
        label_win3->setText(QString());
        label_win4->setText(QString());
        label_win5->setText(QString());
        label_win6->setText(QString());
        label_win7->setText(QString());
        label_win8->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class nineScreen: public Ui_nineScreen {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_NINESCREEN_H
