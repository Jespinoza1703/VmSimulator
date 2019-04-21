#ifndef PROCESS_H
#define PROCESS_H

#include "draw/drawable.h"

#include <QString>
#include <QTime>
#include <QDebug>


class Process : public Drawable
{
public:
    Process(QString id, float time, QWidget *widget);

    void draw();

private:
    QString id;
    float time;
    float percent;
    QTime startTime;
    QWidget *widget;
};

#endif // PROCESS_H
