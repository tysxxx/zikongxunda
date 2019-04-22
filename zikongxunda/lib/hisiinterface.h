#ifndef HISIINTERFACE_H
#define HISIINTERFACE_H

//#ifdef HISI_PLATFORM
#include <QObject>
#include <QList>
#include "type.h"
#include "zkdevdefine.h"
#include "tableitem.h"

class zkCarDevEngine;

class HisiInterface
{
public:
    HisiInterface();
    ~HisiInterface();

    static HisiInterface* instance();
    //屏幕区域和分屏数
    using winShowInfoType = struct WinShowInfoStruct{
        quint32 winNum;
        quint32 x;
        quint32 y;
        quint32 width;
        quint32 height;
    };

    //本地设备
    using localDeviceInfoType = struct localDeviceInfoStruct{
       DeviceInfoType devInfo;
    };

    //远程设备
    using remoteDeviceInfoType = struct remoteDeviceInfoStruct{
       INPUT_DEV_TYPE_E devType;
       ENCODE_TYPE_TYPE_E entype;
       VEDIO_SIZE_ST size;
       REMOTE_DEV_REGIST_INFO_ST* info;
    };

    //一个窗口对应的信息
    using deviceDispWinInfoType = struct deviceDispWinInfoStruct{
        quint32 x;
        quint32 y;
        quint32 width;
        quint32 height;
        bool fullScreen;
        DeviceInfoType deviceInfo;
        quint32 id;
    };

    void hisi_deviceInit();
    //void hisi_initWinShow(winShowInfoType winParams);
    void hisi_getDevieceList(QList<DEVICEINFO_S> *devicelist);
    void hisi_registerLocalDevice(localDeviceInfoType localDeviceParams);
    void hisi_registerRemoteDevice(remoteDeviceInfoType remoteDeviceParams);
    //void hisi_setWinShowModel(winShowInfoType winParams);
    bool hisi_setSingleWinShow(winShowInfoType winParams);
    void hisi_cleanAllWin();
    void hisi_showVideo(DeviceInfoType videoParams, qint32 winNum);
    void hisi_closeVideo(DeviceInfoType videoParams);
    void hisi_grabScreen();
    int hisi_videoRecord(DeviceInfoType videoParams, RECORD_MP4_TYPE_E recordType,
                          VENC_STREAM_TYPE_E streamType, char* path, quint32 secs);
    void hisi_stopVideoRecord(INPUT_DEV_TYPE_E devType,int devId, qint32 recordId);
    void hisi_PushStream(DeviceInfoType videoParams, PUSH_STREAM_PARA_ST* arg);
    void hisi_stopPushStream(DeviceInfoType videoParams, qint32 pushId);

    quint32 localDeviceNum();
    void hisi_setDeviceWin();

    void hisi_localVideoFileQuery(const DeviceInfoType device, const QString date,
                                  list<FILE_PROPERTY_ST>* videoFileInfoList);
    void hisi_openMediaPlayer(quint32 x, quint32 y, quint32 width, quint32 height);
    void hisi_closeMediaPlayer(quint8 videofileType);
    void hisi_startPlayVideo(QString channel, QString date);
    void hisi_playVideo();
    void hisi_pauseVideo();
    void hisi_stopPlayVideo();
    void hisi_forwardVideo();
    void hisi_backwardVideo();
    void hisi_playSingleFile(QString fileName);
    void hisi_playMultipleFile(list<FILE_PROPERTY_ST>* videoFileList);
private:
    #ifdef HISI_PLATFORM
    zkCarDevEngine* HisiDeviceEngine;
    #endif

    quint32 m_localDeviceNum;

    static HisiInterface* m_hisiInterface;
};

#endif // HISIINTERFACE_H
//#endif
