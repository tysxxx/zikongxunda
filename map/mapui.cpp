#include "mapui.h"
#include <QWebView>

MapUi::MapUi(QRect rect, QWidget *parent) : QWidget(parent)
{
    setGeometry(rect);

}

//初始化
void MapUi::init()
{
    QWebView *view = new QWebView(this);
    view->load(QUrl("http://www.gov.cn/"));
    view->resize(this->rect().width(), this->rect().height());
    view->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    view->show();
}

