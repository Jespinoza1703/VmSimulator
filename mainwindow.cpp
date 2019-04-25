#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    makeWidgets(300, 340, widgetList);
    makeWidgets(700, 700, queueList);

    drawer->run();
    production->run();

    manageProcesses();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::makeWidgets(int x, int width, QList<QWidget *> *list)
{
    for(int i = 1; i < 7; i++){
        QWidget *widget = new QWidget(ui->centralWidget);
        widget->setStyleSheet("QWidget { background-color: #a5b5bf; }");
        widget->resize(width, 120);
        if (list->size() == 0) widget->move(x, 20);
        else widget->move(x, (i - 1)*140 + 20);

        list->push_back(widget);
    }

}

void MainWindow::manageProcesses()
{
    QTimer::singleShot(100, this, &MainWindow::manageProcesses);

    QList<QList<Process *>*> runningQueues = production->getRunningQueues();
    QList<QList<Process *>*> waitingQueues = production->getWaitingQueues();

    int i = 0, j = 0;
    for(QList<Process *> *runningQueue : runningQueues){
        for(Process * subProcess : *runningQueue){
            subProcess->setWidget(widgetList->value(i));
        }
        i++;
    }
    for(QList<Process *> *waitingQueue : waitingQueues){
        for(Process * subProcess : *waitingQueue){
            subProcess->setWidget(queueList->value(j));
        }
        j++;
    }
}

void MainWindow::on_vehicle1_clicked()
{
    Vehicle *vehicleA = new Vehicle("A");
    QWidget *qWidget = queueList[0][0];

    vehicleA->addComponent(new Process("A", 35000, qWidget));
    vehicleA->addComponent(new Process("B", 48000, qWidget));
    vehicleA->addComponent(new Process("C", 60000, qWidget));
    vehicleA->addComponent(new Process("D", 25000, qWidget));
    vehicleA->addComponent(new Process("E", 54000, qWidget));
    vehicleA->addComponent(new Process("F", 84000, qWidget));

    production->addVehicle(vehicleA, 1);
}


void MainWindow::on_vehicle2_clicked()
{
    Vehicle *vehicleB = new Vehicle("B");

    QList<Process *> *pList = new QList<Process *>();
    /*
    vehicleA->addComponent(new Process("C", 65000, qWidget));
    vehicleA->addComponent(new Process("A", 24000, qWidget));
    vehicleA->addComponent(new Process("B", 91000, qWidget));
    vehicleA->addComponent(new Process("E", 62000, qWidget));
    vehicleA->addComponent(new Process("D", 22000, qWidget));
    vehicleA->addComponent(new Process("F", 45000, qWidget));
    */

    production->addVehicle(vehicleB, 2);

}



