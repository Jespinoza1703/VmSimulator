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

void MainWindow::makeWidgets(int x, int width, QList<QWidget *> list)
{
    for(int i = 1; i < 7; i++){
        QWidget *widget = new QWidget(ui->centralWidget);
        widget->setStyleSheet("QWidget { background-color: #a5b5bf; }");
        widget->resize(width, 120);
        if (list.size() < 1) widget->move(x, 20);
        else widget->move(x, (i - 1)*140 + 20);
        list.push_back(widget);
    }
}

