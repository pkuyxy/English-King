#include "settingspage.h"
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QGridLayout>
#include <QDebug>
#include <QApplication>
#include <QSpacerItem>
#include <QLabel>

SettingsPage::SettingsPage(QWidget *parent) : QWidget(parent) {
    // 背景设置
    QLabel *background = new QLabel(this);
    background->setPixmap(QPixmap(":/resources/bg.jpg"));
    background->setScaledContents(true);
    background->setGeometry(-100, -100, 1500, 1500);
    background->lower();

    // 主布局
    QGridLayout *mainLayout = new QGridLayout(this);
    mainLayout->setContentsMargins(30, 30, 30, 30);
    mainLayout->setSpacing(0);
    mainLayout->setColumnStretch(0, 1);

    // 返回按钮（固定在左上角）
    backButton = new QPushButton("← 返回主页", this);
    backButton->setFixedSize(120, 40);
    backButton->setStyleSheet(
        "QPushButton {"
        "   background: rgba(255, 255, 255, 180);"
        "   border: 1px solid #ddd;"
        "   border-radius: 5px;"
        "   padding: 5px;"
        "   font-size: 14px;"
        "   color: #333;"
        "}"
        "QPushButton:hover {"
        "   background: rgba(255, 255, 255, 220);"
        "}"
        );
    connect(backButton, &QPushButton::clicked, this, &SettingsPage::backToHome);
    mainLayout->addWidget(backButton, 0, 0, 1, 1, Qt::AlignLeft | Qt::AlignTop);

    // 内容容器（居中显示）
    QWidget *contentWidget = new QWidget(this);
    contentWidget->setFixedWidth(400);
    QVBoxLayout *contentLayout = new QVBoxLayout(contentWidget);
    contentLayout->setContentsMargins(30, 30, 30, 30);
    contentLayout->setSpacing(25);

    // 音量控制
    QLabel *volumeLabel = new QLabel("音量控制", this);
    volumeLabel->setStyleSheet("font-size: 16px; font-weight: bold; color: #333;");

    // 音量控制容器（水平布局）
    QWidget *volumeControlWidget = new QWidget(this);
    QHBoxLayout *volumeLayout = new QHBoxLayout(volumeControlWidget);
    volumeLayout->setContentsMargins(0, 0, 0, 0);
    volumeLayout->setSpacing(10);

    // 音量滑动条
    volumeSlider = new QSlider(Qt::Horizontal, this);
    volumeSlider->setRange(0, 100);
    volumeSlider->setValue(50);
    volumeSlider->setStyleSheet(
        "QSlider {"
        "   height: 30px;"
        "   min-width: 200px;"
        "}"
        "QSlider::groove:horizontal {"
        "   height: 6px;"
        "   background: rgba(200, 200, 200, 100);"
        "   border-radius: 3px;"
        "}"
        "QSlider::handle:horizontal {"
        "   width: 18px;"
        "   height: 18px;"
        "   margin: -6px 0;"
        "   background: #4CAF50;"
        "   border-radius: 9px;"
        "   border: 2px solid #fff;"
        "}"
        );
    connect(volumeSlider, &QSlider::valueChanged, this, &SettingsPage::onVolumeSliderMoved);

    // 静音按钮
    muteButton = new QPushButton(this);
    muteButton->setFixedSize(40, 40);
    muteButton->setCheckable(true);
    muteButton->setStyleSheet(
        "QPushButton {"
        "   background: rgba(255, 255, 255, 180);"
        "   border: 1px solid #ddd;"
        "   border-radius: 5px;"
        "   padding: 5px;"
        "}"
        "QPushButton:hover {"
        "   background: rgba(255, 255, 255, 220);"
        "}"
        "QPushButton:checked {"
        "   background: #f44336;"
        "}"
        );
    muteButton->setText("🔇");  // 使用Unicode静音符号
    muteButton->setStyleSheet(muteButton->styleSheet() + "font-size: 18px;");
    connect(muteButton, &QPushButton::clicked, this, &SettingsPage::onMuteButtonClicked);

    // 添加到水平布局
    volumeLayout->addWidget(volumeSlider);
    volumeLayout->addWidget(muteButton);

    // 字体选择
    QLabel *ChinesefontLabel = new QLabel("中文字体选择", this);
    QLabel *EnglishfontLabel = new QLabel("英文字体选择", this);
    ChinesefontLabel->setStyleSheet("font-size: 16px; font-weight: bold; color: #333;");
    EnglishfontLabel->setStyleSheet("font-size: 16px; font-weight: bold; color: #333;");

    ChinesefontComboBox = new QComboBox(this);
    EnglishfontComboBox = new QComboBox(this);
    setupFontComboBox();

    QString comboBoxStyle =
        "QComboBox {"
        "   background: rgba(255, 255, 255, 180);"
        "   border: 1px solid #ddd;"
        "   border-radius: 4px;"
        "   padding: 8px 15px;"
        "   min-width: 200px;"
        "   font-size: 14px;"
        "}"
        "QComboBox::drop-down {"
        "   width: 25px;"
        "   border-left: 1px solid #ddd;"
        "}"
        "QComboBox::down-arrow {"
        "   image: url(:/resources/arrow_down.png);"
        "   width: 12px;"
        "   height: 12px;"
        "}";
    ChinesefontComboBox->setStyleSheet(comboBoxStyle);
    EnglishfontComboBox->setStyleSheet(comboBoxStyle);

    connect(ChinesefontComboBox, QOverload<int>::of(&QComboBox::currentIndexChanged),
            this, &SettingsPage::onChineseFontComboBoxChanged);
    connect(EnglishfontComboBox, QOverload<int>::of(&QComboBox::currentIndexChanged),
            this, &SettingsPage::onEnglishFontComboBoxChanged);

    // 添加到内容布局
    contentLayout->addWidget(volumeLabel);
    contentLayout->addWidget(volumeControlWidget);
    contentLayout->addSpacing(15);

    contentLayout->addWidget(ChinesefontLabel);
    contentLayout->addWidget(ChinesefontComboBox);
    contentLayout->addSpacing(15);

    contentLayout->addWidget(EnglishfontLabel);
    contentLayout->addWidget(EnglishfontComboBox);
    contentLayout->addStretch();

    // 添加半透明背景效果
    contentWidget->setStyleSheet(
        "QWidget {"
        "   background: rgba(255, 255, 255, 120);"
        "   border-radius: 10px;"
        "}"
        );

    // 将内容区域居中
    mainLayout->addWidget(contentWidget, 1, 0, 1, 1, Qt::AlignCenter);
    setLayout(mainLayout);
}

