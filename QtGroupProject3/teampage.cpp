// teampage.cpp
#include "teampage.h"
#include <QVBoxLayout>

TeamPage::TeamPage(QWidget *parent) : QWidget(parent) {
    QLabel *background = new QLabel(this);
    background->setPixmap(QPixmap(":/resources/bg.jpg"));  // 使用资源文件
    background->setScaledContents(true);  // 缩放图片以适应 QLabel
    background->setGeometry(-100, -100, 1500, 1500);  // 铺满整个窗口

    // 确保背景在最底层
    background->raise();
    QVBoxLayout *layout = new QVBoxLayout(this);

    // 返回按钮
    backButton = new QPushButton("返回主页", this);
    connect(backButton, &QPushButton::clicked, this, &TeamPage::backToHome);

    // 团队介绍内容
    QLabel *title = new QLabel("主创团队", this);
    title->setAlignment(Qt::AlignCenter);
    title->setStyleSheet("font-size: 24px; font-weight: bold;");

    QLabel *member1 = new QLabel("项目经理: 张三", this);
    QLabel *member2 = new QLabel("开发工程师: 李四", this);
    QLabel *member3 = new QLabel("UI设计师: 王五", this);
    QLabel *member4 = new QLabel("测试工程师: 赵六", this);

    // 添加到布局
    layout->addWidget(backButton);
    layout->addWidget(title);
    layout->addStretch();
    layout->addWidget(member1);
    layout->addWidget(member2);
    layout->addWidget(member3);
    layout->addWidget(member4);
    layout->addStretch();

    setLayout(layout);
}
