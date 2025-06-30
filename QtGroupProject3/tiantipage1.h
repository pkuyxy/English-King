#ifndef TIANTIPAGE1_H
#define TIANTIPAGE1_H

#include <QWidget>

#include <QPushButton>
#include <QLabel>

class TiantiPage1 : public QWidget {
    Q_OBJECT
public:
    explicit TiantiPage1(QWidget *parent = nullptr);
    static int Tiantidifficulty;
signals:
    void backToHome();

private:
    int s[6]={};
    int newscore=0;
    QPushButton *BackButton;
public:
    QString getshujukuPath(int difficulty);
    void loadshujuku(int difficulty);
    void paixu();
    void updateshuju(int a);
    void updateshujuku(int difficulty);

};
#endif // TIANTIPAGE1_H
