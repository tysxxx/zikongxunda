#include "localmonitorui.h"
#include <QWidget>
#include <QStyleOption>
#include <QPainter>

LocalMonitorUi::LocalMonitorUi(QRect rect, QWidget *parent) : QWidget(parent)
{
    resize(rect.width(), rect.height());
    init();
}


void LocalMonitorUi::init()
{
    setWindowFlags((Qt::FramelessWindowHint));
    setStyleSheet("QWidget{background-color: transparent;}");

    gridLayout = new QGridLayout;
    gridLayout->setMargin(0);
    gridLayout->setSpacing(0);
    for(int row = 0; row < 4; ++row){
        for(int column = 0; column < 4; ++column){
            QWidget *widget = new QWidget;
            widget->setStyleSheet(".QWidget{border: 0.5px solid rgba(255, 255, 255, 30%);}\
                                   .QWidget:hover{border: 1px solid rgba(255, 0, 0, 80%);}");
            gridLayout->addWidget(widget, row, column);
        }
    }

    setLayout(gridLayout);
}

//重载paintEvent事件
void LocalMonitorUi::paintEvent(QPaintEvent *)
{
    QStyleOption opt;
    opt.init(this);
    QPainter painter(this);
    style()->drawPrimitive(QStyle::PE_Widget, &opt, &painter, this);
}
