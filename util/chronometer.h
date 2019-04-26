#ifndef Chronometer_H
#define Chronometer_H

#include <QTimer>
#include <QDebug>


/**
 * @brief
 *
 * @class Chronometer chronometer.h "chronometer.h"
 */
class Chronometer
{
public:
    /**
     * @brief
     *
     * @fn Chronometer
     * @param interval
     */
    explicit Chronometer(int interval);

    QTimer *timer; /**< TODO: describe */
    int interval; /**< TODO: describe */

    int elapsedTime = 0; /**< TODO: describe */

    /**
     * @brief
     *
     * @fn inicialize
     */
    void inicialize();
    /**
     * @brief
     *
     * @fn stop
     */
    void stop();
    /**
     * @brief
     *
     * @fn resume
     */
    void resume();

public slots:
    /**
     * @brief
     *
     * @fn onTimeOut
     */
    void onTimeOut();
};

#endif // Chronometer_H
