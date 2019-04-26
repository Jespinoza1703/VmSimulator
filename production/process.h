#ifndef PROCESS_H
#define PROCESS_H

#include "draw/drawable.h"

#include <QString>
#include <QTime>
#include <QDebug>
#include <QLabel>
#include <QTableWidget>
#include <QDebug>
#include <QTimer>
#include <string>

using namespace std;

/**
 * @brief
 *
 * @class Process process.h "process.h"
 */
class Process : public Drawable
{

public:
    /**
     * @brief
     *
     * @fn Process
     * @param id
     * @param time
     * @param widget
     */
    Process(QString id, float time, QWidget * widget);

    /**
     * @brief
     *
     * @fn draw
     */
    void draw();
    /**
     * @brief
     *
     * @fn makeLb
     */
    void makeLb();
    /**
     * @brief
     *
     * @fn deleteProcess
     */
    void deleteProcess();

    /**
     * @brief
     *
     * @fn getWidget
     * @return QWidget
     */
    QWidget *getWidget() const;
    /**
     * @brief
     *
     * @fn setWidget
     * @param value
     */
    void setWidget(QWidget *value);

    /**
     * @brief
     *
     * @fn getIdLb
     * @return QLabel
     */
    QLabel *getIdLb() const;

    /**
     * @brief
     *
     * @fn setLabelPos
     * @param i
     */
    void setLabelPos(int i);

private:
    QLabel *idLb; /**< TODO: describe */
    QLabel *imageLb; /**< TODO: describe */
    QString id; /**< TODO: describe */
    float time; /**< TODO: describe */
    float percent; /**< TODO: describe */
    QTime startTime; /**< TODO: describe */
    QWidget *widget; /**< TODO: describe */
    QLabel *rectangle; /**< TODO: describe */
    int lbWidth; /**< TODO: describe */
    int lbHeight; /**< TODO: describe */

};

#endif // PROCESS_H
