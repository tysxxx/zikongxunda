#include "vedioSearch.h"

list<FILE_PROPERTY_ST> vedioSearch::m_show_file_list;

vedioSearch::vedioSearch(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::vedioSearch)
{
    ui->setupUi(this);
    ui->lineEdit->setStyleSheet("QLineEdit{background-color:black;color: white;border-radius:10px;border:2px white;border-style: outset;}");
    ui->comboBox_channel->setView(new QListView());
    ui->comboBox_channel->setStyleSheet("QComboBox{background-color:black;color: white;border-radius:5px;border:2px white;border-style: outset;}"
                                        "QComboBox QAbstractItemView{ background-color:black;color: white;selection-background-color:rgb(0, 0, 255);height:200px;border-radius:10px;border:2px white;border-style: outset; }"
                                        "QComboBox QAbstractItemView::item {height:50px;min-height: 40px; min-width: 60px; }");
    ui->pushButton_search->setStyleSheet("QPushButton{background-color:black;color: white;border-radius:10px;border:2px white;border-style: outset;}"
                                         "QPushButton:hover{background-color:rgb(0, 0, 255);}");
    setDownloadButtonFocusStyle();
    setPlayButtonNoFocusStyle();
    ui->pushButton_dateTime->setStyleSheet("QPushButton{background-image: url(:/recordImg/resource/recordImg/日历.png);}");
    //ui->pushButton_dateTime->setStyleSheet("QPushButton{background-image: url(:/recordImg/resource/recordImg/日历.png);}"
      //                                                   "QPushButton:hover{background-image: url(:/recordImg/resource/recordImg/日历（选中）.png);}"
        //                                                 "QPushButton:pressed{background-image: url(:/recordImg/resource/recordImg/日历（选中）.png);}");

    m_strFormat = QString("yyyy-MM-dd hh:mm");
    m_dateTime = QDateTime::currentDateTime();
    QString text = m_dateTime.toString(m_strFormat);
    ui->lineEdit->setText(text);
    m_stackedWidget = new QStackedWidget(ui->widget);
    QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Preferred);
    sizePolicy.setHorizontalStretch(0);
    sizePolicy.setVerticalStretch(0);
    sizePolicy.setHeightForWidth(m_stackedWidget->sizePolicy().hasHeightForWidth());
    m_stackedWidget->setSizePolicy(sizePolicy);
    m_gridLayout = new QGridLayout(ui->widget);
    m_gridLayout->setSpacing(0);
    m_gridLayout->setContentsMargins(0, 0, 0, 0);
    m_gridLayout->addWidget(m_stackedWidget,0,0);
    m_stackedWidget->setStyleSheet("QStackedWidget{border:none; background-color:transparent;}");

    zkCarDevEngine::instance()->get_dev_list(&m_dev_list);
    list<DEVICEINFO_S>::iterator it = m_dev_list.begin();
    for(;it != m_dev_list.end();++it)
    {
        ui->comboBox_channel->addItem(tr((*it).devName));DEBUGLOG("devName:%s\n",(*it).devName);
    }
    ui->comboBox_channel->setCurrentIndex(0);

    m_lineCnt = 0;
    createTableView();
    creatMediaPlayer();
    m_stackedWidget->addWidget(m_tableView);
    m_stackedWidget->addWidget(m_playerWidget);
    m_stackedWidget->setCurrentIndex(0);

#if 1
    m_calendarWidget = new CalendarWidget();
    m_calendarWidget->setWindowFlags((Qt::FramelessWindowHint));
    //connect(ui->pushButton_dateTime, SIGNAL(clicked()), this,SLOT(showCalendarWidgetSlot()));
    //connect(m_calendarWidget,SIGNAL(dayClicked(const QDateTime&)),this,SLOT(dayClickedSlot(const QDateTime &)));
    //connect(ui->pushButton_dowload,SIGNAL(clicked()),this,SLOT(clickDownloadButtonSlot()));
    //connect(ui->pushButton_play,SIGNAL(clicked()),this,SLOT(clickPlayButtonSlot()));
    //connect(ui->pushButton_search,SIGNAL(clicked()),this,SLOT(clickSearchButtonSlot()));
