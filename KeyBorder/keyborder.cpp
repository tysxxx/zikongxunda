#include "keyborder.h"
#include <QDebug>
#include <QSize>
#include <QPalette>
#include <QCoreApplication>
#include <QMouseEvent>
#include <QApplication>

#define DigitalNumSize QSize(50, 50)

KeyBorder* KeyBorder::m_instacne=nullptr;

//QSharedPointer<KeyBorder> KeyBorder::m_keyBorderInstance(nullptr);
////返回实例
//QSharedPointer<KeyBorder> KeyBorder::instance()
//{
//    if(!m_keyBorderInstance){
//        QSharedPointer<KeyBorder> newKeyBorderInstance(new KeyBorder, destroyInstance);
//        m_keyBorderInstance = newKeyBorderInstance;
//    }
//    return m_keyBorderInstance;
//}
////销毁时调用
//void KeyBorder::destroyInstance(KeyBorder* instance)
//{
//    qDebug() << __FUNCTION__;
//   if(instance)
//       instance->deleteLater();
//   instance = nullptr;
//}

//返回实例
KeyBorder* KeyBorder::instance()
{
    if(!m_instacne)
        m_instacne = new KeyBorder;
    return m_instacne;
}

//销毁实例
void KeyBorder::destroyInstance()
{
    qDebug() << __FUNCTION__;
    if(m_instacne)
        delete m_instacne;
    m_instacne = nullptr;
}

KeyBorder::KeyBorder(QWidget *parent)
    : QWidget(parent)
{
    #if (QT_VERSION < QT_VERSION_CHECK(5,0,0))
    //QT5版本以上默认就是采用UTF-8编码
    QTextCodec *codec = QTextCodec::codecForName("UTF-8");
    QTextCodec::setCodecForLocale(codec);
    QTextCodec::setCodecForCStrings(codec);
    QTextCodec::setCodecForTr(codec);
    #endif
}

KeyBorder::~KeyBorder()
{

}

