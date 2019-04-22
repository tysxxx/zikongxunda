#ifndef MEDIAPLAYER_H
#define MEDIAPLAYER_H

#include "./UI/ui_mediaplayer.h"
#include "window_common.h"


class mediaPlayer : public QDialog, private Ui::mediaPlayer
{
    Q_OBJECT

public:
    explicit mediaPlayer(QWidget *parent = 0);
    ~mediaPlayer();
    bool startMediaPlayer();
    bool closeMediaPlayer();
    bool updateMediasFileList(list<FILE_PROPERTY_ST>* p_list);
private:
    void paintEvent( QPaintEvent* );

private slots:
    void handleTimeout();
    void pushButton_play_click_slot();
    void pushButton_start_stop_click_slot();
    void pushButton_back_click_slot();
    void pushButton_ahead_click_slot();
private:
    Ui::mediaPlayer *ui;
    list<FILE_PROPERTY_ST> m_medias_file_list;
    QTimer *m_pTimer;
    int m_nMin;
    int m_nMax;
    int m_nSingleStep;
    bool m_playFlag;//暂停，播放标志，true：播放，false：暂停
    bool m_startFlag;//播放器开始播放标志
    bool m_mediaPlayerStatu;//播放器启动的状态，true：播放器已启动，false：播放器已关闭
};

#endif // MEDIAPLAYER_H