#endif
   // loadUpdateMediasFileList();
}

void vedioSearch::setDownloadButtonFocusStyle()
{
    ui->pushButton_dowload->setStyleSheet("QPushButton{background-color:rgb(0, 0, 255);color: white;\
                                                                border-top-left-radius:10px;border-bottom-left-radius:10px;\
                                                                border-top-width:2px white;border-left-width:2px white;border-bottom-width:2px white;\
                                                                border-style: outset;}"
                                                               "QPushButton:hover{background-color:rgb(0, 0, 255);}"
                                               );
}

void vedioSearch::setDownloadButtonNoFocusStyle()
{
    ui->pushButton_dowload->setStyleSheet("QPushButton{background-color:rgb(0, 0, 0);color: white;\
                                                                border-top-left-radius:10px;border-bottom-left-radius:10px;\
                                                                border-top-width:2px white;border-left-width:2px white;border-bottom-width:2px white;\
                                                                border-style: outset;}"
                                                               "QPushButton:hover{background-color:rgb(0, 0, 255);}"
                                               );
}

void vedioSearch::setPlayButtonFocusStyle()
{
    ui->pushButton_play->setStyleSheet("QPushButton{background-color:rgb(0, 0, 255);color: white;\
                                               border-top-right-radius:10px;border-bottom-right-radius:10px;\
                                               border-top-width:2px white;border-right-width:2px white;border-bottom-width:2px white;\
                                               border-style: outset;}"
                                              "QPushButton:hover{background-color:rgb(0, 0, 255);}"
                                              );
}

void vedioSearch::setPlayButtonNoFocusStyle()
{
    ui->pushButton_play->setStyleSheet("QPushButton{background-color:rgb(0, 0, 0);color: white;\
                                               border-top-right-radius:10px;border-bottom-right-radius:10px;\
                                               border-top-width:2px white;border-right-width:2px white;border-bottom-width:2px white;\
                                               border-style: outset;}"
                                              "QPushButton:hover{background-color:rgb(0, 0, 255);}"
                                              );
}

void vedioSearch::paintEvent( QPaintEvent* )
{
//    QPainter p(this);
//    QPoint point;
//    p.setCompositionMode( QPainter::CompositionMode_Clear );
//    point = ui->widget->pos();

//    //DEBUGLOG("x:%d,y:%d,width:%d,hetght:%d\n",point.x(),point.y(),ui->widget->width(),ui->widget->height());
//    p.fillRect(point.x(),point.y(),ui->widget->width(),ui->widget->height(), Qt::SolidPattern );
}

bool vedioSearch::goToInitStatu()
{
    setPlayButtonNoFocusStyle();
    setDownloadButtonFocusStyle();
    m_stackedWidget->setCurrentIndex(0);
    m_playerWidget->closeMediaPlayer();
}

void vedioSearch::clickDownloadButtonSlot()
{
    setPlayButtonNoFocusStyle();
    setDownloadButtonFocusStyle();
    m_stackedWidget->setCurrentIndex(0);
    m_playerWidget->closeMediaPlayer();
}

void vedioSearch::clickPlayButtonSlot()
{
    setPlayButtonFocusStyle();
    setDownloadButtonNoFocusStyle();
    m_stackedWidget->setCurrentIndex(1);
    m_playerWidget->startMediaPlayer();
}

void vedioSearch::clickSearchButtonSlot()
{
    loadUpdateMediasFileList();
}

void vedioSearch::showCalendarWidgetSlot()
{
    QPoint pt(ui->pushButton_dateTime->pos().x(),ui->pushButton_dateTime->pos().y()+ui->pushButton_dateTime->height() + 4);
    pt = this->mapToGlobal(pt);

    m_calendarWidget->jumpToDateTime(m_dateTime);
    m_calendarWidget->move(pt);
    m_calendarWidget->show();
}