//初始化
void KeyBorder::init()
{
    //无边框
    setWindowFlags(Qt::Tool|Qt::WindowStaysOnTopHint|Qt::FramelessWindowHint);
    setWindowModality(Qt::WindowModal);

    //设置窗口背景色
    QPalette keyBorderPalette;
    keyBorderPalette.setBrush(QPalette::Background, QColor("lightgray"));
    setPalette(keyBorderPalette);

    //数字
    numbGroup = new QButtonGroup;
    btnNumb0 = new QPushButton(tr("0"));
    btnNumb0->setProperty("KEYID", Qt::Key_0);
    btnNumb0->setProperty("btnNumb", true);
    btnNumb1 = new QPushButton(tr("1"));
    btnNumb1->setProperty("KEYID", Qt::Key_1);
    btnNumb1->setProperty("btnNumb", true);
    btnNumb2 = new QPushButton(tr("2"));
    btnNumb2->setProperty("KEYID", Qt::Key_2);
    btnNumb2->setProperty("btnNumb", true);
    btnNumb3 = new QPushButton(tr("3"));
    btnNumb3->setProperty("KEYID", Qt::Key_3);
    btnNumb3->setProperty("btnNumb", true);
    btnNumb4 = new QPushButton(tr("4"));
    btnNumb4->setProperty("KEYID", Qt::Key_4);
    btnNumb4->setProperty("btnNumb", true);
    btnNumb5 = new QPushButton(tr("5"));
    btnNumb5->setProperty("KEYID", Qt::Key_5);
    btnNumb5->setProperty("btnNumb", true);
    btnNumb6 = new QPushButton(tr("6"));
    btnNumb6->setProperty("KEYID", Qt::Key_6);
    btnNumb6->setProperty("btnNumb", true);
    btnNumb7 = new QPushButton(tr("7"));
    btnNumb7->setProperty("KEYID", Qt::Key_7);
    btnNumb7->setProperty("btnNumb", true);
    btnNumb8 = new QPushButton(tr("8"));
    btnNumb8->setProperty("KEYID", Qt::Key_8);
    btnNumb8->setProperty("btnNumb", true);
    btnNumb9 = new QPushButton(tr("9"));
    btnNumb9->setProperty("KEYID", Qt::Key_9);
    btnNumb9->setProperty("btnNumb", true);

    numbGroup->addButton(btnNumb0, 48);
    numbGroup->addButton(btnNumb1, 49);
    numbGroup->addButton(btnNumb2, 50);
    numbGroup->addButton(btnNumb3, 51);
    numbGroup->addButton(btnNumb4, 52);
    numbGroup->addButton(btnNumb5, 53);
    numbGroup->addButton(btnNumb6, 54);
    numbGroup->addButton(btnNumb7, 55);
    numbGroup->addButton(btnNumb8, 56);
    numbGroup->addButton(btnNumb9, 57);

    //数值按键布局
    QHBoxLayout *numbHBoxLayout = new QHBoxLayout;
    numbHBoxLayout->setContentsMargins(0, 0, 0, 0);
    numbHBoxLayout->setSpacing(5);
    for(auto button: numbGroup->buttons()){
        button->setFixedSize(DigitalNumSize);
        //button->setProperty("KEYID", Qt::Key_0);
        numbHBoxLayout->addWidget(numbGroup->button(numbGroup->id(button)));
    }

    //字母
    letterGroup = new QButtonGroup;
    btnLetterA = new QPushButton(tr("a"));
    btnLetterB = new QPushButton(tr("b"));
    btnLetterC = new QPushButton(tr("c"));
    btnLetterD = new QPushButton(tr("d"));
    btnLetterE = new QPushButton(tr("e"));
    btnLetterF = new QPushButton(tr("f"));
    btnLetterG = new QPushButton(tr("g"));
    btnLetterH = new QPushButton(tr("h"));
    btnLetterI = new QPushButton(tr("i"));
    btnLetterJ = new QPushButton(tr("j"));
    btnLetterK = new QPushButton(tr("k"));
    btnLetterL = new QPushButton(tr("l"));
    btnLetterM = new QPushButton(tr("m"));
    btnLetterN = new QPushButton(tr("n"));
    btnLetterO = new QPushButton(tr("o"));
    btnLetterP = new QPushButton(tr("p"));
    btnLetterQ = new QPushButton(tr("q"));
    btnLetterR = new QPushButton(tr("r"));
    btnLetterS = new QPushButton(tr("s"));
    btnLetterT = new QPushButton(tr("t"));
    btnLetterU = new QPushButton(tr("u"));
    btnLetterV = new QPushButton(tr("v"));
    btnLetterW = new QPushButton(tr("w"));
    btnLetterX = new QPushButton(tr("x"));
    btnLetterY = new QPushButton(tr("y"));
    btnLetterZ = new QPushButton(tr("z"));

    letterGroup->addButton(btnLetterA, 0x61);
    letterGroup->addButton(btnLetterB, 0x62);
    letterGroup->addButton(btnLetterC, 0x63);
    letterGroup->addButton(btnLetterD, 0x64);
    letterGroup->addButton(btnLetterE, 0x65);
    letterGroup->addButton(btnLetterF, 0x66);
    letterGroup->addButton(btnLetterG, 0x67);
    letterGroup->addButton(btnLetterH, 0x68);
    letterGroup->addButton(btnLetterI, 0x69);
    letterGroup->addButton(btnLetterJ, 0x6A);
    letterGroup->addButton(btnLetterK, 0x6B);
    letterGroup->addButton(btnLetterL, 0x6C);
    letterGroup->addButton(btnLetterM, 0x6D);
    letterGroup->addButton(btnLetterN, 0x6E);
    letterGroup->addButton(btnLetterO, 0x6F);
    letterGroup->addButton(btnLetterP, 0x70);
    letterGroup->addButton(btnLetterQ, 0x71);
    letterGroup->addButton(btnLetterR, 0x72);
    letterGroup->addButton(btnLetterS, 0x73);
    letterGroup->addButton(btnLetterT, 0x74);
    letterGroup->addButton(btnLetterU, 0x75);
    letterGroup->addButton(btnLetterV, 0x76);
    letterGroup->addButton(btnLetterW, 0x77);
    letterGroup->addButton(btnLetterX, 0x78);
    letterGroup->addButton(btnLetterY, 0x79);
    letterGroup->addButton(btnLetterZ, 0x7A);
    for(auto button: letterGroup->buttons()){
        button->setFixedSize(DigitalNumSize);
        button->setProperty("KEYID", letterGroup->id(button));
        button->setProperty("btnLetter", true);
    }

    //确定按钮
    btnEnter = new QPushButton(tr("Enter"));
    btnEnter->setFixedHeight(50);
    btnEnter->setObjectName("Enter");
    btnEnter->setProperty("KEYID", 13);
    btnEnter->setProperty("btnOther", true);

    //退格键
    btnBackSpace = new QPushButton(tr("backSpace"));
    btnBackSpace->setFixedHeight(50);
    btnBackSpace->setObjectName("backSpace");
    btnBackSpace->setProperty("KEYID", Qt::Key_Backspace);
    btnBackSpace->setProperty("btnOther", true);

    //大小写
    btnUppercase = new QPushButton(tr("abc"));
    btnUppercase->setFixedHeight(50);
    btnUppercase->setObjectName("caseSensitivity");
    btnUppercase->setProperty("btnOther", true);


    //空格键
    btnSpace = new QPushButton(tr("sapce"));
    btnSpace->setFixedHeight(50);
    btnSpace->setObjectName("space");
    btnSpace->setProperty("KEYID", Qt::Key_Space);
    btnSpace->setProperty("btnOther", true);


    //布局
    QHBoxLayout *qletterHBoxLayout = new QHBoxLayout;
    qletterHBoxLayout->setContentsMargins(0, 0, 0, 0);
    qletterHBoxLayout->setSpacing(5);
    qletterHBoxLayout->addWidget(btnLetterQ);
    qletterHBoxLayout->addWidget(btnLetterW);
    qletterHBoxLayout->addWidget(btnLetterE);
    qletterHBoxLayout->addWidget(btnLetterR);
    qletterHBoxLayout->addWidget(btnLetterT);
    qletterHBoxLayout->addWidget(btnLetterY);
    qletterHBoxLayout->addWidget(btnLetterU);
    qletterHBoxLayout->addWidget(btnLetterI);
    qletterHBoxLayout->addWidget(btnLetterO);
    qletterHBoxLayout->addWidget(btnLetterP);

    QHBoxLayout *aletterHBoxLayout = new QHBoxLayout;
    aletterHBoxLayout->setContentsMargins(0, 0, 0, 0);
    aletterHBoxLayout->setSpacing(5);
    aletterHBoxLayout->addWidget(btnLetterA);
    aletterHBoxLayout->addWidget(btnLetterS);
    aletterHBoxLayout->addWidget(btnLetterD);
    aletterHBoxLayout->addWidget(btnLetterF);
    aletterHBoxLayout->addWidget(btnLetterG);
    aletterHBoxLayout->addWidget(btnLetterH);
    aletterHBoxLayout->addWidget(btnLetterJ);
    aletterHBoxLayout->addWidget(btnLetterK);
    aletterHBoxLayout->addWidget(btnLetterL);
    aletterHBoxLayout->addWidget(btnEnter);

    QHBoxLayout *zletterHBoxLayout = new QHBoxLayout;
    zletterHBoxLayout->setContentsMargins(0, 0, 0, 0);
    zletterHBoxLayout->setSpacing(5);
    zletterHBoxLayout->addWidget(btnUppercase);
    zletterHBoxLayout->addWidget(btnLetterZ);
    zletterHBoxLayout->addWidget(btnLetterX);
    zletterHBoxLayout->addWidget(btnLetterC);
    zletterHBoxLayout->addWidget(btnLetterV);
    zletterHBoxLayout->addWidget(btnLetterB);
    zletterHBoxLayout->addWidget(btnLetterN);
    zletterHBoxLayout->addWidget(btnLetterM);
    zletterHBoxLayout->addWidget(btnBackSpace);

    titleLabel  = new QLabel(tr("输入法:"));
    QVBoxLayout *vBoxLayout = new QVBoxLayout(this);
    vBoxLayout->setContentsMargins(0, 0, 0, 0);
    vBoxLayout->setSpacing(5);
    vBoxLayout->addSpacing(10);
    vBoxLayout->addWidget(titleLabel);
    vBoxLayout->addSpacing(10);
    vBoxLayout->addLayout(numbHBoxLayout);
    vBoxLayout->addLayout(qletterHBoxLayout);
    vBoxLayout->addLayout(aletterHBoxLayout);
    vBoxLayout->addLayout(zletterHBoxLayout);
    vBoxLayout->addWidget(btnSpace);
    vBoxLayout->addSpacing(50);

    //获取所有按键
    QList<QPushButton*> btnList = findChildren<QPushButton*>();
    for(auto button: btnList){
        connect(button, SIGNAL(clicked()), this, SLOT(btnClickedSlot()));
        button->setFocusPolicy(Qt::NoFocus); //键盘设置不能获取焦点
    }

    //设置按键样式
    QString css = ".QPushButton{background-color: #807E70; color: white;\
                   font: bold 21px; border-radius: 5px;}";
    css += ".QPushButton:hover{background-color: #649bf1;}";
    css += ".QLabel{color: gray; font: bold 21px;}";
    setStyleSheet(css);

    //全局焦点改变
    connect(qApp, SIGNAL(focusChanged ( QWidget *, QWidget *)),
            this, SLOT(focusChanged(QWidget *, QWidget *)));
    qApp->installEventFilter(this);

    //按键按下计数器
    btnPressedTimer = new QTimer(this);
    connect(btnPressedTimer, SIGNAL(timeout()), SLOT(btnPressedTimerSlot()));

    //other
    mousePressed = false;
    currentEditType = "";
    caseSensitivity = false;

}

