#include "drawer.h"

Drawer *Drawer::instance = new Drawer();

Drawer::Drawer(QObject *parent) :
    QObject(parent)
{
    QObject::connect(this, &Drawer::start, this, &Drawer::draw);
}

Drawer *Drawer::getInstance()
{
    return instance;
}

void Drawer::run()
{
    draw();
}

void Drawer::addDrawable(Drawable *drawable)
{
    drawables.push_back(drawable);
}

void Drawer::removeDrawable(Drawable *drawable)
{
    int index = drawables.indexOf(drawable);
    drawables.removeAt(index);
}

void Drawer::draw()
{
    QTimer::singleShot(100, this, &Drawer::draw);
    for (Drawable *drawable : drawables)
    {
        drawable->draw();
    }
}

