#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "draw/drawable.h"
#include "production/process.h"
#include "production/vehicle.h"
#include "production/productionmanager.h"
#include "draw/drawer.h"
#include <QTimer>

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

public slots:
    void manageProcesses();

private slots:
    void on_vehicle2_clicked();

    void on_vehicle1_clicked();

private:
    Ui::MainWindow *ui;
    Drawer *drawer = Drawer::getInstance();
    QList<QWidget *> *widgetList = new QList<QWidget *>();
    QList<QWidget *> *queueList = new QList<QWidget *>();
    ProductionManager *production = ProductionManager::getInstance();




};

#endif // MAINWINDOW_H
