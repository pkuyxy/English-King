#include "tiantipage1.h"
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QGridLayout>
#include <QPushButton>
#include <QLabel>
#include <QSpacerItem>
#include <QFile>
#include <QTextStream>
#include <QDebug>
#include <QCoreApplication>
#include <QDir>
#include <QPalette>

TiantiPage1::TiantiPage1(QWidget *parent) : QWidget(parent) {
    // 背景设置
    QLabel *background = new QLabel(this);
    background->setPixmap(QPixmap(":/resources/bg.jpg"));
    background->setScaledContents(true);
    background->setGeometry(-100, -100, 1500, 1500);
    background->lower();

    // 主布局
    QVBoxLayout *mainLayout = new QVBoxLayout(this);
    mainLayout->setContentsMargins(0, 0, 0, 0);
    mainLayout->setSpacing(0);

    // 顶部布局（返回按钮）
    QHBoxLayout *topLayout = new QHBoxLayout();
    topLayout->setContentsMargins(20, 20, 20, 0);

    // 返回按钮
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
        "}");
    connect(BackButton, &QPushButton::clicked, this, &TiantiPage1::backToHome);
    topLayout->addWidget(BackButton, 0, Qt::AlignLeft | Qt::AlignTop);
    topLayout->addStretch();
    mainLayout->addLayout(topLayout);

    // 中央内容区域
    QWidget *centerWidget = new QWidget(this);
    QHBoxLayout *centerLayout = new QHBoxLayout(centerWidget);
    centerLayout->setContentsMargins(0, 0, 0, 0);
    centerLayout->addStretch();

    // 内容容器
    QWidget *contentWidget = new QWidget(this);
    contentWidget->setObjectName("contentWidget");
    contentWidget->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
    QVBoxLayout *contentLayout = new QVBoxLayout(contentWidget);
    contentLayout->setContentsMargins(40, 40, 40, 40);
    contentLayout->setSpacing(0);

    // 加载和处理数据
    loadshujuku(Tiantidifficulty);
    paixu();
    updateshujuku(Tiantidifficulty);

    // 标题
    QLabel *titleLabel = new QLabel("初 中 天 梯 排 行 榜", this);
    titleLabel->setObjectName("titleLabel");
    QPalette titlePalette = titleLabel->palette();
    titlePalette.setColor(QPalette::WindowText, QColor(100, 128, 100));
    titleLabel->setPalette(titlePalette);
    titleLabel->setStyleSheet(
        "font-size: 24pt;"
        "font-weight: bold;"
        "margin-bottom: 30px;");
    titleLabel->setAlignment(Qt::AlignCenter);
    contentLayout->addWidget(titleLabel, 0, Qt::AlignHCenter);

    // 排行榜 - 使用简单清晰的布局
    QWidget *rankingsWidget = new QWidget(this);
    rankingsWidget->setObjectName("rankingsWidget");
    QHBoxLayout *rankingsMainLayout = new QHBoxLayout(rankingsWidget);
    rankingsMainLayout->setContentsMargins(0, 0, 0, 0);
    rankingsMainLayout->setSpacing(40);  // 序号和分数之间的间距

    // 左侧序号列
    QVBoxLayout *ranksLayout = new QVBoxLayout();
    ranksLayout->setSpacing(15);
    ranksLayout->setContentsMargins(0, 0, 0, 0);

    // 右侧分数列
    QVBoxLayout *scoresLayout = new QVBoxLayout();
    scoresLayout->setSpacing(15);
    scoresLayout->setContentsMargins(0, 0, 0, 0);

    for (int i = 0; i < 5; ++i) {
        QLabel *rankLabel = new QLabel(QString("%1.").arg(i+1), rankingsWidget);
        rankLabel->setObjectName(QString("rankLabel%1").arg(i));
        rankLabel->setStyleSheet(
            "font-size: 20pt;"
            "color: #235180;"
            "min-width: 50px;");
        rankLabel->setAlignment(Qt::AlignRight | Qt::AlignVCenter);

        QLabel *scoreLabel = new QLabel(QString("%1").arg(s[i]), rankingsWidget);
        scoreLabel->setObjectName(QString("scoreLabel%1").arg(i));
        scoreLabel->setStyleSheet(
            "font-size: 20pt;"
            "color: #235180;"
            "min-width: 80px;");
        scoreLabel->setAlignment(Qt::AlignLeft | Qt::AlignVCenter);

        ranksLayout->addWidget(rankLabel);
        scoresLayout->addWidget(scoreLabel);
    }

    rankingsMainLayout->addLayout(ranksLayout);
    rankingsMainLayout->addLayout(scoresLayout);
    rankingsMainLayout->addStretch();

    contentLayout->addWidget(rankingsWidget, 0, Qt::AlignHCenter);
    contentLayout->addStretch();

    // 内容容器样式
    contentWidget->setStyleSheet(
        "#contentWidget {"
        "   background: rgba(255, 255, 255, 200);"
        "   border-radius: 20px;"
        "   min-width: 500px;"
        "   min-height: 450px;"
        "}"
        "#rankingsWidget {"
        "   background: transparent;"
        "}");

    centerLayout->addWidget(contentWidget);
    centerLayout->addStretch();
    mainLayout->addWidget(centerWidget, 1);
    mainLayout->addStretch();

    setLayout(mainLayout);
    setWindowTitle("天梯排行榜");
    resize(800, 600);

    // 调试输出
    qDebug() << "TiantiPage1 initialized with scores:";
    for(int i = 0; i < 5; i++) {
        qDebug() << "Rank" << i+1 << ":" << s[i];
    }
}


QString TiantiPage1::getshujukuPath(int difficulty) {
    QString basePath = QCoreApplication::applicationDirPath();
    QString fileName;

    switch(difficulty) {
    case 0: fileName = "shujuku(1).txt"; break;
    case 1: fileName = "shujuku(2).txt"; break;
    case 2: fileName = "shujuku(3).txt"; break;
    case 3: fileName = "shujuku(4).txt"; break;
    default: fileName = "shujuku(1).txt";
    }

    return QDir(basePath).filePath(fileName);
}

void TiantiPage1::loadshujuku(int difficulty) {
    QFile file(getshujukuPath(difficulty));
    if (file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        QTextStream in(&file);
        int i = 0;
        while (!in.atEnd() && i < 5) {
            QString line = in.readLine().trimmed();
            s[i] = line.toInt();
            qDebug() << "Loaded score:" << s[i];
            i++;
        }
        file.close();
    } else {
        qWarning() << "Could not open file:" << file.errorString();
    }
}

void TiantiPage1::paixu() {
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4 - i; j++) {
            if (s[j] < s[j+1]) {
                int temp = s[j];
                s[j] = s[j+1];
                s[j+1] = temp;
            }
        }
    }
}

void TiantiPage1::updateshuju(int newScore) {
    if (newScore > s[4]) {
        s[4] = newScore;
        paixu();
        updateshujuku(Tiantidifficulty);
    }
}

void TiantiPage1::updateshujuku(int difficulty) {
    QFile file(getshujukuPath(difficulty));
    if (file.open(QIODevice::WriteOnly | QIODevice::Text)) {
        QTextStream out(&file);
        for (int i = 0; i < 5; i++) {
            out << s[i] << "\n";
        }
        file.close();
    } else {
        qWarning() << "Could not write to file:" << file.errorString();
    }
}
