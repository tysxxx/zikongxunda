#include "videoinfotableui.h"
#include <QDebug>
#include <QStyleOption>
#include <QPainter>
#include <QHeaderView>
#include <QScrollBar>
#include <QHBoxLayout>

VideoInfoTableUi::VideoInfoTableUi(QRect rect)
{
    resize(rect.width(), rect.height());
    init();
}

VideoInfoTableUi::~VideoInfoTableUi()
{

}

//初始化
void VideoInfoTableUi::init()
{
    //设置表头
    QTableWidgetItem *headerItem;
    QStringList headerText({tr("文件"),tr("大小"), tr("开始时间") ,tr("结束时间"),tr("操作")});

    setColumnCount(headerText.count());
    for(int i=0; i < columnCount(); i++)
    {
        headerItem = new QTableWidgetItem(headerText.at(i));
        QFont font = headerItem->font();
        font.setBold(true);
        font.setPixelSize(20);
        headerItem->setTextColor(Qt::white);
        headerItem->setFont(font);
        headerItem->setTextAlignment(Qt::AlignCenter);
        setHorizontalHeaderItem(i, headerItem);
    }

    for(int i = 0; i < 50; i++){
        appendOneRow("hello", 32, "2222", "3333");
    }

    //设置列的宽度
    setColumnWidth(0, 435);
    setColumnWidth(1, 113);
    setColumnWidth(2, 217);
    setColumnWidth(3, 211);
    setColumnWidth(4, 105);
    verticalHeader()->setVisible(false);
    horizontalHeader()->setFocusPolicy(Qt::NoFocus);
    horizontalHeader()->setStyleSheet(".QHeaderView{background-color: transparent;}\
                                       .QHeaderView::section{background-color: transparent; border: 0.5px solid white;}");
    horizontalHeader()->setFixedHeight(60);

    setEditTriggers(QAbstractItemView::NoEditTriggers); //不可编辑
    setStyleSheet(".QTableWidget{background-color: transparent; border:none; font: 21px; color: white; text-align: center;}\
                   .QTableWidget::item{background-color: transparent;}");

    //设置滚动条
    verticalScrollBar()->setStyleSheet(".QScrollBar{background-color: gray; width:15px; border:2px solid white; border-radius:5px;}\
                                          .QScrollBar::handle{background: blue; border:2px solid blue; border-radius:5px;}\
                                          .QScrollBar::handle:hover{background:gray;}\
                                          .QScrollBar::sub-line{background:transparent; width: 0px; height: 0px;}\
                                          .QScrollBar::add-line{background:transparent; width: 0px; height: 0px;}");
}

//
void VideoInfoTableUi::appendOneRow(QString fileName, qint32 fileSize, QString startTime, QString endTime)
{
    QTableWidgetItem *item;
    auto rowCount = this->rowCount();
    setRowCount(rowCount+1);
    setRowHeight(rowCount, 60);
    //文件名
    item = new QTableWidgetItem(fileName, ctFileName);
    item->setTextAlignment(Qt::AlignCenter);
    setItem(rowCount, 0, item);

    //文件大小
    item = new QTableWidgetItem(QString::number(fileSize), ctFileSize);
    item->setTextAlignment(Qt::AlignCenter);
    setItem(rowCount, 1, item);

    //开始时间
    item = new QTableWidgetItem(startTime, ctStartTime);
    item->setTextAlignment(Qt::AlignCenter);
    setItem(rowCount, 2, item);

    //结束时间
    item = new QTableWidgetItem(endTime, ctEndTime);
    item->setTextAlignment(Qt::AlignCenter);
    setItem(rowCount, 3, item);

    //操作
   QPushButton *uploadBtn = new QPushButton(tr("上传"));
   QPushButton *queryBtn = new QPushButton(tr("查看"));
   QFrame *btnFrame = new QFrame;
   QHBoxLayout *btnHBoxLayout = new QHBoxLayout;
   btnHBoxLayout->setMargin(0);
   btnHBoxLayout->setSpacing(3);
   btnHBoxLayout->addWidget(uploadBtn);
   btnHBoxLayout->addWidget(queryBtn);
   btnFrame->setLayout(btnHBoxLayout);
   btnFrame->setStyleSheet(".QFrame{padding: 0px; margin: 0px;}");
   setCellWidget(rowCount, 4, btnFrame);

}

