#include "mediaplayer.h"

mediaPlayer::mediaPlayer(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::mediaPlayer)
{
    ui->setupUi(this);
    //ui->label_show->setAttribute(Qt::WA_TranslucentBackground,true);
    m_nMin = 0;
    m_nMax = 86400;
    m_nSingleStep = 1;
    m_startFlag = false;
    m_playFlag = false;
    m_mediaPlayerStatu = false;
    ui->label_show->setStyleSheet("QLabel{background-color:rgba(0,0,255,100%);border:3px white;}");
    //ui->horizontalSlider->setStyleSheet("QSlider{background-color:black;border-radius:2px;border-style: outset;}"
     //                                   "QSlider::handle:horizontal {background: green;width:6px;height:6px;border-radius:2px;border:none;}"
      //                                  "QSlider::groove:horizontal{height:5px;background:#ffffff;border-radius:3px;}"
       //                                 "QSlider::add-page:horizontal {border-radius :3px;background: #ffffff;}"
        //                                "QSlider::sub-page:horizontal {border-radius :3px;background-color:blue;}");
    ui->horizontalSlider->setStyleSheet("QSlider{background-color: #ff00ff;border-style: outset;border-radius: 10px;}"
                                        "QSlider::handle:horizontal {background:green;width: 6px;height: 10px;border-radius:8px;border: 1px solid #707070;}"
                                        "QSlider::groove:horizontal{height: 12px;background: qlineargradient(x1:0, y1:0, x2:0, y2:1, stop:0 #B1B1B1, stop:1 #c4c4c4);}"
                                        "QSlider::add-page:horizontal {border-radius :3px;background: #ffffff;}"
                                        "QSlider::sub-page:horizontal {border-radius :3px;background-color:blue;}");
    //ui->pushButton_play->setStyleSheet("QPushButton{background-image: url(:/recordImg/resource/recordImg/播放.png);}");
    ui->pushButton_show->setStyleSheet("QPushButton{background-image: url(:/recordImg/resource/recordImg/全屏.png);}");
    ui->pushButton_play->setStyleSheet("QPushButton{background-color:gray;color:black;border-radius:5px;}");
    ui->pushButton_back->setStyleSheet("QPushButton{background-color:gray;color:black;border-radius:5px;}");
    ui->pushButton_start_stop->setStyleSheet("QPushButton{background-color:gray;color:black;border-radius:5px;}");
    ui->pushButton_ahead->setStyleSheet("QPushButton{background-color:gray;color:black;border-radius:5px;}");
    ui->horizontalSlider->setMinimum(m_nMin);  // 最小值
    ui->horizontalSlider->setMaximum(m_nMax);  // 最大值
    ui->horizontalSlider->setSingleStep(m_nSingleStep);  // 步长
    ui->horizontalSlider->setValue(10);
    connect(ui->pushButton_play,SIGNAL(clicked()),this,SLOT(pushButton_play_click_slot()));
    connect(ui->pushButton_ahead,SIGNAL(clicked()),this,SLOT(pushButton_ahead_click_slot()));
    connect(ui->pushButton_start_stop,SIGNAL(clicked()),this,SLOT(pushButton_start_stop_click_slot()));
    connect(ui->pushButton_back,SIGNAL(clicked()),this,SLOT(pushButton_back_click_slot()));

    m_pTimer = new QTimer(this);
    connect(m_pTimer, SIGNAL(timeout()), this, SLOT(handleTimeout()));
}

mediaPlayer::~mediaPlayer()
{
    m_medias_file_list.clear();
    zkCarDevEngine::instance()->zkCloseMediasPlayer();
}

