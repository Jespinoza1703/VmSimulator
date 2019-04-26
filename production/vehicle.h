#ifndef VEHICLE_H
#define VEHICLE_H

#include <QList>
#include "process.h"
#include <QHBoxLayout>

/**
 * @brief
 *
 * @class Vehicle vehicle.h "vehicle.h"
 */
class Vehicle
{
public:
    /**
     * @brief
     *
     * @fn Vehicle
     * @param id
     */
    Vehicle(QString id);

    /**
     * @brief
     *
     * @fn addComponent
     * @param component
     */
    void addComponent(Process *component);

    /**
     * @brief
     *
     * @fn getComponents
     * @return QList<Process *>
     */
    QList<Process *> *getComponents();

private:
    QString id; /**< TODO: describe */
    QList<Process *> *components; /**< TODO: describe */
};

#endif // VEHICLE_H
