#ifndef TOTIANTIPAGE_H
#define TOTIANTIPAGE_H

#include <QWidget>
#include <QPushButton>
#include <QVBoxLayout>
#include "tiantipage1.h"
class TotiantiPage : public QWidget {
    Q_OBJECT
public:
    explicit TotiantiPage(QWidget *parent = nullptr);
private:
    int difficulty;
signals:
    void backToHome();
    void showtianti1Page();
    void showtianti2Page();
    void showtianti3Page();
    void showtianti4Page();
private:
    QPushButton *difficulty1Button;
    QPushButton *difficulty2Button;
    QPushButton *difficulty3Button;
    QPushButton *difficulty4Button;
    QPushButton *BackButton;
public:
    int getdifficulty() const {return difficulty;}

};

#endif // TOTIANTIPAGE_H
