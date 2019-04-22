#ifndef FOURSCREEN_H
#define FOURSCREEN_H

#include "./UI/ui_fourscreen.h"
#include "window_common.h"
class fourScreen : public QWidget, private Ui::fourScreen
{
    Q_OBJECT

public:
    explicit fourScreen(QWidget *parent = 0);
    ~fourScreen();
private:
    Ui::fourScreen *ui;
};

#endif // FOURSCREEN_H
