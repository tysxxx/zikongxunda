#include "dateTimeButton.h"

#include "dateTimeButton.h"
#include "date.h"
#include <QInputDialog>
#include <QPainter>
#include <QStyleOption>
#include <QDateTime>
#include <QPushButton>
#include <QLineEdit>
#include <QGroupBox>
#include <QLabel>
#include <QDate>
#include <QGridLayout>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QSpacerItem>
#include <QDebug>
#include <QFont>
#include <QMenu>
#include <QComboBox>
#include <QListView>
#include <QStyledItemDelegate>

#define Has_Lunar 0 //农历的宏开关

dateTimeButton::dateTimeButton(QWidget *parent) : QPushButton(parent)
{
    pCldrWgt = new CalendarWidget(this, QMenu().windowFlags() | Qt::FramelessWindowHint);

    //initStyleSheet();
    //initConnect();
}

void dateTimeButton::setText(const QString &text)
{
    if(text.isEmpty() || QDateTime::fromString(text, m_strFormat).isNull())
        return;

    QPushButton::setText(text);
}

void dateTimeButton::showCalendarWidget()
{
    QPoint pt(500, height()-300);
    pt = mapToGlobal(pt);

    pCldrWgt->jumpToDateTime(m_dateTime);
    pCldrWgt->move(pt);qDebug()<<"pt.x():"<<pt.x()<<",pt.y():"<<pt.y();
    pCldrWgt->show();
}

QDateTime dateTimeButton::dateTime() const
{
    return m_dateTime;
}

QDate dateTimeButton::date() const
{
    return m_dateTime.date();
}

QTime dateTimeButton::time() const
{
    return m_dateTime.time();
}

void dateTimeButton::setDateTime(const QDateTime &dateTime)
{
    m_dateTime = dateTime;
    setText(m_dateTime.toString(m_strFormat));
}

void dateTimeButton::setDate(const QDate &date)
{
    setDateTime(QDateTime(date, m_dateTime.time()));
}

void dateTimeButton::setTime(const QTime &time)
{
    setDateTime(QDateTime(m_dateTime.date(), time));
}

void dateTimeButton::setDateTimeRange(const QDateTime &min, const QDateTime &max)
{
    pCldrWgt->setDateTimeRange(min, max);
}

void dateTimeButton::dateTimeRange(QDateTime &min, QDateTime &max)
{
    pCldrWgt->dateTimeRange(min, max);
}

void dateTimeButton::initStyleSheet()
{
    setStyleSheet(QString(
        ".DateTimeInputButton"
        "{"
        "border: 1px solid #00d2ff; "
        "border-radius: 3px;        "
        "background-color:#083590;  "
        "min-height: 26px;          "
        "padding-left: 7px;         "
        "color:#ddf5ff;             "
        "font-size:14px;            "
        "border-radius: 3px;        "
        "text-align : left;         "
        "}"
        ));

    m_strFormat = QString("yyyy/MM/dd hh:mm");
    m_dateTime = QDateTime::currentDateTime();
    QString text = m_dateTime.toString(m_strFormat);
    QPushButton::setText(text);
}

void dateTimeButton::initConnect()
{
    connect(this, SIGNAL(clicked()), this,SLOT(showCalendarWidget()));
    connect(pCldrWgt,SIGNAL(dayClicked(const QDateTime&)),this,SLOT(slotDayClicked(const QDateTime &)));
}

void dateTimeButton::slotDayClicked(const QDateTime &dt)
{
    m_dateTime = dt;
    setText(dt.toString(m_strFormat));
}


//////////////////////////////////////
/// \brief DayLabel::DayLabel
/// \param parent
////////////////////////////////

