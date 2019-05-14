#ifndef HISIINTERFACE_H
#define HISIINTERFACE_H

#include "zkdevdefine.h"
#include "zkCarDevEnginge.h"
#include <QList>
#include <QVector>

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


void hisiInit(HisiDeviceInfoType &hisiDeviceInfo);
void getdeviceList(HisiDeviceInfoType &deviceInfo);
void openAllVideoRecord(QList<DEVICEINFO_S> &localVideoDeviceList);

#endif // HISIINTERFACE_H

