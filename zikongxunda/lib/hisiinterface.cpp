#include "hisiinterface.h"
#include "zkCarDevEnginge.h"
#include <QDebug>
#include <QFileInfo>

HisiInterface* HisiInterface::m_hisiInterface = new HisiInterface();

HisiInterface::HisiInterface() //(QObject *parent): QObject(parent)
{
    #ifdef HISI_PLATFORM
    HisiDeviceEngine = zkCarDevEngine::instance();
    #endif
}

HisiInterface::~HisiInterface()
{
    #ifdef HISI_PLATFORM
    if(HisiDeviceEngine)
        delete HisiDeviceEngine;
    HisiDeviceEngine=nullptr;
    #endif
}

HisiInterface* HisiInterface::instance()
{
    return m_hisiInterface;
}

//初始化实现
void HisiInterface::hisi_deviceInit()
{
    qDebug() << __FILE__<<__FUNCTION__<<__LINE__<<"设备初始化";
    #ifdef HISI_PLATFORM
    HisiDeviceEngine->device_init();
    #endif
}

//获取设备列表
void HisiInterface::hisi_getDevieceList(QList<DEVICEINFO_S> *devicelist)
{
    qDebug() <<"FILE:"<<__FILE__<<"FUNC"<<__FUNCTION__<<"LINE:"<<__LINE__<<"get the devicelist";
    #ifdef HISI_PLATFORM
    list<DEVICEINFO_S> p_list;
//    DEVICEINFO_S deviceinfo;
//    deviceinfo.devType = LOCAL_VEDIO;
//    deviceinfo.devId = 3;
//    memcpy(deviceinfo.devName, "sd1", sizeof("sd1"));
//    p_list.push_back(deviceinfo);
    HisiDeviceEngine->get_dev_list(&p_list); //获取设备列表
    //打印获取到的设备信息
    for(list<DEVICEINFO_S>::iterator it = p_list.begin(); it != p_list.end(); ++it){
        qDebug() << "devType: " << (*it).devType
                 << " devid: " << (*it).devId
                 << " devname:" << (*it).devName;
        devicelist->clear();
        devicelist->append(*it);
    }

    #endif
}

//注册一个本地设备
void HisiInterface::hisi_registerLocalDevice(localDeviceInfoType localDeviceParams)
{
    #ifdef HISI_PLATFORM
//    HisiDeviceEngine->regist_one_local_dev(localDeviceParams.devInfo.devType,localDeviceParams.devInfo.devId,
//                         localDeviceParams.devInfo.devName);
    #endif
}
//注册一个网络设备
void HisiInterface::hisi_registerRemoteDevice(remoteDeviceInfoType remoteDeviceParams)
{
    #ifdef HISI_PLATFORM
    HisiDeviceEngine->regist_one_remote_dev(remoteDeviceParams.devType, remoteDeviceParams.entype,
                          remoteDeviceParams.size, remoteDeviceParams.info);
    #endif
}

//设置单独窗口模式
bool HisiInterface::hisi_setSingleWinShow(winShowInfoType winParams)
{
    qDebug() <<"FILE:"<<__FILE__<<"FUNC"<<__FUNCTION__<<"LINE:"<<__LINE__<< "set one window";
    bool ret = false;
    qDebug() <<"窗口号:"<< winParams.winNum;
    #ifdef HISI_PLATFORM
    rect_st  rect;
    rect.s32X = winParams.x;
    rect.s32Y = winParams.y;
    rect.u32Width = winParams.width;
    rect.u32Height = winParams.height;
    ret = HisiDeviceEngine->zkSetOneWindow(winParams.winNum, &rect);
    #endif

    return ret;
}

//清除窗口
void HisiInterface::hisi_cleanAllWin()
{
  qDebug() <<"FILE:"<<__FILE__<<"FUNC"<<__FUNCTION__<<"LINE:"<<__LINE__<< "clean win";
  #ifdef HISI_PLATFORM
  HisiDeviceEngine->zkCleanStandardWindow();
  #endif
  qDebug() << "clean end";
}

//显示视频
void HisiInterface::hisi_showVideo(DeviceInfoType videoParams, qint32 winNum)
{
    qDebug() <<"FILE:"<<__FILE__<<"FUNC"<<__FUNCTION__<<"LINE:"<<__LINE__<< "show video";
    #ifdef HISI_PLATFORM
    HisiDeviceEngine->zkShowVedio(videoParams.devType, videoParams.id, winNum);
    #endif
}

//关闭显示
void HisiInterface::hisi_closeVideo(DeviceInfoType videoParams)
{
    #ifdef HISI_PLATFORM
    HisiDeviceEngine->zkCloseShow(videoParams.devType, videoParams.id);
    #endif
}

//截屏
void HisiInterface::hisi_grabScreen()
{
    #ifdef HISI_PLATFORM
    HisiDeviceEngine->zkPrintScreen();
    #endif
}

