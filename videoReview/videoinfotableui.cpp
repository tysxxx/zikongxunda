#include "videoinfotableui.h"

VideoInfoTableUi::VideoInfoTableUi()
{
    init();
}

VideoInfoTableUi::~VideoInfoTableUi()
{

}

void VideoInfoTableUi::init()
{
    QTableWidgetItem *headerItem;
    QStringList headerText;
    headerText << "文件" << "大小" << "开始时间" << "结束时间" << "操作";
    setColumnCount(headerText.count());

    for(int i=0; i < columnCount(); i++)
    {
        headerItem = new QTableWidgetItem(headerText.at(i));
        QFont font = headerItem->font();
        font.setBold(true);
        font.setPixelSize(20);
        headerItem->setTextColor(Qt::red);
        headerItem->setFont(font);
        headerItem->setTextAlignment(Qt::AlignCenter);
        setHorizontalHeaderItem(i, headerItem);
    }
}

