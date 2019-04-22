#include "pushButtonMenu.h"

pushButtonMenu::pushButtonMenu()
{

}

bool pushButtonMenu::set_layout(BTN_MENU_LAOUT_PARA_ST* para_st)
{
    if(para_st == NULL)
        return false;
    if(para_st->p_button_list == NULL || para_st->p_qwidget == NULL)
        return false;
    int i = 0;
    m_verticalLayout = new QVBoxLayout();
    m_verticalLayout->setSpacing(0);
    for(i = 0;i<para_st->buttonCnt;i++)
    {
        QSpacerItem* m_verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);
        m_verticalLayout->addItem(m_verticalSpacer);
        m_verticalLayout->addWidget(para_st->p_button_list+i);
        if(i == 0)
        {
            m_verticalLayout->setStretch(2*i,para_st->topSize);
        }else
            {
                m_verticalLayout->setStretch(2*i,para_st->spaceSize);
            }
        m_verticalLayout->setStretch(2*i+1,para_st->buttonSize);
    }
    QSpacerItem* m_verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);
    m_verticalLayout->addItem(m_verticalSpacer);
    m_verticalLayout->setStretch(2*i,para_st->bottomSize);

    m_verticalLayout->setContentsMargins(para_st->leftOffset, 0, 0, 0);

    m_gridLayout = new QGridLayout(para_st->p_qwidget);
    m_gridLayout->setSpacing(0);
    m_gridLayout->setContentsMargins(0, 0, 0, 0);
    m_gridLayout->addLayout(m_verticalLayout,0,0);
    return true;
}

QPushButton* pushButtonMenu::add_one_pushbutton(const char* name,QWidget *p_widget,QFont* font)
{
    if(p_widget == NULL)
        return NULL;
    QPushButton* pushButton = new QPushButton(p_widget);
    if(name != NULL)
        pushButton->setText(QObject::tr(name));
    else
        pushButton->setText(QObject::tr("NULL"));
    if(font != NULL)
        pushButton->setFont(*font);
    else
        {
            QFont tmpFont;
            tmpFont.setPointSize(21);
            pushButton->setFont(tmpFont);
        }
    pushButton->setStyleSheet("QPushButton{text-align:left;color:rgb(255, 255, 255);}");

    return pushButton;
}
