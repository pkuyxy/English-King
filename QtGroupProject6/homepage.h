// homepage.h
#ifndef HOMEPAGE_H
#define HOMEPAGE_H

#include <QWidget>
#include <QPushButton>
#include <QVBoxLayout>

class HomePage : public QWidget {
    Q_OBJECT
public:
    explicit HomePage(QWidget *parent = nullptr);

signals:
    void showTeamPage();
    void showSettingsPage();
    void showModePage();
    void showtotiantiPage();

private:
    QPushButton *teamButton;
    QPushButton *settingsButton;
    QPushButton *modeButton;
    QPushButton *tiantiButton;
};

#endif // HOMEPAGE_H
