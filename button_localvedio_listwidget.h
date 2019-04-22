#ifndef BUTTON_LOCALVEDIO_LISTWIDGET_H
#define BUTTON_LOCALVEDIO_LISTWIDGET_H
#include "window_common.h"

class button_localVedio_listWidget : public QWidget
{
    //注意：要添加槽函数必须自己添加Q_OBJECT，然后要重新qmake一下，不然编译会报错
    Q_OBJECT
public:
    button_localVedio_listWidget();

    ~button_localVedio_listWidget();
    void init();
    static button_localVedio_listWidget* instance();
    static button_localVedio_listWidget* m_instance;

    bool show_listWidget();
    bool hide_listWidget();

    bool change_listWidget_show_statu();

private:
    void set_lists();
    bool add_one_widgetItem(const char* name);
private slots:
    void changePage(QListWidgetItem *current, QListWidgetItem *previous);

private:
    QListWidget *m_list;
    bool m_showStatu;//当前的显示状态，true:显示，false:隐藏
    QFont m_font;
    int m_font_size;//字体大小
    int m_item_cnt;//item实际个数
    int m_curr_item;//光标当前所停留的item
    QListWidgetItem* m_listItem[6];
};

#endif // BUTTON_LOCALVEDIO_LISTWIDGET_H