void vedioSearch::createTableView()
{
    m_tableView = new QTableView();

    QHeaderView tableHeaderView(Qt::Horizontal, m_tableView);
    QFont font;
    font.setPixelSize(50);
    tableHeaderView.setFont(font);
    m_tableView->setStyleSheet("background-color: transparent");


    m_standardItemModel = new QStandardItemModel();
    //添加表头
    m_standardItemModel->setColumnCount(5);
    m_standardItemModel->setHeaderData(0,Qt::Horizontal,QString::fromLocal8Bit("名称"));   //设置表头内容
    m_standardItemModel->setHeaderData(1,Qt::Horizontal,QString::fromLocal8Bit("大小"));
    m_standardItemModel->setHeaderData(2,Qt::Horizontal,QString::fromLocal8Bit("开始时间"));
    m_standardItemModel->setHeaderData(3,Qt::Horizontal,QString::fromLocal8Bit("结束时间"));
    m_standardItemModel->setHeaderData(4,Qt::Horizontal,QString::fromLocal8Bit("操作"));

    //m_standardItemModel->setRowCount(5);
    QList<QStandardItem*> standardItemList;
    QStandardItem *item1 = new QStandardItem;
    item1->setText("fileName");
    //QFont font;
    font.setPixelSize(20);
    item1->setFont(font);
    item1->setForeground(QBrush(QColor(0xff, 0x00, 0x00)));
    m_standardItemModel->setItem(0, 0, item1);
    QStandardItem *item2 = new QStandardItem;
    //standardItemList << &item;
    item2->setText("fileSize");
    item2->setFont(font);
    item2->setForeground(QBrush(QColor(0xff, 0x00, 0x00)));
    m_standardItemModel->setItem(0, 1, item2);
    //standardItemList << &item;
    QStandardItem *item3 = new QStandardItem;
    item3->setText("startTime");
    item3->setFont(font);
    item3->setForeground(QBrush(QColor(0xff, 0x00, 0x00)));
    m_standardItemModel->setItem(0, 2, item3);
    //standardItemList << &item;
    QStandardItem *item4 = new QStandardItem;
    item4->setText("endTime");
    item4->setFont(font);
    item4->setForeground(QBrush(QColor(0xff, 0x00, 0x00)));
    m_standardItemModel->setItem(0, 3, item4);
//    //standardItemList << &item;
//    //m_standardItemModel->insertRows(0, 0, &item);

   //QStandardItemModel model(4, 4);
//  for (int row = 0; row < 5; ++row) {
//      for (int column = 0; column < 4; ++column) {
//          QStandardItem *item = new QStandardItem(QString("row %0, column %1").arg(row).arg(column));
//          m_standardItemModel->setItem(row, column, item);
//      }
//  }



    //loadUpdateMediasFileList();

    QStringList headStringList;
    headStringList << "fileName" << "filesize" << "starttime" << "endtiem" << "operator";
    m_standardItemModel->setHorizontalHeaderLabels(headStringList);
    m_tableView->setModel(m_standardItemModel);    //挂载表格模型
    //向表格添加内容
    //FILE_PROPERTY_ST tmp_st;
    //list<FILE_PROPERTY_ST>::iterator it = m_show_file_list.begin();
    //for(it;it != m_show_file_list.end();it++)
    //{
    //    tmp_st = *it;
    //    addOneLine(&tmp_st);
    //}


    //设置表格属性
    m_tableView->horizontalHeader()->setDefaultAlignment(Qt::AlignCenter);        //表头信息显示居中

    m_tableView->setColumnWidth(0,600);       //设定表格第0列宽度
    m_tableView->setColumnWidth(1,200);
    m_tableView->setColumnWidth(2,300);
    m_tableView->setColumnWidth(3,300);
    m_tableView->setColumnWidth(4,200);
    m_tableView->verticalHeader()->setDefaultSectionSize(50);//设置行高
    //m_tableView->setLineWidth(50);//设置行宽
    //m_tableView->verticalHeader()->hide();    //隐藏默认显示的行头
    m_tableView->setSelectionBehavior(QAbstractItemView::SelectRows); //设置选中时整行选中
    m_tableView->setEditTriggers(QAbstractItemView::NoEditTriggers);  //设置表格属性只读，不能编辑
//  tableView->setContextMenuPolicy(Qt::CustomContextMenu);         //需要在表格使用右键菜单，需要启动该属性
//  tableView->sortByColumn(0,Qt::AscendingOrder);                 //表格第0列，按降序排列
    //此设置放到前面时会有些设置不生效，不知道为啥
   /* m_tableView->setStyleSheet("QHeaderView{background-color:blue;color:white;border: 2px white;}"
                               "QHeaderView::section:first{border-left:2px solid white;border-bottom:2px solid white;height:50px;font:50px;}"
                               "QHeaderView::section:middle{border-left:2px solid white;border-bottom:2px solid white;height:50px;font:20pt;}"
                               "QHeaderView::section:last{border-left:2px solid white;border-bottom:2px solid white;height:50px;font:20pt;}"
                               "QTableView{border:1px solid white;}"
                               //"QTableView::item{background:rgb(0,0,0);color:white;height:50px;font: 15pt;}"
                               "QTableView::item:selected{background:rgb(0,0,255);color:white;}"
                               "QScrollBar:horizontal{height:20px;background-color:rgb(69,69,69);margin:0px,0px,0px,0px;padding-left:20px;padding-right:20px;}"
                               "QScrollBar::handle:horizontal{height:20px;background:blue;border-radius:5px;}"
                               "QScrollBar::handle:horizontal:hover{height:20px;background:blue;border-radius:5px;}"
                               "QScrollBar::add-line:horizontal{height:20px;width:20px;subcontrol-position:right;}"
                               "QScrollBar::sub-line:horizontal{height:20px;width:20px;subcontrol-position:left;}"
                               "QScrollBar::add-line:horizontal:hover{height:20px;width:20px;subcontrol-position:right;}"
                               "QScrollBar::sub-line:horizontal:hover{height:20px;width:20px;subcontrol-position:left;}"
                               "QScrollBar::add-page:horizontal,QScrollBar::sub-page:horizontal{background:gray;border-radius:5px;}"
                               "QScrollBar:vertical{width:20px;background-color:rgb(69, 69, 69);margin:0px,0px,0px,0px;padding-top:20px;padding-bottom:20px;}"
                               "QScrollBar::handle:vertical{width:10px;background:blue ;border-radius:5px;min-height:20px;}"
                               "QScrollBar::handle:vertical:hover{width:20px;background:blue;border-radius:5px;min-height:20px;}"
                               "QScrollBar::add-line:vertical{height:20px;width:20px;subcontrol-position:bottom;}"
                               "QScrollBar::sub-line:vertical{height:20px;width:20px;subcontrol-position:top;}"
                               "QScrollBar::add-line:vertical:hover{height:20px;width:20px;subcontrol-position:bottom;}"
                               "QScrollBar::sub-line:vertical:hover{height:20px;width:20px;subcontrol-position:top;}"
                               "QScrollBar::add-page:vertical,QScrollBar::sub-page:vertical{background:gray;border-radius:5px;}"
                               ); */

}

