#ifndef VEDIOMEETING_H
#define VEDIOMEETING_H

#include "./UI/ui_vediomeeting.h"

class vedioMeeting : public QDialog, private Ui::vedioMeeting
{
    Q_OBJECT

public:
    explicit vedioMeeting(QWidget *parent = 0);
};

#endif // VEDIOMEETING_H
