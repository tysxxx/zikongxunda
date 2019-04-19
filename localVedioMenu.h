#ifndef LOCALVEDIOMENU_H
#define LOCALVEDIOMENU_H
#include "window_common.h"
#include "pushButtonMenu.h"
#include "screenModeMenu.h"

class localVedioMenu : public QWidget
{
    //注意：要添加槽函数必须自己添加Q_OBJECT，然后要重新qmake一下，不然编译会报错
    Q_OBJECT
public:
    localVedioMenu();
    ~localVedioMenu();
    void init();
    static localVedioMenu* instance();
    static localVedioMenu* m_instance;
    bool change_localVedioMenu_show_statu();
    bool set_widget_rect(QRect* rect);
    void set_lists();
private:
    bool add_one_pushbutton(const char* name);
    bool set_button_backGround(int item);
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
    QPushButton* m_button_list[10] = {NULL};//按键对象指针列表
    int m_button_cnt;//添加的按键个数
};

#endif // LOCALVEDIOMENU_H
