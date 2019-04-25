#include "productionmanager.h"

ProductionManager *ProductionManager::instance = new ProductionManager();

ProductionManager *ProductionManager::getInstance()
{
    return instance;
}

void ProductionManager::run()
{
    QTimer::singleShot(1000, this, &ProductionManager::updateQueues);
}

void ProductionManager::addVehicle(Vehicle *vehicle, int type)
{
    QList<Process *> *waitingQueue = waitingQueues.value(type - 1);
    for (Process *process : *vehicle->getComponents())
    {
        waitingQueue->push_back(process);
    }
}

void ProductionManager::updateQueues()
{
    QTimer::singleShot(updateTime, this, &ProductionManager::updateQueues);

    for (int i = 0; i < productionLines; i++)
    {
        QList<Process *> *runningQueue = runningQueues.value(i);
        QList<Process *> *waitingQueue = waitingQueues.value(i);

        if (runningQueue->size() < queueLimit) fillRunningQueue(i);
        else if (!waitingQueue->isEmpty()) {
            Process *running = runningQueue->takeFirst();
            Process *waiting = waitingQueue->takeFirst();

            runningQueue->push_back(waiting);
            waitingQueue->push_back(running);

            enqueueProcess(waiting);
            dequeueProcess(running);
        }
    }
}

QList<QList<Process *> *> ProductionManager::getWaitingQueues() const
{
    return waitingQueues;
}

QList<QList<Process *> *> ProductionManager::getRunningQueues() const
{
    return runningQueues;
}

ProductionManager::ProductionManager()
{
    drawer = Drawer::getInstance();
    updateTime = 5000;
    queueLimit = 3;
    productionLines = 6;

    for (int i = 0; i < productionLines; i++) {
        runningQueues.push_back(new QList<Process*>());
        waitingQueues.push_back(new QList<Process*>());
    }
}

void ProductionManager::enqueueProcess(Process *process)
{
    drawer->addDrawable(process);
}

void ProductionManager::dequeueProcess(Process *process)
{
    drawer->removeDrawable(process);
}

void ProductionManager::fillRunningQueue(int index)
{
    QList<Process *> *runningQueue = runningQueues.value(index);
    QList<Process *> *waitingQueue = waitingQueues.value(index);
    while (runningQueue->size() < queueLimit)
    {
        if (waitingQueue->isEmpty()) break;
        Process *process = waitingQueue->takeFirst();
        runningQueue->push_back(process);
        enqueueProcess(process);
    }
}