//录像
int HisiInterface::hisi_videoRecord(DeviceInfoType videoParams, RECORD_MP4_TYPE_E recordType,
                      VENC_STREAM_TYPE_E streamType, char* path, quint32 secs)
{
    #ifdef HISI_PLATFORM
    return HisiDeviceEngine->zkRecordMp4(videoParams.devType, videoParams.id, recordType, streamType,path, secs);
    #else
    return 0;
    #endif
}

//停止录像
void HisiInterface::hisi_stopVideoRecord(INPUT_DEV_TYPE_E devType,int devId, qint32 recordId)
{
    #ifdef HISI_PLATFORM
    HisiDeviceEngine->zkStopRecordMp4(devType, devId, recordId);
    #endif
}

//推流
void HisiInterface::hisi_PushStream(DeviceInfoType videoParams, PUSH_STREAM_PARA_ST* arg)
{
    #ifdef HISI_PLATFORM
    //HisiDeviceEngine->zkPushStream(videoParams.devType, videoParams.id, arg);
    #endif
}

//停止推流
void HisiInterface::hisi_stopPushStream(DeviceInfoType videoParams, qint32 pushId)
{
    #ifdef HISI_PLATFORM
    //HisiDeviceEngine->zkStopPushStream(videoParams.devType, videoParams.id, pushId);
    #endif
}

//打开播放视频的播放器
void HisiInterface::hisi_openMediaPlayer(quint32 x, quint32 y, quint32 width, quint32 height)
{
    #ifdef HISI_PLATFORM
    RECT_ST rect;
    rect.s32X = x;
    rect.s32Y = y;
    rect.u32Width = width;
    rect.u32Height = height;
    HisiDeviceEngine->zkStartMediaPlayer(1, &rect);
    #endif
}

//关闭播放器
void HisiInterface::hisi_closeMediaPlayer(quint8 videofileType)
{
    #ifdef HISI_PLATFORM
    if(videofileType)
        HisiDeviceEngine->zkCloseMediaPlayer();
    else
        HisiDeviceEngine->zkCloseMediasPlayer();
    #endif
}

//从头开始播放指定视频文件
void HisiInterface::hisi_startPlayVideo(QString channel, QString date)
{
    #ifdef HISI_PLATFORM

    #endif
}

//视频播放
void HisiInterface::hisi_playVideo()
{
    #ifdef HISI_PLATFORM
    //HisiDeviceEngine->zkStopPushStream(videoParams.devType, videoParams.id, pushId);
    #endif
}

//视频暂停
void HisiInterface::hisi_pauseVideo()
{
    #ifdef HISI_PLATFORM
    HisiDeviceEngine->zkStopPlayMedia();
    #endif
}

//视频停止播放
void HisiInterface::hisi_stopPlayVideo()
{
    #ifdef HISI_PLATFORM
    HisiDeviceEngine->zkEndPlayMedia();
    #endif
}

//视频快进
void HisiInterface::hisi_forwardVideo()
{
    #ifdef HISI_PLATFORM
    HisiDeviceEngine->zkPlayMediaAhead(5);
    #endif
}

//视频快退
void HisiInterface::hisi_backwardVideo()
{
    #ifdef HISI_PLATFORM
    HisiDeviceEngine->zkPlayMediaBack(5);
    #endif
}

//
quint32 HisiInterface::localDeviceNum()
{
    return m_localDeviceNum;
}

void HisiInterface::hisi_setDeviceWin()
{

}

//根据日期，查询相应设备的视频文件
void HisiInterface::hisi_localVideoFileQuery(const DeviceInfoType device, const QString date,
                                             list<FILE_PROPERTY_ST>* videoFileInfoList)
{
//    videoFileInfoList->clear();
//    TableItem::tableVideoFileInfoType data;
//    data.fileName = "hello";
//    data.fileSize = "60M";
//    data.startTime = "2019-01-17 18:00";
//    data.endTime = "2019-01-17 19:00";
//    videoFileInfoList->append(data);

//    data.fileName = "world";
//    data.fileSize = "30M";
//    data.startTime = "2019-02-17 18:00";
//    data.endTime = "2019-02-17 19:00";
//    videoFileInfoList->append(data);

//    qDebug() << "query device name:" << device.name
//             << "query date:" << date;


    #ifdef HISI_PLATFORM
    //HisiDeviceEngine->zkGetMp4FileList(device.devType, device.id, date.toUtf8().constData(), &p_list);
    #endif
}

//播放单个视频文件
void HisiInterface::hisi_playSingleFile(QString fileName)
{
    #ifdef HISI_PLATFORM
    HisiDeviceEngine->zkPlayMedia(fileName.toUtf8().constData());
    #endif
}

//播放多个视频文件
void HisiInterface::hisi_playMultipleFile(list<FILE_PROPERTY_ST>* videoFileList)
{
    #ifdef HISI_PLATFORM
    HisiDeviceEngine->zkPlayMedias(videoFileList);
    #endif
}


