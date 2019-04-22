/********************************************************************************
** Form generated from reading UI file 'vediosearch.ui'
**
** Created by: Qt User Interface Compiler version 4.8.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_VEDIOSEARCH_H
#define UI_VEDIOSEARCH_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QComboBox>
#include <QtGui/QDialog>
#include <QtGui/QGridLayout>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QPushButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_vedioSearch
{
public:
    QGridLayout *gridLayout;
    QHBoxLayout *horizontalLayout_4;
    QSpacerItem *horizontalSpacer_2;
    QVBoxLayout *verticalLayout_2;
    QSpacerItem *verticalSpacer_3;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_3;
    QHBoxLayout *horizontalLayout;
    QPushButton *pushButton_dowload;
    QPushButton *pushButton_play;
    QSpacerItem *horizontalSpacer;
    QSpacerItem *verticalSpacer;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer_4;
    QLabel *label_channel;
    QSpacerItem *horizontalSpacer_5;
    QComboBox *comboBox_channel;
    QSpacerItem *horizontalSpacer_6;
    QLabel *label_date;
    QSpacerItem *horizontalSpacer_7;
    QLineEdit *lineEdit;
    QSpacerItem *horizontalSpacer_8;
    QPushButton *pushButton_dateTime;
    QSpacerItem *horizontalSpacer_9;
    QPushButton *pushButton_search;
    QSpacerItem *horizontalSpacer_10;
    QSpacerItem *verticalSpacer_2;
    QWidget *widget;
    QSpacerItem *verticalSpacer_4;
    QSpacerItem *horizontalSpacer_3;

    void setupUi(QDialog *vedioSearch)
    {
        if (vedioSearch->objectName().isEmpty())
            vedioSearch->setObjectName(QString::fromUtf8("vedioSearch"));
        vedioSearch->resize(1100, 733);
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(vedioSearch->sizePolicy().hasHeightForWidth());
        vedioSearch->setSizePolicy(sizePolicy);
        vedioSearch->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 0, 0);"));
        gridLayout = new QGridLayout(vedioSearch);
        gridLayout->setSpacing(0);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(0);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_2);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(0);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalSpacer_3 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer_3);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(0);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(0);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        pushButton_dowload = new QPushButton(vedioSearch);
        pushButton_dowload->setObjectName(QString::fromUtf8("pushButton_dowload"));
        sizePolicy.setHeightForWidth(pushButton_dowload->sizePolicy().hasHeightForWidth());
        pushButton_dowload->setSizePolicy(sizePolicy);
        QFont font;
        font.setPointSize(30);
        pushButton_dowload->setFont(font);
        pushButton_dowload->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));

        horizontalLayout->addWidget(pushButton_dowload);

        pushButton_play = new QPushButton(vedioSearch);
        pushButton_play->setObjectName(QString::fromUtf8("pushButton_play"));
        sizePolicy.setHeightForWidth(pushButton_play->sizePolicy().hasHeightForWidth());
        pushButton_play->setSizePolicy(sizePolicy);
        pushButton_play->setFont(font);
        pushButton_play->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));

        horizontalLayout->addWidget(pushButton_play);

        horizontalLayout->setStretch(0, 1);
        horizontalLayout->setStretch(1, 1);

        horizontalLayout_3->addLayout(horizontalLayout);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer);

        horizontalLayout_3->setStretch(0, 1);
        horizontalLayout_3->setStretch(1, 5);

        verticalLayout->addLayout(horizontalLayout_3);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(0);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_4);

        label_channel = new QLabel(vedioSearch);
        label_channel->setObjectName(QString::fromUtf8("label_channel"));
        QFont font1;
        font1.setPointSize(27);
        label_channel->setFont(font1);
        label_channel->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));

        horizontalLayout_2->addWidget(label_channel);

        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_5);

        comboBox_channel = new QComboBox(vedioSearch);
        comboBox_channel->setObjectName(QString::fromUtf8("comboBox_channel"));
        sizePolicy.setHeightForWidth(comboBox_channel->sizePolicy().hasHeightForWidth());
        comboBox_channel->setSizePolicy(sizePolicy);
        comboBox_channel->setMaximumSize(QSize(200, 16777215));
        QFont font2;
        font2.setPointSize(20);
        comboBox_channel->setFont(font2);
        comboBox_channel->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));

        horizontalLayout_2->addWidget(comboBox_channel);

        horizontalSpacer_6 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_6);

        label_date = new QLabel(vedioSearch);
        label_date->setObjectName(QString::fromUtf8("label_date"));
        label_date->setFont(font1);
        label_date->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));

        horizontalLayout_2->addWidget(label_date);

        horizontalSpacer_7 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_7);

        lineEdit = new QLineEdit(vedioSearch);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(lineEdit->sizePolicy().hasHeightForWidth());
        lineEdit->setSizePolicy(sizePolicy1);
        lineEdit->setFont(font2);
        lineEdit->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));

        horizontalLayout_2->addWidget(lineEdit);

        horizontalSpacer_8 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_8);

        pushButton_dateTime = new QPushButton(vedioSearch);
        pushButton_dateTime->setObjectName(QString::fromUtf8("pushButton_dateTime"));
        sizePolicy.setHeightForWidth(pushButton_dateTime->sizePolicy().hasHeightForWidth());
        pushButton_dateTime->setSizePolicy(sizePolicy);
        pushButton_dateTime->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));

        horizontalLayout_2->addWidget(pushButton_dateTime);

        horizontalSpacer_9 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_9);

        pushButton_search = new QPushButton(vedioSearch);
        pushButton_search->setObjectName(QString::fromUtf8("pushButton_search"));
        sizePolicy.setHeightForWidth(pushButton_search->sizePolicy().hasHeightForWidth());
        pushButton_search->setSizePolicy(sizePolicy);
        pushButton_search->setFont(font1);
        pushButton_search->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));

        horizontalLayout_2->addWidget(pushButton_search);

        horizontalSpacer_10 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_10);

        horizontalLayout_2->setStretch(0, 3);
        horizontalLayout_2->setStretch(1, 2);
        horizontalLayout_2->setStretch(2, 1);
        horizontalLayout_2->setStretch(3, 7);
        horizontalLayout_2->setStretch(4, 3);
        horizontalLayout_2->setStretch(5, 2);
        horizontalLayout_2->setStretch(6, 1);
        horizontalLayout_2->setStretch(7, 8);
        horizontalLayout_2->setStretch(8, 1);
        horizontalLayout_2->setStretch(9, 2);
        horizontalLayout_2->setStretch(10, 2);
        horizontalLayout_2->setStretch(11, 2);
        horizontalLayout_2->setStretch(12, 2);

        verticalLayout->addLayout(horizontalLayout_2);

        verticalLayout->setStretch(0, 1);
        verticalLayout->setStretch(1, 1);
        verticalLayout->setStretch(2, 1);

        verticalLayout_2->addLayout(verticalLayout);

        verticalSpacer_2 = new QSpacerItem(17, 13, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer_2);

        widget = new QWidget(vedioSearch);
        widget->setObjectName(QString::fromUtf8("widget"));

        verticalLayout_2->addWidget(widget);

        verticalSpacer_4 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer_4);

        verticalLayout_2->setStretch(0, 1);
        verticalLayout_2->setStretch(1, 5);
        verticalLayout_2->setStretch(2, 1);
        verticalLayout_2->setStretch(3, 20);
        verticalLayout_2->setStretch(4, 1);

        horizontalLayout_4->addLayout(verticalLayout_2);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_3);

        horizontalLayout_4->setStretch(0, 1);
        horizontalLayout_4->setStretch(1, 50);
        horizontalLayout_4->setStretch(2, 1);

        gridLayout->addLayout(horizontalLayout_4, 0, 0, 1, 1);


        retranslateUi(vedioSearch);

        QMetaObject::connectSlotsByName(vedioSearch);
    } // setupUi

    void retranslateUi(QDialog *vedioSearch)
    {
        vedioSearch->setWindowTitle(QApplication::translate("vedioSearch", "Dialog", 0, QApplication::UnicodeUTF8));
        pushButton_dowload->setText(QApplication::translate("vedioSearch", "\345\275\225\345\203\217\344\270\213\350\275\275", 0, QApplication::UnicodeUTF8));
        pushButton_play->setText(QApplication::translate("vedioSearch", "\345\256\236\346\227\266\345\233\236\346\224\276", 0, QApplication::UnicodeUTF8));
        label_channel->setText(QApplication::translate("vedioSearch", "\351\200\232\351\201\223", 0, QApplication::UnicodeUTF8));
        label_date->setText(QApplication::translate("vedioSearch", "\346\227\245\346\234\237", 0, QApplication::UnicodeUTF8));
        pushButton_dateTime->setText(QString());
        pushButton_search->setText(QApplication::translate("vedioSearch", "\346\237\245\350\257\242", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class vedioSearch: public Ui_vedioSearch {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_VEDIOSEARCH_H
