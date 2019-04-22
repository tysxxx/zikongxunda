#include "fourscreen.h"

fourScreen::fourScreen(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::fourScreen)
{
    ui->setupUi(this);
    this->setAttribute(Qt::WA_TranslucentBackground,true);
    QWSServer::setBackground(QColor(0, 0, 0, 0));
}

fourScreen::~fourScreen()
{
    delete ui;
}
