#ifndef ONESCREEN_H
#define ONESCREEN_H

#include "./UI/ui_onescreen.h"
#include "window_common.h"

class oneScreen : public QWidget, private Ui::oneScreen
{
    Q_OBJECT

public:
    explicit oneScreen(QWidget *parent = 0);
    ~oneScreen();
private:
    Ui::oneScreen *ui;
};

#endif // ONESCREEN_H
