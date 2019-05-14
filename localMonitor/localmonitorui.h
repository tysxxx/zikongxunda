#ifndef LOCALMONITORUI_H
#define LOCALMONITORUI_H

#include <QWidget>
#include <QGridLayout>
#include <QStackedLayout>

class LocalMonitorUi : public QWidget
{
    Q_OBJECT
public:
    explicit LocalMonitorUi(QRect rect, QWidget *parent = 0);

    void paintEvent(QPaintEvent *);
    void init();
signals:

public slots:

private:
    QGridLayout *gridLayout;
    QStackedLayout *gridLayoutStackedLayout;
};

#endif // LOCALMONITORUI_H
