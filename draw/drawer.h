#ifndef DRAWER_H
#define DRAWER_H

#include "drawable.h"

#include <QThread>


class Drawer : public QThread
{
    Q_OBJECT
public:
    static Drawer *getInstance();

    void run();

private:
    static Drawer *instance;
    QList<Drawable *> drawables;

    Drawer(QObject *parent = nullptr);
};

#endif // DRAWER_H
