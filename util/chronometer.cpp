#include "util/chronometer.h"

Chronometer::Chronometer(int interval)
{
    this->interval = interval;
}

void Chronometer::inicialize(){
    timer = new QTimer();
    timer->setInterval(interval);
    timer->start();
    timer->setSingleShot(false);
}

void Chronometer::stop(){
    elapsedTime += (timer->interval() - timer->remainingTime());
    timer->stop();
}

void Chronometer::resume(){
    timer->start();
}
