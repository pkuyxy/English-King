// homepage.cpp
#include "homepage.h"
#include <QLabel>

HomePage::HomePage(QWidget *parent) : QWidget(parent) {
    QLabel *background = new QLabel(this);
    background->setPixmap(QPixmap(":/resources/bg.jpg"));  // 使用资源文件
    background->setScaledContents(true);  // 缩放图片以适应 QLabel
    background->setGeometry(-100, -100, 1500, 1500);  // 铺满整个窗口

    // 确保背景在最底层
    background->raise();
    QVBoxLayout *layout = new QVBoxLayout(this);

    // 标题
    QLabel *title = new QLabel("主页面", this);
    title->setAlignment(Qt::AlignCenter);
    title->setStyleSheet("font-size: 24px; font-weight: bold;");
    layout->addWidget(title);

    // 按钮1 - 团队介绍
    teamButton = new QPushButton("主创团队", this);
    teamButton->setFixedSize(200, 50);
    connect(teamButton, &QPushButton::clicked, this, &HomePage::showTeamPage);

    // 按钮2 - 设置
    settingsButton = new QPushButton("设置", this);
    settingsButton->setFixedSize(200, 50);
    connect(settingsButton, &QPushButton::clicked, this, &HomePage::showSettingsPage);

    // 按钮3 - 模式
    modeButton = new QPushButton("模式",this);
    modeButton->setFixedSize(200,50);
    connect(modeButton,&QPushButton::clicked,this,&HomePage::showModePage);

    // 按钮4 - 天梯
    tiantiButton = new QPushButton("天梯", this);
    tiantiButton->setFixedSize(200, 50);
    connect(tiantiButton,&QPushButton::clicked,this,&HomePage::showtotiantiPage);

    // 添加到布局
    layout->addStretch();
    layout->addWidget(teamButton, 0, Qt::AlignCenter);
    layout->addWidget(settingsButton, 0, Qt::AlignCenter);
    layout->addWidget(modeButton, 0, Qt::AlignCenter);
    layout->addWidget(tiantiButton, 0, Qt::AlignCenter);
    layout->addStretch();

    setLayout(layout);
}


