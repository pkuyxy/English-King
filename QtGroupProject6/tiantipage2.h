#ifndef TIANTIPAGE2_H
#define TIANTIPAGE2_H

#include <QWidget>
#include <QPushButton>
#include <QLabel>

class TiantiPage2 : public QWidget {
    Q_OBJECT
public:
    explicit TiantiPage2(QWidget *parent = nullptr);
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
#endif // TIANTIPAGE2_H
