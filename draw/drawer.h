#ifndef DRAWER_H
#define DRAWER_H

#include "drawable.h"

#include <QObject>
#include <QTimer>


class Drawer : public QObject
{
    Q_OBJECT
public:
    static Drawer *getInstance();

    void run();

    void addDrawable(Drawable *drawable);

    void removeDrawable(Drawable *drawable);

signals:
    void start();

public slots:
    void draw();

private:
    static Drawer *instance;
    QList<Drawable *> drawables;

    Drawer(QObject *parent = nullptr);
};

#endif // DRAWER_H
