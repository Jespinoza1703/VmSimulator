#ifndef PROCESS_H
#define PROCESS_H

#include "draw/drawable.h"

#include <QString>
#include <QTime>
#include <QDebug>
#include <QLabel>
#include <QTableWidget>
#include <QDebug>
#include <QTimer>


class Process : public Drawable
{

public:
    Process(QString id, float time, QWidget *widget);

    void draw();
    QLabel *idLb;

    void makeLb();

private:
    QString id;
    float time;
    float percent;
    QTime startTime;
    QWidget *widget;
    QLabel *rectangle;
};

#endif // PROCESS_H
