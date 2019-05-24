#include "intercomui.h"
#include <QStyleOption>
#include <QPainter>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QApplication>
#include <QDebug>
#include <QScrollBar>

IntercomUi::IntercomUi(QRect rect, QWidget *parent) : QWidget(parent)
{
    qDebug() << "IntercomUi: " << rect;
    //resize(rect.width(), rect.height());
    setGeometry(rect);
    init();

}

IntercomUi::~IntercomUi()
{

}

//初始化
void IntercomUi::init()
{
    qDebug()<< "IntercomUi geometry: " << geometry();
    //界面设置
    setWindowFlags((Qt::FramelessWindowHint));
    //setAttribute(Qt::WA_TranslucentBackground);
    //setStyleSheet(".QWidget{border: 1px solid gray;}");

    //左侧窗口
        //@.按键
    userInteractBtn = new QPushButton(tr("互动对讲"));
    userInteractBtn->setProperty("valid", true);
    userInteractBtn->setStyleSheet("QPushButton{border: 2px solid white; border-right:none; \
                                                border-top-left-radius: 10px; border-bottom-left-radius: 10px; \
                                                background-color: transparent; color: white; height: 46px; width: 137px; font:21px}"
                                   "QPushButton[valid=true]{background-color: #649bf1;}");

    groupInteractBtn = new QPushButton(tr("群组对讲"));
    groupInteractBtn->setProperty("valid", false);
    groupInteractBtn->setStyleSheet("QPushButton{border: 2px solid white; border-left:none; \
                                                 border-top-right-radius: 10px; border-bottom-right-radius: 10px; \
                                                 background-color: transparent; color: white; height: 46px; width:137px; font:21px}"
                                    "QPushButton[valid=true]{background-color: #649bf1;}");

    buttonGroup = new QButtonGroup;
    buttonGroup->addButton(userInteractBtn);
    buttonGroup->addButton(groupInteractBtn);
    connect(buttonGroup, SIGNAL(buttonClicked(QAbstractButton*)), SLOT(btnClickedSlot(QAbstractButton*)));
    lastBtnId = buttonGroup->id(userInteractBtn);

    QHBoxLayout *interactHBoxLayout = new QHBoxLayout;
    interactHBoxLayout->setMargin(0);
    interactHBoxLayout->setSpacing(0);
    interactHBoxLayout->addWidget(userInteractBtn);
    interactHBoxLayout->addWidget(groupInteractBtn);
    interactHBoxLayout->addStretch();

        //@.用户列表
    userInteractTreeWidget = new QTreeWidget;
    userInteractTreeWidget->setExpandsOnDoubleClick(false);
    connect(userInteractTreeWidget, SIGNAL(itemClicked(QTreeWidgetItem*,int)),
            this, SLOT(userInteractItemClickedSlot(QTreeWidgetItem*,int)));
    userInteractTreeWidget->setStyleSheet(".QTreeWidget{background-color: transparent; font: 21px; color: white; border: none; padding-left:0px;}\
                                           .QTreeWidget::item{margin: 10px;}");
    userInteractTreeWidget->setAutoFillBackground(true);
    userInteractTreeWidget->setHeaderHidden(true);
    userInteractTreeWidget->setColumnCount(1);
    userInteractTreeWidget->verticalScrollBar()->setStyleSheet(".QScrollBar{background-color: transparent; width:10px; border:none; border-radius:5px;}\
                                        .QScrollBar::handle{background: gray; border:2px solid gray; border-radius:5px;}\
                                        .QScrollBar::sub-line{background:transparent; width: 0px; height: 0px;}\
                                        .QScrollBar::add-line{background:transparent; width: 0px; height: 0px;}");

        //@.组织列表
    groupInteractListWidget = new QListWidget;
    connect(groupInteractListWidget, SIGNAL(itemClicked(QListWidgetItem*)),
            this, SLOT(groupInteractItemClickedSlot(QListWidgetItem*)));
    groupInteractListWidget->setStyleSheet(".QListWidget{background-color: transparent; font: 21px; color: white; border: none; padding-left:0px;}\
                                           .QListWidget::item{margin: 10px;}");

    groupInteractListWidget->verticalScrollBar()->setStyleSheet(".QScrollBar{background-color: transparent; width:10px; border:none; border-radius:5px;}\
                                        .QScrollBar::handle{background: gray; border:2px solid gray; border-radius:5px;}\
                                        .QScrollBar::sub-line{background:transparent; width: 0px; height: 0px;}\
                                        .QScrollBar::add-line{background:transparent; width: 0px; height: 0px;}");

    listStackedLayout = new QStackedLayout;
    listStackedLayout->setMargin(0);
    listStackedLayout->addWidget(userInteractTreeWidget);
    listStackedLayout->addWidget(groupInteractListWidget);
    listStackedLayout->setCurrentWidget(userInteractTreeWidget);
        //@.布局
    QVBoxLayout *leftMainUiVBoxLayout = new QVBoxLayout;
    leftMainUiVBoxLayout->addSpacing(20);
    leftMainUiVBoxLayout->setSpacing(20);
    leftMainUiVBoxLayout->addLayout(interactHBoxLayout);
    leftMainUiVBoxLayout->addLayout(listStackedLayout);

    QFrame *leftFrame = new QFrame;
    //leftFrame->resize(width()/2, height());
    leftFrame->setFixedSize(width()/2, height());
    leftFrame->setStyleSheet("QFrame{background-color: #040b17; padding-left: 70px;}");
    leftFrame->setLayout(leftMainUiVBoxLayout);

    //右侧窗口
    QFrame *rightFrame = new QFrame;
    //rightFrame->resize(width()/2, height());
    rightFrame->setFixedSize(width()/2, height());
    rightFrame->setStyleSheet("QFrame{background-color: transparent}");

    qDebug() << "rightFrame: " << rightFrame->size();
    QRect rect;
        //@.上端小矩形框
    QFrame *topRect = new QFrame(rightFrame);
    topRect->setStyleSheet(".QFrame{background-color: #040b17;}");
    rect = QRect(0,
                 0,
                 rightFrame->width(),
                 (rightFrame->height() - 544)/2
                 );
    topRect->setGeometry(rect);

        //@.底部小矩形框
    QFrame *bottomRect = new QFrame(rightFrame);
    bottomRect->setStyleSheet(".QFrame{background-color: #040b17;}");
    rect = QRect(0,
                 topRect->height()+544,
                 rightFrame->width(),
                 (rightFrame->height() - 544)/2
                 );
    bottomRect->setGeometry(rect);

        //@.左小矩形框
    QFrame *leftRect = new QFrame(rightFrame);
    leftRect->setStyleSheet(".QFrame{background-color: #040b17;}");
    rect = QRect(0,
                 topRect->height(),
                 (rightFrame->width()-397)/2,
                 rightFrame->height()-topRect->height() - bottomRect->height()
                 );
    leftRect->setGeometry(rect);

        //@.右小矩形框
    QFrame *rightRect = new QFrame(rightFrame);
    rightRect->setStyleSheet(".QFrame{background-color: #040b17;}");
    rect = QRect(leftRect->width()+397,
                 topRect->height(),
                 (rightFrame->width()-397)/2,
                 rightFrame->height()-topRect->height() - bottomRect->height()
                 );
    rightRect->setGeometry(rect);

        //@.中间小矩形框
            //@.用户显示
    userIntercomShow = new QFrame(rightFrame);
    userIntercomShow->setStyleSheet(".QFrame{background-color: rgba(6, 32, 70, 80%);}");
    rect = QRect(leftRect->width(),
                 topRect->height(),
                 397,
                 544
                 );
    userIntercomShow->setGeometry(rect);

    QLabel *userIcon = new QLabel;
    userIcon->setAlignment(Qt::AlignCenter);
    userIcon->setPixmap(QPixmap(":/statusLog/resource/icon/头像.png"));
    userIcon->setStyleSheet("QLabel{background-color: transparent;}");

    QLabel *userIcon1 = new QLabel;
    userIcon1->setAlignment(Qt::AlignCenter);
    userIcon1->setPixmap(QPixmap(":/statusLog/resource/icon/头像.png"));
    userIcon1->setStyleSheet("QLabel{background-color: transparent;}");

    QLabel *userIcon2 = new QLabel;
    userIcon2->setAlignment(Qt::AlignCenter);
    userIcon2->setPixmap(QPixmap(":/statusLog/resource/icon/头像.png"));
    userIcon2->setStyleSheet("QLabel{background-color: transparent;}");

    QLabel *userIcon3 = new QLabel;
    userIcon3->setAlignment(Qt::AlignCenter);
    userIcon3->setPixmap(QPixmap(":/statusLog/resource/icon/头像.png"));
    userIcon3->setStyleSheet("QLabel{background-color: transparent;}");


    QLabel *userName = new QLabel;
    userName->setAlignment(Qt::AlignCenter);
    userName->setText("admin1");
    userName->setStyleSheet("QLabel{background-color: transparent; color: white; font:21px;}");

    QVBoxLayout *userInfoVBoxLayout = new QVBoxLayout;
    userInfoVBoxLayout->setMargin(0);
    userInfoVBoxLayout->addSpacing(5);
    userInfoVBoxLayout->addWidget(userIcon);
    userInfoVBoxLayout->addWidget(userName);
    userInfoVBoxLayout->addSpacing(50);

    userFlowLayout = new QFlowLayout;
    userFlowLayout->setContentsMargins(30, 0, 0, 0);
    userFlowLayout->setAlignment(Qt::AlignCenter);
    userFlowLayout->addWidget(userIcon);
    //userFlowLayout->addChildLayout(userInfoVBoxLayout);
//    userFlowLayout->addWidget(userIcon1);
//    userFlowLayout->addWidget(userIcon2);
//    userFlowLayout->addWidget(userIcon3);

    intercomStatusLabel = new QLabel(tr("通话中"));
    intercomStatusLabel->setAlignment(Qt::AlignCenter);
    intercomStatusLabel->setStyleSheet("QLabel{font:21px; background-color:transparent; color:#0dee44;}");

    intercomExitBtn = new QPushButton(tr("退出"));
    intercomExitBtn->setFixedSize(150, 50);
    intercomExitBtn->setStyleSheet("QPushButton{font: 24px; background-color:#649bf1;}");

    QHBoxLayout *intercomExitBtnHBoxLayout = new QHBoxLayout;
    intercomExitBtnHBoxLayout->addWidget(intercomExitBtn, Qt::AlignCenter);

    QVBoxLayout *userIntercomVBoxLayout = new QVBoxLayout;
    userIntercomVBoxLayout->setMargin(0);
    userIntercomVBoxLayout->setSpacing(20);
    userIntercomVBoxLayout->addSpacing(20);
    //userIntercomVBoxLayout->addLayout(userInfoVBoxLayout);
    userIntercomVBoxLayout->addLayout(userFlowLayout);
    userIntercomVBoxLayout->addWidget(intercomStatusLabel);
    userIntercomVBoxLayout->addLayout(intercomExitBtnHBoxLayout);
    userIntercomVBoxLayout->addSpacing(30);

    userIntercomShow->setLayout(userIntercomVBoxLayout);

            //@.组织显示
    groupIntercomShow = new QFrame(rightFrame);
    groupIntercomShow->setStyleSheet("QFrame{background-color: rgba(6, 32, 70, 80%);}");
    groupIntercomShow->setGeometry(rect);

            //@.
    intercomShowStackedLayout = new QStackedLayout;
    intercomShowStackedLayout->addWidget(userIntercomShow);
    intercomShowStackedLayout->addWidget(groupIntercomShow);
    intercomShowStackedLayout->setCurrentWidget(userIntercomShow);

    //总布局
    QHBoxLayout *mainUiHBoxLayout = new QHBoxLayout;
    mainUiHBoxLayout->setMargin(0);
    mainUiHBoxLayout->setSpacing(2);
    mainUiHBoxLayout->addWidget(leftFrame, 1); //均分
    mainUiHBoxLayout->addWidget(rightFrame, 1);

    setLayout(mainUiHBoxLayout);

    //
    manager = Manager::instance();
    connect(manager.data(), SIGNAL(loadUserInteractList(groupListType&,categoryListType&,userListType&)),
            this, SLOT(loadUserInteractList(groupListType&,categoryListType&,userListType&)));
    connect(manager.data(), SIGNAL(loadGroupInteractList(intercomListType&)),
            this, SLOT(loadGroupInteractList(intercomListType&)));
}

