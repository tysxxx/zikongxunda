#include "manager.h"
#include <QDebug>

QSharedPointer<Manager> Manager::m_instance(new Manager, Manager::destroyInstance);

Manager::Manager(QObject *parent) : QObject(parent)
{
    qDebug() << "Manager Construct";

    connect(&networkManager, SIGNAL(getAllListInfoSuccessed()), this, SLOT(allListInfoHandler()));
}

Manager::~Manager()
{

}

//返回实例
QSharedPointer<Manager> Manager::instance()
{
    return m_instance;
}

//销毁实例
void Manager::destroyInstance(Manager *instance)
{
    if(instance)
        delete instance;
    instance = nullptr;
}

//初始化
void Manager::init()
{
    //初始化设备接口
    hisiInit(hisiDeviceInfo);

    //更新本地视频通道
    updateVideoChannel(hisiDeviceInfo.localVideoDeviceList);
}

//登录
void Manager::login(QString &name, QString &password)
{
    networkManager.login(name, password);
}

//退出
void Manager::logout()
{
    networkManager.logout();
}

//设置分屏窗口的信息
void Manager::setLayoutWindowInfo()
{

}

//设置视频在窗口的显示
void Manager::localVideoWinShow(qint8 row, qint8 column, QVector<LayoutWindowInfoType> &winInfo)
{
     //执行分屏程序前，清一次分屏
     zkCarDevEngine::instance()->zkCleanStandardWindow();

    //设置视频显示相对应的区域
    for(int i=0; i < row*column; i++){
        if(hisiDeviceInfo.localVideoDeviceList.size() > i){
            QPoint point = winInfo.at(i).widget->mapToGlobal(
                            QPoint(winInfo.at(i).widget->rect().x(),
                                   winInfo.at(i).widget->rect().y()));
            RECT_ST rect;
            rect.s32X = point.x();
            rect.s32Y = point.y();
            rect.u32Width = winInfo.at(i).widget->width();
            rect.u32Height = winInfo.at(i).widget->height();

            if(rect.s32X%2 !=0 ) rect.s32X--;
            if(rect.s32Y%2 !=0 ) rect.s32Y--;
            if(rect.u32Width%2 !=0) rect.u32Width--;
            if(rect.u32Height%2 !=0) rect.u32Height--;

            qDebug() << "-----rect" << QRect(rect.s32X, rect.s32Y, rect.u32Width, rect.u32Height);

            zkCarDevEngine::instance()->zkSetOneWindow(winInfo.at(i).widget->winId(), &rect);
        }
    }


    //本地视频设备，显示在对应的窗口号里面
    for(int i=0; i < row * column; i++){
        if(hisiDeviceInfo.localVideoDeviceList.size() > i)
        {
            winInfo[i].devType = hisiDeviceInfo.localVideoDeviceList.at(i).devType;
            winInfo[i].devId = hisiDeviceInfo.localVideoDeviceList.at(i).devId;

            qDebug() << "-------zkshowvideo" << winInfo.at(i).widget->winId();
            //设置视频显示
            zkCarDevEngine::instance()->zkShowVedio(winInfo.at(i).devType,
                                                    winInfo.at(i).devId,
                                                    winInfo.at(i).widget->winId());
        }
    }
}

//请求列表完成后的处理
void Manager::allListInfoHandler()
{
    loadUserInteractList(networkManager.groupListInfo(), networkManager.categoryListInfo(), networkManager.userListInfo());
    loadGroupInteractList(networkManager.intercomListInfo());
    loadMeetingList(networkManager.meetinglistInfo());
}


//返回本地视频列表信息
QList<DEVICEINFO_S>& Manager::localVideoDevice()
{
    return hisiDeviceInfo.localVideoDeviceList;
}

