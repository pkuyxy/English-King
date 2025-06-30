#include "totiantipage.h"
#include "tiantipage1.h"
#include "tiantipage2.h"
#include "tiantipage3.h"
#include "tiantipage4.h"
#include <QLabel>
#include <QGridLayout>
#include <QVBoxLayout>
#include <QSpacerItem>

int TiantiPage1::Tiantidifficulty=0;
int TiantiPage2::Tiantidifficulty=1;
int TiantiPage3::Tiantidifficulty=2;
int TiantiPage4::Tiantidifficulty=3;

TotiantiPage::TotiantiPage(QWidget *parent) : QWidget(parent) {
    // 背景设置
    QLabel *background = new QLabel(this);
    background->setPixmap(QPixmap(":/resources/bg.jpg"));
    background->setScaledContents(true);
    background->setGeometry(-100, -100, 1500, 1500);
    background->lower();

    // 主布局（网格布局）
    QGridLayout *mainLayout = new QGridLayout(this);
    mainLayout->setContentsMargins(20, 20, 20, 20);
    mainLayout->setSpacing(15);

    // 返回按钮（左上角）
    BackButton = new QPushButton("← 返回主页", this);
    BackButton->setFixedSize(120, 40);
    BackButton->setStyleSheet(
        "QPushButton {"
        "   background: rgba(255, 255, 255, 180);"
        "   border: 1px solid #ddd;"
        "   border-radius: 5px;"
        "   padding: 5px;"
        "   font-size: 14px;"
        "   color: #333;"
        "}"
        "QPushButton:hover {"
        "   background: rgba(255, 255, 255, 220);"
        "}"
        );
    connect(BackButton, &QPushButton::clicked, this, &TotiantiPage::backToHome);
    mainLayout->addWidget(BackButton, 0, 0, 1, 1, Qt::AlignLeft | Qt::AlignTop);

    // 内容区域（居中）
    QWidget *contentWidget = new QWidget(this);
    contentWidget->setFixedWidth(350);
    QVBoxLayout *contentLayout = new QVBoxLayout(contentWidget);
    contentLayout->setContentsMargins(25, 25, 25, 25);
    contentLayout->setSpacing(20);

    // 标题
    QLabel *title = new QLabel("天梯排行", contentWidget);
    title->setAlignment(Qt::AlignCenter);
    title->setStyleSheet(
        "QLabel {"
        "   font-size: 24px;"
        "   font-weight: bold;"
        "   color: #333;"
        "   padding-bottom: 10px;"
        "}"
        );

    // 难度选择按钮
    difficulty1Button = new QPushButton("初中水平", contentWidget);
    difficulty2Button = new QPushButton("高中水平", contentWidget);
    difficulty3Button = new QPushButton("四级水平", contentWidget);
    difficulty4Button = new QPushButton("六级水平", contentWidget);

    // 设置按钮样式
    QString buttonStyle =
        "QPushButton {"
        "   background: rgba(255, 255, 255, 180);"
        "   border: 1px solid #ddd;"
        "   border-radius: 5px;"
        "   padding: 10px;"
        "   font-size: 16px;"
        "   min-height: 40px;"
        "}"
        "QPushButton:hover {"
        "   background: rgba(255, 255, 255, 220);"
        "}";

    difficulty1Button->setStyleSheet(buttonStyle);
    difficulty2Button->setStyleSheet(buttonStyle);
    difficulty3Button->setStyleSheet(buttonStyle);
    difficulty4Button->setStyleSheet(buttonStyle);

    // 连接信号
    connect(difficulty1Button, &QPushButton::clicked, this, &TotiantiPage::showtianti1Page);
    connect(difficulty2Button, &QPushButton::clicked, this, &TotiantiPage::showtianti2Page);
    connect(difficulty3Button, &QPushButton::clicked, this, &TotiantiPage::showtianti3Page);
    connect(difficulty4Button, &QPushButton::clicked, this, &TotiantiPage::showtianti4Page);

    // 添加到内容布局
    contentLayout->addWidget(title);
    contentLayout->addSpacing(15);
    contentLayout->addWidget(difficulty1Button);
    contentLayout->addWidget(difficulty2Button);
    contentLayout->addWidget(difficulty3Button);
    contentLayout->addWidget(difficulty4Button);
    contentLayout->addStretch();

    // 内容区域半透明背景
    contentWidget->setStyleSheet(
        "QWidget {"
        "   background: rgba(255, 255, 255, 120);"
        "   border-radius: 10px;"
        "}"
        );

    // 将内容区域居中
    mainLayout->addWidget(contentWidget, 1, 0, 1, 1, Qt::AlignCenter);
    setLayout(mainLayout);

    setWindowTitle("天梯排行");
    setMinimumSize(400, 500);
}
