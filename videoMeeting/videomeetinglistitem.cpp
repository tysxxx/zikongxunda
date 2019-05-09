#include "videomeetinglistitem.h"
#include <QFrame>
#include <QHBoxLayout>
#include <QLabel>

VideoMeetingListItem::VideoMeetingListItem()
{

}

QWidget* VideoMeetingListItem::createEditor(QWidget *parent, const QStyleOptionViewItem &option, const QModelIndex &index) const
{
    return new ItemEditor;
}

void VideoMeetingListItem::paint(QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index) const
{
    if (!index.isValid() || option.state == QStyle::State_None || !index.isValid())
        return;

    painter->fillRect(option.rect, QColor("gray"));
}

void VideoMeetingListItem::setEditorData(QWidget *editor, const QModelIndex &index) const
{
    ItemEditor *itemEditor = qobject_cast<ItemEditor*>(editor);
    itemEditor->setMeetingName(index.data(Qt::DisplayRole).toString());
}

void VideoMeetingListItem::setModelData(QWidget *editor, QAbstractItemModel *model, const QModelIndex &index) const
{
     model->setData(index, dynamic_cast<ItemEditor*>(editor)->meetingName(), Qt::DisplayRole);
}

QSize VideoMeetingListItem::sizeHint(const QStyleOptionViewItem &option, const QModelIndex &index) const
{
    return QSize(100, 30);
}

void VideoMeetingListItem::updateEditorGeometry(QWidget *editor, const QStyleOptionViewItem &option, const QModelIndex &index) const
{
    dynamic_cast<ItemEditor*>(editor)->setFixedSize(option.rect.width(), option.rect.height());
    dynamic_cast<ItemEditor*>(editor)->move(option.rect.topLeft());
}

