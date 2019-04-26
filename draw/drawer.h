#ifndef DRAWER_H
#define DRAWER_H

#include "drawable.h"

#include <QObject>
#include <QTimer>
#include <QDebug>


/**
 * @brief
 *
 * @class Drawer drawer.h "drawer.h"
 */
class Drawer : public QObject
{
    Q_OBJECT

public:
    /**
     * @brief
     *
     * @fn getInstance
     * @return Drawer
     */
    static Drawer *getInstance();

    /**
     * @brief
     *
     * @fn run
     */
    void run();

    /**
     * @brief
     *
     * @fn addDrawable
     * @param drawable
     */
    void addDrawable(Drawable *drawable);

    /**
     * @brief
     *
     * @fn removeDrawable
     * @param drawable
     */
    void removeDrawable(Drawable *drawable);

public slots:
    /**
     * @brief
     *
     * @fn draw
     */
    void draw();

private:
    static Drawer *instance; /**< TODO: describe */
    QList<Drawable *> drawables; /**< TODO: describe */

    /**
     * @brief
     *
     * @fn Drawer
     */
    Drawer();
};

#endif // DRAWER_H
