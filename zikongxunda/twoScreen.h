#ifndef TWOSCREEN_H
#define TWOSCREEN_H

#include "./UI/ui_twoscreen.h"

class twoScreen : public QWidget, private Ui::twoScreen
{
    Q_OBJECT

public:
    explicit twoScreen(QWidget *parent = 0);
};

#endif // TWOSCREEN_H
