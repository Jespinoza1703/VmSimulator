#include "process.h"

Process::Process(QString id, float time) :
    id(id), time(time)
{
    percent = 0;
    startTime.start();
}

void Process::draw()
{
    elapsedTime = startTime.elapsed();
    percent = elapsedTime / time;
}
