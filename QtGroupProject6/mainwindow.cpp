//日志:需要结合他人工作的部分，包括：
//1.修改rec[i].text以及rec[i].answer的具体内容；
//2.继承来自开始界面的字体字号颜色等信息
//进一步工作：
//1.做出练习模式
//2.扩充词汇库
//初版仅以单词address为例
//address
// 四个答案(   n.地址     n.演说        v.处理      v.对...讲话  )
//
#include "mainwindow.h"
#include<QFile>
#include<QDir>
#include<QCoreApplication>
#include "wordlib.h"
#include<QApplication>
#include<QProcess>
#include<QInputDialog>
#include<QPushButton>
int MainWindow::score = 0;    // 初始化分数
int MainWindow::round = 0;    // 初始化轮次

QString getWordLibraryPath(int difficulty,int mode=0) {
    QString basePath = QCoreApplication::applicationDirPath()+"/data"; // 获取可执行文件所在目录

    // 确保data目录存在
    QDir dir(basePath);
    if (!dir.exists()) {
        dir.mkpath("."); // 创建目录
    }

    QString fileName;
    if(mode!=2){
        switch(difficulty) {
        case 0: fileName = "英语词库(1).txt"; break;
        case 1: fileName = "英语词库(2).txt"; break;
        case 2: fileName = "英语词库(3).txt"; break;
        case 3: fileName = "英语词库(4).txt"; break;
        default: fileName = "英语词库(1).txt";
        }
    }
    else{
        fileName="英语词库(5).txt";
    }
    return dir.filePath(fileName);
}
void MainWindow::clearCurrentQuestion() {
    if (rec) {
        delete[] rec;
        rec = nullptr;
    }
    if (x) {
        delete[] x;
        x = nullptr;
    }
    if (y) {
        delete[] y;
        y = nullptr;
    }
    numrec = 0;
}
void MainWindow::loadNewQuestion() {
    // 1. 清理旧题目
    clearCurrentQuestion();

    // 2. 从文件加载新题目（和构造函数一样的加载方式）
    QString filePath = getWordLibraryPath(currentdifficulty, currentmode);
    WordEntry word = WordLibrary::loadFromFile(filePath, currentmode);

    // 3. 设置新单词
    word1 = word.word;
    numrec = word.numrec;

    // 4. 创建选项矩形（和构造函数完全相同的逻辑）
    if (numrec > 0) {

        rec = new Rect[numrec];
        x = new int[numrec];
        y = new int[numrec];

        int startX = 35, startY = 70;
        int rectWidth = 245, rectHeight = 88;
        int xblank = 70, yblank = 35;


        int numanw = word.num;
        int notnumanw = numrec - word.num;

        for (int i = 0; i < numrec; ++i) {

            int row = i / 3;
            int col = i % 3;
            rec[i].rect = QRect(
                startX + col * (rectWidth + xblank),
                startY + row * (rectHeight + yblank),
                rectWidth, rectHeight
                );
            x[i] = startX + col * (rectWidth + xblank);
            y[i] = startY + rectHeight/2 + row * (rectHeight + yblank);


            rec[i].select = false;
            rec[i].answer = QRandomGenerator::global()->bounded(0, 2);
            if (numrec-1-i < numanw) rec[i].answer = 1;
            if(numanw == 0) rec[i].answer = 0;

            if (rec[i].answer) {
                if (numanw > 0) {
                    rec[i].text = word.answers[numanw-1];
                    numanw--;
                } else {
                    rec[i].text = "Invalid answer";
                    qDebug() << "Error: numanw is 0!";
                }
            } else {
                if (notnumanw > 0) {
                    rec[i].text = word.notanswers[notnumanw-1];
                    notnumanw--;
                } else {
                    rec[i].text = "Invalid answer";
                    qDebug() << "Error: notnumanw is 0!";
                }
            }
        }
    }

    end = 0;
    seconds = 10;
    timer->start();
    update();
}
MainWindow::MainWindow(int mode,int difficulty,QFont chinesefont,QFont englishfont,QWidget *parent)
    : QWidget(parent),numrec(0),
    timer(new QTimer(this)),seconds(10)
    ,currentmode(mode),currentdifficulty(difficulty)
    ,ChineseFont(chinesefont),EnglishFont(englishfont)
{
    this->setFixedSize(980,560);//设置窗口大小
    this->setStyleSheet("background-color:rgb(0, 102, 80);");//设置背景颜色
if(mode!=4){
    int startX = 35;
    int startY = 70;
    int rectWidth = 245;
    int rectHeight = 88;
    int xblank=70;
    int yblank=35;
    WordEntry word;
    QString filePath = getWordLibraryPath(difficulty,mode);
    qDebug() << "尝试加载词库文件:" << filePath;
    word = WordLibrary::loadFromFile(filePath,mode);
    numrec=word.numrec;//矩形个数
    if (numrec > 0) {
        x = new int[numrec];
        y = new int[numrec];
        rec = new Rect[numrec];
    } else {
        qDebug() << "Error: numrec is 0!";
        return;
    }
    int numanw = word.num;//正确答案个数
    int notnumanw=numrec-word.num;
    word1=word.word;
    for (int i = 0; i < numrec; ++i) {
        int row = i / 3;
        int col = i % 3;
        rec[i].rect = QRect(startX + col * (rectWidth+xblank), startY + row * (rectHeight+yblank), rectWidth, rectHeight);
        x[i]=startX+ col * (rectWidth+xblank);
        y[i]=startY+rectHeight/2 + row * (rectHeight+yblank);
        rec[i].select=0;
        rec[i].answer=QRandomGenerator::global()->bounded(0, 2);
        if (numrec-1- i < numanw){rec[i].answer = 1;}
        if(numanw==0){rec[i].answer = 0;}
        if (rec[i].answer == true) {
            if (numanw > 0) {
                rec[i].text = word.answers[numanw-1];
                numanw--;
            } else {
                rec[i].text = "Invalid answer";
                qDebug() << "Error: numanw is 0!";
            }
        } else {
            if (notnumanw > 0) {
                rec[i].text = word.notanswers[notnumanw-1];
                notnumanw--;
            } else {
                rec[i].text = "Invalid answer";
                qDebug() << "Error: notnumanw is 0!";
            }
        }
    }
    QPushButton *settingsButton = new QPushButton("设置", this);
    settingsButton->setGeometry(280, 490, 100, 56);  // 设置按钮位置和大小
    settingsButton->setStyleSheet("background-color: rgba(255, 255, 255, 180); border-radius: 5px;");

    connect(settingsButton, &QPushButton::clicked, this, [this]() {
        emit showSettingsRequested();  // 触发跳转到设置界面的信号
    });



    //以下部分是计时器功能
    connect(timer, &QTimer::timeout, this, [this]{
        if (seconds > 0) {
            seconds--;
            this->update();
        } else {
            timer->stop();
            end = 1;
            this->update();
        }
    });
    timer->start(1000);
    //结束
}
else{
    bool ok;
    QString text=QInputDialog::getText(
        nullptr,                     // 父窗口
        "输入框标题",                // 标题
        "请输入内容,格式为：1，英文单词，义项个数n，n个义项，全部用空格分开，例子：“1 apple 1 n.苹果”",               // 提示文本
        QLineEdit::Normal,           // 输入模式
        "",                          // 默认文本
        &ok
        );
    if (ok && !text.isEmpty()) {
        QFile temp(getWordLibraryPath(currentdifficulty,0));
        if (temp.open(QIODevice::Append | QIODevice::Text)) {
            QTextStream out(&temp);

            out<<text<<Qt::endl;
            temp.close();
            this->close();
            emit returnToHome();
        }
    }
}
}


