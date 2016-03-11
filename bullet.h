/**
  * @bullet.h
  * @brief Stores declaration for the Bullet class.
  * @author Rufei Fan
  * @3-10-2016
*/

#ifndef BULLET_H
#define BULLET_H

#include <QGraphicsPixmapItem>
#include <QGraphicsItem>
#include <QObject>

/**
 * @class Bullet
 * @brief A red square bullet moves forward.
 * The Bullet class is a QGraphicsPixmapItem which is a red square that move forward.
 * When the Bullet collide with a Falling Doge object or coming Enemy object, they will both disappear.
*/

class Bullet : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT 
public:
    Bullet(QGraphicsItem * parent=0); 
public slots:
    /**
     * @brief move the red square bullet.
     * When user push the space bar, the player will shoot a bullet.
     * The bullet will move at a constant spped.
     * When the bullet collide with a doge or enemy object they will all be deleted and disappear.
     */
    void move();

};

#endif // BULLET_H
