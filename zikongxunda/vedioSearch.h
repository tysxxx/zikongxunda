#ifndef VEDIOSEARCH_H
#define VEDIOSEARCH_H

#include <QMenu>
#include <QComboBox>
#include <QListView>
#include <QStyledItemDelegate>
#include <QTreeView>
#include <QTableView>
#include <QHeaderView>
#include <QStandardItemModel>
#include <QScrollBar>
#include "./UI/ui_vediosearch.h"
#include "dateTimeButton.h"
#include "window_common.h"
#include "mediaplayer.h"

class vedioSearch : public QDialog, private Ui::vedioSearch
{
    Q_OBJECT

public:
    explicit vedioSearch(QWidget *parent = 0);
    bool goToInitStatu();//回到初始化时的状态
    static bool getMediasFileList(list<FILE_PROPERTY_ST>* p_list);
private:
    void paintEvent( QPaintEvent* );
    void setDownloadButtonFocusStyle();
    void setDownloadButtonNoFocusStyle();
    void setPlayButtonFocusStyle();
    void setPlayButtonNoFocusStyle();
    void createTableView();
    bool addOneLine(FILE_PROPERTY_ST* p_fileProperty);
    bool deleteLine(int line,int cnt);//删除行，line：第几行开始，cnt：总共删除多少行
    bool cleanTable();//清空表格
    void creatMediaPlayer();
    bool loadUpdateMediasFileList();
private slots:

    void clickDownloadButtonSlot();
    void clickPlayButtonSlot();
    void showCalendarWidgetSlot();
    void clickUploadButtonSlot();
    void dayClickedSlot(const QDateTime &dt);
    void clickSearchButtonSlot();
private:
    Ui::vedioSearch *ui;
    QDateTime m_dateTime;
    QString m_strFormat;
    CalendarWidget* m_calendarWidget;
    QGridLayout* m_gridLayout;
    QStackedWidget* m_stackedWidget;
    QTableView* m_tableView;
    QStandardItemModel* m_standardItemModel;
    mediaPlayer* m_playerWidget;
    int m_lineCnt;//表格的总行数
    int m_currLine;//当前在表格的第几行
    static list<FILE_PROPERTY_ST> m_show_file_list;
    list<DEVICEINFO_S> m_dev_list;
};

#endif // VEDIOSEARCH_H
