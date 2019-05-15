#include "localmonitorui.h"
#include <QWidget>
#include <QStyleOption>
#include <QPainter>
#include <QDebug>

LocalMonitorUi::LocalMonitorUi(QRect rect, QWidget *parent) : QWidget(parent)
{
    resize(rect.width(), rect.height());
    init();
}


void LocalMonitorUi::init()
{
    //界面初始化
    setWindowFlags((Qt::FramelessWindowHint));
    setStyleSheet("QWidget{background-color: transparent;}");

    //
    for(int i = 0 ; i < 16; i++){
        QWidget *widget = new QWidget;
        widget->setAttribute(Qt::WA_NativeWindow);
        widget->setStyleSheet(".QWidget{border: 0.5px solid rgba(255, 255, 255, 30%);}\
                               .QWidget:hover{border: 1px solid rgba(255, 0, 0, 80%);}");


        LayoutWindowInfoType *layoutWinInfo = new LayoutWindowInfoType;
        layoutWinInfo->widget = widget;
        layoutWinInfo->windId = widget->winId();
        layoutWinInfo->rect = widget->rect();
        layoutWinInfo->devType = LOCAL_VEDIO;
        layoutWinInfo->devId = -1;
        layoutWindowInfoVector.append(layoutWinInfo);
        widgetVector.append(widget);
    }

    row = 2; column = 2;
    gridLayout = new QGridLayout;
    gridLayout->setMargin(0);
    gridLayout->setSpacing(0);
    for(int i = 0; i < row; ++i){
        for(int j = 0; j < column; ++j){
            gridLayout->addWidget(widgetVector.at(i*column+j), i, j);
        }
    }
    gridLayout->installEventFilter(this);
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


void LocalMonitorUi::layoutSwitchHandler(LayoutMode layoutMode)
{
    int count = gridLayout->count();
    //移除所有部件
    for(int i = 0; i < count; i++){
        QWidget *pwidget = gridLayout->itemAt(0)->widget();
        gridLayout->removeItem(gridLayout->takeAt(0));
        pwidget->setParent(nullptr);
    }

    switch (layoutMode) {
    case LayoutMode::one:
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
    if(layoutMode == LayoutMode::one)
        gridLayout->addWidget(widgetVector.at(0), 0, 0);
    else{
        for(int i = 0; i < row; ++i){
            for(int j = 0; j < column; ++j){
                gridLayout->addWidget(widgetVector.at(i*column+j), i, j);
            }
        }
    }

    setVisible(true); //使能及时的刷新计算空间的大小
    QPoint point = QPoint(layoutWindowInfoVector.at(15)->widget->rect().x(),
                          layoutWindowInfoVector.at(15)->widget->rect().y());
    qDebug() << "layoutwind rect:" << layoutWindowInfoVector.at(15)->widget->mapToGlobal(point)
                                   << layoutWindowInfoVector.at(15)->widget->rect();
}

//设置视频在窗口的显示
void LocalMonitorUi::localVideoWinShow()
{
     //执行分屏程序前，清一次分屏
     zkCarDevEngine::instance()->zkCleanStandardWindow();

    //设置视频显示相对应的区域
    for(int i = 0; i < 16; i++){
        qint64 windId = layoutWindowInfoVector.at(i)->widget->winId();
        QPoint point = layoutWindowInfoVector.at(15)->widget->mapToGlobal(
                        QPoint(layoutWindowInfoVector.at(i)->widget->rect().x(),
                               layoutWindowInfoVector.at(i)->widget->rect().y()));
        RECT_ST rect;
        rect.s32X = point.x();
        rect.s32Y = point.y();
        rect.u32Width = layoutWindowInfoVector.at(i)->widget->width();
        rect.u32Height = layoutWindowInfoVector.at(i)->widget->height();

        if(rect.s32X%2 !=0 ) rect.s32Y++;
        if(rect.s32Y%2 !=0 ) rect.s32Y++;
        zkCarDevEngine::instance()->zkSetOneWindow(windId, &rect);
    }


    //本地视频设备，显示在对应的窗口号里面
    for(int i=0; i < row * column; i++){
//        if(localVideoDeviceList.size() > i){
//        splitWinArray[i]->device.devType = LOCAL_VEDIO;
//        splitWinArray[i]->device.id = localVideoDeviceList.at(i).id;
//        splitWinArray[i]->device.name = localVideoDeviceList.at(i).name;

//        //设置视频显示
//        zkCarDevEngine::instance()->zkShowVedio(LOCAL_VEDIO, splitWinArray[i]->device.id, splitWinArray[i]->id);
//        }
    }
}

//
bool LocalMonitorUi::eventFilter(QObject *obj, QEvent *event)
{
    QWidget *widget = qobject_cast<QWidget*>(obj);
    for(int i = 0; i < 16; i++)
    {
        //if(widget == layoutWindowInfoVector.at(i)->widget){
             if(event->type() == QEvent::Resize)
                qDebug() << "widet child:" << i << " changed" << widget->rect();
        //}
    }
}
