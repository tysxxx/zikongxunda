#ifndef VIDEOINFOTABLEUI_H
#define VIDEOINFOTABLEUI_H

#include <QTableWidget>
#include <QWidget>
#include <QFrame>
#include <QPushButton>
#include "zkCarDevEnginge.h"
#include "zkdevdefine.h"

class VideoInfoTableUi : public QTableWidget
{
    Q_OBJECT
public:
    VideoInfoTableUi(QRect rect);
    ~VideoInfoTableUi();

    enum CellType{ctFileName = 1000, ctFileSize, ctStartTime, ctEndTime, ctOperator};
    void init();
    void appendOneRow(QString fileName, qint32 fileSize, QString startTime, QString endTime);

signals:
    void playSingleVideoFile(QString fileName);
private slots:
    void querySingleVideoBtnClickedSLot();
private:

};

#endif // VIDEOINFOTABLEUI_H
