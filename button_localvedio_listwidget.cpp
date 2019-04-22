#include "button_localvedio_listwidget.h"

button_localVedio_listWidget* button_localVedio_listWidget::m_instance = NULL;

button_localVedio_listWidget::button_localVedio_listWidget()
{
    init();
}


button_localVedio_listWidget::~button_localVedio_listWidget()
{
    if(m_list != NULL)
    {
        delete(m_list);
        m_list = NULL;
    }

}

void button_localVedio_listWidget::init()
{
    m_list = new QListWidget;
    m_list->setWindowFlags((Qt::FramelessWindowHint));//设置窗体无边框
    m_list->setGeometry(QRect(180, 90, 250, 264));
    m_list->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));//设置字体颜色为白色
    //m_list->setStyleSheet("QWidget{background-color:gray;border-top-left-radius:10px;border-top-right-radius:10px;border-bottom-left-radius:10px;border-bottom-right-radius:10px;}");
    m_list->setStyleSheet("QWidget{background-color:black;border-radius:10px;}");//四个角都设置为圆角，半径10px
    m_list->setFocusPolicy(Qt::NoFocus);//去掉被选中项的虚线框
    QGraphicsOpacityEffect *opacityEffect=new QGraphicsOpacityEffect;
    m_list->setGraphicsEffect(opacityEffect);
    opacityEffect->setOpacity(0.8);

    m_item_cnt = 0;
    m_font_size = 21;
    m_curr_item = 0;//光标默认停留在第一个item处
    m_font.setPointSize(m_font_size);

    set_lists();
    //m_list->hide();
    m_showStatu = false;


}

button_localVedio_listWidget* button_localVedio_listWidget::instance()
{
    if(m_instance == NULL)
    {
        m_instance = new button_localVedio_listWidget();

    }
    return m_instance;
}

bool button_localVedio_listWidget::show_listWidget()
{
    if(m_showStatu)
        return true;
    m_list->show();
    m_showStatu = true;
    return true;
}

bool button_localVedio_listWidget::hide_listWidget()
{
    if(!m_showStatu)
        return true;
    m_list->hide();
    m_showStatu = false;
    return true;
}

bool button_localVedio_listWidget::change_listWidget_show_statu()
{
    if(m_showStatu)
    {
        m_list->hide();
        m_showStatu = false;
    }else
        {
            m_list->show();
            m_showStatu = true;
        }
    return true;
}

void button_localVedio_listWidget::set_lists()
{

    add_one_widgetItem("本地抓拍");
    add_one_widgetItem("布局切换");
    add_one_widgetItem("取消本地录像");
    add_one_widgetItem("打开抓拍文件目录");
    add_one_widgetItem("打开本地录像文件目录");
    //将显示列表与堆栈窗口关联，点击列表中的按键，显示相应的窗口
    QObject::connect(m_list,SIGNAL(currentItemChanged(QListWidgetItem *, QListWidgetItem *)),
                    this,SLOT(changePage(QListWidgetItem *, QListWidgetItem *)));

}

bool button_localVedio_listWidget::add_one_widgetItem(const char* name)
{
    QListWidgetItem *pageButton = new QListWidgetItem(m_list);
    if(name != NULL)
        pageButton->setText(QObject::tr(name));
    else
        pageButton->setText(QObject::tr("NULL"));
    pageButton->setTextColor(QColor(255,255,255,255));//设置字体颜色
    pageButton->setFont(m_font);//设置字体大小
    pageButton->setTextAlignment(Qt::AlignLeft);
    //pageButton->setFlags(Qt::ItemIsSelectable | Qt::ItemIsEnabled);
    pageButton->setSizeHint(QSize(240,40));//设置每行item的间距
    m_listItem[m_item_cnt] = pageButton;
    ++m_item_cnt;
    if(m_item_cnt == 1)
    {
        pageButton->setBackground(QColor(0,0,0,255));
        //pageButton->setBackground(QColor(0,0,205,255));
    }
}

void button_localVedio_listWidget::changePage(QListWidgetItem *current, QListWidgetItem *previous)
{
    if (!current)
        current = previous;
    int item = m_list->row(current);
    if(m_curr_item != item)
    {
        m_listItem[m_curr_item]->setBackground(QColor(0,0,0,0));//恢复黑色背景
    }
    //m_listItem[item]->setBackground(QColor(0,0,205,255));//设置为蓝色背景
    m_curr_item = item;
    printf("current page:%d\n",m_list->row(current));
}

