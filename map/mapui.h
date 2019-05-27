#ifndef MAPUI_H
#define MAPUI_H

#include <QWidget>

class MapUi : public QWidget
{
    Q_OBJECT
public:
    explicit MapUi(QRect rect, QWidget *parent = 0);

    void init();
signals:

public slots:
};

#endif // MAPUI_H