//static const QString s_strWeek[] = {LC_STR("周日"),"周一","周二","周三","周四","周五","周六"};
CalendarWidget::CalendarWidget(QWidget *parent, Qt::WindowFlags f)
    : QWidget(parent, f)
{
    // 获取当前年月日
    m_nYear  = QDate::currentDate().year();
    m_nMonth = QDate::currentDate().month();
    m_nDay = QDate::currentDate().day();
    m_pCrtSelect = NULL;

    //  设置默认日期范围
    m_minDt = QDateTime(QDate(1900,1,1));
    m_maxDt = QDateTime(QDate(2099,12,31), QTime(23, 59, 59));

    initWidget();
    initDate();
    initStyleSheet();
    UpdateYear();
}

CalendarWidget::~CalendarWidget()
{

}

void CalendarWidget::initStyleSheet()
{
    setStyleSheet(QString(
        ".CalendarWidget{"
        "border-image:url(:/dateTimeImg/resource/dateTimeImg/bk.png);"
        "} "
        "QLabel{color:#cadfff; font-size:12px;} "
        "QLabel#labelWeekend{color:#00caff;} "
        "QLable#label_splite{font: bold 14px;} "
        "QWidget#widgetTitle{background-color:#061f65;} "
        "QComboBox{background-color: transparent; selection-background-color: transparent; color:#ffffff; font-size: 14px; min-height: 20px;text-align: right;} "
        "QComboBox::down-arrow{ image:url(:/dateTimeImg/resource/dateTimeImg/ComboBoxArrow.png);} "
        "QComboBox::down-arrow:on{ top: 1px; left: 1px; } QComboBox::drop-down{ width: 26px; border:none; } "
        "QComboBox QAbstractItemView {border: none; outline:0px;} QComboBox QAbstractItemView::item{ height: 26px; min-height:26px;} "
        "QComboBox QAbstractItemView::item:selected{ background-color: #0087f1; color: #e6ebf1;} QComboBox QAbstractItemView::item:!selected {background-color: #e6ebf1; color: #000000;} "
        "QPushButton{													  "
        "	background-color: transparent;								  "
        "	border-radius: 11px;										  "
        "	border: 1px solid #259bf3;									  "
        "	font-size: 12px;											  "
        "	font-family: AdobeHeitiStd-Regular;							  "
        "	color:#ffffff;												  "
        "}																  "
        "QPushButton:hover{background-color: rgba(37, 155, 243, 0.41);}	  "
        "QPushButton:pressed{background-color: rgba(37, 155, 243, 0.99);} "
        "QScrollBar:vertical{width:12px;background:rgba(0,0,0,70%);margin:0px,0px,0px,0px;padding-top:9px;padding-bottom:9px;} "//此处的rgba改变下拉框滑块的颜色
        "QScrollBar::handle:vertical{width:12px;border-image:url(:/devicesetting/image/devicesetting/ver_scroll_handle.png);border-radius:0px;min-height:20;}"
        "QScrollBar::handle:vertical:hover{width:20px;border-image:url(:/devicesetting/image/devicesetting/ver_scroll_handle.png);border-radius:0px;min-height:20;}"
        "QScrollBar::add-line:vertical,QScrollBar::add-line:vertical:hover{height:9px;width:8px;border-image:url(:/devicesetting/image/devicesetting/scroll_down.png);subcontrol-position:bottom;background:rgba(0,0,225,100%);}"
        "QScrollBar::sub-line:vertical,QScrollBar::sub-line:vertical:hover{height:9px;width:8px;border-image:url(:/devicesetting/image/devicesetting/scroll_up.png);subcontrol-position:top;background:rgba(0,0,225,100%);}"
        "QScrollBar::add-page:vertical,QScrollBar::sub-page:vertical{background:rgba(0,0,225,100%);}"
        "QScrollBar:horizontal{max-height:12px;background:transparent;padding-left:9px;padding-right:9px;}"
        "QScrollBar::handle:horizontal{height:9px;min-width:10px;border-radius:0px;border-image:url(:/devicesetting/image/devicesetting/hor_scroll_handle.png);}"
        "QScrollBar::handle:horizontal:hover{border-image:url(:/devicesetting/image/devicesetting/hor_scroll_handle.png);}"
        "QScrollBar::sub-line:horizontal,QScrollBar::sub-line:horizontal:hover{height:9px;width:9px;border-image:url(:/devicesetting/image/devicesetting/scroll_left.png);subcontrol-position:left;background:rgba(0,0,225,100%);}"
        "QScrollBar::add-line:horizontal,QScrollBar::add-line:horizontal:hover{height:9px;width:9px;border-image:url(:/devicesetting/image/devicesetting/scroll_right.png);subcontrol-position:right;background:rgba(0,0,225,100%);}"
        "QScrollBar::add-page:horizontal,QScrollBar::sub-page:horizontal{background:rgba(0,0,225,100%);}"
    ));

    setAutoFillBackground(false);
    setAttribute(Qt::WA_TranslucentBackground, true);
}

