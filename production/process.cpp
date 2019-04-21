#include "process.h"

Process::Process(QString id, float time, QWidget *widget) :
    id(id), time(time), widget(widget)
{
    percent = 0;
    startTime.start();
}

void Process::draw()
{
    float elapsedTime = startTime.elapsed();
    percent = elapsedTime / time;
}
