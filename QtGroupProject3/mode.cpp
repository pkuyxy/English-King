#include "mode.h"
#include<QVBoxLayout>
#include<QPushButton>
#include<QLabel>
mode::mode(QWidget *parent):QDialog(parent),model(0),difficulty(0){
    QLabel *background = new QLabel(this);
    background->setPixmap(QPixmap(":/resources/bg.jpg"));  // 使用资源文件
    background->setScaledContents(true);  // 缩放图片以适应 QLabel
    background->setGeometry(-100, -100, 1500, 1500);  // 铺满整个窗口

    // 确保背景在最底层
    background->raise();
    QVBoxLayout *layout=new QVBoxLayout(this);
    backButton = new QPushButton("返回主页",this);
    connect(backButton,&QPushButton::clicked,this,&mode::backToHome);
    layout->addWidget(backButton);
    setWindowTitle("模式选择");
    setMinimumSize(300,400);
    modecombo=new QComboBox(this);
    modecombo->addItem("练习模式",0);
    modecombo->addItem("天梯模式",1);
    modecombo->addItem("错题模式",2);
    modecombo->addItem("自定义模式(使用)",3);
    modecombo->addItem("自定义模式(写入)",4);
    layout->addWidget(new QLabel("选择模式:"));
    layout->addWidget(modecombo);
    diffcombo=new QComboBox;
    diffcombo->addItem("初中水平",0);
    diffcombo->addItem("高中水平",1);
    diffcombo->addItem("四级水平",2);
    diffcombo->addItem("六级水平",3);
    layout->addWidget(new QLabel("选择难度："));
    layout->addWidget(diffcombo);

    QPushButton *confirm=new QPushButton("确定");
    connect(confirm,&QPushButton::clicked,this,&mode::onconfirm);
    layout->addWidget(confirm);
}
void mode::onconfirm(){
    if (modecombo && diffcombo) {
        model = modecombo->currentData().toInt();
        difficulty = diffcombo->currentData().toInt();
        accept();
    }
}

