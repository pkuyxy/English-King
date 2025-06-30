#ifndef TIANTIPAGE4_H
#define TIANTIPAGE4_H

#include <QWidget>
#include <QPushButton>
#include <QLabel>

class TiantiPage4 : public QWidget {
    Q_OBJECT
public:
    explicit TiantiPage4(QWidget *parent = nullptr);
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
#endif // TIANTIPAGE4_H
