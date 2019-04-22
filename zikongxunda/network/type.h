#ifndef CONFIG_H
#define CONFIG_H

#include <QObject>
#include <QVector>
#include <vector>
#include <QDebug>
#include "zkdevdefine.h"

using namespace std;
//namespace Infomation
//{

//=====================================
//查询用户详情
//=====================================
//角色
typedef struct roleStruct{
    qint32 id;
    QString name;
    QString display_name;
    QString description;
    bool    is_active;
    qint64 created_at;
    qint64 updated_at;
}roleType;

//权限
typedef struct permissionStruct{
    qint32 id;
    QString name;
    QString display_name;
    QString description;
    bool is_active;
    qint64 created_at;
    qint64 updated_at;
}permissionType;

typedef struct userDetailStruct{
    qint32 id;
    QString nick;
    QString name;
    QString phone;
    QString avatar;
    bool is_active;
    qint32 group_id;
    qint32 group_category_id;
    qint64 register_at;
    qint64 logged_in_at;
    QString common_name;
    QString common_password;
    QString im_name;
    QString im_password;
    QString sip_name;
    qint32 live_id;
    QString sip_password;
    QString live_push_url;
    QString live_play_url;
    QString live_rtmp_url;
    QString live_hls_url;
    qreal longitude;
    qreal latitude;
    QString address;
    qint32 camera_id;
    bool is_online;
    bool show_location;
    qint32 role_id;
    QString role_name;
    QVector<roleType> roles;
    QVector<permissionType> permissions;
    qint32 scene_type_id;
}userDetailType;

//=====================================
//查询用户列表
//=====================================
typedef struct userListStruct{
    qint32 total;
    QVector<userDetailType> items;

    void clear(){
        total = 0;
        items.clear();
    }
}userListType;

//=====================================
//查询对讲详情
//=====================================
typedef struct intercomDetailStruct{
    qint32 id;
    QString name;
    QString description;
    qint64 created_at;
    qint64 updated_at;
    qint32 group_id;
    qint32 group_category_id;
    qint32 scene_type_id;
    QString im_group_name;
}intercomDetaiType;
//=====================================
//查询对讲列表
//=====================================
typedef struct intercomListStruct{
    qint32 total;
    QVector<intercomDetaiType> items;

    void clear(){
        total = 0;
        items.clear();
    }
}intercomListType;

//=====================================
//查询组织详情
//=====================================
typedef struct groupDetailStruct{
    qint32 id;
    QString name;
    qint64 created_at;
    qint64 updated_at;
}groupDetailType;

//=====================================
//查询组织列表
//=====================================
typedef struct groupListStruct{
    qint32 total;
    QVector<groupDetailType> items;

    void clear(){
        total = 0;
        items.clear();
    }
}groupListType;

//=====================================
//查询组织分类列表
//=====================================
typedef struct groupCategoryDetailStruct{
    qint32 id;
    QString name;
    qint32 group_id;
    qint32 parent_id;
    qint64 created_at;
    qint64 updated_at;
}groupCategoryDetailType;

typedef struct groupCategoryListStruct{
    qint32 total;
    QVector<groupCategoryDetailType> items;

    void clear(){
        total = 0;
        items.clear();
    }
}categoryListType;

//=====================================
//查询会议详情
//=====================================
typedef struct video{
    QString code;
    QString common_name;
    QString im_name;
    QString sip_name;
    qint32  camera_id;
    QString live_push_url;
    QString live_play_url;
    QString live_rtmp_url;
    QString live_hls_url;
    qint32 protocol_type_id;
    qint32 video_type_id;
    qint32 gb_device_type_id;
    struct gbStruct{
      QString device_id;
      QString parent_id;
    }gb;
    QString video_type_name;
}videoType;

typedef struct meetingDetailStruct{
    qint32 id;
    QString name;
    QString description;
    qint64 created_at;
    qint64 updated_at;
    qint32 group_id;
    qint32 group_category_id;
    QString im_group_name;
    qint64 start_time;
    qint64 end_time;
    qint32 meeting_type_id;
    qint32 business_type_id;
    QString group_name;
    qint32 scene_type_id;
    videoType video;
}meetingDetailType;
//=====================================
//查询会议列表
//=====================================
typedef struct meetingListStruct{
    qint32 total;
    QVector<meetingDetailType> items;

    void clear(){
        total = 0;
        items.clear();
    }
}meetingListType;

