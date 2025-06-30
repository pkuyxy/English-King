#ifndef COUNTDOWN_H
#define COUNTDOWN_H
#include <QObject>
#include <QTimer>

class CountDownTimer : public QObject {
    Q_OBJECT

public:
    explicit CountDownTimer(QObject *parent = nullptr);
    ~CountDownTimer();

    void start(int seconds);
    void stop();

signals:
    void tick(int secondsLeft); // 发出信号，传递剩余的秒数

private slots:
    void onTimeout(); // 计时器超时的槽函数

private:
    int remainingSeconds;
    QTimer timer;
};
#endif // COUNTDOWN_H
