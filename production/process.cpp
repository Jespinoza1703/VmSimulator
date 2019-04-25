#include "process.h"
#include "production/productionmanager.h"

Process::Process(QString id, float time, QWidget *widget) :
    id(id), time(time), widget(widget)
{
    lbWidth = 100;
    lbHeight = 100;
    percent = 0;
    startTime.start();
    makeLb();
    draw();
}

QWidget *Process::getWidget() const
{
    return widget;
}

void Process::setWidget(QWidget *value)
{
    widget = nullptr;
    widget = value;
    idLb->setParent(value);
    idLb->show();
}

QLabel *Process::getIdLb() const
{
    return idLb;
}

void Process::setLabelPos(int i)
{
    idLb->move(10*(i+1) + i*100, 10);
}

void Process::draw()
{
    float elapsedTime = startTime.elapsed();
    percent = elapsedTime / time;

    float x = percent * idLb->width();
    rectangle->setStyleSheet("QLabel { background-color: green; }");
    rectangle->resize(x, idLb->height());

    idLb->show();
    imageLb->show();
    rectangle->show();

    if(percent >= 1) {
        ProductionManager::getInstance()->removeProcess(this);
        delete idLb;
    }
}

void Process::makeLb()
{
    idLb = new QLabel();
    idLb->resize(lbWidth, lbHeight);
    idLb->setParent(widget);
    idLb->setStyleSheet("QLabel { background-color: #979b8d; }");
    int processes = widget->children().size();
    if (processes > 1) idLb->move(10*processes + (processes - 1)*100, 10);
    else idLb->move(10, 10);

    rectangle = new QLabel(idLb);

    imageLb = new QLabel(idLb);
    imageLb->setStyleSheet("QLabel { background-color: rgba(255, 255, 255, 0); "
                           "border-image: url(:/images/" + id + ".png); }");
    int imageLength = lbWidth * 0.7;
    imageLb->resize(imageLength, imageLength);
    int x = idLb->width()/2 - imageLb->width()/2;
    int y = idLb->height()/2 - imageLb->height()/2;
    imageLb->move(x, y);

}

void Process::deleteProcess()
{

}


