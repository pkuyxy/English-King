#include "totiantipage.h"
#include "tiantipage1.h"
#include "tiantipage2.h"
#include "tiantipage3.h"
#include "tiantipage4.h"
#include <QLabel>
int TiantiPage1::Tiantidifficulty=0;
int TiantiPage2::Tiantidifficulty=1;
int TiantiPage3::Tiantidifficulty=2;
int TiantiPage4::Tiantidifficulty=3;
TotiantiPage::TotiantiPage(QWidget *parent) : QWidget(parent) {
    QLabel *background = new QLabel(this);
    background->setPixmap(QPixmap(":/resources/bg.jpg"));  // 使用资源文件
    background->setScaledContents(true);  // 缩放图片以适应 QLabel
    background->setGeometry(-100, -100, 1500, 1500);  // 铺满整个窗口

    // 确保背景在最底层
    background->raise();
    QVBoxLayout *layout = new QVBoxLayout(this);
    // 标题
    QLabel *title = new QLabel("天梯排行", this);
    title->setAlignment(Qt::AlignCenter);
    title->setStyleSheet("font-size: 24px; font-weight: bold;");
    layout->addWidget(title);
    //返回上一界面
    BackButton = new QPushButton("返回主页", this);
    BackButton->setFixedSize(200, 50);
    connect(BackButton, &QPushButton::clicked, this, &TotiantiPage::backToHome);

    // 选择难度
   difficulty1Button = new QPushButton("初中", this);
   difficulty1Button->setFixedSize(200, 50);
   connect(difficulty1Button, &QPushButton::clicked, this, &TotiantiPage:: showtianti1Page);
   //
   difficulty2Button = new QPushButton("高中", this);
   difficulty2Button->setFixedSize(200, 50);
   connect(difficulty2Button, &QPushButton::clicked, this, &TotiantiPage:: showtianti2Page);
   //
   difficulty3Button = new QPushButton("四级", this);
   difficulty3Button->setFixedSize(200, 50);
   connect(difficulty3Button, &QPushButton::clicked, this, &TotiantiPage:: showtianti3Page);
   //
   difficulty4Button = new QPushButton("六级", this);
   difficulty4Button->setFixedSize(200, 50);
   connect(difficulty4Button, &QPushButton::clicked, this, &TotiantiPage:: showtianti4Page);
    // 添加到布局
    layout->addStretch();
    layout->addWidget(BackButton, 0, Qt::AlignCenter);
    layout->addWidget(difficulty1Button, 0, Qt::AlignCenter);
    layout->addWidget(difficulty2Button, 0, Qt::AlignCenter);
    layout->addWidget(difficulty3Button, 0, Qt::AlignCenter);
    layout->addWidget(difficulty4Button, 0, Qt::AlignCenter);
    layout->addStretch();

    setLayout(layout);
}

// void TotiantiPage::showtianti1Page(){
//     TotiantiPage::difficulty=0;
//     TiantiPage::showpage( getdifficulty());

// }
// void TotiantiPage::showtianti2Page(){
//     TotiantiPage::difficulty=1;
//     TiantiPage::showpage( getdifficulty());
// }
// void TotiantiPage::showtianti3Page(){
//     TotiantiPage::difficulty=2;
//     TiantiPage::showpage( getdifficulty());
// }
// void TotiantiPage::showtianti4Page(){
//     TotiantiPage::difficulty=3;
//     TiantiPage::showpage( getdifficulty());
// }