//鼠标移动事件
void KeyBorder::mouseMoveEvent(QMouseEvent *event)
{
    if(mousePressed){
        move(event->globalPos() - mousePoint);
        event->accept();
    }
}

//鼠标按下事件
void KeyBorder::mousePressEvent(QMouseEvent *event)
{
    if(event->button() == Qt::LeftButton){
        mousePressed = true;
        mousePoint = event->globalPos() - this->pos();
        event->accept();
    }
}

//鼠标释放事件
void KeyBorder::mouseReleaseEvent(QMouseEvent *event)
{
    Q_UNUSED(event)
    mousePressed = false;
}

//焦点改变
void KeyBorder::focusChanged(QWidget *oldWidget, QWidget *nowWidget)
{
    qDebug() << "focus";

    if(nowWidget !=0 && !this->isAncestorOf(nowWidget)){

        qDebug() << "now widget: " << nowWidget->objectName();


         //if(nowWidget->inherits("QLineEdit"))
         //   currentEditType = "QLineEdit";

        caseSensitivity = false;
        letterCaseSensitivity(caseSensitivity);
        qDebug() << "now widget: " << nowWidget->objectName();
        if(nowWidget->inherits("QLineEdit")){
            m_curFocusedWidget = nowWidget;
            currentEditType = "QLineEdit";

            if(!oldWidget){
                qDebug() << "old widget is not exist";
                return;
            }
            updatePosition();
            this->setVisible(true);
        }else{
            m_curFocusedWidget = 0;
            currentEditType = "";
            //caseSensitivity = false;
            //letterCaseSensitivity(caseSensitivity);
            setVisible(false);
        }
    }
}