//=====================================
//查询会议成员列表
//=====================================
//struct meeting_device{
//    qint32 total;
//    //
//};
//struct conference_user{
//    qint32 total;
//    //
//};
//using conference_member_list = struct conference_member_list{
//    qint32 total;
//    conference_user user;
//    conference_device device;
//};

//=====================================
//查询设备详情
//=====================================
struct deviceGroupid{
    qint32 id;
};

struct deviceGroupCategoryid{
    qint32 id;
};
struct gbStruct{
  QString device_id;
  QString parent_id;
};
typedef struct deviceDetailStruct{
    qint32 id;
    QString code;
    QString name;
    bool is_active;
    qint64 created_at;
    qint64 updated_at;
    qint32 device_type_id;
    QString device_type_name;
    qint32 protocol_type_id;
    QString protocol_type_name;
    QVector<qint32> group_ids;
    QVector<qint32> group_category_ids;
    QString common_name;
    QString common_password;
    QString im_name;
    QString im_password;
    QString sip_name;
    QString sip_password;
    QString live_id;
    QString live_push_url;
    QString live_play_url;
    QString live_rtmp_url;
    QString live_hls_url;
    qreal longitude;
    qreal latitude;
    QString address;
    qint32 camera_id;
    bool is_online;
    bool show_location;
    qint32 gb_device_type_id;
    struct gbStruct gb;
    QString group_names;
    QString ext_live_play;
    QString video_type_name;
}deviceDetailType;
//=====================================
//查询设备列表
//=====================================
typedef struct deviceListStruct{
    qint32 total;
    QVector<deviceDetailType> items;

    void clear(){
        total = 0;
        items.clear();
    }
}deviceListType;

//=====================================
//查询报警详情
//=====================================
typedef struct alarmPhotoStruct{
    //
    QString photoName;
}alarmPhotoType;

typedef struct alarmContentStruct{
    qint32 camera_id;
    QString camera_ip;
    QString camera_location;
    qint32  rule;
    qint32  direction;
}alarmContentType;

typedef struct alarmDetailStruct{
    qint32 id;
    qint32 platform;
    QString platform_name;
    qint32 type;
    bool is_active;
    QString type_name;
    qint32 reporting_mode_id;
    QString reporting_mode_name;
    QVector<alarmPhotoType> photos;
    QString common_name;
    QString name;
    QString code;
    qint64 published_at;
    QString address;
    QString message;
    alarmContentType content;
    QString url;
    QString im_group_name;
    bool concluded;
    QString scene;
    QString basic;
    QString evidence;
    QString analysis;
    qint32 investigation_no;
}alarmDetailType;

//=====================================
//查询报警列表
//=====================================
typedef struct alarmListStruct{
    qint32 total;
    QVector<alarmDetailType> items;

    void clear(){
        total = 0;
        items.clear();
    }
}alarmListType;

//=====================================
//配置列表
//=====================================
//安卓安装信息
typedef struct androidUpdateStruct{
    qint32 version_code;
    QString version_name;
    bool must_install;
    bool load_page;
    QString message;
    QString url;
}androidUpdateType;

//苹果安装信息
typedef struct iosUpdateStruct{
    qint32 version_code;
    QString version_name;
    bool must_install;
    bool load_page;
    QString message;
    QString url;
}iosUpdateType;

//配置响应的参数
typedef struct ConfigStruct{
    bool enable_sip;
    bool enable_agora;
    QString http_api_host;
    qint32 http_api_port;
    QString https_api_host;
    qint32 https_api_port;
    QString im_host;
    qint32 im_port;
    QString sip_host;
    qint32 sip_port;
    QString file_host;
    qint32 file_port;
    QString ftp_host;
    qint32 ftp_port;
    QString ftp_name;
    QString ftp_pass;
    QString map_host;
    qint32 map_port;
    QString templet_host;
    qint32 templet_port;
    QString help_url;
    QString treaty_url;
    QString download_url;
    androidUpdateType android_update;
    iosUpdateType ios_update;
}ConfigType;