void CalendarWidget::UpdateYear()
{
    comboBox_Year->clear();
    QDate d1 = m_minDt.date();
    QDate d2 = m_maxDt.date();
    for (int i = d1.year(); i<= d2.year(); i++)
    {
        comboBox_Year->addItem(QString::number(i));
    }
}

DayLabel *CalendarWidget::getDayLabel(int y, int m, int d)
{
    int nWeek  = Date::getFirstDayOfWeek(y, m);
    nWeek = (0 == nWeek ? 7 : nWeek);
    // 显示当前天数
    return labelDay[d + nWeek - 1];
}

void CalendarWidget::changeCurrentSelectDay()
{
    DayLabel *pLabel = getDayLabel(m_nYear, m_nMonth, m_nDay);

    if(m_pCrtSelect)
        m_pCrtSelect->setSelected(false);
    m_pCrtSelect = pLabel;
    if(m_pCrtSelect)
        m_pCrtSelect->setSelected(true);
}

void CalendarWidget::paintEvent(QPaintEvent *e)
{
    QPainter p(this);
    p.drawPixmap(0, 0, QPixmap(":/dateTimeImg/resource/dateTimeImg/bk.png").scaled(size()));

    QWidget::paintEvent(e);
}

int CalendarWidget::year() const
{
    return m_nYear;
}

void CalendarWidget::setYear(int nYear)
{
    m_nYear = nYear;
    disconnect(comboBox_Year, SIGNAL(currentIndexChanged(int)), this, SLOT(sltComboBoxDateChange(int)));
    comboBox_Year->setCurrentIndex(comboBox_Year->findText(QString::number(nYear)));
    connect(comboBox_Year, SIGNAL(currentIndexChanged(int)), this, SLOT(sltComboBoxDateChange(int)));
}

int CalendarWidget::month() const
{
    return m_nMonth;
}

void CalendarWidget::setMonth(int nMonth)
{
    m_nMonth = nMonth;
    disconnect(comboBox_Month, SIGNAL(currentIndexChanged(int)), this, SLOT(sltComboBoxDateChange(int)));
    comboBox_Month->setCurrentIndex(nMonth - 1);
    connect(comboBox_Month, SIGNAL(currentIndexChanged(int)), this, SLOT(sltComboBoxDateChange(int)));
}

int CalendarWidget::day() const
{
    return m_nDay;
}

void CalendarWidget::setDay(int nDay)
{
    m_nDay = nDay;
}

int CalendarWidget::hour() const
{
    return m_nHour;
}

void CalendarWidget::setHour(int h)
{
    m_nHour = h;
    disconnect(comboBox_Hour, SIGNAL(currentIndexChanged(int)), this, SLOT(sltComboBoxTimeChange(int)));
    comboBox_Hour->setCurrentIndex(h);
    connect(comboBox_Hour, SIGNAL(currentIndexChanged(int)), this, SLOT(sltComboBoxTimeChange(int)));
}

int CalendarWidget::minute()
{
    return m_nMin;
}

