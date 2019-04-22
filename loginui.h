#ifndef LOGINUI_H
#define LOGINUI_H

#include <QDialog>
#include <QPushButton>
#include <QLineEdit>
#include <QLabel>
#include <QObject>
#include "network/networkmanager.h"

class LoginUi : public QDialog
{
    Q_OBJECT
public:
    LoginUi(QWidget *parent = 0);
    ~LoginUi();

    QString loginUserName(){return loginUser->text();}
    QString loginUserPasswd(){return loginPasswd->text();}
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
};

#endif // LOGINUI_H
