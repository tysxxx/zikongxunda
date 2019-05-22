#include "networkmanager.h"
#include <QDebug>
#include <QTextCodec>
#include <QFile>

NetworkManager *NetworkManager::NetworkManagerInstance = new NetworkManager();

NetworkManager::NetworkManager(QObject *parent)
    : QObject(parent)
{
    initNetWorkManager();
}

NetworkManager::~NetworkManager()
{
    qDebug() << "~NetworkManager";
}

//创建实例
NetworkManager *NetworkManager::instance()
{
     return NetworkManagerInstance;
}

//销毁实例
void NetworkManager::destroy()
{
    if(NetworkManagerInstance)
        delete NetworkManagerInstance;
    NetworkManagerInstance = nullptr;
}

//初始化
void NetworkManager::initNetWorkManager()
{
    netManager = new QNetworkAccessManager(this);
    connect(netManager, SIGNAL(finished(QNetworkReply *)),this, SLOT(networkReplyFinished(QNetworkReply *)));
    //connect(this, SIGNAL(userLoginStatus(qint8)), SLOT(userLoginStatusHandler(qint8)));//登录状态
}

//用户登录操作
void NetworkManager::login(QString name, QString password)
{
    postGetCategory = PostGetCategory::postUserLogin;

    QUrl url(QString(HTTP_ADDRESS).append(LOGIN_PART_ADDRESS));
    Json::Value user;
    user["name"] = Json::Value(name.toStdString());
    user["password"] = Json::Value(password.toStdString());

    std::string data = user.toStyledString();
    httpPost(url, data);
}

//登录用户退出
void NetworkManager::logout()
{
    postGetCategory = PostGetCategory::postUserLogout;

    QUrl url(QString(HTTP_ADDRESS).append(LOGIN_PART_ADDRESS));
    std::string data = "";
    httpPost(url, data);
}

//查询用户详情
void NetworkManager::getUserDetailInfoRequest(qint32 id)
{
    postGetCategory = PostGetCategory::getUserDetailInfo;
    QUrl url = QString(HTTP_ADDRESS).append(USER_DETAIL_PART_ADDRESS)/*.append("?")
            .append(tr("id=%1").arg(id));*/;
    httpGet(url);
}

//查询用户列表
void NetworkManager::getUserListInfoRequest(qint32 page_index, qint32 page_size, qint32 group_id, qint32 group_category_id)
{
    postGetCategory = PostGetCategory::getUserListInfo;
    QUrl url = QString(HTTP_ADDRESS).append(USER_LIST_PART_ADDRESS)/*.append("?")
            .append(tr("page_index=%1").arg(page_index))
            .append(tr("&page_size=%1").arg(page_size))
            .append(tr("&group_id=%1").arg(group_id))
            .append(tr("&group_category_id=%1").arg(group_category_id));*/;
     httpGet(url);
}

//查询对讲详情
void NetworkManager::getIntercomDetailInfoRequest(qint32 id)
{
    postGetCategory = PostGetCategory::getIntercomDetailInfo;
    QUrl url = QString(HTTP_ADDRESS).append(USER_DETAIL_PART_ADDRESS)/*.append("?")
            .append(tr("id=%1").arg(id));*/;
    httpGet(url);
}

//查询对讲列表
void NetworkManager::getIntercomListInfoRequest(qint32 page_index, qint32 page_size,
                                     qint32 group_id, qint32 group_category_id)
{
    postGetCategory = PostGetCategory::getIntercomListInfo;
    QUrl url = QString(HTTP_ADDRESS).append(INTERCOM_LIST_PART_ADDRESS)/*.append("?")
            .append(tr("page_index=%1").arg(page_index))
            .append(tr("&page_size=%1").arg(page_size))
            .append(tr("&group_id=%1").arg(group_id))
            .append(tr("&group_category_id=%1").arg(group_category_id));*/;
    httpGet(url);
}

