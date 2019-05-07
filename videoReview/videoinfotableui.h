#ifndef VIDEOINFOTABLEUI_H
#define VIDEOINFOTABLEUI_H

#include <QTableWidget>
#include <QWidget>
#include <QFrame>
#include <QPushButton>

class VideoInfoTableUi : public QTableWidget
{
    enum CellType{ctFileName = 1000, ctFileSize, ctStartTime, ctEndTime, ctOperator};
public:
    VideoInfoTableUi(QRect rect);
    ~VideoInfoTableUi();

    void init();
//    void paintEvent(QPaintEvent *);
    void appendOneRow(QString fileName, qint32 fileSize, QString startTime, QString endTime);
private:

};

#endif // VIDEOINFOTABLEUI_H
