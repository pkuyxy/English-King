// main.cpp
#include "totalmainwindow.h"
#include <QApplication>
#include <QMediaPlayer>
#include <QAudioOutput>

int main(int argc, char *argv[]) {
    qputenv("QT_MEDIA_BACKEND", "windows");
    QApplication a(argc, argv);

    // 初始化全局字体
    QFont defaultFont("Microsoft YaHei", 10);
    a.setFont(defaultFont);

    // 创建背景音乐播放器
    QMediaPlayer *bgmPlayer = new QMediaPlayer();
    QAudioOutput *audioOutput = new QAudioOutput();  // Qt 6 需要音频输出对象
    bgmPlayer->setAudioOutput(audioOutput);          // 关联音频输出
    bgmPlayer->setSource(QUrl("qrc:/resources/bgm.mp3")); // 替换为实际音乐文件
    audioOutput->setVolume(0.5);
    bgmPlayer->play();

    TotalMainWindow totalw;
    totalw.show();

    // 连接设置信号
    SettingsPage *settingsPage = totalw.findChild<SettingsPage*>();
    if (settingsPage) {
        QObject::connect(settingsPage, &SettingsPage::volumeChanged,audioOutput,
                         [audioOutput](int volume) {
                             audioOutput->setVolume(volume/100.0);
                         });

        QObject::connect(settingsPage, &SettingsPage::ChinesefontChanged,&a,
                         [&a](const QFont &font) {
                             a.setFont(font);
                         });
    }

    return a.exec();
}