//查询组织详情
void NetworkManager::getGroupDetailInfoRequest(qint32 id)
{
    postGetCategory = PostGetCategory::getGroupDetailInfo;
    QUrl url = QString(HTTP_ADDRESS).append(GROUP_DETAIL_PART_ADDRESS)/*.append("?")
            .append(tr("id=%1").arg(id));*/;
    httpGet(url);
}

//查询组织列表
void NetworkManager::getGroupListInfoRequest(qint32 page_index, qint32 page_size)
{
    postGetCategory = PostGetCategory::getGroupListInfo;
    QUrl url = QString(HTTP_ADDRESS).append(GROUP_LIST_PART_ADDRESS)/*.append("?")
            .append(tr("page_index=%1").arg(page_index))
            .append(tr("&page_size=%1").arg(page_size));*/;
    httpGet(url);
}

//查询组织分类列表
void NetworkManager::getGroupCategoryListInfoRequest(qint32 id, qint32 page_index, qint32 page_size)
{
    postGetCategory = PostGetCategory::getGroupCategoryListInfo;
    QUrl url = QString(HTTP_ADDRESS).append(GROUP_CATEGORY_PART_ADDRESS)/*.append("?")
            .append(tr("id=%1").arg(id))
            .append(tr("&page_index=%1").arg(page_index))
            .append(tr("&page_size=%1").arg(page_size));*/;
    httpGet(url);
}

//查询会议详情
void NetworkManager::getMeetingDetailInfoRequest(qint32 id)
{
    postGetCategory = PostGetCategory::getMeetingDetailInfo;
    QUrl url = QString(HTTP_ADDRESS).append(MEETING_DETAIL_PART_ADDRESS)/*.append("?")
            .append(tr("id=%1").arg(id));*/;
    httpGet(url);
}

//查询会议列表
void NetworkManager::getMeetingListInfoRequest(qint32 page_index, qint32 page_size,
                                    qint32 group_id, qint32 group_category_id)
{
    postGetCategory = PostGetCategory::getMeetingListInfo;
    QUrl url = QString(HTTP_ADDRESS).append(MEETING_LIST_PART_ADDRESS)/*.append("?")
            .append(tr("page_index=%1").arg(page_index))
            .append(tr("&page_size=%1").arg(page_size))
            .append(tr("&group_id=%1").arg(group_id))
            .append(tr("&group_category_id=%1").arg(group_category_id));*/;
    httpGet(url);
}

//查询设备详情
void NetworkManager::getDeviceDetailInfoRequest(qint32 id)
{
    postGetCategory = PostGetCategory::getDeviceDetailInfo;
    QUrl url = QString(HTTP_ADDRESS).append(DEVICE_DETAIL_PART_ADDRESS)/*.append("?")
            .append(tr("id=%1").arg(id));*/;
    httpGet(url);
}

//查询设备列表
void NetworkManager::getDeviceListInfoRequest(qint32 page_index, qint32 page_size,
                                   qint32 group_id, qint32 group_category_id)
{
    postGetCategory = PostGetCategory::getDeviceListInfo;
    QUrl url = QString(HTTP_ADDRESS).append(DEVICE_LIST_PART_ADDRESS)/*.append("?")
            .append(tr("page_index=%1").arg(page_index))
            .append(tr("&page_size=%1").arg(page_size))
            .append(tr("&group_id=%1").arg(group_id))
            .append(tr("&group_category_id=%1").arg(group_category_id));*/;
    httpGet(url);
}

//查询报警详情
void NetworkManager::getAlarmDetailInfoRequest(qint32 id)
{
    postGetCategory = PostGetCategory::getAlarmDetailInfo;
    QUrl url = QString(HTTP_ADDRESS).append(ALARM_DETAIL_PART_ADDRESS)/*.append("?")
            .append(tr("id=%1").arg(id));*/;
    httpGet(url);
}

