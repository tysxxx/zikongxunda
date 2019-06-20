#include "keyborder.h"
#include <QApplication>
#include "mainwindow.h"
#include <QSharedPointer>
#include <QDebug>

#if 0
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

//    QSharedPointer<KeyBorder> keyborder = KeyBorder::instance();
//    keyborder->show();
    KeyBorder::instance()->init();
    MainWindow w;
    w.show();

    int ret = a.exec();
    qDebug() << "exit main";
    KeyBorder::destroyInstance();
    return ret;
}
#endif
