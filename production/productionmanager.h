#ifndef PRODUCTIONMANAGER_H
#define PRODUCTIONMANAGER_H

#include <QTimer>

#include <draw/drawer.h>

#include "process.h"
#include "vehicle.h"

class ProductionManager : public QObject
{
    Q_OBJECT

public:
    static ProductionManager *getInstance();

    void run();

    void addVehicle(Vehicle *vehicle, int type);

    QList<QList<Process *> *> getRunningQueues() const;

    QList<QList<Process *> *> getWaitingQueues() const;

private slots:
    void updateQueues();

private:
    static ProductionManager *instance;
    Drawer *drawer;
    int updateTime;
    int queueLimit;
    int productionLines;
    QList<QList<Process *> *> runningQueues;
    QList<QList<Process *> *> waitingQueues;

    ProductionManager();

    void enqueueProcess(Process *process);

    void dequeueProcess(Process *process);

    void fillRunningQueue(int index);
};

#endif // PRODUCTIONMANAGER_H