MainWindow::~MainWindow()
{
   clearCurrentQuestion();
}

void MainWindow::setChineseFont(const QFont &font){
    ChineseFont=font;
    update();
}

void MainWindow::setEnglishFont(const QFont &font){
    EnglishFont=font;
    update();
}

// 鼠标按下事件
void MainWindow::mousePressEvent(QMouseEvent *event)
{
    QTextStream qout(stdout);
    qout << "鼠标按下，位置: (" << event->pos().x() << ", " << event->pos().y() << ")" << "\n";
    QPainter pa(this);
    if(end==0){
        for (int i = 0; i < numrec; ++i) {
            if(event->pos().x()>=x[i]&&event->pos().x()<=x[i]+245){
                if(event->pos().y()>=y[i]-88/2&&event->pos().y()<=y[i]+88/2){
                    this->update();
                    rec[i].select=!rec[i].select;
                }
            }
        }//这一部分是代表是否选中
    }
    if(QRect(385, 490, 140, 70).contains(event->pos())){
        end=1-end;
        this->update();
        if(end==1){
            int score2=score;
            int allright=1;
            int sum=0;
            for (int i = 0; i < numrec; ++i) {
                if(rec[i].select==1){
                    sum++;
                    if(rec[i].answer==false){
                        score=score2;
                        allright=0;
                        break;
                    }
                }
                else{
                    if(rec[i].answer==true){
                        allright=2;
                    }
                }
            }
            if(allright==1){
                score+=2;
            }
            else if(allright==2){
                if(sum!=0)score+=1;
                else{allright=0;}
            }
            if(allright==0&&currentmode!=2){
                QFile temp(getWordLibraryPath(0,2));
                int k1=0;
                for (int i = 0; i < numrec; ++i) {
                    if(rec[i].answer==true){
                        k1++;
                    }
                }
                if (temp.open(QIODevice::Append | QIODevice::Text)) {
                    QTextStream out(&temp);
                    out<<"0 "<<word1<<" "<<k1<<" ";
                    for(int i=0;i<numrec;i++){
                        if(rec[i].answer==true){
                            out<<rec[i].text<<" ";
                        }
                    }
                    out<<Qt::endl;
                }
                temp.close();
            }
        }
        else{
            if(currentmode==0){
                round++;
                this->setWindowTitle("练习模式");
                loadNewQuestion();
            }
            else if(currentmode==1){
                if(round<10){
                    round++;
                    this->setWindowTitle("天梯模式");
                    loadNewQuestion();  // 请求刷新题目
                }
                else{
                    saveHighScore(score,currentdifficulty);
                    emit returnToHome();
                }
            }
            else if(currentmode==2){
                round++;        
                this->setWindowTitle("错题模式");
                loadNewQuestion();
            }
            else if(currentmode==3){
                round++;             
                this->setWindowTitle("自定义模式");
                loadNewQuestion();
            }
        }
    }
    if(QRect(553, 490, 100, 56).contains(event->pos())){
        emit returnToHome();
    }
}

