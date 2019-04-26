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

/**
 * @brief
 *
 * @class MainWindow mainwindow.h "mainwindow.h"
 */
class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    /**
     * @brief
     *
     * @fn MainWindow
     * @param parent
     */
    explicit MainWindow(QWidget *parent = nullptr);
    /**
     * @brief
     *
     * @fn ~MainWindow
     */
    ~MainWindow();

    /**
     * @brief
     *
     * @fn makeWidgets
     * @param x
     * @param width
     * @param list
     */
    void makeWidgets(int x, int width, QList<QWidget *> *list);

public slots:
    /**
     * @brief
     *
     * @fn manageProcesses
     */
    void manageProcesses();

private slots:
    /**
     * @brief
     *
     * @fn on_vehicle2_clicked
     */
    void on_vehicle2_clicked();

    /**
     * @brief
     *
     * @fn on_vehicle1_clicked
     */
    void on_vehicle1_clicked();

    /**
     * @brief
     *
     * @fn on_vehicle3_clicked
     */
    void on_vehicle3_clicked();

    /**
     * @brief
     *
     * @fn on_vehicle4_clicked
     */
    void on_vehicle4_clicked();

    /**
     * @brief
     *
     * @fn on_vehicle5_clicked
     */
    void on_vehicle5_clicked();

    /**
     * @brief
     *
     * @fn on_vehicle6_clicked
     */
    void on_vehicle6_clicked();

private:
    Ui::MainWindow *ui; /**< TODO: describe */
    Drawer *drawer = Drawer::getInstance(); /**< TODO: describe */
    QList<QWidget *> *widgetList = new QList<QWidget *>(); /**< TODO: describe */
    QList<QWidget *> *queueList = new QList<QWidget *>(); /**< TODO: describe */
    ProductionManager *production = ProductionManager::getInstance(); /**< TODO: describe */




};

#endif // MAINWINDOW_H
