/********************************************************************************
** Form generated from reading UI file 'fourscreen.ui'
**
** Created by: Qt User Interface Compiler version 4.8.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FOURSCREEN_H
#define UI_FOURSCREEN_H

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

class Ui_fourScreen
{
public:
    QGridLayout *gridLayout;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label_win0;
    QFrame *line_2;
    QLabel *label_win1;
    QFrame *line;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_win2;
    QFrame *line_3;
    QLabel *label_win3;

    void setupUi(QWidget *fourScreen)
    {
        if (fourScreen->objectName().isEmpty())
            fourScreen->setObjectName(QString::fromUtf8("fourScreen"));
        fourScreen->resize(1143, 769);
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(fourScreen->sizePolicy().hasHeightForWidth());
        fourScreen->setSizePolicy(sizePolicy);
        gridLayout = new QGridLayout(fourScreen);
        gridLayout->setSpacing(0);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setSizeConstraint(QLayout::SetMinAndMaxSize);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(0);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setSizeConstraint(QLayout::SetMinAndMaxSize);
        label_win0 = new QLabel(fourScreen);
        label_win0->setObjectName(QString::fromUtf8("label_win0"));
        QFont font;
        font.setPointSize(16);
        label_win0->setFont(font);
        label_win0->setStyleSheet(QString::fromUtf8("color: rgb(255, 0, 0);"));

        horizontalLayout->addWidget(label_win0);

        line_2 = new QFrame(fourScreen);
        line_2->setObjectName(QString::fromUtf8("line_2"));
        QSizePolicy sizePolicy1(QSizePolicy::Fixed, QSizePolicy::Expanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(line_2->sizePolicy().hasHeightForWidth());
        line_2->setSizePolicy(sizePolicy1);
        line_2->setMinimumSize(QSize(1, 0));
        line_2->setMaximumSize(QSize(1, 16777215));
        line_2->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        line_2->setFrameShape(QFrame::VLine);
        line_2->setFrameShadow(QFrame::Sunken);

        horizontalLayout->addWidget(line_2);

        label_win1 = new QLabel(fourScreen);
        label_win1->setObjectName(QString::fromUtf8("label_win1"));
        label_win1->setFont(font);

        horizontalLayout->addWidget(label_win1);


        verticalLayout->addLayout(horizontalLayout);

        line = new QFrame(fourScreen);
        line->setObjectName(QString::fromUtf8("line"));
        QSizePolicy sizePolicy2(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(line->sizePolicy().hasHeightForWidth());
        line->setSizePolicy(sizePolicy2);
        line->setMinimumSize(QSize(0, 1));
        line->setMaximumSize(QSize(16777215, 1));
        line->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);

        verticalLayout->addWidget(line);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(0);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalLayout_2->setSizeConstraint(QLayout::SetMinAndMaxSize);
        label_win2 = new QLabel(fourScreen);
        label_win2->setObjectName(QString::fromUtf8("label_win2"));
        label_win2->setFont(font);

        horizontalLayout_2->addWidget(label_win2);

        line_3 = new QFrame(fourScreen);
        line_3->setObjectName(QString::fromUtf8("line_3"));
        sizePolicy1.setHeightForWidth(line_3->sizePolicy().hasHeightForWidth());
        line_3->setSizePolicy(sizePolicy1);
        line_3->setMinimumSize(QSize(1, 0));
        line_3->setMaximumSize(QSize(1, 16777215));
        line_3->setFrameShape(QFrame::VLine);
        line_3->setFrameShadow(QFrame::Sunken);

        horizontalLayout_2->addWidget(line_3);

        label_win3 = new QLabel(fourScreen);
        label_win3->setObjectName(QString::fromUtf8("label_win3"));
        QFont font1;
        font1.setPointSize(17);
        label_win3->setFont(font1);

        horizontalLayout_2->addWidget(label_win3);


        verticalLayout->addLayout(horizontalLayout_2);


        gridLayout->addLayout(verticalLayout, 0, 0, 1, 1);


        retranslateUi(fourScreen);

        QMetaObject::connectSlotsByName(fourScreen);
    } // setupUi

    void retranslateUi(QWidget *fourScreen)
    {
        fourScreen->setWindowTitle(QApplication::translate("fourScreen", "Form", 0, QApplication::UnicodeUTF8));
        label_win0->setText(QString());
        label_win1->setText(QString());
        label_win2->setText(QString());
        label_win3->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class fourScreen: public Ui_fourScreen {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FOURSCREEN_H