void SettingsPage::setupFontComboBox() {
    // 中文字体（10个选项）
    ChinesefontComboBox->addItem("默认字体", QFont());
    ChinesefontComboBox->addItem("微软雅黑", QFont("Microsoft YaHei"));
    ChinesefontComboBox->addItem("宋体", QFont("SimSun"));
    ChinesefontComboBox->addItem("黑体", QFont("SimHei"));
    ChinesefontComboBox->addItem("楷体", QFont("KaiTi"));
    ChinesefontComboBox->addItem("仿宋", QFont("FangSong"));
    ChinesefontComboBox->addItem("隶书", QFont("LiSu"));
    ChinesefontComboBox->addItem("幼圆", QFont("YouYuan"));
    ChinesefontComboBox->addItem("华文细黑", QFont("STXihei"));
    ChinesefontComboBox->addItem("华文楷体", QFont("STKaiti"));

    // 英文字体（10个选项）
    EnglishfontComboBox->addItem("Default", QFont());
    EnglishfontComboBox->addItem("Arial", QFont("Arial"));
    EnglishfontComboBox->addItem("Times New Roman", QFont("Times New Roman"));
    EnglishfontComboBox->addItem("Verdana", QFont("Verdana"));
    EnglishfontComboBox->addItem("Georgia", QFont("Georgia"));
    EnglishfontComboBox->addItem("Courier New", QFont("Courier New"));
    EnglishfontComboBox->addItem("Comic Sans MS", QFont("Comic Sans MS"));
    EnglishfontComboBox->addItem("Trebuchet MS", QFont("Trebuchet MS"));
    EnglishfontComboBox->addItem("Impact", QFont("Impact"));
    EnglishfontComboBox->addItem("Lucida Console", QFont("Lucida Console"));
}

void SettingsPage::onVolumeSliderMoved(int value) {
    // 如果滑动条被拖动且当前是静音状态，自动取消静音
    if (isMuted && value > 0) {
        isMuted = false;
        muteButton->setChecked(false);
        muteButton->setStyleSheet(
            "QPushButton {"
            "   background: rgba(255, 255, 255, 180);"
            "   border: 1px solid #ddd;"
            "   border-radius: 5px;"
            "   padding: 5px;"
            "   font-size: 18px;"
            "}"
            );
    }

    emit volumeChanged(value);
    qDebug() << "音量设置为:" << value;
}

void SettingsPage::onMuteButtonClicked(bool checked) {
    isMuted = checked;

    if (isMuted) {
        // 保存当前音量并设置为0
        lastVolume = volumeSlider->value();
        volumeSlider->setValue(0);
        muteButton->setStyleSheet(
            "QPushButton {"
            "   background: #f44336;"
            "   border: 1px solid #ddd;"
            "   border-radius: 5px;"
            "   padding: 5px;"
            "   font-size: 18px;"
            "}"
            );
    } else {
        // 恢复之前保存的音量
        volumeSlider->setValue(lastVolume > 0 ? lastVolume : 50);
        muteButton->setStyleSheet(
            "QPushButton {"
            "   background: rgba(255, 255, 255, 180);"
            "   border: 1px solid #ddd;"
            "   border-radius: 5px;"
            "   padding: 5px;"
            "   font-size: 18px;"
            "}"
            );
    }

    emit volumeChanged(volumeSlider->value());
    qDebug() << (isMuted ? "已静音" : "取消静音") << "当前音量:" << volumeSlider->value();
}

void SettingsPage::onChineseFontComboBoxChanged(int index) {
    QFont selectedFont = ChinesefontComboBox->itemData(index).value<QFont>();
    chinesefont = selectedFont;
    emit ChinesefontChanged(selectedFont);
}

void SettingsPage::onEnglishFontComboBoxChanged(int index) {
    QFont selectedFont = EnglishfontComboBox->itemData(index).value<QFont>();
    englishfont = selectedFont;
    emit EnglishfontChanged(selectedFont);
}
