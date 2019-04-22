#include "onescreen.h"

oneScreen::oneScreen(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::oneScreen)
{
    ui->setupUi(this);
    this->setAttribute(Qt::WA_TranslucentBackground,true);
    QWSServer::setBackground(QColor(0, 0, 0, 0));

}

oneScreen::~oneScreen()
{
    delete ui;
}
