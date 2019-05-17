#ifndef LOCALMONITORUI_H
#define LOCALMONITORUI_H

#include <QWidget>
#include <QGridLayout>
#include <QStackedLayout>
#include <QVector>
#include <QEvent>
#include "common/common.h"
#include "manager/manager.h"

class LocalMonitorUi : public QWidget
{
    Q_OBJECT
public:
    LocalMonitorUi(QRect rect = QRect(), QWidget *parent = 0);

    void init();

    bool eventFilter(QObject *, QEvent *);
signals:

public slots:
    void layoutSwitchHandler(LayoutMode layoutMode);
private:
    QGridLayout *gridLayout;
    QStackedLayout *gridLayoutStackedLayout;

    LayoutMode currLayoutMode;
    QVector<LayoutWindowInfoType> layoutWindowInfoVector;
    quint8 row;
    quint8 column;
    QSharedPointer<Manager> manager;

    quint32 addWindId = 0;
};

#endif // LOCALMONITORUI_H
