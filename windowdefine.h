#ifndef WINDOWDEFINE_H
#define WINDOWDEFINE_H
#include <stdio.h>
#include <unistd.h>
#include <QWidget>
#include <QPushButton>
#include <QLabel>
#include <QHBoxLayout>
#include "../hisi3531aLib/zkdevdefine.h"
#include "../hisi3531aLib/zkCarDevEnginge.h"
typedef enum function_menu_e
{
    ONESCREENSHOW = 0,
    TWOSCREENSHOW,
    FOURSCREENSHOW,
    NINESCREENSHOW,
    SIXTEENSCREENSHOW,
    INTERACTIONFUN,
    VEDIOMEETFUN,
    MAPFUN,
    CONSULTRECORDFUN,
    SETPARAFUN,
}FUNCTION_MENU_E;

typedef struct btn_menu_laout_para_st
{
    int buttonCnt;//共有多少个按键
    int topSize;//第一个按键与顶部间的布局距离比例
    int bottomSize;//最后一个按键与顶部间的布局距离比例
    int spaceSize;//每个按键之间的布局距离比例
    int buttonSize;//按键自身的布局比例
    int leftOffset;//按键文本左移的距离
    QPushButton* p_button_list;//按键对象的指针列表
    QWidget* p_qwidget;//按键所在的父窗口
}BTN_MENU_LAOUT_PARA_ST;

typedef struct screen_menu_unit_st
{
    QPushButton* p_button;//按键对象指针
    QLabel * p_lable;//放置图标的label对象指针
    QHBoxLayout *horizontalLayout;//按键和图标一一对应，用水平布局
}SCREEN_MENU_UNIT_ST;

typedef struct window_property_st
{
    RECT_ST rect;//窗口位置尺寸
    long long winfd;//窗口句柄
    bool statu;//窗口使用状态，true:窗口已被占用，false:窗口空闲状态
    INPUT_DEV_TYPE_E user_devType;//窗口使用者类型
    int user_devId;//窗口使用者的id
}WINDOW_PROPERTY_ST;



#endif // WINDOWDEFINE_H
