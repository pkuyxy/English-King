#include "totalmainwindow.h"
#include <QApplication>
#include <QMediaPlayer>
#include <QAudioOutput>
#include <QDebug>

int main(int argc, char *argv[]) {
    qputenv("QT_MEDIA_BACKEND", "windows");  // 强制使用 FFmpeg
    QApplication a(argc, argv);

    // 初始化全局字体
    QFont defaultFont("Microsoft YaHei", 10);
    a.setFont(defaultFont);

    // 创建背景音乐播放器
    static QMediaPlayer bgmPlayer;
    static QAudioOutput audioOutput;
    bgmPlayer.setAudioOutput(&audioOutput);
    bgmPlayer.setSource(QUrl("qrc:/resources/bgm.wav"));
    audioOutput.setVolume(0.5);

    // 调试输出
    qDebug() << "Music source:" << bgmPlayer.source();
    QObject::connect(&bgmPlayer, &QMediaPlayer::errorOccurred, [](QMediaPlayer::Error error) {
        qDebug() << "Media error:" << error;
    });

    // 监听状态变化
    QObject::connect(&bgmPlayer, &QMediaPlayer::playbackStateChanged, [](QMediaPlayer::PlaybackState state) {
        qDebug() << "Playback state:" << state;
    });

    // 设置循环播放
    bgmPlayer.setLoops(QMediaPlayer::Infinite);
    bgmPlayer.play();

    TotalMainWindow totalw;
    totalw.show();

    // 连接设置信号
    SettingsPage *settingsPage = totalw.findChild<SettingsPage*>();
    if (settingsPage) {
        QObject::connect(settingsPage, &SettingsPage::volumeChanged, &audioOutput,
                         [](int volume) { audioOutput.setVolume(volume / 100.0); });
    }

    return a.exec();
}
