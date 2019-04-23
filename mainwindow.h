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

    void makeWidgets();

private:
    Ui::MainWindow *ui;
    Drawer *drawer = Drawer::getInstance();
    ProductionManager *production = ProductionManager::getInstance();

    QList<QWidget *> widgetList;
};

#endif // MAINWINDOW_H