void CalendarWidget::setMinute(int m)
{
    m_nMin = m;
    disconnect(comboBox_min, SIGNAL(currentIndexChanged(int)), this, SLOT(sltComboBoxTimeChange(int)));
    comboBox_min->setCurrentIndex(m);
    connect(comboBox_min, SIGNAL(currentIndexChanged(int)), this, SLOT(sltComboBoxTimeChange(int)));
}

void CalendarWidget::jumpToDateTime(const QDateTime& dt)
{
    setYear(dt.date().year());
    setMonth(dt.date().month());
    setDay(dt.date().day());
    setHour(dt.time().hour());
    setMinute(dt.time().minute());

    initDate();

    changeCurrentSelectDay();
}

void CalendarWidget::setDateTimeRange(const QDateTime &min, const QDateTime &max)
{
    if(max <= min)
        return;

    m_minDt = min; m_maxDt = max;
}
//static const QString s_strWeek[] = {LC_STR("周日"),LC_STR("周一"),LC_STR("周二"),LC_STR("周三"),LC_STR("周四"),LC_STR("周五"),LC_STR("周六"),};
void CalendarWidget::dateTimeRange(QDateTime &min, QDateTime &max)
{
    min = m_minDt; max = m_maxDt;
}

/**
 * @brief CalendarWidget::initWidget 初始化界面
 */
