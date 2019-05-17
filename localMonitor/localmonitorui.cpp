#include "localmonitorui.h"
#include <QWidget>
#include <QStyleOption>
#include <QPainter>
#include <QDebug>

LocalMonitorUi::LocalMonitorUi(QRect rect, QWidget *parent) : QWidget(parent)
{
    resize(rect.width(), rect.height());
}


void LocalMonitorUi::init()
{
    //界面初始化
    setWindowFlags((Qt::FramelessWindowHint));
    setAttribute(Qt::WA_TranslucentBackground);

    //获取对象
    manager = Manager::instance();

    //
    for(int i = 0 ; i < 16; i++){
        QWidget *widget = new QWidget;
        widget->setAttribute(Qt::WA_NativeWindow);
        widget->setStyleSheet(".QWidget{border: 0.5px solid rgba(255, 255, 255, 30%);}\
                               .QWidget:hover{border: 1px solid rgba(255, 0, 0, 80%);}");

        LayoutWindowInfoType layoutWinInfo;
        layoutWinInfo.widget = widget;
        layoutWinInfo.devType = LOCAL_VEDIO;
        layoutWinInfo.devId = -1;
        layoutWindowInfoVector.append(layoutWinInfo);
    }

    //初始化分屏
    currLayoutMode = LayoutMode::one;
    row = 2; column = 2;
    gridLayout = new QGridLayout;
    gridLayout->setMargin(0);
    gridLayout->setSpacing(0);
//    for(int i = 0; i < row; ++i){
//        for(int j = 0; j < column; ++j){
//            gridLayout->addWidget(layoutWindowInfoVector.at(i*column+j).widget, i, j);
//        }
//    }

    setLayout(gridLayout);
}

//分屏
void LocalMonitorUi::layoutSwitchHandler(LayoutMode layoutMode)
{
    if(currLayoutMode == layoutMode)
        return;

    currLayoutMode = layoutMode;
    int count = gridLayout->count();
    //移除所有部件
    for(int i = 0; i < count; i++){
        QWidget *pwidget = gridLayout->itemAt(0)->widget();
        gridLayout->removeItem(gridLayout->takeAt(0));
        pwidget->setParent(nullptr);
    }

    switch (layoutMode) {
    case LayoutMode::one:
        row=1; column=1;
           break;
    case LayoutMode::two:
       row = 1; column = 2;
        break;
    case LayoutMode::four:
       row = 2; column = 2;
        break;
    case LayoutMode::nine:
        row = 3; column = 3;
        break;
    case LayoutMode::sixteen:
        row = 4; column = 4;
        break;
    default:
        break;
    }

    setVisible(false);
    for(int i = 0; i < row; ++i){
        for(int j = 0; j < column; ++j){
            gridLayout->addWidget(layoutWindowInfoVector.at(i*column+j).widget, i, j);
        }
    }
    setVisible(true); //使能及时的刷新计算空间的大小

   //视频显示
   manager->localVideoWinShow(row, column, layoutWindowInfoVector);
}

//
bool LocalMonitorUi::eventFilter(QObject *obj, QEvent *event)
{
    QWidget *widget = qobject_cast<QWidget*>(obj);
    for(int i = 0; i < 16; i++)
    {
         if(event->type() == QEvent::Resize)
            qDebug() << "widet child:" << i << " changed" << widget->rect();
    }
}
