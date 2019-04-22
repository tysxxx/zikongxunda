#ifndef INTERACTIONMANAGER_H
#define INTERACTIONMANAGER_H

#include "./UI/ui_interactionmanager.h"
#include "window_common.h"


class interactionUserUnit:public QWidget
{
    Q_OBJECT

public:
    interactionUserUnit(const char* name);
private:
    QGridLayout* m_gridLayout;
    QLabel m_label;
    QPushButton m_audioButton;
    QPushButton m_vedioButton;
    QSpacerItem* m_spacerItem0;
    QSpacerItem* m_spacerItem1;
    QSpacerItem* m_spacerItem2;
    QSpacerItem* m_spacerItem3;
    QHBoxLayout m_hboxLayout;
    //QVBoxLayout verticalLayout;

    QFont m_font;
    int m_font_size;//字体大小
};

class interactionManager : public QDialog, private Ui::interactionManager
{
    Q_OBJECT

public:
    explicit interactionManager(QWidget *parent = 0);
private:
    bool add_one_interaction_user(const char* userName);
    void delete_one_interaction_user();
    void clearInteractionListWidget();
private:
    Ui::interactionManager *ui;
    QGridLayout* m_gridLayout;
    QStackedWidget* m_stackedWidget_left_userList;
    QListWidget *m_interaction_list;//互动对讲用户列表
    QListWidget *m_group_list;//群主对讲用户列表
};

#endif // INTERACTIONMANAGER_H
