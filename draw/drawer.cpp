#include "drawer.h"

Drawer *Drawer::instance = new Drawer();

Drawer::Drawer(QObject *parent) :
    QThread(parent)
{
}

Drawer *Drawer::getInstance()
{
    return instance;
}

void Drawer::run()
{
    // Loop
    for (int i = 0; i < drawables.size(); i++) {
        drawables.value(i).draw();
    }

    exec();
}