//=====================================
//节点详情
//=====================================
typedef struct userNode{
    qint32 id;
    QString name;
    qint32 categoryid;
    qint32 groupid;
}userNodeType;

typedef struct intercomNode{
    qint32 id;
    QString name;
    qint32 categoryid;
    qint32 groupid;
}intercomNodeType;

typedef struct meetingNode{
    qint32 id;
    QString name;
    qint32 categoryid;
    qint32 groupid;
}meetingNodeType;

typedef struct deviceNode{
    qint32 id;
    QString name;
    QVector<qint32> categoryid;
    QVector<qint32> groupid;
}deviceNodeType;

typedef struct categoryNode{
    qint32 id;
    QString name;
    qint32 parentid;
    qint32 groupid;
    QVector<userNodeType*> users;
    //QVector<intercomNodeType*> intercoms;
    //QVector<meetingNodeType*> meetings;
    QVector<deviceNodeType> devices;
    QVector<struct categoryNode*> categorys;

    categoryNode(){
        users.clear();
        categorys.clear();
    }

    ~categoryNode(){
        //qDebug() << __FUNCTION__;
        for(QVector<userNodeType *>::iterator iterator=users.begin();
            iterator != users.end(); ++iterator){
            userNodeType *tmpPtr=*iterator;
            if(tmpPtr)
                delete tmpPtr;
            tmpPtr = nullptr;
            qDebug() << "users";
        }

        for(QVector<categoryNode *>::iterator iterator=categorys.begin();
            iterator != categorys.end(); ++iterator){
            categoryNode *tmpPtr=*iterator;
            if(tmpPtr)
                delete tmpPtr;
            tmpPtr = nullptr;
             qDebug() << "categorys";
        }

        users.clear();
        categorys.clear();
    }
}categoryNodeType;

typedef struct groupNode{
    qint32 id;
    QString name;
    QVector<userNodeType> users;
    QVector<intercomNodeType> intercoms;
    QVector<meetingNodeType> meetings;
    QVector<deviceNodeType> devices;
    QVector<categoryNodeType> categorys;

    ~groupNode(){
        //qDebug() << __FUNCTION__;
    }
}groupNodeType;

typedef struct groupListNode{
    qint32 total;
    QVector<groupNodeType> groups;

    groupListNode(){
        total = 0;
        groups.clear();
    }

    ~groupListNode(){
        //qDebug() << __FUNCTION__;
    }
}groupListNodeType;

#ifdef HISI_PLATFORM
typedef long long winIDType;
#else
typedef long long  winIDType;
#endif

//设备信息
typedef struct deviceInfoStruct{
    INPUT_DEV_TYPE_E devType;
    qint32 id;
    QString name;
} DeviceInfoType;

//显示区域信息
typedef struct dispWinStruct{
    winIDType id;
    quint32 x;
    quint32 y;
    quint32 width;
    quint32 height;
    bool show;
    bool enlarge;
    DeviceInfoType device;

    dispWinStruct(){
        id = 0;
        x = 0;
        y = 0;
        width = 0;
        height = 0;
        show = false;
        enlarge = false;
    }

    dispWinStruct(const struct dispWinStruct& value){
        id = value.id;
        x = value.x;
        y = value.y;
        width = value.width;
        height = value.height;
        show = value.show;
        enlarge = value.enlarge;
    }
    dispWinStruct& operator=(const struct dispWinStruct& value){
        id = value.id;
        x = value.x;
        y = value.y;
        width = value.width;
        height = value.height;
        show = value.show;
        enlarge = value.enlarge;
        return *this;
    }
}dispWinType;

//检索视频文件日期所需条件
typedef struct videoFileQuery{
    DeviceInfoType device;
    QString date;
}videoFileQueryType;

//视频文件上传，查看
typedef  struct videoFileUploadOrLook
{
    DeviceInfoType device;
    QString date;

}videoFileUploadOrLookType;

typedef struct videoRecordInfoStruct{
    INPUT_DEV_TYPE_E devType;
    int devId;
    RECORD_MP4_TYPE_E recordType;
    VENC_STREAM_TYPE_E streamType;
    char* path;
    unsigned int secs;
    int recordId;
}videoRecordInfoType;


#endif // CONFIG_H
