#include <QApplication>
#include <QTextCodec>
#include <QDebug>
#include "zkCarDevEnginge.h"
#include <QFontDatabase>
#include <QFile>
#include <QtPlugin>
#if (QT_VERSION <= QT_VERSION_CHECK(5,0,0))
#include <QWSServer>
#endif
#include <QDesktopWidget>
#include "mainUI/mainui.h"
#include "common/nofocusrectstyle.h"
#include "manager/ui.h"
#include "common/keyborder.h"
#include "test.h"

QString loadFontFamily();
#define FONT_PATH   "/mnt/Anyv/php/htdocs/storage/qt4.8_arm_share/lib/font/SourceHanSans-Regular.otf"
#define PLUGINS_LIB_PAHT "/mnt/Anyv/php/htdocs/storage/qt4.8_arm_share/plugins"

int main(int argc, char *argv[])
{
    zkCarDevEngine::instance()->fb0_init();

    //设置编解码
    QTextCodec::setCodecForTr(QTextCodec::codecForName("UTF-8"));
    QTextCodec::setCodecForLocale(QTextCodec::codecForName("UTF-8"));
    QTextCodec::setCodecForCStrings(QTextCodec::codecForName("UTF-8"));

    //设备背景色
    QWSServer::setBackground(Qt::transparent);

    //应用程序
    QApplication app(argc, argv);

    //设置字体
    app.setFont(loadFontFamily());
    //加载库
    QApplication::addLibraryPath(PLUGINS_LIB_PAHT); //显示jpg格式文件
    NoFocusRectStyle *style = new NoFocusRectStyle(app.style());//去掉控件被选中时的虚线框
    app.setStyle(style);
    //加载键盘
    KeyBorder::instance()->init();

    UI ui;
    ui.initUi();
    //Test test;
    //test.show();


    int ret = app.exec();

    KeyBorder::destroyInstance();
    return ret;
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
