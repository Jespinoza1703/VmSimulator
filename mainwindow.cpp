#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    makeWidgets(300, 340, widgetList);
    makeWidgets(700, 1150, queueList);

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
        int k = 0;
        for(Process * subProcess : *runningQueue){
            subProcess->setWidget(widgetList->value(i));
            subProcess->setLabelPos(k);
            k++;
        }
        i++;
    }
    for(QList<Process *> *waitingQueue : waitingQueues){
        int n = 0;
        for(Process * subProcess : *waitingQueue){
            subProcess->setWidget(queueList->value(j));
            subProcess->setLabelPos(n);
            n++;
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
    QWidget *qWidget = queueList[0][1];

    vehicleB->addComponent(new Process("C", 62000, qWidget));
    vehicleB->addComponent(new Process("A", 25000, qWidget));
    vehicleB->addComponent(new Process("B", 47000, qWidget));
    vehicleB->addComponent(new Process("E", 36000, qWidget));
    vehicleB->addComponent(new Process("D", 71000, qWidget));
    vehicleB->addComponent(new Process("F", 18000, qWidget));

    production->addVehicle(vehicleB, 2);

}

void MainWindow::on_vehicle3_clicked()
{

    Vehicle *vehicleC = new Vehicle("C");
    QWidget *qWidget = queueList[0][2];

    vehicleC->addComponent(new Process("D", 55000, qWidget));
    vehicleC->addComponent(new Process("E", 96000, qWidget));
    vehicleC->addComponent(new Process("A", 78000, qWidget));
    vehicleC->addComponent(new Process("C", 60000, qWidget));
    vehicleC->addComponent(new Process("B", 87000, qWidget));
    vehicleC->addComponent(new Process("F", 22000, qWidget));

    production->addVehicle(vehicleC, 3);
}


void MainWindow::on_vehicle4_clicked()
{

    Vehicle *vehicleD = new Vehicle("D");
    QWidget *qWidget = queueList[0][3];

    vehicleD->addComponent(new Process("B", 53000, qWidget));
    vehicleD->addComponent(new Process("C", 61000, qWidget));
    vehicleD->addComponent(new Process("D", 48000, qWidget));
    vehicleD->addComponent(new Process("A", 52000, qWidget));
    vehicleD->addComponent(new Process("F", 45000, qWidget));
    vehicleD->addComponent(new Process("E", 69000, qWidget));

    production->addVehicle(vehicleD, 4);
}

void MainWindow::on_vehicle5_clicked()
{

    Vehicle *vehicleE = new Vehicle("E");
    QWidget *qWidget = queueList[0][4];

    vehicleE->addComponent(new Process("E", 44000, qWidget));
    vehicleE->addComponent(new Process("F", 66000, qWidget));
    vehicleE->addComponent(new Process("B", 83000, qWidget));
    vehicleE->addComponent(new Process("C", 72000, qWidget));
    vehicleE->addComponent(new Process("A", 21000, qWidget));
    vehicleE->addComponent(new Process("D", 32000, qWidget));

    production->addVehicle(vehicleE, 5);
}


void MainWindow::on_vehicle6_clicked()
{

    Vehicle *vehicleF = new Vehicle("F");
    QWidget *qWidget = queueList[0][5];

    vehicleF->addComponent(new Process("F", 77000, qWidget));
    vehicleF->addComponent(new Process("D", 62000, qWidget));
    vehicleF->addComponent(new Process("C", 57000, qWidget));
    vehicleF->addComponent(new Process("B", 45000, qWidget));
    vehicleF->addComponent(new Process("E", 84000, qWidget));
    vehicleF->addComponent(new Process("A", 90000, qWidget));

    production->addVehicle(vehicleF, 6);
}
