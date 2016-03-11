/**
  * @falling.h
  * @brief Stores declaration for the Falling class.
  * @author Rufei Fan
  * @3-10-2016
*/

#ifndef FALLING_H
#define FALLING_H

#include <QGraphicsPixmapItem>
#include <QObject>

/**
 * @class Falling
 * @brief A Falling object with the image of a tomato icon that moves downward.
 * The Falling class is a QGraphicsPixmapItem which is a tomato icon that move downward.
 * When the player collides with a Falling object, the falling object will be deleted and the player will get a speed bonus.
*/
class Falling : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    Falling();
public slots:
    /**
    * @brief move the Falling object.
    * Set the Falling object to fall at a constant speed.
    * When the object falls out of the lowerbound it gets deleted.
    */
    void move();

};

#endif // FALLING_H
