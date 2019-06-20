#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QWidget>
#include <QLineEdit>
#include "keyborder.h"
#include <QSharedPointer>
#include <QEvent>

class MainWindow : public QWidget
{
    Q_OBJECT
public:
    explicit MainWindow(QWidget *parent = nullptr);
signals:

private:
    QLineEdit *lineEdit;
};

#endif // MAINWINDOW_H
