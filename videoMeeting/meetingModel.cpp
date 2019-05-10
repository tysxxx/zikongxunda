#include "meetingModel.h"
#include <QDebug>

MeetingListModel::MeetingListModel(QObject *parent)
    : QAbstractListModel(parent)
{
    headerList << "视频会议列表";
}

MeetingListModel::~MeetingListModel()
{

}

//设置头
QVariant MeetingListModel::headerData( int section, Qt::Orientation orientation,int role) const
{
    //if((orientation == Qt::Horizontal) && (role == Qt::DisplayRole)){
        return headerList[section];
    //}else
    //    return QVariant();
}

bool MeetingListModel::setHeaderData(int section, Qt::Orientation orientation, const QVariant &value, int role)
{
    //if((orientation == Qt::Horizontal) && (role == Qt::DisplayRole)){
        headerList[section] = value.toString();
        return true;
    //}else
    //    return false;
}

//返回行数
int MeetingListModel::rowCount(const QModelIndex &parent) const
{
    Q_UNUSED(parent)
    return meetingNameList.count();
}

bool MeetingListModel::insertRows(int row, int count, const QModelIndex &parent)
{

}

bool MeetingListModel::removeRows(int row, int count, const QModelIndex &parent)
{

}

//返回索引节点的值
QVariant MeetingListModel::data(const QModelIndex &index, int role) const
{
//    if (role != Qt::DisplayRole)
//        return QVariant();

//    if (!index.isValid())
//        return QVariant();

    return  meetingNameList[index.row()];
}

//设置值
bool MeetingListModel::setData(const QModelIndex &index, const QVariant &value, int role)
{
//    if(!index.isValid())
//        return false;

//    if(data(index, role) != value) {
        meetingNameList[index.row()] = value.toString();
        return true;
    //}
    //return false;
}

//标记
Qt::ItemFlags MeetingListModel::flags(const QModelIndex &index) const
{
//    if (!index.isValid())
//        return Qt::NoItemFlags;

    return Qt::ItemIsSelectable | Qt::ItemIsEnabled | Qt::ItemIsEditable;
}

//返回角色名
QHash<int, QByteArray> MeetingListModel::roleNames() const
{
//    QHash<int, QByteArray> rolesNames;
//    rolesNames[nameRole] = "name";
//    return rolesNames;
}

//设置模型数据
void MeetingListModel::setMeetingListModelData(QStringList &list)
{
    beginResetModel ();
    meetingNameList = list;
    endResetModel();
}









