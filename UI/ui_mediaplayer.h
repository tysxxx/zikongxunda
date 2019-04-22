/********************************************************************************
** Form generated from reading UI file 'mediaplayer.ui'
**
** Created by: Qt User Interface Compiler version 4.8.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MEDIAPLAYER_H
#define UI_MEDIAPLAYER_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QGridLayout>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QPushButton>
#include <QtGui/QSlider>
#include <QtGui/QSpacerItem>
#include <QtGui/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_mediaPlayer
{
public:
    QGridLayout *gridLayout;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer_3;
    QVBoxLayout *verticalLayout;
    QSpacerItem *verticalSpacer_3;
    QLabel *label_show;
    QSpacerItem *verticalSpacer_2;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QSlider *horizontalSlider;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *pushButton_show;
    QHBoxLayout *horizontalLayout_3;
    QSpacerItem *horizontalSpacer_5;
    QPushButton *pushButton_play;
    QSpacerItem *horizontalSpacer_6;
    QPushButton *pushButton_back;
    QSpacerItem *horizontalSpacer_7;
    QPushButton *pushButton_start_stop;
    QSpacerItem *horizontalSpacer_8;
    QPushButton *pushButton_ahead;
    QSpacerItem *horizontalSpacer_9;
    QSpacerItem *verticalSpacer;
    QSpacerItem *horizontalSpacer_4;

    void setupUi(QDialog *mediaPlayer)
    {
        if (mediaPlayer->objectName().isEmpty())
            mediaPlayer->setObjectName(QString::fromUtf8("mediaPlayer"));
        mediaPlayer->resize(1055, 612);
        mediaPlayer->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 0, 0);"));
        gridLayout = new QGridLayout(mediaPlayer);
        gridLayout->setSpacing(0);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(0);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_3);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalSpacer_3 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_3);

        label_show = new QLabel(mediaPlayer);
        label_show->setObjectName(QString::fromUtf8("label_show"));

        verticalLayout->addWidget(label_show);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_2);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(0);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        horizontalSlider = new QSlider(mediaPlayer);
        horizontalSlider->setObjectName(QString::fromUtf8("horizontalSlider"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(horizontalSlider->sizePolicy().hasHeightForWidth());
        horizontalSlider->setSizePolicy(sizePolicy);
        horizontalSlider->setMinimumSize(QSize(0, 6));
        horizontalSlider->setMaximumSize(QSize(16777215, 6));
        horizontalSlider->setOrientation(Qt::Horizontal);

        horizontalLayout->addWidget(horizontalSlider);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);

        pushButton_show = new QPushButton(mediaPlayer);
        pushButton_show->setObjectName(QString::fromUtf8("pushButton_show"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(pushButton_show->sizePolicy().hasHeightForWidth());
        pushButton_show->setSizePolicy(sizePolicy1);
        pushButton_show->setMinimumSize(QSize(49, 49));
        pushButton_show->setMaximumSize(QSize(49, 49));
        pushButton_show->setStyleSheet(QString::fromUtf8(""));

        horizontalLayout->addWidget(pushButton_show);

        horizontalLayout->setStretch(0, 1);
        horizontalLayout->setStretch(1, 50);
        horizontalLayout->setStretch(2, 1);
        horizontalLayout->setStretch(3, 2);

        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(0);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_5);

        pushButton_play = new QPushButton(mediaPlayer);
        pushButton_play->setObjectName(QString::fromUtf8("pushButton_play"));
        sizePolicy1.setHeightForWidth(pushButton_play->sizePolicy().hasHeightForWidth());
        pushButton_play->setSizePolicy(sizePolicy1);
        pushButton_play->setMinimumSize(QSize(55, 49));
        pushButton_play->setMaximumSize(QSize(55, 49));
        pushButton_play->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
"color: rgb(0, 0, 0);"));

        horizontalLayout_3->addWidget(pushButton_play);

        horizontalSpacer_6 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_6);

        pushButton_back = new QPushButton(mediaPlayer);
        pushButton_back->setObjectName(QString::fromUtf8("pushButton_back"));
        QSizePolicy sizePolicy2(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(pushButton_back->sizePolicy().hasHeightForWidth());
        pushButton_back->setSizePolicy(sizePolicy2);
        pushButton_back->setMinimumSize(QSize(55, 49));
        pushButton_back->setMaximumSize(QSize(55, 49));
        pushButton_back->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
"color: rgb(0, 0, 0);"));

        horizontalLayout_3->addWidget(pushButton_back);

        horizontalSpacer_7 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_7);

        pushButton_start_stop = new QPushButton(mediaPlayer);
        pushButton_start_stop->setObjectName(QString::fromUtf8("pushButton_start_stop"));
        pushButton_start_stop->setMinimumSize(QSize(55, 49));
        pushButton_start_stop->setMaximumSize(QSize(55, 49));
        pushButton_start_stop->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
"color: rgb(0, 0, 0);"));

        horizontalLayout_3->addWidget(pushButton_start_stop);

        horizontalSpacer_8 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_8);

        pushButton_ahead = new QPushButton(mediaPlayer);
        pushButton_ahead->setObjectName(QString::fromUtf8("pushButton_ahead"));
        sizePolicy2.setHeightForWidth(pushButton_ahead->sizePolicy().hasHeightForWidth());
        pushButton_ahead->setSizePolicy(sizePolicy2);
        pushButton_ahead->setMinimumSize(QSize(55, 49));
        pushButton_ahead->setMaximumSize(QSize(55, 49));
        pushButton_ahead->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);\n"
"background-color: rgb(255, 255, 255);"));

        horizontalLayout_3->addWidget(pushButton_ahead);

        horizontalSpacer_9 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_9);

        horizontalLayout_3->setStretch(0, 1);
        horizontalLayout_3->setStretch(1, 18);
        horizontalLayout_3->setStretch(2, 30);
        horizontalLayout_3->setStretch(3, 18);
        horizontalLayout_3->setStretch(4, 3);
        horizontalLayout_3->setStretch(5, 18);
        horizontalLayout_3->setStretch(6, 3);
        horizontalLayout_3->setStretch(7, 18);
        horizontalLayout_3->setStretch(8, 40);

        verticalLayout->addLayout(horizontalLayout_3);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        verticalLayout->setStretch(0, 1);
        verticalLayout->setStretch(1, 30);
        verticalLayout->setStretch(2, 1);
        verticalLayout->setStretch(3, 2);
        verticalLayout->setStretch(4, 2);
        verticalLayout->setStretch(5, 1);

        horizontalLayout_2->addLayout(verticalLayout);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_4);

        horizontalLayout_2->setStretch(0, 2);
        horizontalLayout_2->setStretch(1, 7);
        horizontalLayout_2->setStretch(2, 2);

        gridLayout->addLayout(horizontalLayout_2, 0, 0, 1, 1);


        retranslateUi(mediaPlayer);

        QMetaObject::connectSlotsByName(mediaPlayer);
    } // setupUi

    void retranslateUi(QDialog *mediaPlayer)
    {
        mediaPlayer->setWindowTitle(QApplication::translate("mediaPlayer", "Dialog", 0, QApplication::UnicodeUTF8));
        label_show->setText(QString());
        pushButton_show->setText(QString());
        pushButton_play->setText(QApplication::translate("mediaPlayer", "\345\201\234\346\255\242", 0, QApplication::UnicodeUTF8));
        pushButton_back->setText(QApplication::translate("mediaPlayer", "\345\220\216\351\200\200", 0, QApplication::UnicodeUTF8));
        pushButton_start_stop->setText(QApplication::translate("mediaPlayer", "\346\222\255\346\224\276", 0, QApplication::UnicodeUTF8));
        pushButton_ahead->setText(QApplication::translate("mediaPlayer", "\345\211\215\350\277\233", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class mediaPlayer: public Ui_mediaPlayer {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MEDIAPLAYER_H
