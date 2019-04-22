#include "loginui.h"
#include <QDebug>
#include <QVBoxLayout>
#include <QMessageBox>

LoginUi::LoginUi(QWidget *parent)
    :QDialog(parent)
{
    init();
}

LoginUi::~LoginUi()
{

}

//初始化
void LoginUi::init()
{
    setWindowFlags(Qt::CustomizeWindowHint | Qt::WindowCloseButtonHint);
    setWindowModality(Qt::ApplicationModal);
    setAttribute(Qt::WA_DeleteOnClose);
    setStyleSheet("background: rgba(255, 255, 255, 80%); width:320px; height: 360px");

    loginTitle = new QLabel(tr("登录"));
    loginTitle->setAlignment(Qt::AlignCenter);
    loginTitle->setLineWidth(10);
    QFont font = loginTitle->font();
    font.setLetterSpacing(QFont::AbsoluteSpacing, 10); //设置字体间隔
    loginTitle->setFont(font);
    loginTitle->setStyleSheet("font-size: 20px; ");

    loginUser = new QLineEdit;
    loginUser->setPlaceholderText("请输入账号");
    loginUser->setAlignment(Qt::AlignCenter);
    loginUser->setStyleSheet("font-size: 15px; height: 30px");

    loginPasswd = new QLineEdit;
    loginPasswd->setPlaceholderText("请输入密码");
    loginPasswd->setAlignment(Qt::AlignCenter);
    loginPasswd->setStyleSheet("font-size: 15px; height: 30px");

    loginBtn = new QPushButton;
    loginBtn->setText("登录");
    loginBtn->setStyleSheet("font-size: 15px; height: 30px; background-color:#6060cc;");

    logoutBtn = new QPushButton;
    logoutBtn->setText("退出");
    logoutBtn->setStyleSheet("font-size: 15px; width: 320px; height: 30px; background-color:#6060cc;");

    QVBoxLayout *vBoxLayout = new QVBoxLayout;
    vBoxLayout->setSpacing(20);
    vBoxLayout->addWidget(loginTitle);
    vBoxLayout->insertSpacing(1, 10);
    vBoxLayout->addWidget(loginUser);
    vBoxLayout->addWidget(loginPasswd);
    vBoxLayout->addWidget(loginBtn);
    vBoxLayout->addWidget(logoutBtn);
    setLayout(vBoxLayout);

    connect(loginBtn, SIGNAL(clicked()), this, SLOT(loginBtn_clicked_slot()));
    connect(logoutBtn, SIGNAL(clicked()), this, SLOT(logoutBtn_clicked_slot()));
}

//登录
void LoginUi::loginBtn_clicked_slot()
{
    qDebug("login");
    NetworkManager::instance()->login("xytest001", "123456");
    loginUser->setText("xytest001");
    loginPasswd->setText("123456");
//    if(loginUser->text().isEmpty() || loginPasswd->text().isEmpty()){
//        return;
//    }
//    NetworkManager::instance()->login(loginUser->text(), loginPasswd->text());
}


//退出
void LoginUi::logoutBtn_clicked_slot()
{
    qDebug("logout");
    NetworkManager::instance()->logout();
}