void CalendarWidget::initWidget()
{
#ifdef Q_OS_ANDROID
    this->setMinimumSize(1400, 800);
#else
    this->setMinimumSize(377, 323);
    this->setObjectName("widgetCalendar");
#endif

    verLayoutCalendar = new QVBoxLayout(this);
    verLayoutCalendar->setContentsMargins(18, 20, 18, 18);
//    verLayoutCalendar->setSpacing(6);

    //! [1] 标题行
    widgetTitle = new QWidget(this);
    widgetTitle->setObjectName("widgetTitle");
    widgetTitle->setMinimumHeight(32);

    comboBox_Year = new QComboBox(this);
    comboBox_Month = new QComboBox(this);
    comboBox_Hour = new QComboBox(this);
    label_splite = new QLabel(this);
    comboBox_min = new QComboBox(this);

    QStringList monthList;
    monthList<<LC_STR("一月")<<LC_STR("二月")<<LC_STR("三月")<<LC_STR("四月")<<LC_STR("五月")<<LC_STR("六月")
             <<LC_STR("七月")<<LC_STR("八月")<<LC_STR("九月")<<LC_STR("十月")<<LC_STR("十一月")<<LC_STR("十二月");
    comboBox_Month->addItems(monthList);

    label_splite->setText(LC_STR(":"));
    label_splite->setMinimumWidth(4);
    comboBox_Hour->clear();
    for (int i = 0; i < 24; ++i)
        //comboBox_Hour->addItem(QString::asprintf("%02d", i));
        comboBox_Hour->addItem(QString::number(i,10));
    comboBox_min->clear();
    for (int i = 0; i < 60; ++i)
        //comboBox_min->addItem(QString::asprintf("%02d", i));
        comboBox_min->addItem(QString::number(i,10));

    QHBoxLayout *HTopLayout = new QHBoxLayout(widgetTitle);
    HTopLayout->setContentsMargins(14, 0, 14, 0);
    HTopLayout->setSpacing(0);
    HTopLayout->addWidget(comboBox_Year);
    HTopLayout->addStretch(1);
    HTopLayout->addWidget(comboBox_Month);
    HTopLayout->addStretch(1);
    HTopLayout->addWidget(comboBox_Hour);
    HTopLayout->addWidget(label_splite);
    HTopLayout->addWidget(comboBox_min);

    verLayoutCalendar->addWidget(widgetTitle);

    comboBox_Year->setObjectName("comboBox_Year");
    comboBox_Month->setObjectName("comboBox_Month");
    label_splite->setObjectName("label_splite");

    comboBox_Year->setItemDelegate(new QStyledItemDelegate());
    comboBox_Month->setItemDelegate(new QStyledItemDelegate());
    comboBox_Hour->setItemDelegate(new QStyledItemDelegate());
    comboBox_min->setItemDelegate(new QStyledItemDelegate());

    connect(comboBox_Year, SIGNAL(currentIndexChanged(int)), this, SLOT(sltComboBoxDateChange(int)));
    connect(comboBox_Month, SIGNAL(currentIndexChanged(int)), this, SLOT(sltComboBoxDateChange(int)));
    connect(comboBox_Hour, SIGNAL(currentIndexChanged(int)), this, SLOT(sltComboBoxTimeChange(int)));
    connect(comboBox_min, SIGNAL(currentIndexChanged(int)), this, SLOT(sltComboBoxTimeChange(int)));
    //! [1]

    //! [2] 星期行
    widgetWeek = new QWidget(this);
    widgetWeek->setObjectName("widgetWeek");

    horLayoutWeek = new QHBoxLayout(widgetWeek);
    horLayoutWeek->setContentsMargins(0, 0, 0, 0);
    horLayoutWeek->setSpacing(0);
    QString s_strWeek[] = {"周日","周一","周二","周三","周四","周五","周六",};
    for (int i = 0; i < Week; i++) {
        labelWeek[i] = new QLabel(widgetWeek);
        labelWeek[i]->setText(s_strWeek[i]);
        labelWeek[i]->setObjectName("labelWeek");
        labelWeek[i]->setMinimumHeight(30);
        labelWeek[i]->setAlignment(Qt::AlignCenter);
        if ((0 == (i % 7)) || (6 == (i% 7))) {
            labelWeek[i]->setProperty("weekend", true);
            labelWeek[i]->setObjectName("labelWeekend");
        }
        horLayoutWeek->addWidget(labelWeek[i]);
    }

    verLayoutCalendar->addWidget(widgetWeek);
    //! [2]

    //! [3] 主体日期
    widgetBody = new QWidget(this);
    verLayoutCalendar->addWidget(widgetBody, 1);
    gridLayoutBody = new QGridLayout(widgetBody);
    gridLayoutBody->setHorizontalSpacing(0);
    gridLayoutBody->setVerticalSpacing(0);
    gridLayoutBody->setContentsMargins(0, 0, 0, 0);

    for (int i = 0; i < 42; i++) {
        labelDay[i] = new DayLabel(widgetBody);
        labelDay[i]->setObjectName("labelDay");
        labelDay[i]->setAlignment(Qt::AlignCenter);
        labelDay[i]->setText(QString::number(i));
        if ((0 == (i % 7)) || (6 == (i% 7))) {
            labelDay[i]->setProperty("weekend", true);
        }
        gridLayoutBody->addWidget(labelDay[i], i / 7, i % 7);
        connect(labelDay[i], SIGNAL(signalClicked(int,int)), this, SLOT(sltDayClicked(int,int)));
    }
    //! [3]

    //! [4] 底栏行
    widget_bottom = new QWidget(this);
    pushBtn_Rtn = new QPushButton(this);
    pushBtn_Now = new QPushButton(this);
    pushBtn_Ok = new QPushButton(this);
    pushBtn_Rtn->setFixedSize(67, 23);
    pushBtn_Now->setFixedSize(67, 23);
    pushBtn_Ok->setFixedSize(67, 23);

    pushBtn_Rtn->setText(LC_STR("返回今天"));
    pushBtn_Now->setText(LC_STR("此刻"));
    pushBtn_Ok->setText(LC_STR("确定"));

    QHBoxLayout* hBottomLay = new QHBoxLayout(widget_bottom);
    hBottomLay->setContentsMargins(25, 0, 25, 13);
    hBottomLay->addWidget(pushBtn_Rtn);
    hBottomLay->addStretch(1);
    hBottomLay->addWidget(pushBtn_Now);
    hBottomLay->addStretch(1);
    hBottomLay->addWidget(pushBtn_Ok);
    verLayoutCalendar->addWidget(widget_bottom);

    connect(pushBtn_Rtn, SIGNAL(clicked()), this, SLOT(slotPushBtnRtn()));
    connect(pushBtn_Now, SIGNAL(clicked()), this, SLOT(slotPushBtnNow()));
    connect(pushBtn_Ok, SIGNAL(clicked()), this, SLOT(slotPushBtnOk()));
    //! [4]
}

