#ifndef ITEMEDITOR_H
#define ITEMEDITOR_H

#include <QWidget>
#include <QLabel>
#include <QPushButton>
#include <QHBoxLayout>

class ItemEditor : public QLabel
{
    Q_OBJECT
public:
    explicit ItemEditor(QWidget *parent = 0);

    QString meetingName();
    void setMeetingName(QString name);
signals:

public slots:
private:
    QLabel *m_meetingName;
    QPushButton *enterMeetingBtn;
};

#endif // ITEMEDITOR_H
