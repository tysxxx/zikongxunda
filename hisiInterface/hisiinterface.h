#ifndef HISIINTERFACE_H
#define HISIINTERFACE_H

#include "zkdevdefine.h"
#include "zkCarDevEnginge.h"
#include <QList>
#include <QVector>
#include <QRect>
#include <QWidget>

enum DeviceType{
    allDevice = 0,
    localVideoDevice,
    localAudioDevice,
};

typedef struct _hisiDeviceInfo
{
   QList<DEVICEINFO_S> allDeviceList; //0:总的设备列表
   QList<DEVICEINFO_S> localVideoDeviceList; //1:本地视频列表
   QList<DEVICEINFO_S> localAudioDeviceList; //2:本地音频设备列表
   bool openLocalVideoRecord;  //打开本地视频录像

}HisiDeviceInfoType;

typedef struct layoutWindowInfo
{
    QWidget *widget; //具体的窗口
    qint64 windId; //窗口id
    QRect  rect;   //窗口的位置
    INPUT_DEV_TYPE_E devType; //窗口关联的摄像头的类型
    qint32 devId; //窗口关联的摄像头id

}LayoutWindowInfoType;

void hisiInit(HisiDeviceInfoType &hisiDeviceInfo);
void getdeviceList(HisiDeviceInfoType &deviceInfo);
void openAllLocalVideoRecord(QList<DEVICEINFO_S> &localVideoDeviceList);

#endif // HISIINTERFACE_H

