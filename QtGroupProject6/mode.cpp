#include "mode.h"
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QGridLayout>
#include <QPushButton>
#include <QLabel>
#include <QSpacerItem>

mode::mode(QWidget *parent): QDialog(parent), model(0), difficulty(0) {
    // 背景设置
    QLabel *background = new QLabel(this);
    background->setPixmap(QPixmap(":/resources/bg.jpg"));
    background->setScaledContents(true);
    background->setGeometry(-100, -100, 1500, 1500);
    background->lower();

    // 主布局（网格布局更灵活）
    QGridLayout *mainLayout = new QGridLayout(this);
    mainLayout->setContentsMargins(20, 20, 20, 20);
    mainLayout->setSpacing(15);

    // 返回按钮（固定在左上角）
    backButton = new QPushButton("← 返回主页", this);
    backButton->setFixedSize(120, 40);
    backButton->setStyleSheet(
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
    connect(backButton, &QPushButton::clicked, this, &mode::backToHome);
    mainLayout->addWidget(backButton, 0, 0, 1, 1, Qt::AlignLeft | Qt::AlignTop);

    // 内容区域（居中显示）
    QWidget *contentWidget = new QWidget(this);
    contentWidget->setFixedWidth(350);  // 固定内容宽度
    QVBoxLayout *contentLayout = new QVBoxLayout(contentWidget);
    contentLayout->setContentsMargins(25, 25, 25, 25);
    contentLayout->setSpacing(20);

    // 模式选择
    QLabel *modeLabel = new QLabel("选择模式:", this);
    modeLabel->setStyleSheet("font-size: 16px; font-weight: bold; color: #333;");

    modecombo = new QComboBox(this);
    modecombo->addItem("练习模式", 0);
    modecombo->addItem("天梯模式", 1);
    modecombo->addItem("错题模式", 2);
    modecombo->addItem("自定义模式(使用)", 3);
    modecombo->addItem("自定义模式(写入)", 4);
    modecombo->setStyleSheet(
        "QComboBox {"
        "   background: rgba(255, 255, 255, 180);"
        "   border: 1px solid #ddd;"
        "   border-radius: 4px;"
        "   padding: 8px 15px;"
        "   font-size: 14px;"
        "   min-height: 30px;"
        "}"
        "QComboBox::drop-down {"
        "   width: 25px;"
        "}"
        );

    // 难度选择
    QLabel *diffLabel = new QLabel("选择难度:", this);
    diffLabel->setStyleSheet("font-size: 16px; font-weight: bold; color: #333;");

    diffcombo = new QComboBox(this);
    diffcombo->addItem("初中水平", 0);
    diffcombo->addItem("高中水平", 1);
    diffcombo->addItem("四级水平", 2);
    diffcombo->addItem("六级水平", 3);
    diffcombo->setStyleSheet(modecombo->styleSheet());

    // 确定按钮
    QPushButton *confirm = new QPushButton("确 定", this);
    confirm->setFixedHeight(40);
    confirm->setStyleSheet(
        "QPushButton {"
        "   background: #4CAF50;"
        "   color: white;"
        "   border: none;"
        "   border-radius: 5px;"
        "   font-size: 16px;"
        "   font-weight: bold;"
        "}"
        "QPushButton:hover {"
        "   background: #45a049;"
        "}"
        );

    // 添加到内容布局
    contentLayout->addWidget(modeLabel);
    contentLayout->addWidget(modecombo);
    contentLayout->addSpacing(15);
    contentLayout->addWidget(diffLabel);
    contentLayout->addWidget(diffcombo);
    contentLayout->addSpacing(25);
    contentLayout->addWidget(confirm);
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

    // 连接信号
    connect(confirm, &QPushButton::clicked, this, &mode::onconfirm);
    setWindowTitle("模式选择");
    setMinimumSize(400, 450);  // 调整最小窗口大小
}

void mode::onconfirm() {
    if (modecombo && diffcombo) {
        model = modecombo->currentData().toInt();
        difficulty = diffcombo->currentData().toInt();
        accept();
    }
}
