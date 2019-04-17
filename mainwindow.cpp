#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    Vehicle *vehicleA = new Vehicle("A");
    Drawable *processA = new Process("A", 2, ui->centralWidget);
    processA->draw();

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::drawWidgets()
{

}
