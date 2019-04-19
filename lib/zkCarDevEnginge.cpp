#include "zkCarDevEnginge.h"
#include "./device/ZkxdDevManager.h"
#include "./device/ZkxdSystemCfg.h"
#include "./device/ZkxdMediaPlayer.h"
zkCarDevEngine* zkCarDevEngine::m_instance = NULL;

zkCarDevEngine::zkCarDevEngine()
{
	
}
zkCarDevEngine::~zkCarDevEngine()
{
	
}
	
zkCarDevEngine* zkCarDevEngine::instance()
{
  if (m_instance == NULL) {
    m_instance = new zkCarDevEngine();
  }
  return m_instance;
}

bool zkCarDevEngine::fb0_init()
{
	return ZkxdSystemCfg::instance()->init();
}

bool zkCarDevEngine::device_init(int winNum,RECT_ST* rect)
{
	if(ZkxdDevManager::instance()->init() != 0)
		return false;
	if(ZkxdDevManager::instance()->set_show_model(winNum,rect))
		return false;
	return true;
}

bool zkCarDevEngine::get_dev_list(list<DEVICEINFO_S>* p_list)
{
	return ZkxdDevManager::instance()->get_dev_list(p_list);
}

bool zkCarDevEngine::regist_one_local_dev(INPUT_DEV_TYPE_E devType,int devId,char* devName)
{
	return ZkxdDevManager::instance()->regist_one_local_dev(devType,devId,devName);
}

int zkCarDevEngine::regist_one_remote_dev(INPUT_DEV_TYPE_E devType,ENCODE_TYPE_TYPE_E entype,VEDIO_SIZE_ST size,REMOTE_DEV_REGIST_INFO_ST* info)
{
	return ZkxdDevManager::instance()->regist_one_remote_dev(devType,entype,size,info);
}

bool zkCarDevEngine::zkSetShowModel(int winNum,RECT_ST* rect)
{
	return ZkxdDevManager::instance()->set_show_model(winNum,rect);
}

bool zkCarDevEngine::zkSetOneWindow(int winNum,RECT_ST* rect)
{
	return ZkxdDevManager::instance()->set_one_window(winNum,rect);
}

int zkCarDevEngine::zkGetStandardWinNum()
{
	return ZkxdDevManager::instance()->get_standard_winNum();
}

bool zkCarDevEngine::zkGetWindowList(list<WINDOW_ST>* p_list)
{
	return ZkxdDevManager::instance()->get_window_list(p_list);
}

bool zkCarDevEngine::zkCleanStandardWindow()
{
	return ZkxdDevManager::instance()->clean_standard_window();
}

bool zkCarDevEngine::zkShowVedio(INPUT_DEV_TYPE_E devType,int devId,int winNum)
{
	return ZkxdDevManager::instance()->show_vedio(devType,devId,winNum);
}

bool zkCarDevEngine::zkCloseShow(INPUT_DEV_TYPE_E devType,int devId)
{
	return ZkxdDevManager::instance()->close_show(devType,devId);
}

bool zkCarDevEngine::zkPrintScreen()
{
	return ZkxdDevManager::instance()->print_screen();
}

bool zkCarDevEngine::zkTakePicture(INPUT_DEV_TYPE_E devType,int devId)
{
	return ZkxdDevManager::instance()->take_picture(devType,devId);
}

int zkCarDevEngine::zkRecordMp4(INPUT_DEV_TYPE_E devType,int devId,RECORD_MP4_TYPE_E recordType,VENC_STREAM_TYPE_E streamType,unsigned int secs)
{
	return ZkxdDevManager::instance()->record_mp4(devType,devId,recordType,streamType,secs);
}

bool zkCarDevEngine::zkStopRecordMp4(INPUT_DEV_TYPE_E devType,int devId,int recordId)
{
	return ZkxdDevManager::instance()->stop_record_mp4(devType,devId,recordId);
}

int zkCarDevEngine::zkPushStream(INPUT_DEV_TYPE_E devType,int devId,PUSH_STREAM_PARA_ST* arg)
{
	return ZkxdDevManager::instance()->push_stream(devType,devId,arg);
}

bool zkCarDevEngine::zkStopPushStream(INPUT_DEV_TYPE_E devType,int devId,int pushId)
{
	return ZkxdDevManager::instance()->stop_push_stream(devType,devId,pushId);
}

bool zkCarDevEngine::zkStartMediaPlayer(int priority,RECT_ST* rect)
{
	return ZkxdMediaPlayer::instance()->start_media_player(priority,rect);
}

bool zkCarDevEngine::zkPlayMedia(const char* fileName)
{
	return ZkxdMediaPlayer::instance()->play_media(fileName);
}

bool zkCarDevEngine::zkStopPlayMedia()
{
	return ZkxdMediaPlayer::instance()->stop_play_media();
}

bool zkCarDevEngine::zkEndPlayMedia()
{
	return ZkxdMediaPlayer::instance()->end_play_media();
}

bool zkCarDevEngine::zkCloseMediaPlayer()
{
	return ZkxdMediaPlayer::instance()->close_media_player();
}

bool zkCarDevEngine::zkPlayAhead(int sec)
{
	return ZkxdMediaPlayer::instance()->play_ahead(sec);
}

bool zkCarDevEngine::zkPlayBack(int sec)
{
	return ZkxdMediaPlayer::instance()->play_back(sec);
}

bool zkCarDevEngine::zkPlayJumpTo(int sec)
{
	return ZkxdMediaPlayer::instance()->play_jump_to(sec);
}











