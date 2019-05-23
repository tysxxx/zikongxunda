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

QString loadFontFamily();
#define FONT_PATH   "/mnt/Anyv/php/htdocs/storage/qt4.8_arm_share/lib/font/SourceHanSans-Regular.otf"
#define PLUGINS_LIB_PAHT "/mnt/Anyv/php/htdocs/storage/qt4.8_arm_share/plugins"

int main(int argc, char *argv[])
{
    zkCarDevEngine::instance()->fb0_init();

    QTextCodec::setCodecForTr(QTextCodec::codecForName("UTF-8"));
    QTextCodec::setCodecForLocale(QTextCodec::codecForName("UTF-8"));
    QTextCodec::setCodecForCStrings(QTextCodec::codecForName("UTF-8"));

    QWSServer::setBackground(Qt::transparent);

    QApplication app(argc, argv);
    app.setFont(loadFontFamily());
    QApplication::addLibraryPath(PLUGINS_LIB_PAHT); //显示jpg格式文件
    NoFocusRectStyle *style = new NoFocusRectStyle(app.style());//去掉控件被选中时的虚线框
    app.setStyle(style);

    UI ui;
    ui.initUi();

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
