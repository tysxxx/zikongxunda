#include "videoinfotableui.h"
#include <QDebug>
#include <QStyleOption>
#include <QPainter>
#include <QHeaderView>
#include <QScrollBar>
#include <QHBoxLayout>

VideoInfoTableUi::VideoInfoTableUi(QRect rect)
{
    //resize(rect.width(), rect.height());
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

    for(int i = 0; i < 20; i++){
        appendOneRow("hello", 32, "2222", "3333");
    }
    for(int i = 0; i < 5; i++){
        appendOneRow("world", 32, "4444", "555");
    }

    //设置列的宽度
    setColumnWidth(0, 335);
    setColumnWidth(1, 113);
    setColumnWidth(2, 217);
    setColumnWidth(3, 211);
    //setColumnWidth(4, 105);
    verticalHeader()->setVisible(false);
    horizontalHeader()->setFocusPolicy(Qt::NoFocus);
    horizontalHeader()->setStyleSheet(".QHeaderView{background-color: transparent;}\
                                       .QHeaderView::section{background-color: transparent; border: 0.5px solid white;}");
    horizontalHeader()->setFixedHeight(60);
    horizontalHeader()->setStretchLastSection(true); //最后一项自动伸展

    setVerticalScrollMode(QAbstractItemView::ScrollPerItem);
    setEditTriggers(QAbstractItemView::NoEditTriggers); //不可编辑
    setSelectionBehavior(QAbstractItemView::SelectRows);
    setStyleSheet("QTableWidget{background-color: transparent; border:none; font: 21px; color: white; }\
                   QTableWidget::item{background-color: transparent;}");

    //设置滚动条
    verticalScrollBar()->setStyleSheet(".QScrollBar{background-color: gray; width:15px; border:2px solid white; border-radius:5px;}\
                                        .QScrollBar::handle{background: #649bf1; border:2px solid #649bf1; border-radius:5px;}\
                                        .QScrollBar::handle:hover{background: blue;}\
                                        .QScrollBar::sub-line{background:transparent; width: 0px; height: 0px;}\
                                        .QScrollBar::add-line{background:transparent; width: 0px; height: 0px;}");
}

//表格添加行数据
void VideoInfoTableUi::appendOneRow(QString fileName, qint32 fileSize, QString startTime, QString endTime)
{
    QTableWidgetItem *item;
    auto rowCount = this->rowCount();
    setRowCount(rowCount+1);
    setRowHeight(rowCount, 60);
    //文件名
    int index = fileName.lastIndexOf('&');
    QString file = fileName.mid(index); //获取文件名
    item = new QTableWidgetItem(file, ctFileName);
    item->setTextAlignment(Qt::AlignCenter);
    setItem(rowCount, 0, item);

    //文件大小
    QString fileSizeString;
    qreal fileSizeTmp = fileSize;
    if(fileSize >= 1000*1000){
        fileSizeTmp /= 1000*1000;
        fileSizeString = QString::number(fileSizeTmp,'f', 2) + "M";
    }else if(fileSize >= 1000){
        fileSizeTmp /=1000;
        fileSizeString = QString::number(fileSizeTmp,'f', 2) + "KB";
    }else{
        fileSizeString = QString::number(fileSize) + "B";
    }

    item = new QTableWidgetItem(fileSizeString, ctFileSize);
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
   uploadBtn->setFixedHeight(40);
   uploadBtn->setStyleSheet(".QPushButton{font:bold 20px; color: green; background-color: transparent;}\
                             .QPushButton:hover{ border: 1px solid #649bf1; border-radius: 5px;}");
   //uploadBtn->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Preferred);
   uploadBtn->setProperty("fileName", fileName);
   connect(uploadBtn, SIGNAL(clicked(bool)), SLOT(uploadFile()));

   QPushButton *queryBtn = new QPushButton(tr("查看"));
   queryBtn->setFixedHeight(40);
   queryBtn->setStyleSheet(".QPushButton{font:bold 20px; color: #649bf1; background-color: transparent}");
   //queryBtn->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Preferred);
   connect(queryBtn, SIGNAL(clicked()), this, SLOT(querySingleVideoBtnClickedSLot()));
   queryBtn->setProperty("fileName", fileName);

   QFrame *btnFrame = new QFrame;
   QHBoxLayout *btnHBoxLayout = new QHBoxLayout;
   btnHBoxLayout->setMargin(0);
   btnHBoxLayout->setSpacing(1);
   btnHBoxLayout->addWidget(uploadBtn);
   btnHBoxLayout->addWidget(queryBtn);
   btnFrame->setLayout(btnHBoxLayout);
   btnFrame->setStyleSheet(".QFrame{padding: 0px; padding-left: 2px; padding-right: 2px; margin: 0px;}");
   setCellWidget(rowCount, 4, btnFrame);

}

//播放单个视频按键
void VideoInfoTableUi::querySingleVideoBtnClickedSLot()
{
    QPushButton *button = qobject_cast<QPushButton*>(sender());
    playSingleVideoFile(button->property("fileName").toString());
}

//上传文件
void VideoInfoTableUi::uploadFile()
{
    QPushButton *button = qobject_cast<QPushButton*>(sender());
    zkCarDevEngine::instance()->zkUploadFile(button->property("fileName").toString().toUtf8().data(), "");
}

