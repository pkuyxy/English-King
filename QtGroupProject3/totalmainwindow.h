// mainwindow.h
#ifndef TOTALMAINWINDOW_H
#define TOTALMAINWINDOW_H

#include <QMainWindow>
#include <QStackedWidget>
#include "homepage.h"
#include "teampage.h"
#include "settingspage.h"
#include "mode.h"
#include "mainwindow.h"
#include "totiantipage.h"
#include "tiantipage1.h"
#include "tiantipage2.h"
#include "tiantipage3.h"
#include "tiantipage4.h"
#include <memory>

class TotalMainWindow : public QMainWindow {
    Q_OBJECT
public:
    TotalMainWindow(QWidget *parent = nullptr);
    ~TotalMainWindow();
private:
    QStackedWidget *stackedWidget;
    HomePage *homePage;
    TeamPage *teamPage;
    SettingsPage *settingsPage;
    mode *modePage;
    TotiantiPage *totiantiPage;
    TiantiPage1 *tiantiPage1;
    TiantiPage2 *tiantiPage2;
    TiantiPage3 *tiantiPage3;
    TiantiPage4 *tiantiPage4;
    //MainWindow *mainWindow;

private slots:
    void onShowModePage();
    void showMainWindow();

    //  void showtiantiPage1();
    // void showtiantiPage2();
    //  void showtiantiPage3();
    // void showtiantiPage4();
    //void startGame(int mode,int difficulty);
private:
    std::unique_ptr<MainWindow> mainWindow;
};

#endif // TOTALMAINWINDOW_H
