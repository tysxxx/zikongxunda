/********************************************************************************
** Form generated from reading UI file 'interactionmanager.ui'
**
** Created by: Qt User Interface Compiler version 4.8.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_INTERACTIONMANAGER_H
#define UI_INTERACTIONMANAGER_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
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

class Ui_interactionManager
{
public:
    QGridLayout *gridLayout;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QVBoxLayout *verticalLayout;
    QSpacerItem *verticalSpacer;
    QWidget *widget_left;
    QGridLayout *gridLayout_2;
    QVBoxLayout *verticalLayout_3;
    QSpacerItem *verticalSpacer_5;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *pushButton_interaction_speak;
    QPushButton *pushButton_group_speak;
    QSpacerItem *horizontalSpacer_5;
    QSpacerItem *verticalSpacer_6;
    QWidget *widget;
    QSpacerItem *verticalSpacer_7;
    QSpacerItem *verticalSpacer_2;
    QSpacerItem *horizontalSpacer_2;
    QFrame *line;
    QSpacerItem *horizontalSpacer_3;
    QVBoxLayout *verticalLayout_2;
    QSpacerItem *verticalSpacer_3;
    QWidget *widget_right;
    QGridLayout *gridLayout_3;
    QHBoxLayout *horizontalLayout_3;
    QSpacerItem *horizontalSpacer_6;
    QVBoxLayout *verticalLayout_4;
    QSpacerItem *verticalSpacer_8;
    QLabel *label_picture;
    QSpacerItem *verticalSpacer_9;
    QLabel *label_user_name;
    QSpacerItem *verticalSpacer_10;
    QLabel *label_statu;
    QSpacerItem *verticalSpacer_11;
    QPushButton *pushButton_over_speak;
    QSpacerItem *verticalSpacer_12;
    QSpacerItem *horizontalSpacer_7;
    QSpacerItem *verticalSpacer_4;
    QSpacerItem *horizontalSpacer_4;

    void setupUi(QDialog *interactionManager)
    {
        if (interactionManager->objectName().isEmpty())
            interactionManager->setObjectName(QString::fromUtf8("interactionManager"));
        interactionManager->resize(1209, 751);
        interactionManager->setStyleSheet(QString::fromUtf8("background-color: rgb(4, 11, 23);"));
        gridLayout = new QGridLayout(interactionManager);
        gridLayout->setSpacing(0);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(0);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        widget_left = new QWidget(interactionManager);
        widget_left->setObjectName(QString::fromUtf8("widget_left"));
        gridLayout_2 = new QGridLayout(widget_left);
        gridLayout_2->setSpacing(0);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        gridLayout_2->setContentsMargins(0, 0, 0, 0);
        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setSpacing(0);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        verticalSpacer_5 = new QSpacerItem(17, 13, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_3->addItem(verticalSpacer_5);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(0);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        pushButton_interaction_speak = new QPushButton(widget_left);
        pushButton_interaction_speak->setObjectName(QString::fromUtf8("pushButton_interaction_speak"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(pushButton_interaction_speak->sizePolicy().hasHeightForWidth());
        pushButton_interaction_speak->setSizePolicy(sizePolicy);
        QFont font;
        font.setPointSize(32);
        pushButton_interaction_speak->setFont(font);
        pushButton_interaction_speak->setStyleSheet(QString::fromUtf8("background-color: rgb(4, 11, 23);\n"
"color: rgb(255, 255, 255);"));

        horizontalLayout_2->addWidget(pushButton_interaction_speak);

        pushButton_group_speak = new QPushButton(widget_left);
        pushButton_group_speak->setObjectName(QString::fromUtf8("pushButton_group_speak"));
        sizePolicy.setHeightForWidth(pushButton_group_speak->sizePolicy().hasHeightForWidth());
        pushButton_group_speak->setSizePolicy(sizePolicy);
        pushButton_group_speak->setFont(font);
        pushButton_group_speak->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));

        horizontalLayout_2->addWidget(pushButton_group_speak);

        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_5);

        horizontalLayout_2->setStretch(0, 6);
        horizontalLayout_2->setStretch(1, 6);
        horizontalLayout_2->setStretch(2, 4);

        verticalLayout_3->addLayout(horizontalLayout_2);

        verticalSpacer_6 = new QSpacerItem(17, 13, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_3->addItem(verticalSpacer_6);

        widget = new QWidget(widget_left);
        widget->setObjectName(QString::fromUtf8("widget"));

        verticalLayout_3->addWidget(widget);

        verticalSpacer_7 = new QSpacerItem(17, 13, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_3->addItem(verticalSpacer_7);

        verticalLayout_3->setStretch(0, 1);
        verticalLayout_3->setStretch(1, 3);
        verticalLayout_3->setStretch(2, 1);
        verticalLayout_3->setStretch(3, 25);
        verticalLayout_3->setStretch(4, 1);

        gridLayout_2->addLayout(verticalLayout_3, 0, 0, 1, 1);


        verticalLayout->addWidget(widget_left);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_2);

        verticalLayout->setStretch(0, 1);
        verticalLayout->setStretch(1, 15);
        verticalLayout->setStretch(2, 1);

        horizontalLayout->addLayout(verticalLayout);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);

        line = new QFrame(interactionManager);
        line->setObjectName(QString::fromUtf8("line"));
        QSizePolicy sizePolicy1(QSizePolicy::Fixed, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(line->sizePolicy().hasHeightForWidth());
        line->setSizePolicy(sizePolicy1);
        line->setMinimumSize(QSize(2, 0));
        line->setMaximumSize(QSize(2, 16777215));
        line->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"background-color: rgb(255, 255, 255);"));
        line->setFrameShape(QFrame::VLine);
        line->setFrameShadow(QFrame::Sunken);

        horizontalLayout->addWidget(line);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_3);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(0);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalSpacer_3 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer_3);

        widget_right = new QWidget(interactionManager);
        widget_right->setObjectName(QString::fromUtf8("widget_right"));
        widget_right->setStyleSheet(QString::fromUtf8("background-color: rgba(6, 32, 70, 204);"));
        gridLayout_3 = new QGridLayout(widget_right);
        gridLayout_3->setSpacing(0);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        gridLayout_3->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(0);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        horizontalSpacer_6 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_6);

        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setSpacing(0);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        verticalSpacer_8 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_4->addItem(verticalSpacer_8);

        label_picture = new QLabel(widget_right);
        label_picture->setObjectName(QString::fromUtf8("label_picture"));
        label_picture->setStyleSheet(QString::fromUtf8("image: url(:/statusLog/resource/icon/\345\244\264\345\203\217.png);\n"
"background-color: rgba(6, 32, 70, 0);"));
        label_picture->setAlignment(Qt::AlignCenter);

        verticalLayout_4->addWidget(label_picture);

        verticalSpacer_9 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_4->addItem(verticalSpacer_9);

        label_user_name = new QLabel(widget_right);
        label_user_name->setObjectName(QString::fromUtf8("label_user_name"));
        QFont font1;
        font1.setPointSize(25);
        label_user_name->setFont(font1);
        label_user_name->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"background-color: rgba(6, 32, 70, 0);"));
        label_user_name->setAlignment(Qt::AlignCenter);

        verticalLayout_4->addWidget(label_user_name);

        verticalSpacer_10 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_4->addItem(verticalSpacer_10);

        label_statu = new QLabel(widget_right);
        label_statu->setObjectName(QString::fromUtf8("label_statu"));
        QFont font2;
        font2.setPointSize(19);
        label_statu->setFont(font2);
        label_statu->setStyleSheet(QString::fromUtf8("color: rgb(13, 238, 68);\n"
"background-color: rgba(6, 32, 70, 0);"));
        label_statu->setAlignment(Qt::AlignCenter);

        verticalLayout_4->addWidget(label_statu);

        verticalSpacer_11 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_4->addItem(verticalSpacer_11);

        pushButton_over_speak = new QPushButton(widget_right);
        pushButton_over_speak->setObjectName(QString::fromUtf8("pushButton_over_speak"));
        sizePolicy.setHeightForWidth(pushButton_over_speak->sizePolicy().hasHeightForWidth());
        pushButton_over_speak->setSizePolicy(sizePolicy);
        QFont font3;
        font3.setPointSize(39);
        pushButton_over_speak->setFont(font3);
        pushButton_over_speak->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"background-color: rgb(0, 0, 255);"));

        verticalLayout_4->addWidget(pushButton_over_speak);

        verticalSpacer_12 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_4->addItem(verticalSpacer_12);

        verticalLayout_4->setStretch(0, 4);
        verticalLayout_4->setStretch(1, 5);
        verticalLayout_4->setStretch(2, 1);
        verticalLayout_4->setStretch(3, 3);
        verticalLayout_4->setStretch(4, 5);
        verticalLayout_4->setStretch(5, 5);
        verticalLayout_4->setStretch(6, 5);
        verticalLayout_4->setStretch(7, 3);
        verticalLayout_4->setStretch(8, 5);

        horizontalLayout_3->addLayout(verticalLayout_4);

        horizontalSpacer_7 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_7);

        horizontalLayout_3->setStretch(0, 1);
        horizontalLayout_3->setStretch(1, 1);
        horizontalLayout_3->setStretch(2, 1);

        gridLayout_3->addLayout(horizontalLayout_3, 0, 0, 1, 1);


        verticalLayout_2->addWidget(widget_right);

        verticalSpacer_4 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer_4);

        verticalLayout_2->setStretch(0, 1);
        verticalLayout_2->setStretch(1, 12);
        verticalLayout_2->setStretch(2, 1);

        horizontalLayout->addLayout(verticalLayout_2);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_4);

        horizontalLayout->setStretch(0, 1);
        horizontalLayout->setStretch(1, 7);
        horizontalLayout->setStretch(2, 1);
        horizontalLayout->setStretch(3, 1);
        horizontalLayout->setStretch(4, 1);
        horizontalLayout->setStretch(5, 7);
        horizontalLayout->setStretch(6, 1);

        gridLayout->addLayout(horizontalLayout, 0, 0, 1, 1);


        retranslateUi(interactionManager);

        QMetaObject::connectSlotsByName(interactionManager);
    } // setupUi

    void retranslateUi(QDialog *interactionManager)
    {
        interactionManager->setWindowTitle(QApplication::translate("interactionManager", "Dialog", 0, QApplication::UnicodeUTF8));
        pushButton_interaction_speak->setText(QApplication::translate("interactionManager", "\344\272\222\345\212\250\345\257\271\350\256\262", 0, QApplication::UnicodeUTF8));
        pushButton_group_speak->setText(QApplication::translate("interactionManager", "\347\276\244\344\270\273\345\257\271\350\256\262", 0, QApplication::UnicodeUTF8));
        label_picture->setText(QString());
        label_user_name->setText(QApplication::translate("interactionManager", "admin", 0, QApplication::UnicodeUTF8));
        label_statu->setText(QApplication::translate("interactionManager", "\351\200\232\350\257\235\344\270\255...", 0, QApplication::UnicodeUTF8));
        pushButton_over_speak->setText(QApplication::translate("interactionManager", "\351\200\200\345\207\272", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class interactionManager: public Ui_interactionManager {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_INTERACTIONMANAGER_H