//按键处理
void KeyBorder::btnClickedSlot()
{
    QPushButton *button = qobject_cast<QPushButton*>(sender());
    QString objectName = button->objectName();

    if(objectName == tr("Enter")){
        this->setVisible(false);
    } else if(objectName == tr("backSpace")){
        dealKeyborderCharacter(button->property("KEYID"));
    }else if(objectName == tr("caseSensitivity")){
        caseSensitivity = !caseSensitivity;
        letterCaseSensitivity(caseSensitivity);
    }else {
        dealKeyborderCharacter(button->property("KEYID"));
    }
}

//改变字母大小写
void KeyBorder::letterCaseSensitivity(bool upperCase)
{
    //qDebug() << __FUNCTION__ << upperCase;
    quint8 i = 0;
    for(auto button: letterGroup->buttons()){
        if(upperCase){
            button->setText(button->text().toUpper());
            btnUppercase->setText("ABC");
            button->setProperty("KEYID", 0x41+i++);
        }else{
            button->setText(button->text().toLower());
            btnUppercase->setText("abc");
            button->setProperty("KEYID", 0x61+i++);
        }
    }
}

//更新键盘的位置
void KeyBorder::updatePosition()
{
    if(!m_curFocusedWidget) return;

    QRect widgetRect = m_curFocusedWidget->rect();
    QPoint panelPos = QPoint(widgetRect.left(), widgetRect.bottom() + 2);
    panelPos = m_curFocusedWidget->mapToGlobal(panelPos);
    move(panelPos);
}

