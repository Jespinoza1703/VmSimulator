#ifndef VEHICLE_H
#define VEHICLE_H

#include <QList>
#include "process.h"

class Vehicle
{
public:
    Vehicle(QString id);

    void addComponent(Process *component);

private:
    QString id;
    QList<Process *> components;
};

#endif // VEHICLE_H