//查询报警列表
void NetworkManager::getAlarmListInfoRequest(qint32 page_index, qint32 page_size,
                                  qint32 type, quint64 from_time, quint64 to_time)
{
    postGetCategory = PostGetCategory::getAlarmListInfo;
    QUrl url = QString(HTTP_ADDRESS).append(ALARM_LIST_PART_ADDRESS)/*.append("?")
            .append(tr("page_index=%1").arg(page_index))
            .append(tr("&page_size=%1").arg(page_size))
            .append(tr("&type=%1").arg(type))
            .append(tr("&from_time=%1").arg(from_time))
            .append(tr("&to_time=%1").arg(to_time));*/;
    httpGet(url);
}

//查询配置
void NetworkManager::getConfigInfoRequest()
{
    postGetCategory = PostGetCategory::getConfigInfo;
    QUrl url(QString(HTTP_ADDRESS).append(CONFIG_PART_ADDRESS));
    httpGet(url);
}

//http post请求
void NetworkManager::httpPost(QUrl &url, string &str)
{
    QNetworkRequest request;
    request.setRawHeader("Content-Type", "application/json");
    request.setRawHeader("Platform", "5");
    request.setRawHeader("Client-Type", "2");

    request.setUrl(QUrl(url));
    netReply = netManager->post(request, QString::fromStdString(str).toUtf8());
    connect(netReply, SIGNAL(downloadProgress(qint64, qint64)), this, SLOT(downloadProgress(qint64, qint64)));
    connect(netReply, SIGNAL(error(QNetworkReply::NetworkError)),this, SLOT(networkReplyError(QNetworkReply::NetworkError)));

}

//http get请求
void NetworkManager::httpGet(QUrl &url)
{
    QNetworkRequest netRequest;
    netRequest.setRawHeader(QString(AUTHORIZATION).toUtf8(), httpRequestHeader.toUtf8());
    netRequest.setUrl(url);

    netReply = netManager->get(netRequest);
    connect(netReply, SIGNAL(downloadProgress(qint64, qint64)), this, SLOT(downloadProgress(qint64, qint64)));
    connect(netReply, SIGNAL(error(QNetworkReply::NetworkError)),this, SLOT(networkReplyError(QNetworkReply::NetworkError)));
}

//请求错误时错误处理
void NetworkManager::networkReplyError(QNetworkReply::NetworkError error)
{
    qDebug() << "NetworkReply error:" << error;
}

//获取各数据列表.依次获取
void NetworkManager::getListInfo()
{
    switch (postGetCategory) {
        case PostGetCategory::postUserLogin:
             getUserListInfoRequest();
            break;
        case PostGetCategory::getUserListInfo:
            getIntercomListInfoRequest();
           break;
        case PostGetCategory::getIntercomListInfo:
            getGroupListInfoRequest();
            break;
        case PostGetCategory::getGroupListInfo:
            getGroupCategoryListInfoRequest();
           break;
        case PostGetCategory::getGroupCategoryListInfo:
            getMeetingListInfoRequest();
           break;
        case PostGetCategory::getMeetingListInfo:
            getDeviceListInfoRequest();
            break;
        case PostGetCategory::getDeviceListInfo:
            getAlarmListInfoRequest();
            break;
        case PostGetCategory::getAlarmListInfo:
            getConfigInfoRequest();
            break;
        case PostGetCategory::getConfigInfo:
            getAllListInfoSuccessed();
            disconnect(this, SIGNAL(getListInfoSuccessed()), this, SLOT(getListInfo()));
            emit userLoginStatus(true);
            break;
        default: break;
    }
}

//reply finish
void NetworkManager::networkReplyFinished(QNetworkReply *reply)
{
    reply->deleteLater();
    reply = nullptr;

    PostGetReplyData.clear(); //清空数据
    emit getListInfoSuccessed();
}

