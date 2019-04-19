#include "mainwidget.h"
#include <QApplication>
#include <QTextCodec>
#include <QDebug>
//#include "../hisi3531aLib/zkdevdefine.h"
//#include "../hisi3531aLib/zkCarDevEnginge.h"
#include "nofocusrectstyle.h"
#include "zkCarDevEnginge.h"
#include <QFontDatabase>
#include <QFile>

QString loadFontFamily();
#define FONT_PATH   "/mnt/Anyv/php/htdocs/storage/qt4.8_arm_share/lib/font/SourceHanSans-Regular.otf"

int main(int argc, char *argv[])
{
    zkCarDevEngine::instance()->fb0_init();

    QTextCodec::setCodecForTr(QTextCodec::codecForName("UTF-8"));
    QTextCodec::setCodecForLocale(QTextCodec::codecForName("UTF-8"));
    QTextCodec::setCodecForCStrings(QTextCodec::codecForName("UTF-8"));

    QApplication a(argc, argv);
    a.setFont(loadFontFamily());
    NoFocusRectStyle *style = new NoFocusRectStyle(a.style());//去掉控件被选中时的虚线框
    a.setStyle(style);
    MainWidget w;
    w.show();
    w.init();//只有在show以后才能获取到窗口的真实尺寸

    return a.exec();
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
