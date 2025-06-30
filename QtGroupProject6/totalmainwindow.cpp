// mainwindow.cpp
#include "totalmainwindow.h"

TotalMainWindow::TotalMainWindow(QWidget *parent) : QMainWindow(parent) {
    // 设置窗口大小
    resize(800, 600);

    // 创建堆叠窗口
    stackedWidget = new QStackedWidget(this);
    setCentralWidget(stackedWidget);

    // 创建各个页面
    homePage = new HomePage(this);
    teamPage = new TeamPage(this);
    settingsPage = new SettingsPage(this);
    modePage = new mode(this);
    totiantiPage = new TotiantiPage(this);

    tiantiPage1 = new TiantiPage1(this);
    tiantiPage2 = new TiantiPage2(this);
    tiantiPage3 = new TiantiPage3(this);
    tiantiPage4 = new TiantiPage4(this);

    // 添加页面到堆叠窗口
    stackedWidget->addWidget(homePage);
    stackedWidget->addWidget(teamPage);
    stackedWidget->addWidget(settingsPage);
    stackedWidget->addWidget(modePage);
    stackedWidget->addWidget(totiantiPage);
     stackedWidget->addWidget(tiantiPage1);
    stackedWidget->addWidget(tiantiPage2);
    stackedWidget->addWidget(tiantiPage3);
    stackedWidget->addWidget(tiantiPage4);


    // 连接页面切换信号
    connect(homePage, &HomePage::showTeamPage, [this]() {

        stackedWidget->setCurrentWidget(teamPage);
    });

    connect(homePage, &HomePage::showSettingsPage, [this]() {
        stackedWidget->setCurrentWidget(settingsPage);
    });

    connect(homePage, &HomePage::showtotiantiPage, [this]() {
        stackedWidget->setCurrentWidget(totiantiPage);
    });
    connect(teamPage, &TeamPage::backToHome, [this]() {
        stackedWidget->setCurrentWidget(homePage);
    });

    connect(settingsPage, &SettingsPage::backToHome, [this]() {
        stackedWidget->setCurrentWidget(homePage);
    });

    connect(modePage,&mode::backToHome,[this](){
        stackedWidget->setCurrentWidget(homePage);
    });

    connect(totiantiPage,&TotiantiPage::backToHome,[this](){
        stackedWidget->setCurrentWidget(homePage);
    });

    connect(tiantiPage1,&TiantiPage1::backToHome,[this](){
        stackedWidget->setCurrentWidget(totiantiPage);
    });
    connect(tiantiPage2,&TiantiPage2::backToHome,[this](){
        stackedWidget->setCurrentWidget(totiantiPage);
    });

    connect(tiantiPage3,&TiantiPage3::backToHome,[this](){
        stackedWidget->setCurrentWidget(totiantiPage);
    });
    connect(tiantiPage4,&TiantiPage4::backToHome,[this](){
        stackedWidget->setCurrentWidget(totiantiPage);
    });


    connect(homePage,&HomePage::showModePage,this,&TotalMainWindow::onShowModePage);

    connect(modePage, &mode::accepted, this,&TotalMainWindow::showMainWindow);

    //
    connect(totiantiPage,&TotiantiPage::showtianti1Page,[this](){
        TiantiPage1::Tiantidifficulty=0;
        stackedWidget->addWidget(tiantiPage1);
        stackedWidget->setCurrentWidget(tiantiPage1);
    });
    connect(totiantiPage,&TotiantiPage::showtianti2Page,[this](){
        TiantiPage2::Tiantidifficulty=1;
        stackedWidget->addWidget(tiantiPage2);
        stackedWidget->setCurrentWidget(tiantiPage2);
    });
    connect(totiantiPage,&TotiantiPage::showtianti3Page,[this](){
        TiantiPage3::Tiantidifficulty=2;
        stackedWidget->addWidget(tiantiPage3);
        stackedWidget->setCurrentWidget(tiantiPage3);
    });
    connect(totiantiPage,&TotiantiPage::showtianti4Page,[this](){
        TiantiPage4::Tiantidifficulty=3;
        stackedWidget->addWidget(tiantiPage4);
        stackedWidget->setCurrentWidget(tiantiPage4);
    });



    // 默认显示主页
    stackedWidget->setCurrentWidget(homePage);
}
TotalMainWindow::~TotalMainWindow(){}

void TotalMainWindow::onShowModePage() {
    stackedWidget->setCurrentWidget(modePage);
}

void TotalMainWindow::showMainWindow() {
    int selectedMode = modePage->getmode();
    int selectedDifficulty = modePage->getdifficulty();
    QFont chinesefont = settingsPage->getchinesefont();
    QFont englishfont = settingsPage->getenglishfont();

    // if (mainWindow) {
    //     qDebug()<<"if mainWindow";
    //     delete mainWindow;
    //     qDebug()<<"hh";
    //     mainWindow = nullptr;
    // }
    initGameWindow(selectedMode, selectedDifficulty, chinesefont, englishfont);
}
void TotalMainWindow::initGameWindow(int mode, int difficulty, QFont chineseFont, QFont englishFont) {
    if (mainWindow) {
        mainWindow->disconnect();
        mainWindow.reset();
    }

    mainWindow.reset(new MainWindow(mode, difficulty, chineseFont, englishFont, nullptr));

    // 游戏内设置按钮点击
    connect(mainWindow.get(), &MainWindow::showSettingsRequested, this, [this]() {
        settingsPage->setFromGame(true);  // 标记来源为游戏
        settingsPage->show();
        stackedWidget->setCurrentWidget(settingsPage);
        mainWindow->hide();  // 隐藏游戏窗口
    });

    // 设置界面返回游戏
    connect(settingsPage, &SettingsPage::backToGame, this, [this]() {
        settingsPage->setFromGame(false);
        mainWindow->show();  // 重新显示游戏窗口
        settingsPage->hide();
        // 不需要操作stackedWidget，保持设置页面在堆栈中
    });

    // 普通返回主页（从主页进入设置时）
    connect(settingsPage, &SettingsPage::backToHome, this, [this]() {
        stackedWidget->setCurrentWidget(homePage);
    });
    connect(mainWindow.get(), &MainWindow::returnToHome, this, [this]() {
        mainWindow->resetGameData();
        stackedWidget->setCurrentWidget(homePage);  // 返回主页
        mainWindow->close();  // 隐藏游戏窗口
    });
    connect(settingsPage, &SettingsPage::ChinesefontChanged, mainWindow.get(), &MainWindow::setChineseFont);
    connect(settingsPage, &SettingsPage::EnglishfontChanged, mainWindow.get(), &MainWindow::setEnglishFont);
    mainWindow->show();
}