//获取数据的经过
void NetworkManager::downloadProgress(qint64 bytesReceived, qint64 bytesTotal)
{
    qDebug() << "---recv:" <<bytesReceived << "---total:" << bytesTotal;

    //数据量大时，一次接收不完全,需要多次接收
    QNetworkReply *reply = static_cast<QNetworkReply *>(sender());
    PostGetReplyData += reply->read(reply->bytesAvailable());

    //接收完成
    if(bytesReceived == bytesTotal)
    {
        //qDebug() << PostGetReplyData;
        Json::Reader reader;
        Json::Value root;

        std::string totalData = QString::fromUtf8(PostGetReplyData).toStdString();
        if(reader.parse(totalData, root) && !root.isNull()){
            if(root["code"].asInt() == 0) //数据成功,解析数据
                parseJson(root["data"], postGetCategory);
            qDebug() << QString::fromStdString(root["msg"].asString());

            //当登录成功时,获取请求的头信息,以便用于后续的get请求功能
            if(postGetCategory == PostGetCategory::postUserLogin){
                httpRequestHeader = QString(AUTHORIZATION).append(":")+ QString(reply->rawHeader(QString(AUTHORIZATION).toUtf8()));
                connect(this, SIGNAL(getListInfoSuccessed()), this, SLOT(getListInfo()));
            }
        }else{
            qDebug() << QString::fromStdString(reader.getFormatedErrorMessages());
        }
    }
}

//分类解析请求的数据
void NetworkManager::parseJson(Json::Value &jsonValue, PostGetCategory category)
{
    switch (category) {
        case PostGetCategory::postUserLogin:
             parseJsonUserDetailInfo(jsonValue, m_userDetailInfo);
            break;
        case PostGetCategory::postUserLogout:
            break;
        case PostGetCategory::getUserDetailInfo:break;
        case PostGetCategory::getUserListInfo:
            parseJsonUserListInfo(jsonValue, m_userListInfo);
            break;
        case PostGetCategory::getIntercomDetailInfo:break;
        case PostGetCategory::getIntercomListInfo:
            parseJsonIntercomListInfo(jsonValue, m_intercomListInfo);
            break;
        case PostGetCategory::getGroupDetailInfo:break;
        case PostGetCategory::getGroupListInfo:
           parseJsonGroupListInfo(jsonValue, m_groupListInfo);
           break;
        case PostGetCategory::getGroupCategoryListInfo:
           parseJsonGroupCategoryListInfo(jsonValue, m_categoryListInfo);
           break;
        case PostGetCategory::getMeetingDetailInfo:break;
        case PostGetCategory::getMeetingListInfo:
            parseJsonMeetingListInfo(jsonValue, m_meetingListInfo);
            break;
        case PostGetCategory::getDeviceDetailInfo:break;
        case PostGetCategory::getDeviceListInfo:
            parseJsonDeviceListInfo(jsonValue, m_deviceListInfo);
            break;
        case PostGetCategory::getAlarmDetailInfo:break;
        case PostGetCategory::getAlarmListInfo:
            parseJsonAlarmListInfo(jsonValue, m_alarmListInfo);
            break;
        case PostGetCategory::getConfigInfo:
            parseJsonConfigInfo(jsonValue, m_configInfo);
           break;
        default: break;
    }
}

