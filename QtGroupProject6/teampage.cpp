#include "teampage.h"
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QTextEdit>
#include <QGridLayout>
#include <QSpacerItem>

TeamPage::TeamPage(QWidget *parent) : QWidget(parent) {
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
    backButton = new QPushButton("← 返回主页", this);
    backButton->setFixedSize(120, 40);
    backButton->setStyleSheet(
        "QPushButton {"
        "   background: rgba(255, 255, 255, 180);"
        "   border: black;"
        "   border-radius: 5px;"
        "   padding: 5px;"
        "   font-size: 14px;"
        "   color: #333;"
        "}"
        "QPushButton:hover {"
        "   background: rgba(255, 255, 255, 220);"
        "}"
        );
    connect(backButton, &QPushButton::clicked, this, &TeamPage::backToHome);
    mainLayout->addWidget(backButton, 0, 0, 1, 1, Qt::AlignLeft | Qt::AlignTop);

    // 内容区域（居中）
    QWidget *contentWidget = new QWidget(this);
    contentWidget->setFixedWidth(500);  // 比之前稍宽以适应文本内容
    QVBoxLayout *contentLayout = new QVBoxLayout(contentWidget);
    contentLayout->setContentsMargins(25, 25, 25, 25);
    contentLayout->setSpacing(20);

    // 1. 主创团队标题
    QLabel *title = new QLabel("主创团队", contentWidget);
    title->setAlignment(Qt::AlignCenter);
    title->setStyleSheet(
        "QLabel {"
        "   font-size: 24px;"
        "   font-weight: bold;"
        "   color: #333;"
        "   padding-bottom: 10px;"
        "}"
        );

    // 2. 团队成员名单（水平排列）
    QWidget *teamListWidget = new QWidget(contentWidget);
    QHBoxLayout *teamListLayout = new QHBoxLayout(teamListWidget);
    teamListLayout->setSpacing(30);  // 增加成员间距
    teamListLayout->setContentsMargins(10, 0, 10, 0);  // 增加左右边距

    // 团队成员标签样式
    QString memberStyle =
        "QLabel {"
        "   font-size: 18px;"
        "   font-weight: bold;"
        "   min-width: 80px;"
        "   color: #444;"
        "   padding: 8px 12px;"
        "   background: rgba(255, 255, 255, 150);"
        "   border-radius: 5px;"
        "}";

    auto createMemberLabel = [](const QString& name) -> QLabel* {
        QLabel *label = new QLabel(name);
        label->setStyleSheet(
            "QLabel {"
            "   font-size: 16px;"
            "   min-width: 80px;"
            "   padding: 8px 12px;"
            "   background: rgba(255, 255, 255, 150);"
            "   border-radius: 5px;"
            "   color: black;"
            "}"
            );
        label->setAlignment(Qt::AlignCenter);
        label->setMinimumWidth(80);
        label->setSizePolicy(QSizePolicy::MinimumExpanding, QSizePolicy::Fixed);
        return label;
    };

    teamListLayout->addWidget(createMemberLabel("杨浩宇"));
    teamListLayout->addWidget(createMemberLabel("苏洪令"));
    teamListLayout->addWidget(createMemberLabel("杨新懿"));
    teamListLayout->addWidget(createMemberLabel("deepseek"));

    // 3. 功能介绍文本区域
    QTextEdit *description = new QTextEdit(contentWidget);
    description->setPlainText(
        "功能介绍:\n\n"
        "1. 设置页面可以调节背景音量大小，还可以分别改变中英文字体\n"
        "2. 模式界面有五个模式、四个难度可供选择：\n"
        "   - 训练模式：无限练习\n"
        "   - 天梯模式：10道题挑战\n"
        "   - 错题模式：从错题集中练习\n"
        "   - 自定义模式：使用自定义题库\n"
        "   - 自定义加单词：添加单词到自定义题库\n"
        "3. 排行榜界面显示天梯模式前五名成绩\n"
        "   - 完全正确: 2分\n"
        "   - 部分正确: 1分\n"
        "   - 错误或未选: 0分"
        );
    description->setReadOnly(true);
    description->setFixedHeight(250);  // 稍高以适应更多内容
    description->setStyleSheet(
        "QTextEdit {"
        "   background: rgba(255, 255, 255, 180);"
        "   border-radius: 10px;"
        "   padding: 15px;"
        "   font-size: 14px;"
        "   border: 1px solid #ddd;"
        "   color: black;"
        "}"
        );

    // 将所有部件添加到内容布局
    contentLayout->addWidget(title);
    contentLayout->addWidget(teamListWidget);
    contentLayout->addSpacing(15);
    contentLayout->addWidget(description);
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

    setWindowTitle("关于我们");
    setMinimumSize(600, 550);  // 调整最小窗口大小
}
