#include "electronicMap.h"


electronicMap::electronicMap(QWidget *parent) :
    QDialog(parent)
{
    setupUi(this);


    QString strMapPath="file:///";
    strMapPath+=QCoreApplication::applicationDirPath();
    strMapPath+="/map.html";
    QUrl url(strMapPath);
    viewr = new QWebView(this);
    //viewr = ui->webView;//解决页面显示不全的问题
    m_gridLayout = new QGridLayout(this);
    m_gridLayout->setSpacing(0);
    m_gridLayout->setContentsMargins(0, 0, 0, 0);
    m_gridLayout->addWidget(viewr,0,0);
    viewr->setStyleSheet(QString::fromUtf8("background-color: rgb(34, 45, 67);"));
    viewr->load(url);
    viewr->setContentsMargins(0,0,0,0);
    viewr->setTextSizeMultiplier(1);//设置网页字体大小
    viewr->show();
    connect(viewr->page()->mainFrame(), SIGNAL(javaScriptWindowObjectCleared()),this, SLOT(slotPopulateJavaScriptWindowObject()));


}


void electronicMap::handleSslErrors(QNetworkReply* reply, const QList<QSslError> &errors)
{
    qDebug() << "handleSslErrors: ";
    foreach (QSslError e, errors)
    {
        qDebug() << "ssl error: " << e;
    }

    reply->ignoreSslErrors();
}

bool electronicMap::showMap()
{
    this->show();
    return true;
}

bool electronicMap::setWindowRect(RECT_ST* rect)
{
    if(rect == NULL)
        return false;
    viewr->setGeometry(QRect(rect->s32X,rect->s32Y,rect->u32Width,rect->u32Height));
    return true;
}


void electronicMap::mousePressEvent(QMouseEvent *event){
    QWebFrame *frame = viewr->page()->mainFrame();
    if(event->button()==Qt::LeftButton){  //判断是否是左键点击
        printf("press leftButton\n");
        QString cmd = QString("moveMap(-10,-10)");
        frame->evaluateJavaScript(cmd);

    }else {
        printf("press rigthButton\n");
        QString cmd = QString("moveMap(10,10)");
        frame->evaluateJavaScript(cmd);
    }
}

void electronicMap::wheelEvent(QWheelEvent * event)
{
    QWebFrame *frame = viewr->page()->mainFrame();

    if(event->delta() > 0){
        QString cmd = QString("zoomInMap()");//放大
        frame->evaluateJavaScript(cmd);
    }else{
        QString cmd = QString("zoomOutMap()");//缩小
        frame->evaluateJavaScript(cmd);
    }

    event->accept();
}


void electronicMap::mouseMoveEvent(QMouseEvent *event)
{
    this->repaint();
}

void electronicMap::slotPopulateJavaScriptWindowObject()
{
    viewr->page()->mainFrame()->addToJavaScriptWindowObject("ReinforcePC", this);
}
