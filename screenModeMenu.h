#ifndef SCREENMODEMENU_H
#define SCREENMODEMENU_H

#include "window_common.h"
#include "mainwidget.h"

class screenModeMenu : public QWidget
{
    Q_OBJECT
public:
    screenModeMenu();
    ~screenModeMenu();
    void init();
    static screenModeMenu* instance();
    static screenModeMenu* m_instance;
    bool show_screenModeMenu();
    bool hide_screenModeMenu();
    bool change_screenModeMenu_show_statu();
    bool set_widget_rect(QRect* rect);
    void set_lists();
private:
    bool add_one_unit(const char* iconPath,const char* name);

private slots:
    void pushButton0_click_slot();
    void pushButton1_click_slot();
    void pushButton2_click_slot();
    void pushButton3_click_slot();
    void pushButton4_click_slot();

private:
    QWidget *m_widget;
    QGridLayout* m_gridLayout;
    QVBoxLayout *verticalLayout;
    QSpacerItem* m_verticalSpacer0;
    QSpacerItem* m_verticalSpacer1;
    QSpacerItem* m_verticalSpacer2;
    QSpacerItem* m_verticalSpacer3;
    QSpacerItem* m_verticalSpacer4;
    QSpacerItem* m_verticalSpacer5;
    QRect m_rect;//位置及大小
    int m_curr_item;//当前处于被选中状态的item
    bool m_showStatu;//当前的显示状态，true:显示，false:隐藏
    QFont m_font;
    int m_font_size;//字体大小
    SCREEN_MENU_UNIT_ST m_unit_list[10];
    int m_unit_cnt;//添加的按键个数
};

#endif // SCREENMODEMENU_H
