/********************************************************************************
** Form generated from reading UI file 'mainwidget.ui'
**
** Created by: Qt User Interface Compiler version 4.8.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWIDGET_H
#define UI_MAINWIDGET_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QFrame>
#include <QtGui/QGridLayout>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QPushButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWidget
{
public:
    QGridLayout *gridLayout_5;
    QGridLayout *gridLayout_4;
    QVBoxLayout *verticalLayout_2;
    QFrame *frame_status;
    QGridLayout *gridLayout_3;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QLabel *label_logo;
    QSpacerItem *horizontalSpacer_3;
    QPushButton *pushButton_login;
    QSpacerItem *horizontalSpacer_4;
    QLabel *label_time;
    QSpacerItem *horizontalSpacer_5;
    QLabel *label_operator;
    QSpacerItem *horizontalSpacer_6;
    QLabel *label_signas;
    QSpacerItem *horizontalSpacer_7;
    QLabel *label_power;
    QSpacerItem *horizontalSpacer_2;
    QFrame *line;
    QFrame *frame_menu;
    QGridLayout *gridLayout;
    QVBoxLayout *verticalLayout;
    QSpacerItem *verticalSpacer;
    QPushButton *pushButton_local_vedio;
    QSpacerItem *verticalSpacer_3;
    QPushButton *pushButton_interaction;
    QSpacerItem *verticalSpacer_4;
    QPushButton *pushButton_vedio_meet;
    QSpacerItem *verticalSpacer_5;
    QPushButton *pushButton_map;
    QSpacerItem *verticalSpacer_6;
    QPushButton *pushButton_consult_record;
    QSpacerItem *verticalSpacer_7;
    QPushButton *pushButton_set_para;
    QSpacerItem *verticalSpacer_2;
    QGridLayout *gridLayout_2;
    QFrame *line_3;
    QWidget *widget_central_show;
    QFrame *line_4;
    QFrame *line_2;

    void setupUi(QWidget *MainWidget)
    {
        if (MainWidget->objectName().isEmpty())
            MainWidget->setObjectName(QString::fromUtf8("MainWidget"));
        MainWidget->resize(1280, 720);
        gridLayout_5 = new QGridLayout(MainWidget);
        gridLayout_5->setSpacing(0);
        gridLayout_5->setContentsMargins(11, 11, 11, 11);
        gridLayout_5->setObjectName(QString::fromUtf8("gridLayout_5"));
        gridLayout_5->setContentsMargins(0, 0, 0, 0);
        gridLayout_4 = new QGridLayout();
        gridLayout_4->setSpacing(0);
        gridLayout_4->setObjectName(QString::fromUtf8("gridLayout_4"));
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(0);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        frame_status = new QFrame(MainWidget);
        frame_status->setObjectName(QString::fromUtf8("frame_status"));
        frame_status->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 0, 0);"));
        frame_status->setFrameShape(QFrame::StyledPanel);
        frame_status->setFrameShadow(QFrame::Raised);
        gridLayout_3 = new QGridLayout(frame_status);
        gridLayout_3->setSpacing(0);
        gridLayout_3->setContentsMargins(11, 11, 11, 11);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        gridLayout_3->setContentsMargins(0, 0, 0, 0);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(0);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        label_logo = new QLabel(frame_status);
        label_logo->setObjectName(QString::fromUtf8("label_logo"));
        QFont font;
        font.setPointSize(16);
        label_logo->setFont(font);
        label_logo->setStyleSheet(QString::fromUtf8("image: url(:/statusLog/resource/icon/logo.png);"));

        horizontalLayout->addWidget(label_logo);

        horizontalSpacer_3 = new QSpacerItem(13, 57, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_3);

        pushButton_login = new QPushButton(frame_status);
        pushButton_login->setObjectName(QString::fromUtf8("pushButton_login"));
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(pushButton_login->sizePolicy().hasHeightForWidth());
        pushButton_login->setSizePolicy(sizePolicy);
        pushButton_login->setMinimumSize(QSize(100, 60));
        pushButton_login->setMaximumSize(QSize(300, 60));
        QFont font1;
        font1.setPointSize(21);
        pushButton_login->setFont(font1);
        pushButton_login->setStyleSheet(QString::fromUtf8("color: rgb(23, 238, 73);"));
        pushButton_login->setIconSize(QSize(16, 16));

        horizontalLayout->addWidget(pushButton_login);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_4);

        label_time = new QLabel(frame_status);
        label_time->setObjectName(QString::fromUtf8("label_time"));
        QFont font2;
        font2.setPointSize(20);
        label_time->setFont(font2);
        label_time->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));

        horizontalLayout->addWidget(label_time);

        horizontalSpacer_5 = new QSpacerItem(13, 57, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_5);

        label_operator = new QLabel(frame_status);
        label_operator->setObjectName(QString::fromUtf8("label_operator"));
        QFont font3;
        font3.setPointSize(18);
        label_operator->setFont(font3);
        label_operator->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));

        horizontalLayout->addWidget(label_operator);

        horizontalSpacer_6 = new QSpacerItem(13, 57, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_6);

        label_signas = new QLabel(frame_status);
        label_signas->setObjectName(QString::fromUtf8("label_signas"));
        label_signas->setStyleSheet(QString::fromUtf8("image: url(:/statusLog/resource/icon/\344\277\241\345\217\267.png);"));

        horizontalLayout->addWidget(label_signas);

        horizontalSpacer_7 = new QSpacerItem(13, 57, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_7);

        label_power = new QLabel(frame_status);
        label_power->setObjectName(QString::fromUtf8("label_power"));
        label_power->setStyleSheet(QString::fromUtf8("image: url(:/statusLog/resource/icon/\347\224\265\351\207\217.png);"));

        horizontalLayout->addWidget(label_power);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);

        horizontalLayout->setStretch(0, 7);
        horizontalLayout->setStretch(1, 10);
        horizontalLayout->setStretch(2, 5);
        horizontalLayout->setStretch(3, 10);
        horizontalLayout->setStretch(4, 120);
        horizontalLayout->setStretch(5, 25);
        horizontalLayout->setStretch(6, 7);
        horizontalLayout->setStretch(7, 10);
        horizontalLayout->setStretch(8, 5);
        horizontalLayout->setStretch(9, 10);
        horizontalLayout->setStretch(10, 5);
        horizontalLayout->setStretch(11, 10);
        horizontalLayout->setStretch(12, 5);

        gridLayout_3->addLayout(horizontalLayout, 0, 0, 1, 1);


        verticalLayout_2->addWidget(frame_status);

        line = new QFrame(MainWidget);
        line->setObjectName(QString::fromUtf8("line"));
        line->setMinimumSize(QSize(0, 2));
        line->setMaximumSize(QSize(16777215, 2));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);

        verticalLayout_2->addWidget(line);


        gridLayout_4->addLayout(verticalLayout_2, 0, 0, 1, 2);

        frame_menu = new QFrame(MainWidget);
        frame_menu->setObjectName(QString::fromUtf8("frame_menu"));
        frame_menu->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 0, 0);"));
        frame_menu->setFrameShape(QFrame::StyledPanel);
        frame_menu->setFrameShadow(QFrame::Raised);
        frame_menu->setLineWidth(0);
        gridLayout = new QGridLayout(frame_menu);
        gridLayout->setSpacing(0);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalSpacer = new QSpacerItem(145, 13, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        pushButton_local_vedio = new QPushButton(frame_menu);
        pushButton_local_vedio->setObjectName(QString::fromUtf8("pushButton_local_vedio"));
        sizePolicy.setHeightForWidth(pushButton_local_vedio->sizePolicy().hasHeightForWidth());
        pushButton_local_vedio->setSizePolicy(sizePolicy);
        pushButton_local_vedio->setMinimumSize(QSize(0, 0));
        pushButton_local_vedio->setMaximumSize(QSize(16777215, 16777215));
        QFont font4;
        font4.setPointSize(26);
        pushButton_local_vedio->setFont(font4);
        pushButton_local_vedio->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"background-color: rgb(0, 0, 255);"));

        verticalLayout->addWidget(pushButton_local_vedio);

        verticalSpacer_3 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_3);

        pushButton_interaction = new QPushButton(frame_menu);
        pushButton_interaction->setObjectName(QString::fromUtf8("pushButton_interaction"));
        sizePolicy.setHeightForWidth(pushButton_interaction->sizePolicy().hasHeightForWidth());
        pushButton_interaction->setSizePolicy(sizePolicy);
        pushButton_interaction->setMinimumSize(QSize(0, 0));
        pushButton_interaction->setFont(font4);
        pushButton_interaction->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));

        verticalLayout->addWidget(pushButton_interaction);

        verticalSpacer_4 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_4);

        pushButton_vedio_meet = new QPushButton(frame_menu);
        pushButton_vedio_meet->setObjectName(QString::fromUtf8("pushButton_vedio_meet"));
        sizePolicy.setHeightForWidth(pushButton_vedio_meet->sizePolicy().hasHeightForWidth());
        pushButton_vedio_meet->setSizePolicy(sizePolicy);
        pushButton_vedio_meet->setMinimumSize(QSize(0, 0));
        pushButton_vedio_meet->setFont(font4);
        pushButton_vedio_meet->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));

        verticalLayout->addWidget(pushButton_vedio_meet);

        verticalSpacer_5 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_5);

        pushButton_map = new QPushButton(frame_menu);
        pushButton_map->setObjectName(QString::fromUtf8("pushButton_map"));
        sizePolicy.setHeightForWidth(pushButton_map->sizePolicy().hasHeightForWidth());
        pushButton_map->setSizePolicy(sizePolicy);
        pushButton_map->setMinimumSize(QSize(0, 0));
        pushButton_map->setFont(font4);
        pushButton_map->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));

        verticalLayout->addWidget(pushButton_map);

        verticalSpacer_6 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_6);

        pushButton_consult_record = new QPushButton(frame_menu);
        pushButton_consult_record->setObjectName(QString::fromUtf8("pushButton_consult_record"));
        sizePolicy.setHeightForWidth(pushButton_consult_record->sizePolicy().hasHeightForWidth());
        pushButton_consult_record->setSizePolicy(sizePolicy);
        pushButton_consult_record->setMinimumSize(QSize(0, 0));
        pushButton_consult_record->setFont(font4);
        pushButton_consult_record->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));

        verticalLayout->addWidget(pushButton_consult_record);

        verticalSpacer_7 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_7);

        pushButton_set_para = new QPushButton(frame_menu);
        pushButton_set_para->setObjectName(QString::fromUtf8("pushButton_set_para"));
        sizePolicy.setHeightForWidth(pushButton_set_para->sizePolicy().hasHeightForWidth());
        pushButton_set_para->setSizePolicy(sizePolicy);
        pushButton_set_para->setMinimumSize(QSize(0, 0));
        pushButton_set_para->setFont(font4);
        pushButton_set_para->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));

        verticalLayout->addWidget(pushButton_set_para);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_2);

        verticalLayout->setStretch(0, 3);
        verticalLayout->setStretch(1, 4);
        verticalLayout->setStretch(2, 2);
        verticalLayout->setStretch(3, 4);
        verticalLayout->setStretch(4, 2);
        verticalLayout->setStretch(5, 4);
        verticalLayout->setStretch(6, 2);
        verticalLayout->setStretch(7, 4);
        verticalLayout->setStretch(8, 2);
        verticalLayout->setStretch(9, 4);
        verticalLayout->setStretch(10, 2);
        verticalLayout->setStretch(11, 4);
        verticalLayout->setStretch(12, 6);

        gridLayout->addLayout(verticalLayout, 0, 0, 1, 1);


        gridLayout_4->addWidget(frame_menu, 1, 0, 1, 1);

        gridLayout_2 = new QGridLayout();
        gridLayout_2->setSpacing(0);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        line_3 = new QFrame(MainWidget);
        line_3->setObjectName(QString::fromUtf8("line_3"));
        line_3->setMinimumSize(QSize(2, 0));
        line_3->setMaximumSize(QSize(2, 16777215));
        line_3->setFrameShape(QFrame::VLine);
        line_3->setFrameShadow(QFrame::Sunken);

        gridLayout_2->addWidget(line_3, 0, 0, 1, 1);

        widget_central_show = new QWidget(MainWidget);
        widget_central_show->setObjectName(QString::fromUtf8("widget_central_show"));

        gridLayout_2->addWidget(widget_central_show, 0, 1, 1, 1);

        line_4 = new QFrame(MainWidget);
        line_4->setObjectName(QString::fromUtf8("line_4"));
        line_4->setMinimumSize(QSize(2, 0));
        line_4->setMaximumSize(QSize(2, 16777215));
        line_4->setFrameShape(QFrame::VLine);
        line_4->setFrameShadow(QFrame::Sunken);

        gridLayout_2->addWidget(line_4, 0, 2, 1, 1);

        line_2 = new QFrame(MainWidget);
        line_2->setObjectName(QString::fromUtf8("line_2"));
        line_2->setMinimumSize(QSize(0, 2));
        line_2->setMaximumSize(QSize(16777215, 2));
        line_2->setFrameShape(QFrame::HLine);
        line_2->setFrameShadow(QFrame::Sunken);

        gridLayout_2->addWidget(line_2, 1, 0, 1, 2);


        gridLayout_4->addLayout(gridLayout_2, 1, 1, 1, 1);

        gridLayout_4->setRowStretch(0, 1);
        gridLayout_4->setRowStretch(1, 12);
        gridLayout_4->setColumnStretch(0, 1);
        gridLayout_4->setColumnStretch(1, 8);

        gridLayout_5->addLayout(gridLayout_4, 0, 0, 1, 1);


        retranslateUi(MainWidget);

        QMetaObject::connectSlotsByName(MainWidget);
    } // setupUi

    void retranslateUi(QWidget *MainWidget)
    {
        MainWidget->setWindowTitle(QApplication::translate("MainWidget", "MainWidget", 0, QApplication::UnicodeUTF8));
        label_logo->setText(QString());
        pushButton_login->setText(QApplication::translate("MainWidget", "admin", 0, QApplication::UnicodeUTF8));
        label_time->setText(QApplication::translate("MainWidget", "1970-01-01 00:00:00", 0, QApplication::UnicodeUTF8));
        label_operator->setText(QApplication::translate("MainWidget", "\344\270\255\345\233\275\347\247\273\345\212\250", 0, QApplication::UnicodeUTF8));
        label_signas->setText(QString());
        label_power->setText(QString());
        pushButton_local_vedio->setText(QApplication::translate("MainWidget", "\346\234\254\345\234\260\347\233\221\346\216\247", 0, QApplication::UnicodeUTF8));
        pushButton_interaction->setText(QApplication::translate("MainWidget", "\344\272\222\345\212\250\350\260\203\345\272\246", 0, QApplication::UnicodeUTF8));
        pushButton_vedio_meet->setText(QApplication::translate("MainWidget", "\350\247\206\351\242\221\344\274\232\350\256\256", 0, QApplication::UnicodeUTF8));
        pushButton_map->setText(QApplication::translate("MainWidget", "\347\224\265\345\255\220\345\234\260\345\233\276", 0, QApplication::UnicodeUTF8));
        pushButton_consult_record->setText(QApplication::translate("MainWidget", "\345\275\225\345\203\217\346\237\245\351\230\205", 0, QApplication::UnicodeUTF8));
        pushButton_set_para->setText(QApplication::translate("MainWidget", "\350\256\276\347\275\256", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class MainWidget: public Ui_MainWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWIDGET_H