// 鼠标移动事件
void MainWindow::mouseMoveEvent(QMouseEvent *event)
{
    QTextStream qout(stdout);
    qout << "鼠标移动，位置: (" << event->pos().x() << ", " << event->pos().y() << ")" << "\n";
}

// 鼠标释放事件
void MainWindow::mouseReleaseEvent(QMouseEvent *event)
{
    QTextStream qout(stdout);
    qout << "鼠标释放，位置: (" << event->pos().x() << ", " << event->pos().y() << ")" << "\n";
}
void MainWindow::paintEvent(QPaintEvent *event){
    QPainter word(this),meaning(this),painter(this);//WORD:英文，meaning：中文
    QColor rectColor = QColor(176,196,222),rectColor2=QColor(0,200,100),rectColor3=QColor(200,0,0),rectColor4=QColor(0,0,200);//正常，选，选而不对，对而不选
    painter.setBrush(rectColor);
    painter.setPen(Qt::black);
    painter.drawRect(QRect(385,490,140,70));
    painter.drawRect(QRect(553,490,100,56));
    word.setPen(Qt::black);
    meaning.setPen(Qt::black);//颜色实现
    ChineseFont.setPointSize(30);
    EnglishFont.setPointSize(30);
    word.setFont(EnglishFont);
    meaning.setFont(ChineseFont);//字体实现
    word.drawText(420,35, word1);
    meaning.drawText(420,525,"确定");
    meaning.drawText(560,525,"返回");
    meaning.drawText(70,35,QString("分数：%1").arg(score));
    meaning.drawText(700,35,QString("轮次：%1").arg(round));
    if(end==0){
        meaning.drawText(700,525,QString("时间剩余：%1").arg(seconds));
    }
    if(currentmode==1){
        int highscore=loadHighScore(currentdifficulty);
        meaning.drawText(700,490,QString("历史得分：%1").arg(highscore));
    }
    for (int i = 0; i < numrec; ++i) {
        if(rec[i].select==false){
            if(end==0||(end==1&&rec[i].answer==false)){
                painter.setBrush(rectColor);
                painter.drawRect(rec[i].rect);
            }
            else{
                painter.setBrush(rectColor4);
                painter.drawRect(rec[i].rect);
            }
        }
        else{
            if(end==0||(end==1&&rec[i].answer==true)){
                painter.setBrush(rectColor2);
                painter.drawRect(rec[i].rect);
            }
            else{
                painter.setBrush(rectColor3);
                painter.drawRect(rec[i].rect);
            }
        }
        meaning.drawText(x[i],y[i],rec[i].text);
    }
}
void MainWindow::saveHighScore(int score,int difficulty) {
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
    QFile file(QDir(basePath).filePath(fileName));
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        qWarning() << "无法打开文件:" << file.errorString();
    }
    int s[5]={};

    QTextStream out(&file);
    out >> s[0]>> s[1]>> s[2]>> s[3]>> s[4];
    if(score>s[4]){
        s[4]=score;
    }
    file.close();
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text)) {
        qWarning() << "无法打开文件:" << file.errorString();
        return;
    }
    out << s[0]<<"\n"<< s[1]<<"\n"<< s[2]<<"\n"<< s[3]<<"\n"<< s[4]<<"\n";
    file.close();
}
int MainWindow::loadHighScore(int difficulty){
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
    QFile file(QDir(basePath).filePath(fileName));
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        qWarning() << "无法打开文件:" << file.errorString();
    }
    int s=0;
    QTextStream out(&file);
    out>>s;
    file.close();
    return s;
}
void MainWindow::resetGameData() {
    score = 0;    // 重置分数
    round = 0;    // 重置轮次
    update();     // 刷新界面显示
}