bool mediaPlayer::startMediaPlayer()
{
    RECT_ST rect;
    QPoint point;
    point = this->mapToGlobal(ui->label_show->pos());
    rect.s32X = point.x();
    rect.s32Y = point.y();
    rect.u32Width = ui->label_show->geometry().width();
    rect.u32Height = ui->label_show->geometry().height();
    if(rect.s32X%2 == 1)
        rect.s32X -= 1;
    if(rect.s32Y%2 == 1)
        rect.s32Y -= 1;
    if(rect.u32Width%2 == 1)
        rect.u32Width += 1;
    if(rect.u32Height%2 == 1)
        rect.u32Height += 1;DEBUGLOG("rect.s32X:%d,rect.s32Y:%d,rect.u32Width:%d,rect.u32Height:%d",rect.s32X,rect.s32Y,rect.u32Width,rect.u32Height);
    //rect.s32X = 300;
    //rect.s32Y = 300;
    //rect.u32Height = 600;
    //rect.u32Width = 900;
    zkCarDevEngine::instance()->zkStartMediaPlayer(1,&rect);
    m_mediaPlayerStatu = true;

    m_pTimer->start(1000);
}

bool mediaPlayer::closeMediaPlayer()
{
    if(m_mediaPlayerStatu)
    {
        m_pTimer->stop();
        ui->label_show->setStyleSheet("QLabel{background-color:rgba(0,0,255,100%);border:3px white;}");
        zkCarDevEngine::instance()->zkEndPlayMedias();
        m_startFlag = false;
        zkCarDevEngine::instance()->zkCloseMediasPlayer();
        m_mediaPlayerStatu = false;
    }
}

bool mediaPlayer::updateMediasFileList(list<FILE_PROPERTY_ST>* p_list)
{
    if(p_list == NULL)
        return false;
    ui->label_show->setStyleSheet("QLabel{background-color:rgba(0,0,255,100%);border:3px white;}");
    zkCarDevEngine::instance()->zkEndPlayMedias();

    m_medias_file_list.clear();
    list<FILE_PROPERTY_ST>::iterator it = p_list->begin();
    for(;it != p_list->end();++it)
    {
        m_medias_file_list.push_back(*it);
    }
    DEBUGLOG("更新播单!\n");


    return true;
}

void mediaPlayer::paintEvent( QPaintEvent* )
{
    QPainter p(this);
    QPoint point;
    p.setCompositionMode( QPainter::CompositionMode_Clear );
    point = ui->label_show->pos();

    //DEBUGLOG("x:%d,y:%d,width:%d,hetght:%d\n",point.x(),point.y(),ui->label_show->width(),ui->label_show->height());
    p.fillRect(point.x(),point.y(),ui->label_show->width(),ui->label_show->height(), Qt::SolidPattern );
}

void mediaPlayer::handleTimeout()
{
    int time = zkCarDevEngine::instance()->zkGetMediasPlayTime();
    ui->horizontalSlider->setValue(time);
    //DEBUGLOG("sec:%d\n",time);
}

void mediaPlayer::pushButton_play_click_slot()
{
    m_pTimer->stop();
    ui->label_show->setStyleSheet("QLabel{background-color:rgba(0,0,255,100%);border:3px white;}");
    zkCarDevEngine::instance()->zkEndPlayMedias();
    m_startFlag = false;
}

void mediaPlayer::pushButton_start_stop_click_slot()
{
    if(!m_mediaPlayerStatu)
    {
        startMediaPlayer();
    }

    if(!m_startFlag)
    {
        m_pTimer->start(1000);
        ui->label_show->setStyleSheet("QLabel{background-color:rgba(0,0,255,0%);border:3px white;}");
        zkCarDevEngine::instance()->zkPlayMedias(&m_medias_file_list);
        m_startFlag = true;
        DEBUGLOG("开始播放录像!,m_medias_file_list.size:%d\n",m_medias_file_list.size());
        return;
    }

    zkCarDevEngine::instance()->zkStopPlayMedias();
}

void mediaPlayer::pushButton_back_click_slot()
{
    zkCarDevEngine::instance()->zkPlayMediasBack(m_nSingleStep);

}

void mediaPlayer::pushButton_ahead_click_slot()
{
    zkCarDevEngine::instance()->zkPlayMediasAhead(m_nSingleStep);

}
