#ifndef LOCALMONITORUI_H
#define LOCALMONITORUI_H

#include <QWidget>
#include <QGridLayout>
#include <QStackedLayout>
#include <QVector>
#include "common/common.h"
#include "hisiInterface/hisiinterface.h"
#include <QEvent>

class LocalMonitorUi : public QWidget
{
    Q_OBJECT
public:
    explicit LocalMonitorUi(QRect rect, QWidget *parent = 0);

    void paintEvent(QPaintEvent *);
    void init();
    void layoutSwitchHandler(LayoutMode layoutMode);
    void localVideoWinShow();
    bool eventFilter(QObject *, QEvent *);
signals:

public slots:

private:
    QGridLayout *gridLayout;
    QStackedLayout *gridLayoutStackedLayout;

    QVector<QWidget*> widgetVector;
    QVector<LayoutWindowInfoType*> layoutWindowInfoVector;
    quint8 row;
    quint8 column;
};

#endif // LOCALMONITORUI_H
