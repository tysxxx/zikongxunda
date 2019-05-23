
#include "hisiinterface.h"
#include <QDebug>

#define LOCAL_VIDEO_RECORD_PATH "/mnt/recordVedio"
//#define LOCAL_VIDEO_RECORD_PATH "/mnt/tys"

//@.hisi接口初始化
void hisiInit(HisiDeviceInfoType &hisiDeviceInfo)
{
    //初始化设备
    zkCarDevEngine::instance()->device_init();
    qDebug() << "devie_init()";
    //获取设备列表
    getdeviceList(hisiDeviceInfo);
    qDebug() << "getdevicelist()";

    //打开本地录像录制
    openAllLocalVideoRecord(hisiDeviceInfo.localVideoDeviceList);
}

//@.获取底层设备列表，即接口有哪些摄像头等设备
void getdeviceList(HisiDeviceInfoType &deviceInfo)
{
    deviceInfo.allDeviceList.clear();

    list<DEVICEINFO_S> pDeviceList;
    zkCarDevEngine::instance()->get_dev_list(&pDeviceList);
    deviceInfo.allDeviceList = QList<DEVICEINFO_S>::fromStdList(pDeviceList);

    //打印获取到的设备信息
    for(list<DEVICEINFO_S>::iterator iterator = pDeviceList.begin(); iterator != pDeviceList.end(); ++iterator){
        qDebug() << "---devType: " << (*iterator).devType
                 << "\tdevid: " << (*iterator).devId
                 << "\tdevname:" << (*iterator).devName;
    }

    for(auto device: deviceInfo.allDeviceList)
    {
        if(device.devType == LOCAL_VEDIO) //等于本地视频
        {
            qDebug() << "local video";
            qDebug() << "devType: " << device.devType
                 << "\tdevid: " << device.devId
                 << "\tdevname:" << device.devName;
            deviceInfo.localVideoDeviceList.append(device);
        }
        else if(device.devType == LOCAL_AUDIO) //等于本地音频
        {
            deviceInfo.localAudioDeviceList.append(device);
        }
    }
}

//打开本地所有视频设备的录制
void openAllLocalVideoRecord(QList<DEVICEINFO_S> &localVideoDeviceList)
{
    for(auto device: localVideoDeviceList){
        zkCarDevEngine::instance()->zkRecordMp4(device.devType, device.devId, RECORD_LOOP, LITTLESTREAM, LOCAL_VIDEO_RECORD_PATH, 60);
    }
}

