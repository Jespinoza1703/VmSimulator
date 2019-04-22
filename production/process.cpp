#include "process.h"

Process::Process(QString id, float time, QWidget *widget) :
    id(id), time(time), widget(widget)
{
    percent = 0;
    startTime.start();
}

void Process::draw()
{
    float elapsedTime = startTime.elapsed();
    percent = elapsedTime / time;

    QLabel *idLb = new QLabel();
    idLb->setText(id);
    idLb->setAlignment(Qt::AlignCenter);
    idLb->setStyleSheet("QLabel { background-color: red; }");
    idLb->setParent(widget);
    idLb->resize(100, 100);

}
