#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QMainWindow>
#include <QPainter>
#include <QTextStream>
#include <QMouseEvent>
#include <QFont>
#include <QRect>
#include <QRandomGenerator>
#include <cstring>
#include<QTimer>
struct Rect{
    QRect rect;
    bool select;
    QString text;
    bool answer;
};

class MainWindow : public QWidget
{
    Q_OBJECT

public:
    MainWindow(int mode,int difficulty,QFont chinesefont,QFont englishfont,QWidget *parent = nullptr);
    ~MainWindow();
protected:
    void paintEvent(QPaintEvent *event)override;//内容填充
    void mousePressEvent(QMouseEvent *event) override; // 鼠标按下事件
    void mouseMoveEvent(QMouseEvent *event) override;  // 鼠标移动事件
    void mouseReleaseEvent(QMouseEvent *event) override; // 鼠标释放事件
    void saveHighScore(int score,int difficulty);
    int loadHighScore(int difficulty);


private:
    int numrec;//矩形个数
    Rect *rec;//矩形数组
    int *x;
    int *y;
    static int score;//分数
    static int round;//轮次
    int end=0;//表示是否已经确认
    QTimer *timer;
    int seconds;//读秒
    int currentmode;
    int currentdifficulty;
    QString word1="address";
    QFont ChineseFont;
    QFont EnglishFont;

public slots:
    void setChineseFont(const QFont &font);
    void setEnglishFont(const QFont &font);
};

#endif
