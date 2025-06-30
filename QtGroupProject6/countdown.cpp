#include "countdown.h"

CountDownTimer::CountDownTimer(QObject *parent)
    : QObject(parent), remainingSeconds(0) {
}

CountDownTimer::~CountDownTimer() {
    stop();
}

void CountDownTimer::start(int seconds) {
    if (timer.isActive()) {
        stop();
    }
    // 断开之前的连接
    disconnect(&timer, &QTimer::timeout, this, &CountDownTimer::onTimeout);

    remainingSeconds = seconds;
    timer.setInterval(1000); // 设置计时器间隔为1000毫秒（即1秒）
    connect(&timer, &QTimer::timeout, this, &CountDownTimer::onTimeout);
    timer.start();
}//开始计时

void CountDownTimer::stop() {
    timer.stop();
    remainingSeconds = 0;
    emit tick(remainingSeconds); // 发出倒计时结束的信号
}

void CountDownTimer::onTimeout() {
    if (remainingSeconds > 0) {
        remainingSeconds--;
        emit tick(remainingSeconds); // 发出信号，传递剩余的秒数
    } else {
        stop(); // 如果倒计时结束，停止计时器
    }
}