//解析用户详情
void NetworkManager::parseJsonUserDetailInfo(const Json::Value& object, userDetailType& userDetail)
{
    userDetail.id = object["id"].asInt();
    userDetail.nick = QString(object["nick"].asCString());
    userDetail.name = QString(object["name"].asCString());
    userDetail.phone = QString(object["phone"].asCString());
    userDetail.avatar = QString(object["avatar"].asCString());
    userDetail.group_id = object["group_id"].asInt();
    userDetail.group_category_id = object["group_category_id"].asInt();
    userDetail.im_name = QString(object["im_name"].asCString());
    userDetail.im_password = QString(object["im_password"].asCString());
    userDetail.sip_name = QString(object["sip_name"].asCString());
    userDetail.sip_password = QString(object["sip_password"].asCString());
    userDetail.live_id = object["live_id"].asInt();
    userDetail.live_push_url = QString(object["live_push_url"].asCString());
    userDetail.live_play_url = QString(object["live_play_url"].asCString());
    userDetail.live_rtmp_url = QString(object["live_rtmp_url"].asCString());
    userDetail.live_hls_url = QString(object["live_hls_url"].asCString());

    Json::Value jsonArray = object["roles"];
    for(const auto var: jsonArray){
        roleType role;
        role.id = var["id"].asInt();
        role.name = QString(var["name"].asCString());
        role.display_name = QString(var["display_name"].asCString());
        userDetail.roles.append(role);
        //qDebug() << role.display_name << role.name;
    }

    jsonArray = object["permissions"];
    for(const auto var: jsonArray){
        permissionType permisson;
        permisson.id = var["id"].asInt();
        permisson.name = QString(var["name"].asCString());
        permisson.display_name = QString(var["display_name"].asCString());
        userDetail.permissions.append(permisson);
        qDebug() << permisson.display_name << permisson.name;
    }
    qDebug() << "解析用户详情完成";
}

//解析get用户列表
void NetworkManager::parseJsonUserListInfo(const Json::Value& object, userListType& userList)
{
    userList.clear();
    userList.total = object["items"].size();
    //qDebug() << "items size" << userList.total;
    userDetailType userDetail;
    //Json::Value jsonArray = object["items"];
    for(const auto var: object["items"]){
        parseJsonUserDetailInfo(var, userDetail);
        userList.items.append(userDetail);
    }
    qDebug() << "解析用户列表完成";
}

//get解析组织列表
void NetworkManager::parseJsonGroupListInfo(const Json::Value& object, groupListType& groupList)
{
    groupList.clear();
    groupList.total = object["items"].size();
    for(const auto var: object["items"]){
        groupDetailType groupDetail;
        groupDetail.id = var["id"].asInt();
        groupDetail.name = QString::fromStdString(var["name"].asString());
        //groupDetail.created_at = var["created_at"].asInt();
        //groupDetail.updated_at = var["updated_at"].asInt();
        groupList.items.append(groupDetail);
    }
    qDebug() << "解析组织列表完成";
}

//get解析组织分类列表
void NetworkManager::parseJsonGroupCategoryListInfo(const Json::Value& object, categoryListType& categoryList)
{
    categoryList.clear();
    categoryList.total = object["items"].size();
    for(const auto var: object["items"]){
        groupCategoryDetailType groupCategoryDetail;
        groupCategoryDetail.id = var["id"].asInt();
        groupCategoryDetail.name = QString::fromStdString(var["name"].asString());
        groupCategoryDetail.group_id = var["group_id"].asInt();
        groupCategoryDetail.parent_id = var["parent_id"].asInt();
        //groupCategoryDetail.created_at = var["created_at"].asInt();
        //groupCategoryDetail.updated_at = var["updated_at"].asInt();
        categoryList.items.append(groupCategoryDetail);
    }
    qDebug() << "解析组织分类列表完成";
}

//get解析对讲详情
void NetworkManager::parseJsonIntercomDetailInfo(const Json::Value& object, intercomDetaiType& intercomDetail)
{
    intercomDetail.id = object["id"].asInt();
    intercomDetail.name = QString::fromStdString(object["name"].asString());
    intercomDetail.description = QString::fromStdString(object["description"].asString());
    //intercomDetail.created_at = object["created_at"].asInt();
    //intercomDetail.updated_at = object["updated_at"].asInt();
    intercomDetail.group_id = object["group_id"].asInt();
    intercomDetail.group_category_id = object["group_category_id"].asInt();
    //intercomDetail.scene_type_id = object["scene_type_id"].asInt();
    //intercomDetail.im_group_name = QString::fromStdString(object["im_group_name"].asString());

    qDebug() << "解析对讲详情完成";
}