/**
 * @brief CalendarWidget::initDate 初始化日期
 */
void CalendarWidget::initDate()
{
    // 首先判断当前月的第一天是星期几
    int nWeek  = Date::getFirstDayOfWeek(m_nYear, m_nMonth);
    int nMonthDays = Date::getMonthDays(m_nYear, m_nMonth);
    // 上月天数
    int nPreMonDays = Date::getMonthDays(1 == m_nMonth ? m_nYear - 1 : m_nYear, 1 == m_nMonth ? 12 : m_nMonth - 1);

    // 显示上月剩余天数
    if (0 == nWeek) {
        // 显示上月天数
        for (int i = 0; i < 7; i++) {
            labelDay[i]->showDay((nPreMonDays - 7 + i + 1), Date::getLunarDate(m_nYear, m_nMonth, nPreMonDays - 7 + i + 1));
            labelDay[i]->setColor(PREV_MONTH_DAY);
        }
        // 显示下月天数
        for (int i = 0; i < (42 - nMonthDays - 7); i++) {
            labelDay[nMonthDays + 7 + i]->showDay((i + 1), Date::getLunarDate(m_nYear, m_nMonth, i + 1));
            labelDay[nMonthDays + 7 + i]->setColor(NEXT_MONTH_DAY);
        }
    }
    else {
        for (int i = 0; i < nWeek; i++) {
            labelDay[i]->showDay((nPreMonDays - nWeek + i + 1), Date::getLunarDate(m_nYear, m_nMonth, (nPreMonDays - nWeek + i + 1)));
            labelDay[i]->setColor(PREV_MONTH_DAY);
        }

        // 显示下月天数
        for (int i = (nWeek + nMonthDays); i < 42; i++) {
            labelDay[i]->showDay((i - (nWeek + nMonthDays) + 1), Date::getLunarDate(m_nYear, m_nMonth, (i - (nWeek + nMonthDays) + 1)));
            labelDay[i]->setColor(NEXT_MONTH_DAY);
        }
    }

    // 显示当前月
    int nProperty = 1;
    int index = 0;
    for (int i = nWeek; i < (nMonthDays + nWeek); i++) {
        index = (0 == nWeek ? (i + 7) : i);
        labelDay[index]->showDay(i - nWeek + 1, Date::getLunarDate(m_nYear, m_nMonth, i - nWeek + 1));
        nProperty = (((0 == (i % 7)) || (6 == (i% 7))) ? WEEKEND_DAY : CURR_MONTH_DAY);
        labelDay[index]->setColor(nProperty);
    }

    //  如果现在显示的是当前月，则设置当前的日期
    QDate d = QDate::currentDate();
    if(d == QDate(m_nYear, m_nMonth, d.day()))
    {
        getDayLabel(m_nYear, m_nMonth, d.day())->setColor(CURRENT_DAY);
    }
}

/**
 * @brief CalendarWidget::sltDayClicked 点击响应
 * @param type  类型 0 表示上月 1表示下月
 * @param day  当前点击的天数
 */
void CalendarWidget::sltDayClicked(int type, int day)
{
    // 上月
    if (PREV_MONTH_DAY == type) {
        sltShowPrevMonth();
    }
    // 下月
    else if (NEXT_MONTH_DAY == type) {
        sltShowNextMonth();
    }
    // 当天/周末/当月天数都显示在右边，并转换成农历
    else if ((CURR_MONTH_DAY == type)
             || (WEEKEND_DAY == type)
             || (CURRENT_DAY == type)) {
        // 选中当天
        m_nDay = day;
        emit dayClicked(QDateTime(QDate(m_nYear, m_nMonth, m_nDay), QTime(m_nHour, m_nMin)));
    }

    //  更改当前选中项
    changeCurrentSelectDay();
}

