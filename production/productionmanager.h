#ifndef PRODUCTIONMANAGER_H
#define PRODUCTIONMANAGER_H

#include <QTimer>

#include <draw/drawer.h>

#include "process.h"
#include "vehicle.h"

/**
 * @brief
 *
 * @class ProductionManager productionmanager.h "productionmanager.h"
 */
class ProductionManager : public QObject
{
    Q_OBJECT

public:
    /**
     * @brief
     *
     * @fn getInstance
     * @return ProductionManager
     */
    static ProductionManager *getInstance();

    /**
     * @brief
     *
     * @fn run
     */
    void run();

    /**
     * @brief
     *
     * @fn addVehicle
     * @param vehicle
     * @param type
     */
    void addVehicle(Vehicle *vehicle, int type);

    /**
     * @brief
     *
     * @fn getRunningQueues
     * @return QList<QList<Process *> *>
     */
    QList<QList<Process *> *> getRunningQueues() const;

    /**
     * @brief
     *
     * @fn getWaitingQueues
     * @return QList<QList<Process *> *>
     */
    QList<QList<Process *> *> getWaitingQueues() const;

    /**
     * @brief
     *
     * @fn removeProcess
     * @param process
     */
    void removeProcess(Process *process);

private slots:
    /**
     * @brief
     *
     * @fn updateQueues
     */
    void updateQueues();

private:
    static ProductionManager *instance; /**< TODO: describe */
    Drawer *drawer; /**< TODO: describe */
    int updateTime; /**< TODO: describe */
    int queueLimit; /**< TODO: describe */
    int productionLines; /**< TODO: describe */
    QList<QList<Process *> *> runningQueues; /**< TODO: describe */
    QList<QList<Process *> *> waitingQueues; /**< TODO: describe */

    /**
     * @brief
     *
     * @fn ProductionManager
     */
    ProductionManager();

    /**
     * @brief
     *
     * @fn enqueueProcess
     * @param process
     */
    void enqueueProcess(Process *process);

    /**
     * @brief
     *
     * @fn dequeueProcess
     * @param process
     */
    void dequeueProcess(Process *process);

    /**
     * @brief
     *
     * @fn fillRunningQueue
     * @param index
     */
    void fillRunningQueue(int index);
};

#endif // PRODUCTIONMANAGER_H
