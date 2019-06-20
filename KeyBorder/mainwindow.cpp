#include "mainwindow.h"
#include <QVBoxLayout>
#include <QPointer>
#include <QApplication>
#include <QDebug>

MainWindow::MainWindow(QWidget *parent) : QWidget(parent)
{
    setFocusPolicy(Qt::NoFocus);
    lineEdit = new QLineEdit();
    lineEdit->setObjectName("lineEdit");
    //lineEdit->setFocusPolicy(Qt::NoFocus);

    QLineEdit *lineEdit1 = new QLineEdit();
    lineEdit1->setObjectName("lineEdit1");
    //lineEdit1->setFocusPolicy(Qt::ClickFocus);

    QLineEdit *lineEdit2 = new QLineEdit();
    lineEdit2->setObjectName("lineEdit2");
    //lineEdit2->setFocusPolicy(Qt::ClickFocus);

    QVBoxLayout *vboxLayout = new QVBoxLayout(this);
    vboxLayout->addWidget(lineEdit);
    vboxLayout->addWidget(lineEdit1);
    vboxLayout->addWidget(lineEdit2);
}
