//get解析对讲列表
void NetworkManager::parseJsonIntercomListInfo(const Json::Value& object, intercomListType& intercomList)
{
    intercomList.clear();
    intercomDetaiType intercomDetail;
    intercomList.total = object["items"].size();
    for(const auto var: object["items"])
    {
        parseJsonIntercomDetailInfo(var, intercomDetail);
        intercomList.items.append(intercomDetail);
    }

    qDebug() << "解析对讲列表完成";
}

//get解析会议详情
void NetworkManager::parseJsonMeetingDetailInfo(const Json::Value& object, meetingDetailType& meetingDetail)
{
    meetingDetail.id = object["id"].asInt();
    meetingDetail.name = QString(object["name"].asCString());
    //meetingDetail.description = QString(object["description"].asCString());
    //meetingDetail.created_at = object["created_at"].asInt();
    //meetingDetail.updated_at = object["updated_at"].asInt();
    meetingDetail.group_id = object["group_id"].asInt();
    meetingDetail.group_category_id = object["group_category_id"].asInt();
    meetingDetail.im_group_name = QString(object["im_group_name"].asCString());
    //meetingDetail.start_time = object["start_time"].asInt();
    //meetingDetail.end_time = object["end_time"].asInt();
    //meetingDetail.meeting_type_id = object["meeting_type_id"].asInt();
    //meetingDetail.business_type_id = object["business_type_id"].asInt();
    //meetingDetail.scene_type_id = object["scene_type_id"].asInt();
    meetingDetail.group_name = QString(object["group_name"].asCString());

    meetingDetail.video.code = QString::fromStdString(object["video"]["code"].asString());
    //meetingDetail.video.common_name = QString::fromStdString(object["video"]["common_name"].asString());
    meetingDetail.video.im_name = QString::fromStdString(object["video"]["im_name"].asString());
    meetingDetail.video.sip_name = QString::fromStdString(object["video"]["sip_name"].asString());
    meetingDetail.video.camera_id = object["video"]["camera_id"].asInt();
    meetingDetail.video.live_push_url = QString::fromStdString(object["video"]["live_push_url"].asString());
    meetingDetail.video.live_play_url = QString::fromStdString(object["video"]["live_play_url"].asString());
    meetingDetail.video.live_rtmp_url = QString::fromStdString(object["video"]["live_rtmp_url"].asString());
    meetingDetail.video.live_hls_url =  QString::fromStdString(object["video"]["live_hls_url"].asString());
    //meetingDetail.video.protocol_type_id = object["video"]["protocol_type_id"].asInt();
    //meetingDetail.video.video_type_id = object["video"]["video_type_id"].asInt();
    //meetingDetail.video.gb_device_type_id = object["video"]["gb_device_type_id"].asInt();

    //qDebug() << "video" << meetingDetail.video.code;

    if(!object["video"]["gb"].empty()){
        meetingDetail.video.gb.device_id = QString::fromStdString(object["video"]["gb"]["device_id"].asString());
        meetingDetail.video.gb.parent_id = QString::fromStdString(object["video"]["gb"]["parent_id"].asString());
    }

    qDebug() << "解析会议详情完成";
}

//get解析会议列表
void NetworkManager::parseJsonMeetingListInfo(const Json::Value& object, meetingListType& meetingList)
{
    meetingList.clear();
    meetingDetailType meetingDetail;
    meetingList.total = object["items"].size();
    qDebug() << "meeting list size:" << meetingList.total;
    for(const auto var: object["items"])
    {
        parseJsonMeetingDetailInfo(var, meetingDetail);
        meetingList.items.append(meetingDetail);
    }

    qDebug() << "解析会议列表完成";
}

