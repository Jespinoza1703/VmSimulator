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
    for (Drawable *drawable : drawables)
    {
        drawable->draw();
    }

    exec();
}