void vedioSearch::dayClickedSlot(const QDateTime &dt)
{
    m_dateTime = dt;
    ui->lineEdit->setText(dt.toString(m_strFormat));
}

bool vedioSearch::addOneLine(FILE_PROPERTY_ST* p_fileProperty)
{
    if(p_fileProperty == NULL)
        return false;
    char startTime[50] = {0};
    char endTime[50] = {0};
    int i = 0;
    QFont font1;
    font1.setPointSize(18);
    for(i = strlen(p_fileProperty->fileName);i>0;--i)
    {
        if(*(p_fileProperty->fileName+i) == '.')
            break;
    }
    memcpy(startTime,p_fileProperty->fileName+i-19,19);
    DEBUGLOG("p_fileProperty->fileName:%s\n",p_fileProperty->fileName);
    QStandardItem *standItem1 = new QStandardItem(tr(p_fileProperty->fileName));
    QStandardItem *standItem2 = new QStandardItem(QString::fromLocal8Bit("%1MB").arg(QString::number((double)p_fileProperty->size / (1024 * 1024), 'f', 2)));
    QStandardItem *standItem3 = new QStandardItem(tr(startTime));
    QStandardItem *standItem4 = new QStandardItem(tr(endTime));
    m_standardItemModel->setItem(m_lineCnt,0,standItem1);                                //表格第i行，第0列添加一项内容
    m_standardItemModel->item(m_lineCnt,0)->setForeground(QBrush(QColor(255,255,255)));      //设置字符颜色
    m_standardItemModel->item(m_lineCnt,0)->setFont(font1);
    m_standardItemModel->item(m_lineCnt,0)->setTextAlignment(Qt::AlignCenter);           //设置表格内容居中
    m_standardItemModel->setItem(m_lineCnt,1,standItem2);
    m_standardItemModel->item(m_lineCnt,1)->setForeground(QBrush(QColor(255,255,255)));
    m_standardItemModel->item(m_lineCnt,1)->setFont(font1);
    m_standardItemModel->item(m_lineCnt,1)->setTextAlignment(Qt::AlignCenter);
    m_standardItemModel->setItem(m_lineCnt,2,standItem3);
    m_standardItemModel->item(m_lineCnt,2)->setForeground(QBrush(QColor(255,255,255)));
    m_standardItemModel->item(m_lineCnt,2)->setFont(font1);
    m_standardItemModel->item(m_lineCnt,2)->setTextAlignment(Qt::AlignCenter);
    m_standardItemModel->setItem(m_lineCnt,3,standItem4);
    m_standardItemModel->item(m_lineCnt,3)->setForeground(QBrush(QColor(255,255,255)));
    m_standardItemModel->item(m_lineCnt,3)->setFont(font1);
    m_standardItemModel->item(m_lineCnt,3)->setTextAlignment(Qt::AlignCenter);


    QPushButton* button = new QPushButton("上传");
    //m_button->setText(QObject::tr("上传"));
    button->setStyleSheet(QString::fromUtf8("background-color:blue;color: rgb(28, 247, 85);border-radius:5px;margin:5px 15px 5px 15px;font-size:15px;"));
    //触发上传按钮的槽函数
    connect(button, SIGNAL(clicked(bool)), this, SLOT(clickUploadButtonSlot()));
    button->setProperty("名称", tr(p_fileProperty->fileName));  //为按钮设置row属性
    button->setProperty("大小",QString::fromLocal8Bit("%1MB").arg(QString::number((double)p_fileProperty->size / (1024 * 1024), 'f', 2)));
    button->setProperty("开始时间",tr(startTime));
    button->setProperty("结束时间",tr(endTime));
    //setIndexWidget要生效，必须setModel(model)在它的前面，大多习惯有了数据后再设置model，请注意
    m_tableView->setIndexWidget(m_standardItemModel->index(m_standardItemModel->rowCount()-1, 4), button);

    ++m_lineCnt;
    return true;
}


