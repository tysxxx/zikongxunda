#include "mainwidget.h"
#include <QApplication>
#include <QTextCodec>
#include <QDebug>
#include "nofocusrectstyle.h"
#include "zkCarDevEnginge.h"
#include <QFontDatabase>
#include <QFile>
#include <QtPlugin>
#include <QDesktopWidget>
#include "mainUI/mainui.h"

QString loadFontFamily();
#define FONT_PATH   "/mnt/Anyv/php/htdocs/storage/qt4.8_arm_share/lib/font/SourceHanSans-Regular.otf"
#define PLUGINS_LIB_PAHT "/mnt/Anyv/php/htdocs/storage/qt4.8_arm_share/plugins"

int main(int argc, char *argv[])
{
    zkCarDevEngine::instance()->fb0_init();

    QTextCodec::setCodecForTr(QTextCodec::codecForName("UTF-8"));
    QTextCodec::setCodecForLocale(QTextCodec::codecForName("UTF-8"));
    QTextCodec::setCodecForCStrings(QTextCodec::codecForName("UTF-8"));

    QWSServer::setBackground(QColor(0, 0, 0, 0));

    QApplication app(argc, argv);
    app.setFont(loadFontFamily());
    QApplication::addLibraryPath(PLUGINS_LIB_PAHT); //显示jpg格式文件
    NoFocusRectStyle *style = new NoFocusRectStyle(app.style());//去掉控件被选中时的虚线框
    app.setStyle(style);

    QRect rect;
    //获取屏幕尺寸
    QDesktopWidget *desktopWidget = QApplication::desktop();
    if(desktopWidget){
        rect = desktopWidget->availableGeometry();
        qDebug() << "availableGeometry: " << rect;
    }

//    MainWidget mainWidget;
//    mainWidget.setGeometry(rect);
//    mainWidget.init();//只有在show以后才能获取到窗口的真实尺寸
//    mainWidget.show();

    //rect.setWidth(rect.width()-1);
    MainUi mainUi(rect);
    mainUi.setGeometry(rect);
    mainUi.init();
    mainUi.show();

    return app.exec();
}


QString loadFontFamily()
{
   qDebug("loadFontFamily");
   QFile fontFilePath(FONT_PATH);
   if(!fontFilePath.exists())
    qDebug() << "font file not exist";

    QFontDatabase fontDatabase;
    int fontId = fontDatabase.addApplicationFont(FONT_PATH);
    if(fontId != -1){
        qDebug("font load success");
        return fontDatabase.applicationFontFamilies(fontId).at(0);
    }
    return QString();
}
