#include "vehicle.h"

Vehicle::Vehicle(QString id) :
    id(id)
{
    components = new QList<Process *>();
}

void Vehicle::addComponent(Process *component)
{
    components->push_back(component);
}

QList<Process *> *Vehicle::getComponents()
{
    return components;
}

