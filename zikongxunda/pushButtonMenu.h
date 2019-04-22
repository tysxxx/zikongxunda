#ifndef PUSHBUTTONMENU_H
#define PUSHBUTTONMENU_H

#include "window_common.h"

class pushButtonMenu : public QWidget
{
public:
    pushButtonMenu();
    bool set_layout(BTN_MENU_LAOUT_PARA_ST* para_st);
    QPushButton*  add_one_pushbutton(const char* name,QWidget *p_widget,QFont* font);
private:
    QGridLayout* m_gridLayout;
    QVBoxLayout *m_verticalLayout;
};

#endif // PUSHBUTTONMENU_H