//返回当前的焦点组件
QWidget* KeyBorder::curFocusedWidget()
{
    return m_curFocusedWidget;
}

//发送按键值
void KeyBorder::dealKeyborderCharacter(QVariant letter)
{
    if(!m_curFocusedWidget) return;
    QKeyEvent keypress(QEvent::KeyPress, letter.toInt(), Qt::NoModifier, QString(letter.toInt()));
    qApp->sendEvent(m_curFocusedWidget, &keypress); //发送键盘事件
}

//按键过滤
bool KeyBorder::eventFilter(QObject *obj, QEvent *event)
{
    if(event->type() == QEvent::MouseButtonPress){
        QMouseEvent *mouseEvent = (QMouseEvent*)(event);
        QPoint point = mouseEvent->globalPos();
        if(qApp->widgetAt(point)->hasFocus()){ //判断鼠标点击的地方的空间是否获取了焦点
            qDebug() << "pressed" << "currentEditType=" << currentEditType;
            if(currentEditType !="" && obj != btnEnter){
                updatePosition();
                setVisible(true);
            }
        }

        //键盘上面的按钮
        if(obj->inherits("QPushButton")){
            pressedBtn = qobject_cast<QPushButton*>(obj); //获取按下的按键
            if(checkKeyborderBtnPress()){
                btnPressed = true;
                btnPressedTimer->start(500);
            }
        }

        //return false;
    }else if(event->type() == QEvent::MouseButtonRelease)
    {
        //键盘上面的按钮
        if(obj->inherits("QPushButton")){
            if(checkKeyborderBtnPress()){
                btnPressed = false;
                btnPressedTimer->stop();
            }
        }
        //return  false;
    }
    return  QWidget::eventFilter(obj, event);
}

//按钮一直被按下
void KeyBorder::btnPressedTimerSlot()
{
    if(btnPressed){
        btnPressedTimer->setInterval(30);
        pressedBtn->click();
    }
}

//判断是不是键盘上面的按键
bool KeyBorder::checkKeyborderBtnPress()
{
    bool numbOk = pressedBtn->property("btnNumb").toBool();
    bool letterOk = pressedBtn->property("btnLetter").toBool();
    bool otherOk = pressedBtn->property("btnOther").toBool();

    if(numbOk || letterOk || otherOk)
        return true;
    else
        return false;
}
