#ifndef LOGINUI_H
#define LOGINUI_H

#include <QDialog>
#include <QPushButton>
#include <QLineEdit>
#include <QLabel>
#include <QObject>
#include <QCloseEvent>
#include <QSharedPointer>
#include "manager/manager.h"
#include "network/networkmanager.h"

class LoginUi : public QDialog
{
    Q_OBJECT
public:
    LoginUi(QWidget *parent = 0);
    ~LoginUi();

    void closeEvent(QCloseEvent *);

    QString loginUserName(){return loginUser->text();}
    QString loginUserPasswd(){return loginPasswd->text();}
signals:

private slots:
    void loginBtn_clicked_slot();
    void logoutBtn_clicked_slot();

private:
    void init();

    QLabel *loginTitle;
    QPushButton *loginBtn;
    QPushButton *logoutBtn;
    QLineEdit *loginUser;
    QLineEdit *loginPasswd;
    QSharedPointer<Manager> manager;
};

#endif // LOGINUI_H
