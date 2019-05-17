#ifndef __ZKCARDEVENGINGE_H
#define __ZKCARDEVENGINGE_H
#include "zkdevdefine.h"
class zkCarDevEngine
{
public:
	zkCarDevEngine();
	~zkCarDevEngine();
	static zkCarDevEngine* instance();
	static zkCarDevEngine* m_instance;
	//fb0初始化
	bool fb0_init();
	//初始化
	bool device_init();
	bool device_init(int winNum,RECT_ST* rect);
	//获取设备列表
	bool get_dev_list(list<DEVICEINFO_S>* p_list);
	//注册一个本地设备
	bool regist_one_local_dev(INPUT_DEV_TYPE_E devType,int devId,char* devName);
	//注册一个网络设备
	int zkAddOneRemoteDev(INPUT_DEV_TYPE_E devType,int devId,const char* url);
	//获取设备的注册信息
	bool zkGetDevRegistInfo(INPUT_DEV_TYPE_E devType,int devId,void* regist_info);
	//启动一个设备
	bool zkStartDevice(INPUT_DEV_TYPE_E devType,int devId);
	//停止一个设备
	bool zkStopDevice(INPUT_DEV_TYPE_E devType,int devId);
	//设置分屏模式,winNum:要分屏的总数，rect:显示区域总大小
	bool zkSetShowModel(int winNum,RECT_ST* rect);
	//设置单个显示窗口的位置尺寸,winNum:窗口号，rect:该窗口显示区域大小
	bool zkSetOneWindow(long long winFd,RECT_ST* rect);
	//获取标准分屏的总窗口数
	int zkGetStandardWinNum();
	//获取所有窗口列表
	bool zkGetWindowList(list<WINDOW_ST>* p_list);
	//清除标准分屏模式下的所有窗口
	bool zkCleanStandardWindow();
	//显示视频
	bool zkShowVedio(INPUT_DEV_TYPE_E devType,int devId,long long winFd);
	//关闭显示
	bool zkCloseShow(INPUT_DEV_TYPE_E devType,int devId);
	//截屏
	bool zkPrintScreen();
	//拍照
	bool zkTakePicture(INPUT_DEV_TYPE_E devType,int devId);
	//获取视频编码数据
	int zkGetEnData(INPUT_DEV_TYPE_E devType,int devId,VENC_STREAM_TYPE_E streamType,ENCODE_DATA_S* enData);
	//停止获取视频编码数据
	bool zkStopGetEnData(INPUT_DEV_TYPE_E devType,int devId,int enFd);
	//录像
	int zkRecordMp4(INPUT_DEV_TYPE_E devType,int devId,RECORD_MP4_TYPE_E recordType,VENC_STREAM_TYPE_E streamType,const char* path,unsigned int secs);
	//停止录像
	bool zkStopRecordMp4(INPUT_DEV_TYPE_E devType,int devId,int recordId);
	//推流
	int zkPushStream(INPUT_DEV_TYPE_E devType,int devId,PUSH_STREAM_PARA_ST* arg);
	//停止推流
	bool zkStopPushStream(INPUT_DEV_TYPE_E devType,int devId,int pushId);
	//打开播放器,priority:显示优先级，rect:播放器界面的坐标及界面大小
	bool zkStartMediaPlayer(int priority,RECT_ST* rect);
	//播放视频,单个视频
	bool zkPlayMedia(const char* fileName);
	//暂停播放,单个视频
	bool zkStopPlayMedia();
	//结束播放,单个视频
	bool zkEndPlayMedia();
	//关闭播放器,单个视频
	bool zkCloseMediaPlayer();
	//快进,单个视频
	bool zkPlayMediaAhead(int sec);
	//后退,单个视频
	bool zkPlayMediaBack(int sec);
	//跳转至第几秒,单个视频
	bool zkPlayMediaJumpTo(int sec);
	//获取当前的播放进度，单位s,单个视频
	int zkGetMediaPlayTime();
	//播放视频，连续的多个视频
	bool zkPlayMedias(list<FILE_PROPERTY_ST>* p_list);
	//暂停播放，连续的多个视频
	bool zkStopPlayMedias();
	//结束播放，连续的多个视频
	bool zkEndPlayMedias();
	//关闭播放器，连续的多个视频
	bool zkCloseMediasPlayer();
	//快进，连续的多个视频
	bool zkPlayMediasAhead(int sec);
	//后退，连续的多个视频
	bool zkPlayMediasBack(int sec);
	//跳转至第几秒，连续的多个视频
	bool zkPlayMediasJumpTo(int sec);
	//获取当前的播放进度，单位s,连续的多个视频
	int zkGetMediasPlayTime();
	//获取视频文件列表
	bool zkGetMp4FileList(INPUT_DEV_TYPE_E devType,int devId,const char* str_time,list<FILE_PROPERTY_ST>* p_list);
	//上传文件
	bool zkUploadFile(const char* srcFileName,const char* url);
	//获取内存
	char* zkGetMemory(int size);
	//释放内存
	void zkDelMemory(char* buff);
};
#endif
