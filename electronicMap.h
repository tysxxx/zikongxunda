#ifndef ELECTRONICMAP_H
#define ELECTRONICMAP_H

#include "./UI/ui_electronicmap.h"
#include <QtWebKit/QWebView>
#include <QUrl>
#include <QtWebKit/QWebPage>
#include <QtWebKit/QWebFrame>
#include <QMouseEvent>
#include<QWheelEvent>
#include <QNetworkReply>
#include <QNetworkRequest>
#include <QNetworkAccessManager>
#include <QSslConfiguration>
#include <QSslError>
#include "window_common.h"

class electronicMap : public QDialog, private Ui::electronicMap
{
    Q_OBJECT

public:
    explicit electronicMap(QWidget *parent = 0);
    bool showMap();
    bool setWindowRect(RECT_ST* rect);

public slots:
    void slotPopulateJavaScriptWindowObject();
    void handleSslErrors(QNetworkReply* reply, const QList<QSslError> &errors);


private:
    QWebView* viewr;
    QGridLayout* m_gridLayout;
private:

    void wheelEvent(QWheelEvent * event);
    void mousePressEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);
};

#endif // ELECTRONICMAP_H
