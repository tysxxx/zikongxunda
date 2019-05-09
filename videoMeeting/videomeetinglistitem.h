#ifndef VIDEOMEETINGLISTITEM_H
#define VIDEOMEETINGLISTITEM_H

#include <QStyledItemDelegate>
#include <QPushButton>
#include <QWidget>
#include <QPainter>
#include <QStyleOptionViewItem>
#include <QModelIndex>
#include <QAbstractItemModel>
#include "itemeditor.h"

class VideoMeetingListItem : public QStyledItemDelegate
{
public:
    VideoMeetingListItem();
    //创建编辑器
    QWidget *createEditor(QWidget *parent, const QStyleOptionViewItem &option, const QModelIndex &index) const override;

    //绘画
    void paint(QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index) const override;

    //设置编辑器数据
    void setEditorData(QWidget *editor, const QModelIndex &index) const override;

    //设置模型数据
    void setModelData(QWidget *editor, QAbstractItemModel *model, const QModelIndex &index) const override;

    //设置大小
    QSize sizeHint(const QStyleOptionViewItem &option, const QModelIndex &index) const override;

    //更新编辑器位置和大小
    void updateEditorGeometry(QWidget *editor, const QStyleOptionViewItem &option, const QModelIndex &index) const override;

private:
    QPushButton *enterMeetingBtn;
};

#endif // VIDEOMEETINGLISTITEM_H
