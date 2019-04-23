#ifndef DRAWER_H
#define DRAWER_H

#include "drawable.h"

#include <QObject>
#include <QTimer>
#include <QDebug>


class Drawer : public QObject
{
    Q_OBJECT

public:
    static Drawer *getInstance();

    void run();

    void addDrawable(Drawable *drawable);

    void removeDrawable(Drawable *drawable);

public slots:
    void draw();

private:
    static Drawer *instance;
    QList<Drawable *> drawables;

    Drawer();
};

#endif // DRAWER_H
