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
    idLb->setStyleSheet("QLabel { background-color: #979b8d; }");
    idLb->resize(100, 100);
    idLb->setParent(widget);
    int processes = widget->children().size();
    if (processes > 1) idLb->move(10*processes + (processes - 1)*100, 10);
    else idLb->move(10, 10);

}
