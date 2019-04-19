#ifndef Chronometer_H
#define Chronometer_H

#include <QTimer>
#include <QDebug>


class Chronometer
{
public:
    explicit Chronometer(int interval);

    QTimer *timer;
    int interval;

    int elapsedTime = 0;

    void inicialize();
    void stop();
    void resume();

public slots:
    void onTimeOut();
};

#endif // Chronometer_H
