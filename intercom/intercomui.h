#ifndef INTERCOMUI_H
#define INTERCOMUI_H

#include <QWidget>
#include <QPushButton>
#include <QButtonGroup>


class IntercomUi : public QWidget
{
    Q_OBJECT
public:
    explicit IntercomUi(QWidget *parent = nullptr);
    ~IntercomUi();

    void init();
    void paintEvent(QPaintEvent *);
signals:

private slots:
    void btnClickedSlot(QAbstractButton* button);
private:
    QPushButton *userInteractBtn;
    QPushButton *groupInteractBtn;
    QButtonGroup *buttonGroup;
    int lastBtnId;
};

#endif // INTERCOMUI_H
