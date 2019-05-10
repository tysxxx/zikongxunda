#include "itemeditor.h"

ItemEditor::ItemEditor(QWidget *parent) : QLabel(parent)
{
    setWindowFlags(Qt::FramelessWindowHint);
    m_meetingName = new QLabel;
    enterMeetingBtn = new QPushButton(tr("进入会议"));
    enterMeetingBtn->setStyleSheet(".QPushButton{color: red; font: 21px;}");
    QHBoxLayout *hBoxLayout = new QHBoxLayout;
    hBoxLayout->setMargin(0);
    hBoxLayout->setSpacing(10);
    hBoxLayout->addWidget(m_meetingName);
    hBoxLayout->addWidget(enterMeetingBtn);
    setLayout(hBoxLayout);
}

//返回会议名称
QString ItemEditor::meetingName()
{
    return m_meetingName->text();
}

//设置会议名称
void ItemEditor::setMeetingName(QString name)
{
    m_meetingName->setText(name);
}

