#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    makeWidgets();

    Vehicle *vehicleA = new Vehicle("A");
    Drawable *processA = new Process("A", 2, widgetList[0]);
    processA->draw();
    Drawable *processB = new Process("B", 2, widgetList[0]);
    processB->draw();
    Drawable *processC = new Process("C", 2, widgetList[0]);
    processC->draw();


}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::makeWidgets()
{
    for(int i = 1; i < 7; i++){
        QWidget *widget = new QWidget(ui->centralWidget);
        widget->setStyleSheet("QWidget { background-color: #a5b5bf; }");
        widget->resize(340, 120);
        if (widgetList.size() < 1) widget->move(200, 20);
        else widget->move(200, (i - 1)*140 + 20);
        widgetList.push_back(widget);
    }
}

