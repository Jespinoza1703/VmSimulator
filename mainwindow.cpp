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

void MainWindow::manageProcesses(QList<Process *> *list, Vehicle *vehicle, int i)
{
    QWidget *widget = widgetList[0][i];

    for(Process *process : *list){
        for (Process *subProcess : *production->getRunningQueues().value(i)){
            if(process == subProcess) process->setWidget(widget);
        }
        vehicle->addComponent(process);
    }
}

void MainWindow::on_vehicle1_clicked()
{
    Vehicle *vehicleA = new Vehicle("A");
    QWidget *qWidget = queueList[0][0];

    QList<Process *> *pList = new QList<Process *>();
    pList->push_back(new Process("A", 35000, qWidget));
    pList->push_back(new Process("B", 48000, qWidget));
    pList->push_back(new Process("C", 60000, qWidget));
    pList->push_back(new Process("D", 25000, qWidget));
    pList->push_back(new Process("E", 54000, qWidget));
    pList->push_back(new Process("F", 84000, qWidget));

    manageProcesses(pList, vehicleA, 1);

    production->addVehicle(vehicleA, 1);
}


void MainWindow::on_vehicle2_clicked()
{
    Vehicle *vehicleB = new Vehicle("B");

    QList<Process *> *pList = new QList<Process *>();
    /*
    pList->push_back(new Process("C", 65000));
    pList->push_back(new Process("A", 24000));
    pList->push_back(new Process("B", 91000));
    pList->push_back(new Process("E", 62000));
    pList->push_back(new Process("D", 22000));
    pList->push_back(new Process("F", 45000));
    */


    manageProcesses(pList, vehicleB, 2);

    production->addVehicle(vehicleB, 2);

}



