// settingspage.cpp
#include "settingspage.h"
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QDebug>
#include <QApplication>

SettingsPage::SettingsPage(QWidget *parent) : QWidget(parent) {
    QLabel *background = new QLabel(this);
    background->setPixmap(QPixmap(":/resources/bg.jpg"));  // 使用资源文件
    background->setScaledContents(true);  // 缩放图片以适应 QLabel
    background->setGeometry(-100, -100, 1500, 1500);  // 铺满整个窗口

    // 确保背景在最底层
    background->raise();
    QVBoxLayout *mainLayout = new QVBoxLayout(this);

    // 返回按钮
    backButton = new QPushButton("返回主页", this);
    connect(backButton, &QPushButton::clicked, this, &SettingsPage::backToHome);

    // 音量控制部分
    QLabel *volumeLabel = new QLabel("音量控制", this);
    volumeSlider = new QSlider(Qt::Horizontal, this);
    volumeSlider->setRange(0, 100);
    volumeSlider->setValue(50);
    connect(volumeSlider, &QSlider::valueChanged, this, &SettingsPage::onVolumeSliderMoved);

    // 字体选择部分
    QLabel *ChinesefontLabel = new QLabel("中文字体选择", this);
    QLabel *EnglishfontLabel = new QLabel("英文字体选择", this);
    ChinesefontComboBox = new QComboBox(this);
    EnglishfontComboBox = new QComboBox(this);
    setupFontComboBox();
    connect(ChinesefontComboBox, QOverload<int>::of(&QComboBox::currentIndexChanged),
            this, &SettingsPage::onChineseFontComboBoxChanged);
    connect(EnglishfontComboBox, QOverload<int>::of(&QComboBox::currentIndexChanged),
            this, &SettingsPage::onEnglishFontComboBoxChanged);

    // 布局设置
    QVBoxLayout *volumeLayout = new QVBoxLayout();
    volumeLayout->addWidget(volumeLabel);
    volumeLayout->addWidget(volumeSlider);

    QVBoxLayout *ChinesefontLayout = new QVBoxLayout();
    ChinesefontLayout->addWidget(ChinesefontLabel);
    ChinesefontLayout->addWidget(ChinesefontComboBox);

    QVBoxLayout *EnglishfontLayout = new QVBoxLayout();
    EnglishfontLayout->addWidget(EnglishfontLabel);
    EnglishfontLayout->addWidget(EnglishfontComboBox);

    mainLayout->addWidget(backButton);
    mainLayout->addLayout(volumeLayout);
    mainLayout->addLayout(ChinesefontLayout);
    mainLayout->addLayout(EnglishfontLayout);
    mainLayout->addStretch();

    setLayout(mainLayout);
}

void SettingsPage::setupFontComboBox() {
    // 添加常用字体
    ChinesefontComboBox->addItem("默认字体", QFont());
    ChinesefontComboBox->addItem("宋体", QFont("SimSun"));
    ChinesefontComboBox->addItem("黑体", QFont("SimHei"));
    ChinesefontComboBox->addItem("微软雅黑", QFont("Microsoft YaHei"));
    //添加中文常用字体
    EnglishfontComboBox->addItem("默认字体", QFont());
    EnglishfontComboBox->addItem("Arial", QFont("Arial"));
    EnglishfontComboBox->addItem("Times New Roman", QFont("Times New Roman"));
}

void SettingsPage::onVolumeSliderMoved(int value) {
    emit volumeChanged(value);
    qDebug() << "音量设置为:" << value;
}

void SettingsPage::onChineseFontComboBoxChanged(int index) {
    QFont selectedFont = ChinesefontComboBox->itemData(index).value<QFont>();
    chinesefont=selectedFont;
    emit ChinesefontChanged(selectedFont);
}

void SettingsPage::onEnglishFontComboBoxChanged(int index) {
    QFont selectedFont = EnglishfontComboBox->itemData(index).value<QFont>();
    englishfont=selectedFont;
    emit EnglishfontChanged(selectedFont);
}
