#ifndef VEHICLE_H
#define VEHICLE_H

#include <QList>
#include "process.h"
#include <QHBoxLayout>

class Vehicle
{
public:
    Vehicle(QString id);

    void addComponent(Process *component);

    QList<Process *> *getComponents();

private:
    QString id;
    QList<Process *> *components;
};

#endif // VEHICLE_H
