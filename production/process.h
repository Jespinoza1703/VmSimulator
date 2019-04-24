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
#include <string>

using namespace std;

class Process : public Drawable
{

public:
    Process(QString id, float time, QWidget * widget);

    void draw();
    void makeLb();
    void deleteProcess();

    QWidget *getWidget() const;
    void setWidget(QWidget *value);

private:
    QLabel *idLb;
    QLabel *imageLb;
    QString id;
    float time;
    float percent;
    QTime startTime;
    QWidget *widget;
    QLabel *rectangle;
    int lbWidth;
    int lbHeight;
};

#endif // PROCESS_H
