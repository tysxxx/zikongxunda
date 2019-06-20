#ifndef KEYBORDER_H
#define KEYBORDER_H

#include <QWidget>
#include <QPushButton>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QButtonGroup>
#include <QMouseEvent>
#include <QList>
#include <QTextCodec>
#include <QLabel>
#include <QEvent>
#include <QMouseEvent>
#include <QSharedPointer>
#include <QTimer>
#include <QDebug>

class KeyBorder : public QWidget
{
    Q_OBJECT
public:
    KeyBorder(QWidget *parent = nullptr);
    ~KeyBorder();

    static KeyBorder* instance();
    static void destroyInstance();

//    static QSharedPointer<KeyBorder> instance();
//    static void destroyInstance(KeyBorder*);

    void init();
    void mouseMoveEvent(QMouseEvent *event);
    void mousePressEvent(QMouseEvent *event);
    void mouseReleaseEvent(QMouseEvent *event);
    bool eventFilter(QObject *obj, QEvent *event);
    void updatePosition();
    QWidget* curFocusedWidget();
    void dealKeyborderCharacter(QVariant letter);
    bool checkKeyborderBtnPress();
signals:
    void characterGenerated(QChar);
private slots:
    void btnClickedSlot();
    void btnPressedTimerSlot();
    void letterCaseSensitivity(bool upperCase);
    void focusChanged(QWidget *oldWidget, QWidget *nowWidget);  //焦点改变事件槽函数处理
private:
    //static QSharedPointer<KeyBorder> m_keyBorderInstance;
    static KeyBorder* m_instacne;

    QLabel *titleLabel;
    QButtonGroup *numbGroup;
    QPushButton *btnNumb0;
    QPushButton *btnNumb1;
    QPushButton *btnNumb2;
    QPushButton *btnNumb3;
    QPushButton *btnNumb4;
    QPushButton *btnNumb5;
    QPushButton *btnNumb6;
    QPushButton *btnNumb7;
    QPushButton *btnNumb8;
    QPushButton *btnNumb9;

    QButtonGroup *letterGroup;
    QPushButton *btnLetterA;
    QPushButton *btnLetterB;
    QPushButton *btnLetterC;
    QPushButton *btnLetterD;
    QPushButton *btnLetterE;
    QPushButton *btnLetterF;
    QPushButton *btnLetterG;
    QPushButton *btnLetterH;
    QPushButton *btnLetterI;
    QPushButton *btnLetterJ;
    QPushButton *btnLetterK;
    QPushButton *btnLetterL;
    QPushButton *btnLetterM;
    QPushButton *btnLetterN;
    QPushButton *btnLetterO;
    QPushButton *btnLetterP;
    QPushButton *btnLetterQ;
    QPushButton *btnLetterR;
    QPushButton *btnLetterS;
    QPushButton *btnLetterT;
    QPushButton *btnLetterU;
    QPushButton *btnLetterV;
    QPushButton *btnLetterW;
    QPushButton *btnLetterX;
    QPushButton *btnLetterY;
    QPushButton *btnLetterZ;

    QPushButton *btnBackSpace; //退格键
    QPushButton *btnEnter;     //确认键
    QPushButton *btnUppercase; //字母大小切换
    QPushButton *btnSpace; //空格键

    bool mousePressed;
    QPoint mousePoint;

    QWidget *lastFocusedWidget;
    QWidget *m_curFocusedWidget; //当前焦点输入的部件

    bool caseSensitivity; //大小写
    QString currentEditType;

    bool btnPressed;
    QPushButton *pressedBtn;
    QTimer *btnPressedTimer;
};

#endif // KEYBORDER_H
