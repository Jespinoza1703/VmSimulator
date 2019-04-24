#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    makeWidgets(300, 340, widgetList);
    makeWidgets(700, 440, queueList);

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

void MainWindow::on_vehicle1_clicked()
{
    Vehicle *vehicleA = new Vehicle("A");
    QWidget *widget = widgetList[0][0];

    vehicleA->addComponent(new Process("A", 3500, widget));
    vehicleA->addComponent(new Process("B", 4800, widget));
    vehicleA->addComponent(new Process("C", 10000, widget));
    vehicleA->addComponent(new Process("D", 2500, widget));
    vehicleA->addComponent(new Process("E", 5400, widget));
    vehicleA->addComponent(new Process("F", 8400, widget));
}

void MainWindow::on_vehicle2_clicked()
{
    Vehicle *vehicleA = new Vehicle("B");
    /*
    vehicleA->addComponent(new Process("C", 15000, widget));
    vehicleA->addComponent(new Process("A", 2400, widget));
    vehicleA->addComponent(new Process("B", 9100, widget));
    vehicleA->addComponent(new Process("E", 6200, widget));
    vehicleA->addComponent(new Process("D", 1200, widget));
    vehicleA->addComponent(new Process("F", 4500, widget));
    */

}



