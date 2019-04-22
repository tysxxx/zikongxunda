#ifndef ZKDEVDEFINE_H
#define ZKDEVDEFINE_H
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdarg.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <vector>
#include <list>
using namespace std;

#define MAXLOGFILESIZE 100*1024*1024
#define DEBUGLOGFILEPATH "/var/log/ZkxdErrMsg.log"

#define WIDTH 1920   //屏幕的宽
#define HEIGHT 1080  //屏幕的高
#define MAXSTANDARDWINNUM 36//标准分屏模式下的最大窗口个数
class DebugLog{
public:
    DebugLog();
    void WriteLog(const char *logfile,const char *fileName,const char *functionName,int lineNum, const char *format, ...)
    {
        va_list args;
        time_t ltime;
        struct tm * newtime;
        FILE * file;
        struct stat buf;
        stat(logfile, &buf);
        if(buf.st_size > MAXLOGFILESIZE)
        {
            file = fopen(logfile, "w");
        }else
            {
                file = fopen(logfile, "a");
             }
        if (file == NULL)
        {
            //perror("fopen fail in WriteLog of the pubfun.cpp file:log director not exist!\n");
            /*mkdir("log");*/
            return;
        }
        time(&ltime);
        newtime = localtime(&ltime);
        fprintf(file, "%d-%02d-%02d %02d:%02d:%02d ",
            newtime->tm_year + 1900, newtime->tm_mon + 1, newtime->tm_mday,
            newtime->tm_hour, newtime->tm_min, newtime->tm_sec);
        fprintf(file, "FILE:%s ",fileName);
        fprintf(file, "FUNCTION:%s ",functionName);
        fprintf(file, "LINE:%d ",lineNum);
        va_start(args, format);
        vfprintf(file, format, args);
        va_end(args);
        fprintf(file, "\n");
        fclose(file);
        return;
    }

};

#ifndef DEBUG
    #define DEBUG 1
#endif

#if DEBUG
    #define DEBUGLOG(format,...) printf("FILE: %s, FUN: %s, LINE: %d " format "\n",__FILE__,__FUNCTION__,__LINE__,##__VA_ARGS__)


#else
    #define DEBUGLOG(format,...)
#endif

#define DEBUG_TOFILE_XIUTAN(...)		DebugLog::WriteLog(DEBUGLOGFILEPATH,__FILE__,__FUNCTION__,__LINE__,__VA_ARGS__)

typedef enum input_dev_type_e
{
    LOCAL_VEDIO = 0,
    LOCAL_AUDIO = 1,
    RTSP_VEDIO = 2,
    RTSP_AUDIO = 3,
    WBC_VEDIO = 4,


}INPUT_DEV_TYPE_E;

typedef enum encode_type_e
{
    V_H264 = 0,
    A_PCM,
    A_AAC,
}ENCODE_TYPE_TYPE_E;

typedef enum venc_stream_type_e
{
    BIGSTREAM = 0,//1920*1080
    LITTLESTREAM = 1,//720*576
    OTHERSTREAM = 2,
}VENC_STREAM_TYPE_E;

typedef struct rect_st
{
    unsigned int s32X;
    unsigned int s32Y;
    unsigned int u32Width;
    unsigned int u32Height;
}RECT_ST;

typedef struct window_st
{
    RECT_ST rect;//窗口坐标位置信息
    int winNum;//窗口号
    bool statu;//窗口使用情况，true代表窗口已被占用，false代表窗口空闲可用
}WINDOW_ST;

typedef enum record_mp4_type_e
{
    RECORD_ONE = 0,//录制单个视频
    RECORD_LOOP,//循环录制视频
    RECORD_OTHER
}RECORD_MP4_TYPE_E;

typedef struct vedio_size_st
{
    unsigned int u32Width;
    unsigned int u32Height;
}VEDIO_SIZE_ST;

typedef struct deviceInfo_s
{
    INPUT_DEV_TYPE_E devType;
    int devId;
    char devName[500]={0};
}DEVICEINFO_S;

typedef int(*push_vedio_stream_callback)(void *pRtmpKit,unsigned char* pData, int nDLen,long vTts);
typedef int(*push_audio_stream_callback)(void *pRtmpKit,unsigned char* pData, int nDLen,long vTts);

typedef struct push_stream_para_st
{
    char rtsp[500];//推流网址
    VENC_STREAM_TYPE_E streamType;//码流类型
    void* pRtmpKit;//推流句柄
    push_vedio_stream_callback push_vedio_callback;
    push_audio_stream_callback push_audio_callback;
}PUSH_STREAM_PARA_ST;



typedef struct rtsp_data_para_st
{
    char rtsp[500];//rtsp数据源网址
    INPUT_DEV_TYPE_E devType;//视频源类型
    int devId;//视频源设备对应的id
    VENC_STREAM_TYPE_E streamType;//码流类型
    bool endFlag;//停止标志，true:停止推流，false:正常推流
    bool overFlag;//结束标志，用于判断推流线程是否结束，方便使用者进行资源回收，true:结束推流，false:正常推流
    void* ptRtsp;//rtsp数据流句柄
}RTSP_DATA_PARA_ST;


typedef struct stream_data_s
{
    int dataLen;
    unsigned long long timeStamp;
    char* data;
}STREAM_DATA_S;

typedef struct remote_dev_regist_info_st
{
    char url[500];//rtsp数据源网址
    list<STREAM_DATA_S>* p_vedio_list;//需要被解码的视频源数据链表指针
    pthread_mutex_t vedio_pthreadMutex;
    list<STREAM_DATA_S>* p_audio_list;//需要被解码的音频源数据链表指针
    pthread_mutex_t audio_pthreadMutex;
}REMOTE_DEV_REGIST_INFO_ST;


typedef struct file_property_st//定义一个文件属性的结构体
{
    long long size;
    int cnt;//第几个视频
    char time[30];
    char fileName[300];
}FILE_PROPERTY_ST;

#endif // ZKDEVDEFINE_H
