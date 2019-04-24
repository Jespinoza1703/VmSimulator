#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "draw/drawable.h"
#include "production/process.h"
#include "production/vehicle.h"
#include "production/productionmanager.h"
#include "draw/drawer.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    void makeWidgets(int x, int width, QList<QWidget *> *list);

private slots:
    void on_vehicle2_clicked();

    void on_vehicle1_clicked();

private:
    Ui::MainWindow *ui;
    Drawer *drawer = Drawer::getInstance();
    ProductionManager *production = ProductionManager::getInstance();

    QList<QWidget *> *widgetList = new QList<QWidget *>();
    QList<QWidget *> *queueList = new QList<QWidget *>();

    void manageProcesses(QList<Process *> *list, Vehicle *vehicle, int i);
};

#endif // MAINWINDOW_H