//重载paintEvent事件
void IntercomUi::paintEvent(QPaintEvent *)
{
    QStyleOption opt;
    opt.init(this);
    QPainter painter(this);
    style()->drawPrimitive(QStyle::PE_Widget, &opt, &painter, this);
}

//按键处理
void IntercomUi::btnClickedSlot(QAbstractButton* button)
{
    buttonGroup->button(lastBtnId)->setProperty("valid", false);
    buttonGroup->button(lastBtnId)->style()->polish(buttonGroup->button(lastBtnId));
    button->setProperty("valid", true);
    button->style()->polish(button);

    lastBtnId = buttonGroup->id(button);
    if(button == userInteractBtn){
        listStackedLayout->setCurrentWidget(userInteractTreeWidget);
        intercomShowStackedLayout->setCurrentWidget(userIntercomShow);
    }else if(button == groupInteractBtn){
        listStackedLayout->setCurrentWidget(groupInteractListWidget);
        intercomShowStackedLayout->setCurrentWidget(groupIntercomShow);
    }
}


//加载用户互动对讲列表
void IntercomUi::loadUserInteractList(groupListType &group, categoryListType &groupCategory, userListType &user)
{
    //创建组节点
    QList<TreeWidgetItem *> groupListItem;
    QList<groupDetailType> groupDetailList;
    for (quint32 i = 0; i < group.total; ++i){
        TreeWidgetItem *item = new TreeWidgetItem(userInteractTreeWidget);
        item->setForeground(0, QColor("white"));
        item->setText(0, group.items.at(i).name);
        groupListItem.append(item);

        groupDetailType detail;
        detail.id = group.items.at(i).id;
        groupDetailList.append(detail);
    }


    //创建组织分类节点
    QList<TreeWidgetItem *> groupCategoryListItem;
    QList<groupCategoryDetailType> groupCategoryDetailList;
    for(quint32 i = 0; i < groupCategory.total; i++){
        TreeWidgetItem *item = new TreeWidgetItem;
        item->setForeground(0, QColor("white"));
        item->setText(0, groupCategory.items.at(i).name);
        groupCategoryListItem.append(item);

        groupCategoryDetailType detail;
        detail.group_id = groupCategory.items.at(i).group_id;
        detail.parent_id = groupCategory.items.at(i).parent_id;
        groupCategoryDetailList.append(detail);
    }

    //添加用户节点
    QList<TreeWidgetItem *> userListItem;
    QList<userDetailType> userDetailList;
    for(quint32 i = 0; i < user.total; i++){
        TreeWidgetItem *item = new TreeWidgetItem;
        //item->setForeground(0, QColor("white"));
        item->setText(0, user.items.at(i).name);
        item->setBackgroundColor(0, QColor("transparent"));
        userListItem.append(item);

        userDetailType detail;
        detail.group_id = user.items.at(i).group_id;
        detail.group_category_id = user.items.at(i).group_category_id;
        userDetailList.append(detail);
    }

    //用户添加到分组里面
    for(qint32 categoryIndex=0; categoryIndex < groupCategoryListItem.size(); categoryIndex++){
        for(qint32 userIndex=0; userIndex < userListItem.size(); userIndex++){
            if(userDetailList.at(userIndex).group_id == groupCategoryDetailList.at(categoryIndex).group_id
            && userDetailList.at(userIndex).group_category_id == groupCategoryDetailList.at(categoryIndex).id){
                groupCategoryListItem.at(categoryIndex)->addChild(userListItem.at(userIndex));
            }
        }
    }

    //分组添加到分组里面
    for(qint32 categoryIndex=0; categoryIndex < groupCategoryListItem.size(); categoryIndex++){
        for(qint32 subCategoryIndex=0; subCategoryIndex < groupCategoryListItem.size(); subCategoryIndex++){
            if(groupCategoryDetailList.at(subCategoryIndex).group_id == groupCategoryDetailList.at(categoryIndex).group_id
            && groupCategoryDetailList.at(subCategoryIndex).parent_id == groupCategoryDetailList.at(categoryIndex).id){
                groupCategoryListItem.at(categoryIndex)->addChild(groupCategoryListItem.at(subCategoryIndex));
            }
        }
    }

    //用户和分组放到组里面
    for(qint32 groupIndex = 0; groupIndex < groupListItem.size(); groupIndex++){

        //用户放入组
        for(qint32 userIndex=0; userIndex < userListItem.size(); userIndex++){
            if(userDetailList.at(userIndex).group_id == groupDetailList.at(groupIndex).id
            && userDetailList.at(userIndex).group_category_id == 0){
                groupListItem.at(groupIndex)->addChild(userListItem.at(userIndex));
            }
        }

        //分组加入组
        for(qint32 categoryIndex=0; categoryIndex < groupCategoryListItem.size(); categoryIndex++){
            if(groupCategoryDetailList.at(categoryIndex).group_id == groupDetailList.at(groupIndex).id)
                groupListItem.at(groupIndex)->addChild(groupCategoryListItem.at(categoryIndex));
        }
    }


    //清空
    //userInteractTreeWidget->clear();

    //添加总的列表
    //userInteractTreeWidget->addTopLevelItems(groupListItem);
    qApp->processEvents();

//    for(quint32 userIndex=0; userIndex < userListItem.size(); userIndex++)
//    {
//        //
//        QFrame *frame = new QFrame;
//        frame->setAttribute(Qt::WA_TranslucentBackground);
//        //frame->setStyleSheet("QFrame{background-color: transparent; padding: 0px;}");
//        qApp->processEvents();
//        QLabel *userName = new QLabel;
//        userName->setText(userListItem.at(userIndex)->text(0));
//        userName->setStyleSheet(".QLabel{background-color: transparent; color: white; font: 21px;}");
//        QPushButton *voiceBtn = new QPushButton(tr("对讲"));
//        voiceBtn->setStyleSheet(".QPushButton{background-color: transparent; color: white; font: 21px;}");
//        QPushButton *videoBtn = new QPushButton(tr("视频"));
//        videoBtn->setStyleSheet(".QPushButton{background-color: transparent; color: white; font: 21px;}");

//        QHBoxLayout *HBoxLayout = new QHBoxLayout;
//        HBoxLayout->setMargin(0);
//        HBoxLayout->addWidget(userName);
//        HBoxLayout->addStretch();
//        HBoxLayout->addWidget(voiceBtn);
//        HBoxLayout->addWidget(videoBtn);

//        frame->setLayout(HBoxLayout);
//        qApp->processEvents();
//        userInteractTreeWidget->setItemWidget(userListItem.at(userIndex), 0, frame);
//        qApp->processEvents();
//    }
}


//加载群组互动对讲列表
void IntercomUi::loadGroupInteractList(intercomListType &intercom)
{
    //清空
    groupInteractListWidget->clear();

    //加载
    for(qint32 i=0; i < intercom.total; i++){
        ListWidgetItem *item = new ListWidgetItem(groupInteractListWidget);
        item->setText(intercom.items.at(i).name);
    }
}


//项选择处理
void IntercomUi::userInteractItemClickedSlot(QTreeWidgetItem *item, int column)
{
    TreeWidgetItem *myItem = dynamic_cast<TreeWidgetItem*>(item);
    qDebug() << "child count:" << item->childCount();
    if(item->childCount()){
        if(item->isExpanded())
        item->setExpanded(false);
        else
          item->setExpanded(true);

        }
    qDebug() << "tree item" << myItem->text(column);
}


void IntercomUi::groupInteractItemClickedSlot(QListWidgetItem *item)
{
    ListWidgetItem *myItem = dynamic_cast<ListWidgetItem*>(item);
    qDebug() << "item clicked" << myItem->text();// << myItem->itemInfo().id << myItem->itemInfo().groupId;
}

