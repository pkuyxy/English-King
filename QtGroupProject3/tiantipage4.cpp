#include "tiantipage4.h"
#include <QLabel>
#include <QApplication>
#include <QMainWindow>
#include <QGridLayout>
#include <QWidget>
#include <QFile>
#include <QTextStream>
#include <QDebug>
#include <QCoreApplication>
#include <QDir>
TiantiPage4::TiantiPage4(QWidget *parent) : QWidget(parent){
    QLabel *background = new QLabel(this);
    background->setPixmap(QPixmap(":/resources/bg.jpg"));  // 使用资源文件
    background->setScaledContents(true);  // 缩放图片以适应 QLabel
    background->setGeometry(-100, -100, 1500, 1500);  // 铺满整个窗口

    // 确保背景在最底层
    background->raise();
    Tiantidifficulty=3;
    // QPalette palette;
    // palette.setColor(QPalette::Button, Qt::cyan);       // 按钮背景
    // this->setPalette(palette);

    // 注意：子控件需启用自动填充
    QPushButton *btn = new QPushButton(this);
    btn->setAutoFillBackground(true);
    qDebug()<<"Tianti="<<Tiantidifficulty;
    loadshujuku( Tiantidifficulty);//加载数据
    paixu();//数据排序
    // updateshuju(newscore);//加载新数据
    paixu();
    updateshujuku(Tiantidifficulty);//传入数据

    BackButton = new QPushButton("返回主页", this);
    BackButton->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
    connect(BackButton, &QPushButton::clicked, this, &TiantiPage4::backToHome);

    setWindowTitle("天梯排行榜");
    resize(400, 300);
    // 创建中央部件和竖直布局
    QVBoxLayout *verticalLayout = new QVBoxLayout(this);

    for (int i = 0; i < 6; ++i) {
        if(i>=1)
        {QLabel *label = new QLabel(QString("      %1.      %2").arg(i).arg(s[i-1]));
            QPalette palette = label->palette();
            palette.setColor(QPalette::WindowText, QColor(235, 180, 0));  // 金色
            label->setPalette(palette);
            label->setStyleSheet("font-size: 16pt;");
            label->setAlignment(Qt::AlignLeft);
            verticalLayout->addWidget(label);}
        else{
            QLabel *label = new QLabel(QString("六 级 天 梯 排 行 榜"));
            QPalette palette = label->palette();
            palette.setColor(QPalette::WindowText, QColor(100, 128, 100));  // 深绿色
            label->setPalette(palette);
            label->setStyleSheet("font-size: 22pt;");
            label->setAlignment(Qt::AlignLeft);
            verticalLayout->addWidget(label);
        }
    }
    //
    verticalLayout->setContentsMargins(300, 100, 40, 20);
    verticalLayout->setSpacing(10);


}
QString TiantiPage4::getshujukuPath(int difficulty) {
    qDebug()<<"getWordLibraryPath start";
    QString basePath = QCoreApplication::applicationDirPath(); // 获取可执行文件所在目录
    QString fileName;
    qDebug()<<basePath;
    switch(difficulty) {
    case 0: fileName = "shujuku(1).txt"; break;
    case 1: fileName = "shujuku(2).txt"; break;
    case 2: fileName = "shujuku(3).txt"; break;
    case 3: fileName = "shujuku(4).txt"; break;
    default: fileName = "shujuku(1).txt";
    }
    return QDir(basePath).filePath(fileName); // 构建完整路径
}
void TiantiPage4::loadshujuku(int difficulty){
    QFile file(getshujukuPath(difficulty));
    if (file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        QTextStream in(&file);
        int i=0;
        while (!in.atEnd()) {
            QString line = in.readLine().trimmed();
            s[i]=line.toInt();
            qDebug() << line;
            i++;
        }
        file.close();
    }
}
void TiantiPage4::paixu(){
    int term;
    for(int i=0;i<=4;i++)
        for(int j=3;j>=i;j--)
            if(s[j]<s[j+1])
            {
                term=s[j];
                s[j]=s[j+1];
                s[j+1]=term;
            }
}//记录排序
void TiantiPage4::updateshuju(int a){
    if(a>s[4])
        s[4]=a;
}//加载新分

void TiantiPage4::updateshujuku(int difficulty){
    QFile file(getshujukuPath( difficulty));
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text)) {
        qWarning() << "无法打开文件:" << file.errorString();
        return;
    }
    QTextStream out(&file);
    out.setEncoding(QStringConverter::Utf8);
    out << s[0]<<"\n"<< s[1]<<"\n"<< s[2]<<"\n"<< s[3]<<"\n"<< s[4]<<"\n";
    file.close();
}//更新记录

