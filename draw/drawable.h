#ifndef DRAWABLE_H
#define DRAWABLE_H


/**
 * @brief
 *
 * @class Drawable drawable.h "drawable.h"
 */
class Drawable
{
public:
    /**
     * @brief
     *
     * @fn ~Drawable
     */
    virtual ~Drawable() {}

    /**
     * @brief
     *
     * @fn draw
     */
    virtual void draw() = 0;
};

#endif // DRAWABLE_H
