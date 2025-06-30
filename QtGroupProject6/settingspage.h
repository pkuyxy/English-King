#ifndef SETTINGSPAGE_H
#define SETTINGSPAGE_H

#include <QWidget>
#include <QSlider>
#include <QComboBox>
#include <QPushButton>
#include <QCloseEvent>
class SettingsPage : public QWidget
{
    Q_OBJECT

public:
    explicit SettingsPage(QWidget *parent = nullptr);
public:
    QFont getchinesefont() const { return chinesefont; }
    QFont getenglishfont() const { return englishfont; }
    void closeEvent(QCloseEvent *event) override;
    void setFromGame(bool fromGame) { m_fromGame = fromGame; }
signals:
    void volumeChanged(int value);
    void ChinesefontChanged(const QFont &font);
    void EnglishfontChanged(const QFont &font);
    void backToHome();
    void backToGame();
private slots:
    void onVolumeSliderMoved(int value);
    void onChineseFontComboBoxChanged(int index);
    void onEnglishFontComboBoxChanged(int index);
    void onMuteButtonClicked(bool checked);
    void onBackButtonClicked();

private:
    void setupFontComboBox();

    QSlider *volumeSlider;
    QComboBox *ChinesefontComboBox;
    QComboBox *EnglishfontComboBox;
    QPushButton *backButton;
    QPushButton *muteButton;
    QFont chinesefont;
    QFont englishfont;
    bool isMuted = false;
    int lastVolume = 50;
    bool m_fromGame = false;
};

#endif // SETTINGSPAGE_H
