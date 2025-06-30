// teampage.h
#ifndef TEAMPAGE_H
#define TEAMPAGE_H

#include <QWidget>
#include <QPushButton>
#include <QLabel>

class TeamPage : public QWidget {
    Q_OBJECT
public:
    explicit TeamPage(QWidget *parent = nullptr);
signals:
    void backToHome();

private:
    QPushButton *backButton;
};

#endif // TEAMPAGE_H
