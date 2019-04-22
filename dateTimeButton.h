#ifndef DATETIMEBUTTON_H
#define DATETIMEBUTTON_H

#include <QPushButton>
#include <QWidget>
#include <QLabel>
#include <QDateTime>
#include <QDateTimeEdit>
#include <QString>
#include <QDebug>

QT_BEGIN_NAMESPACE
class QPushButton;
class QComboBox;
class QGroupBox;
class QLineEdit;
class QDate;
class QGridLayout;
class QHBoxLayout;
class QVBoxLayout;

class Event;
class DataBase;
QT_END_NAMESPACE


class CalendarWidget;
class dateTimeButton : public QPushButton
{
    Q_OBJECT
public:
    explicit dateTimeButton(QWidget *parent = 0);

    void setText(const QString &text);

public slots:
    void showCalendarWidget();

    QDateTime dateTime() const;
    QDate date() const;
    QTime time() const;

    void setDateTime(const QDateTime &dateTime);
    void setDate(const QDate &date);
    void setTime(const QTime &time);

    void setDateTimeRange(const QDateTime &min, const QDateTime &max);
    void dateTimeRange(QDateTime &min, QDateTime &max);

signals:
    void dateTimeChanged(const QDateTime &dateTime);

protected:
    void initStyleSheet();
    void initConnect();

protected slots:
    void slotDayClicked(const QDateTime & dt);

private:
    CalendarWidget* pCldrWgt;
    QDateTime m_dateTime;
    QString m_strFormat;
};

typedef enum {
    Sunday,
    Monday,
    Tuesday,
    Wednesday,
    Thursday,
    Friday,
    Saturday,
    Week
} E_WEEK;

typedef enum {
    PREV_MONTH_DAY,     // 上月剩余天数
    NEXT_MONTH_DAY,     // 下个月的天数
    CURR_MONTH_DAY,     // 当月天数
    WEEKEND_DAY,        // 周末
    SELECT_DAY,         // 选中的天
    CURRENT_DAY,        // 当天
} E_DAY;

///////////////////////////////////////////////
/// \brief The DayLabel class
/// 自定义的日子显示控件
///////////////////////////////////////////////
class DayLabel : public QLabel {
    Q_OBJECT

public:
    explicit DayLabel(QWidget *parent = 0);

    bool getBSelect() const;
    void setSelected(bool value);
    void setColor(int type);
    void showDay(int nDay, QString strLunar);

signals:
    void signalClicked(int ntype, int day);

private:
    QLabel *labelIcon;
    int m_nDay;
    bool m_bHover;
    bool m_bSelect;
    QString m_strText;

protected:
    void enterEvent(QEvent *e);
    void leaveEvent(QEvent *e);
    void mousePressEvent(QMouseEvent *e);
    void mouseDoubleClickEvent(QMouseEvent *e);
    void paintEvent(QPaintEvent* e);
};

/////////////////////////////////////////////////
/// \brief The CalendarWidget class
/// 日历界面
////////////////////////////////////////////////
class CalendarWidget : public QWidget
{
    Q_OBJECT

public:
    explicit CalendarWidget(QWidget *parent = 0, Qt::WindowFlags f = Qt::WindowFlags());
    ~CalendarWidget();

    int year() const;
    void setYear(int year);

    int month() const;
    void setMonth(int month);

    int day() const;
    void setDay(int day);

    int hour() const;
    void setHour(int h);

    int minute();
    void setMinute(int m);

    void jumpToDateTime(const QDateTime& dt);

    void setDateTimeRange(const QDateTime &min, const QDateTime &max);
    void dateTimeRange(QDateTime &min, QDateTime &max);

signals:
    void dayClicked(const QDateTime&);
    void selectDayChanged(const QDateTime&);

private:
    QVBoxLayout *verLayoutCalendar;

    QWidget *widgetTitle;
    QComboBox* comboBox_Year;
    QComboBox* comboBox_Month;

    QWidget *widgetWeek;
    QLabel *labelWeek[Week];
    QHBoxLayout *horLayoutWeek;

    QWidget *widgetBody;
    DayLabel *labelDay[42];
    QGridLayout *gridLayoutBody;

    QWidget *widgetRight;

    QLabel *labelShowToday;
    QLabel *labelShowWeek;
    QLabel *labelShowDay;
    QLabel *labelShowNYear;
    QLabel *labelShowLunarDate;
    QLabel *labelSpacer;
    QLabel *labelScheduleTitle;
    QLabel *labelSchedule;

    QWidget* widget_bottom;
    QComboBox* comboBox_Hour;
    QComboBox* comboBox_min;
    QLabel* label_splite;
    QPushButton* pushBtn_Rtn;
    QPushButton* pushBtn_Now;
    QPushButton* pushBtn_Ok;

    QVBoxLayout *verlayoutWidgetRight;

    QHBoxLayout *horLayoutGlobal;

private:
    int m_nYear;
    int m_nMonth;
    int m_nDay;
    int m_nHour;
    int m_nMin;
    QDateTime m_maxDt;
    QDateTime m_minDt;
    DayLabel* m_pCrtSelect;

private:
    void initWidget();
    void initDate();
    void initStyleSheet();
    void UpdateYear();
    DayLabel* getDayLabel(int y, int m, int d);
    void changeCurrentSelectDay();

protected:
    virtual void paintEvent(QPaintEvent* e);

private slots:
    void sltDayClicked(int type, int day);
    void sltShowPrevMonth();
    void sltShowNextMonth();
    void sltComboBoxDateChange(int);
    void sltComboBoxTimeChange(int);
    void slotPushBtnRtn();
    void slotPushBtnNow();
    void slotPushBtnOk();
};


#endif // DATETIMEBUTTON_H
