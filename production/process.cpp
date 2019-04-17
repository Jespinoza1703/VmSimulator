#include "process.h"

Process::Process(QString id, float time) :
    id(id), time(time)
{
    percent = 0;
    startTime.start();
}

void Process::draw()
{
    float elapsedTime = startTime.elapsed();
    percent = elapsedTime / time;
}
