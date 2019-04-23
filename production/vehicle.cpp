#include "vehicle.h"

Vehicle::Vehicle(QString id) :
    id(id)
{
}

void Vehicle::addComponent(Process *component)
{
    components.push_back(component);
}

QList<Process *> Vehicle::getComponents() const
{
    return components;
}