//get解析设备详情
void NetworkManager::parseJsonDeviceDetailInfo(const Json::Value& object, deviceDetailType& deviceDetail)
{
    deviceDetail.id = object["id"].asInt();
    deviceDetail.code = QString(object["code"].asCString());
    deviceDetail.name = QString(object["name"].asCString());
    deviceDetail.is_active = object["is_active"].asBool();
    //deviceDetail.created_at = object["created_at"].asInt();
    //deviceDetail.updated_at = object["updated_at"].asInt();
    deviceDetail.device_type_id = object["device_type_id"].asInt();
    deviceDetail.device_type_name = QString(object["device_type_name"].asCString());
    deviceDetail.protocol_type_id = object["protocol_type_id"].asInt();
    deviceDetail.protocol_type_name = QString(object["protocol_type_name"].asCString());
    for(const auto var: object["group_ids"])
        deviceDetail.group_ids.append(var.asInt());
    for(const auto var: object["group_category_ids"])
        deviceDetail.group_category_ids.append(var.asInt());
    //deviceDetail.common_name = QString(object["common_name"].asCString());
    //deviceDetail.common_password = QString(object["common_password"].asCString());
    deviceDetail.im_name = QString(object["im_name"].asCString());
    deviceDetail.im_password = QString(object["im_password"].asCString());
    deviceDetail.sip_name = QString(object["sip_name"].asCString());
    deviceDetail.sip_password = QString(object["sip_password"].asCString());
    deviceDetail.live_id = QString(object["live_id"].asCString());
    deviceDetail.live_push_url = QString(object["live_push_url"].asCString());
    deviceDetail.live_play_url = QString(object["live_play_url"].asCString());
    deviceDetail.live_rtmp_url = QString(object["live_rtmp_url"].asCString());
    deviceDetail.live_hls_url = QString(object["live_hls_url"].asCString());
    //deviceDetail.longitude = object["longitude"].asDouble();
    //deviceDetail.latitude = object["latitude"].asDouble();
    //deviceDetail.address = QString(object["address"].asCString());
    deviceDetail.camera_id = object["camera_id"].asInt();
    deviceDetail.is_online = object["is_online"].asInt();
    //deviceDetail.show_location = object["show_location"].asInt();
    deviceDetail.gb_device_type_id = object["gb_device_type_id"].asInt();
    if(!object["gb"].empty()){
        deviceDetail.gb.device_id = QString::fromStdString(object["gb"]["device_id"].asString());
        deviceDetail.gb.parent_id = QString::fromStdString(object["gb"]["parent_id"].asString());
    }
    deviceDetail.group_names = QString(object["group_names"].asCString());
    //deviceDetail.ext_live_play = QString(object["ext_live_play"].asCString());
    //deviceDetail.video_type_name = QString(object["video_type_name"].asCString());

    qDebug() << "解析设备详情完成";
}

//get解析设备列表
void NetworkManager::parseJsonDeviceListInfo(const Json::Value& object, deviceListType& deviceList)
{
    deviceList.clear();
    deviceDetailType deviceDetail;
    deviceList.total = object["items"].size();
    for(const auto var: object["items"]){
        parseJsonDeviceDetailInfo(var, deviceDetail);
        deviceList.items.append(deviceDetail);
    }

    qDebug() << "解析设备列表完成";
}

