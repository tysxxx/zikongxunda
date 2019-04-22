#ifndef NINESCREEN_H
#define NINESCREEN_H

#include "./UI/ui_ninescreen.h"

class nineScreen : public QWidget, private Ui::nineScreen
{
    Q_OBJECT

public:
    explicit nineScreen(QWidget *parent = 0);
};

#endif // NINESCREEN_H
