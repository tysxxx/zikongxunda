#ifndef SIXTEENSCREEN_H
#define SIXTEENSCREEN_H

#include "./UI/ui_sixteenscreen.h"

class sixteenScreen : public QWidget, private Ui::sixteenScreen
{
    Q_OBJECT

public:
    explicit sixteenScreen(QWidget *parent = 0);
};

#endif // SIXTEENSCREEN_H
