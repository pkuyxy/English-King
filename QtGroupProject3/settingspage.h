// settingspage.h
#ifndef SETTINGSPAGE_H
#define SETTINGSPAGE_H

#include <QWidget>
#include <QSlider>
#include <QComboBox>
#include <QPushButton>
#include <QLabel>

class SettingsPage : public QWidget {
    Q_OBJECT
public:
    explicit SettingsPage(QWidget *parent = nullptr);
    QFont getchinesefont(){return chinesefont;};
    QFont getenglishfont(){return englishfont;};

private:
    QFont chinesefont;
    QFont englishfont;

signals:
    void backToHome();
    void volumeChanged(int volume);
    void ChinesefontChanged(const QFont &font);
    void EnglishfontChanged(const QFont &font);

private slots:
    void onVolumeSliderMoved(int value);
    void onChineseFontComboBoxChanged(int index);
    void onEnglishFontComboBoxChanged(int index);

private:
    QSlider *volumeSlider;
    QComboBox *ChinesefontComboBox;
    QComboBox *EnglishfontComboBox;
    QPushButton *backButton;

    void setupFontComboBox();
};

#endif // SETTINGSPAGE_H