//get解析报警详情
void NetworkManager::parseJsonAlarmDetailInfo(const Json::Value& object, alarmDetailType& alarmDetail)
{
    alarmDetail.id = object["id"].asInt();
    alarmDetail.platform = object["platform"].asInt();
    alarmDetail.platform_name = QString(object["platform_name"].asCString());
    alarmDetail.type = object["type"].asInt();
    alarmDetail.is_active = object["is_active"].asBool();
    alarmDetail.type_name = QString(object["type_name"].asCString());
    alarmDetail.reporting_mode_id = object["reporting_mode_id"].asInt();
    alarmDetail.reporting_mode_name = QString(object["reporting_mode_name"].asCString());
    for(const auto var: object["photos"]){
        alarmPhotoType photo;
        photo.photoName = QString::fromStdString(var.asString());
        alarmDetail.photos.append(photo);
    }
    //alarmDetail.common_name = QString(object["common_name"].asCString());
    //alarmDetail.name = QString(object["name"].asCString());
    //alarmDetail.code = QString(object["code"].asCString());
    //alarmDetail.published_at = object["published_at"].asInt();
    alarmDetail.address = QString(object["address"].asCString());
    alarmDetail.message = QString(object["message"].asCString());
    //alarmDetail.content.camera_id = object["camera_id"]["camera_id"].asInt();
    //alarmDetail.content.camera_ip = QString::fromStdString(object["camera_ip"]["camera_ip"].asString());
    //alarmDetail.content.camera_location = QString::fromStdString(object["camera_location"]["camera_location"].asString());
    //alarmDetail.content.rule = object["content"]["rule"].asInt();
    //alarmDetail.content.direction = object["content"]["direction"].asInt();
    alarmDetail.url = QString(object["url"].asCString());
    alarmDetail.im_group_name = QString(object["im_group_name"].asCString());
    //alarmDetail.concluded = object["concluded"].asBool();
    //alarmDetail.scene = QString(object["scene"].asCString());
    //alarmDetail.basic = QString(object["basic"].asCString());
    //alarmDetail.evidence = QString(object["evidence"].asCString());
    //alarmDetail.analysis = QString(object["analysis"].asCString());
    //alarmDetail.investigation_no = object["investigation_no"].asInt();
    qDebug() << "解析报警详情完成";
}

//get解析报警列表
void NetworkManager::parseJsonAlarmListInfo(const Json::Value& object, alarmListType& alarmList)
{
    alarmList.clear();
    alarmDetailType alarmDetail;
    alarmList.total = object["items"].size();
    for(const auto var: object["items"]){
        parseJsonAlarmDetailInfo(var, alarmDetail);
        alarmList.items.append(alarmDetail);
    }

    qDebug() << "解析报警列表完成";
}

//解析获取配置信息
void NetworkManager::parseJsonConfigInfo(const Json::Value& object, ConfigType& configDetail)
{
    configDetail.enable_sip = object["enable_sip"].asBool();
    configDetail.enable_agora = object["enable_agora"].asBool();
    configDetail.http_api_host = QString(object["http_api_host"].asCString());
    configDetail.http_api_port = object["http_api_port"].asInt();
    configDetail.https_api_host = QString(object["https_api_host"].asCString());
    configDetail.https_api_port = object["https_api_port"].asInt();
    configDetail.im_host = QString(object["im_host"].asCString());
    configDetail.im_port = object["im_port"].asInt();
    configDetail.sip_host = QString(object["sip_host"].asCString());
    configDetail.sip_port = object["sip_port"].asInt();
    configDetail.file_host = QString(object["file_host"].asCString());
    configDetail.file_port = object["file_port"].asInt();
    configDetail.ftp_host = QString(object["ftp_host"].asCString());
    configDetail.ftp_port = object["ftp_port"].asInt();
    configDetail.ftp_name = QString(object["ftp_name"].asCString());
    configDetail.ftp_pass = QString(object["ftp_pass"].asCString());
    configDetail.map_host = QString(object["map_host"].asCString());
    configDetail.map_port = object["map_port"].asInt();
    configDetail.templet_host = QString(object["templet_host"].asCString());
    configDetail.templet_port = object["templet_port"].asInt();
    configDetail.help_url = QString(object["help_url"].asCString());
    configDetail.treaty_url = QString(object["treaty_url"].asCString());
    configDetail.download_url = QString(object["download_url"].asCString());
    //configDetail.android_update
    //configDetail.ios_update;
    qDebug() << "解析配置详情完成";
}

//返回用户列表
userListType& NetworkManager::userListInfo()
{
    return m_userListInfo;
}

//返回分组列表
categoryListType& NetworkManager::categoryListInfo()
{
    return m_categoryListInfo;
}

//返回组列表
groupListType& NetworkManager::groupListInfo()
{
    return m_groupListInfo;
}

//返回互动列表
intercomListType& NetworkManager::intercomListInfo()
{
    return m_intercomListInfo;
}

//返回视频会议列表
meetingListType& NetworkManager::meetinglistInfo()
{
    return m_meetingListInfo;
}



