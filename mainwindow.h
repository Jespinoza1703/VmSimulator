#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "draw/drawable.h"
#include "production/process.h"
#include "production/vehicle.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    void drawWidgets();



private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