void vedioSearch::clickUploadButtonSlot()
{
    QPushButton *btn = (QPushButton *)sender();   //产生事件的对象
    QString fileName = btn->property("名称").toString();  //取得按钮的名称属性
    QString startTime = btn->property("开始时间").toString();  //获取按钮的开始时间属性，其他的可以自行添加。
    qDebug()<<fileName<<" "<<startTime;
    char*  str_fileName;
    QByteArray ba_date = fileName.toLatin1();
    str_fileName = ba_date.data();
    //zkCarDevEngine::instance()->zkUploadFile(str_fileName,"ftp://192.168.110.203:2121");
    zkCarDevEngine::instance()->zkUploadFile(str_fileName, 0);
}

bool vedioSearch::deleteLine(int line,int cnt)
{
    m_standardItemModel->removeRows(line,cnt);//删除从第line行开始的连续cnt行
    return true;
}

bool vedioSearch::cleanTable()
{
    m_standardItemModel->removeRows(0,m_standardItemModel->rowCount());//删除从第line行开始的连续cnt行
    return true;
}

void vedioSearch::creatMediaPlayer()
{
    m_playerWidget = new mediaPlayer();

}

bool vedioSearch::loadUpdateMediasFileList()
{
    QString date = ui->lineEdit->text();
    char*  str_date;
    QByteArray ba_date = date.toLatin1();
    str_date = ba_date.data();
    memset(str_date+10,0,1);

    QString devName = ui->comboBox_channel->currentText();
    char*  str_devName;
    INPUT_DEV_TYPE_E devType;
    int devId = -1;
    QByteArray ba_devName = devName.toLatin1();
    str_devName = ba_devName.data();DEBUGLOG("devName:%s\n",str_devName);
    list<DEVICEINFO_S>::iterator it = m_dev_list.begin();
    for(;it != m_dev_list.end();++it)
    {
        if(strstr(str_devName,(*it).devName) != NULL)
        {
            devType = (*it).devType;
            devId = (*it).devId;DEBUGLOG("devType:%d,devId:%d,devName:%s\n",devType,devId,(*it).devName);
            break;
        }
    }
    m_show_file_list.clear();
    cleanTable();
    zkCarDevEngine::instance()->zkGetMp4FileList(devType,devId,str_date,&m_show_file_list);
    //zkCarDevEngine::instance()->zkGetMp4FileList(LOCAL_VEDIO,3,"2019-03-05",&m_show_file_list);
    DEBUGLOG("m_show_file_list.size():%d\n",m_show_file_list.size());
    FILE_PROPERTY_ST tmp_st;
    list<FILE_PROPERTY_ST>::iterator it1 = m_show_file_list.begin();
    for(it1;it1 != m_show_file_list.end();it1++)
    {
        tmp_st = *it1;
        addOneLine(&tmp_st);
    }
//    m_tableView->setStyleSheet("QHeaderView{background-color:black;color:white;border: 2px white;}"
//                               "QHeaderView::section:first{border-left:2px solid white;border-bottom:2px solid white;height:50px;font:15pt;}"
//                               "QHeaderView::section:middle{border-left:2px solid white;border-bottom:2px solid white;height:50px;font:15pt;}"
//                               "QHeaderView::section:last{border-left:2px solid white;border-bottom:2px solid white;height:50px;font:15pt;}"
//                               "QTableView{border:1px solid white;}"
//                               "QTableView::item{background:rgb(0,0,0);color:white;height:50px;font: 15pt;}"
//                               "QTableView::item:selected{background:rgb(0,0,255);color:white;}"
//                               "QScrollBar:horizontal{height:20px;background-color:rgb(69,69,69);margin:0px,0px,0px,0px;padding-left:20px;padding-right:20px;}"
//                               "QScrollBar::handle:horizontal{height:20px;background:blue;border-radius:5px;}"
//                               "QScrollBar::handle:horizontal:hover{height:20px;background:blue;border-radius:5px;}"
//                               "QScrollBar::add-line:horizontal{height:20px;width:20px;subcontrol-position:right;}"
//                               "QScrollBar::sub-line:horizontal{height:20px;width:20px;subcontrol-position:left;}"
//                               "QScrollBar::add-line:horizontal:hover{height:20px;width:20px;subcontrol-position:right;}"
//                               "QScrollBar::sub-line:horizontal:hover{height:20px;width:20px;subcontrol-position:left;}"
//                               "QScrollBar::add-page:horizontal,QScrollBar::sub-page:horizontal{background:gray;border-radius:5px;}"
//                               "QScrollBar:vertical{width:20px;background-color:rgb(69, 69, 69);margin:0px,0px,0px,0px;padding-top:20px;padding-bottom:20px;}"
//                               "QScrollBar::handle:vertical{width:10px;background:blue ;border-radius:5px;min-height:20px;}"
//                               "QScrollBar::handle:vertical:hover{width:20px;background:blue;border-radius:5px;min-height:20px;}"
//                               "QScrollBar::add-line:vertical{height:20px;width:20px;subcontrol-position:bottom;}"
//                               "QScrollBar::sub-line:vertical{height:20px;width:20px;subcontrol-position:top;}"
//                               "QScrollBar::add-line:vertical:hover{height:20px;width:20px;subcontrol-position:bottom;}"
//                               "QScrollBar::sub-line:vertical:hover{height:20px;width:20px;subcontrol-position:top;}"
//                               "QScrollBar::add-page:vertical,QScrollBar::sub-page:vertical{background:gray;border-radius:5px;}"
//                               );
    return m_playerWidget->updateMediasFileList(&m_show_file_list);
}

bool vedioSearch::getMediasFileList(list<FILE_PROPERTY_ST>* p_list)
{
    if(p_list == NULL)
        return false;
    list<FILE_PROPERTY_ST>::iterator it = m_show_file_list.begin();
    for(;it != m_show_file_list.end();++it)
    {
        p_list->push_back(*it);
    }
    return true;
}
