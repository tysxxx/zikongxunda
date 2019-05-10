#ifndef TREEMODEL_H
#define TREEMODEL_H

#include <QAbstractListModel>
#include <QList>
#include <QHash>
#include <QStringList>

class MeetingListModel : public QAbstractListModel
{
    Q_OBJECT
public:
    explicit MeetingListModel(QObject *parent = nullptr);
    ~MeetingListModel() override;

    enum MeetingListRoles{
          nameRole=Qt::UserRole+1
    };

    //头相关
    QVariant headerData ( int section, Qt::Orientation orientation,int role = Qt::DisplayRole) const override;
    bool setHeaderData ( int section, Qt::Orientation orientation, const QVariant & value, int role = Qt::EditRole) override;
    //行数
    int rowCount(const QModelIndex &parent = QModelIndex()) const override;
    bool insertRows(int row, int count, const QModelIndex &parent = QModelIndex()) override;
    bool removeRows(int row, int count, const QModelIndex &parent = QModelIndex()) override;
    //数据
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;
    bool setData(const QModelIndex &index, const QVariant &value, int role = Qt::EditRole) override;
    Qt::ItemFlags flags(const QModelIndex &index) const override;
    QHash<int, QByteArray> roleNames() const;

    void setMeetingListModelData(QStringList &list);
private:
    QHash<int, QByteArray> mRoleName;
    QStringList headerList;
    QStringList meetingNameList;
};

Q_DECLARE_METATYPE(MeetingListModel*)
#endif // TREEMODEL_H
