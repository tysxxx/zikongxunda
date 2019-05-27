#ifndef SETTINGUI_H
#define SETTINGUI_H

#include <QWidget>

class SettingUi : public QWidget
{
    Q_OBJECT
public:
    explicit SettingUi(QRect rect, QWidget *parent = 0);

    void init();
signals:

public slots:
};

#endif // SETTINGUI_H