/**
 * @brief CalendarWidget::sltShowPrevMonth 显示上月日期
 */
void CalendarWidget::sltShowPrevMonth()
{
    m_nMonth--;
    if (m_nMonth < 1) {
        m_nMonth = 12;
        m_nYear--;
    }

    setYear(m_nYear);
    setMonth(m_nMonth);
    initDate();
    // 发送更新信号
    emit dayClicked(QDateTime(QDate(m_nYear, m_nMonth, m_nDay), QTime(m_nHour, m_nMin)));
}

/**
 * @brief CalendarWidget::sltShowNextMonth 显示下月日期
 */
void CalendarWidget::sltShowNextMonth()
{
    m_nMonth++;
    if (m_nMonth > 12) {
        m_nMonth = 1;
        m_nYear++;
    }
    setYear(m_nYear);
    setMonth(m_nMonth);
    initDate();
    // 发送更新信号
    emit dayClicked(QDateTime(QDate(m_nYear, m_nMonth, m_nDay), QTime(m_nHour, m_nMin)));
}

void CalendarWidget::sltComboBoxDateChange(int)
{
    if(comboBox_Year->isVisible() && comboBox_Month->isVisible())
    {
        m_nYear = comboBox_Year->currentText().toInt();
        m_nMonth = comboBox_Month->currentIndex() + 1;

        int days = Date::getMonthDays(m_nYear, m_nMonth);
        if(m_nDay > days)
            m_nDay = days;

        initDate();

        //  更新当前选中项
        changeCurrentSelectDay();
        //qDebug()<<"sltComboBoxDateChange"<<"m_nYear"<<m_nYear<<"m_nMonth"<<m_nMonth<<"m_nDay"<<m_nDay<<"m_nHour"<<m_nHour<<"m_nMin"<<m_nMin;
        // 发送更新信号
        emit dayClicked(QDateTime(QDate(m_nYear, m_nMonth, m_nDay), QTime(m_nHour, m_nMin)));
    }
}

void CalendarWidget::sltComboBoxTimeChange(int)
{
    if(comboBox_Hour->isVisible() && comboBox_min->isVisible())
    {
        m_nHour = comboBox_Hour->currentIndex();
        m_nMin = comboBox_min->currentIndex();
        //qDebug()<<"sltComboBoxTimeChange"<<"m_nYear"<<m_nYear<<"m_nMonth"<<m_nMonth<<"m_nDay"<<m_nDay<<"m_nHour"<<m_nHour<<"m_nMin"<<m_nMin;
        emit dayClicked(QDateTime(QDate(m_nYear, m_nMonth, m_nDay), QTime(m_nHour, m_nMin)));
    }
}

void CalendarWidget::slotPushBtnRtn()
{
    jumpToDateTime(QDateTime::currentDateTime());
    emit dayClicked(QDateTime(QDate(m_nYear, m_nMonth, m_nDay), QTime(m_nHour, m_nMin)));
}

void CalendarWidget::slotPushBtnNow()
{
    slotPushBtnRtn();
    close();
}

void CalendarWidget::slotPushBtnOk()
{
    close();
}

//////////////////////////////////////
/// \brief DayLabel::DayLabel
/// \param parent
////////////////////////////////

#include <QMouseEvent>
#include <QEvent>
#include <QPixmap>

DayLabel::DayLabel(QWidget *parent):
    QLabel(parent)
{
    m_bSelect = false;
    m_nDay = 0;
    m_bHover = false;
}

bool DayLabel::getBSelect() const
{
    return m_bSelect;
}

void DayLabel::setSelected(bool value)
{
    m_bSelect = value;
    update();
}

void DayLabel::setColor(int type)
{
    // 设置控件属性类型
    this->setProperty("type", type);

    update();
}

/**
 * @brief DayLabel::showDay
 * @param nDay
 * @param strLunar
 * @param type
 */
void DayLabel::showDay(int nDay, QString strLunar)
{
    m_strText = QString::number(nDay);
    m_nDay = nDay;

#if Has_Lunar    //  显示农历
    if ("" != strLunar) {
        m_strText.append("\n");
        m_strText.append(strLunar);
    }
#endif
}

void DayLabel::enterEvent(QEvent *e)
{
    int nProperty = this->property("type").toInt();
    if (PREV_MONTH_DAY == nProperty || NEXT_MONTH_DAY == nProperty) return;

    m_bHover = true;
    update();

    QLabel::enterEvent(e);
}

void DayLabel::leaveEvent(QEvent *e)
{
    int nProperty = this->property("type").toInt();
    if (PREV_MONTH_DAY == nProperty || NEXT_MONTH_DAY == nProperty) return;

    m_bHover = false;
    update();

    QLabel::leaveEvent(e);
}

void DayLabel::mousePressEvent(QMouseEvent *e)
{
    emit signalClicked(this->property("type").toInt(), m_nDay);

    QLabel::mousePressEvent(e);
}

void DayLabel::mouseDoubleClickEvent(QMouseEvent *e)
{
//    int nProperty = this->property("type").toInt();
//    if (PREV_MONTH_DAY == nProperty || NEXT_MONTH_DAY == nProperty) return;

    QLabel::mouseDoubleClickEvent(e);
}

void DayLabel::paintEvent(QPaintEvent *e)
{
    QPainter p(this);
    p.setRenderHint(QPainter::Antialiasing, true);

    //  不是悬停
    if(!m_bHover)
    {
        //  选中
        if(m_bSelect)
        {
            p.setBrush(QBrush(QColor("#117dd9")));
            p.setPen(QPen(QColor("#117dd9"), 1));
#if Has_Lunar    //  显示农历
            p.drawRect(rect());
#else
            p.drawEllipse(rect().center(), 12, 12);
#endif
            p.setPen(QPen(QColor("#ffffff"), 1));
            p.drawText(rect(), Qt::AlignCenter, m_strText);
        }
        else
        {
            int type = this->property("type").toInt();
            //  当前日
            if(CURRENT_DAY == type)
            {
                p.setPen(QPen(QColor("#117dd9"), 1));
#if Has_Lunar    //  显示农历
                p.drawRect(rect());
#else
                p.drawEllipse(rect().center(), 12, 12);
#endif
                p.setPen(QPen(QColor("#cadfff"), 1));
                p.drawText(rect(), Qt::AlignCenter, m_strText);
            }
            // 其他月
            else if ((PREV_MONTH_DAY == type) || (NEXT_MONTH_DAY == type)) {
                p.setPen(QPen(QColor("#2360bc"), 1));
                p.drawText(rect(), Qt::AlignCenter, m_strText);
            }
            // 当前月
            else if (CURR_MONTH_DAY == type) {
                p.setPen(QPen(QColor("#cadfff"), 1));
                p.drawText(rect(), Qt::AlignCenter, m_strText);
            }
            // 周末
            else if (WEEKEND_DAY == type) {
                p.setPen(QPen(QColor("#00caff"), 1));
                p.drawText(rect(), Qt::AlignCenter, m_strText);
            }
        }
    }
    //  悬停的效果
    else
    {
        p.setBrush(QBrush(QColor("#117dd9")));
        p.setPen(QPen(QColor("#117dd9"), 1));
#if Has_Lunar    //  显示农历
        p.drawRect(rect());
#else
        p.drawEllipse(rect().center(), 12, 12);
#endif
        p.setPen(QPen(QColor("#ffffff"), 1));
        p.drawText(rect(), Qt::AlignCenter, m_strText);
    }


//    QLabel::paintEvent(e);
}
