/**
  * @enemy.h
  * @brief Stores declaration for the Enemy class.
  * @author Rufei Fan
  * @3-10-2016
*/

#ifndef ENEMY_H
#define ENEMY_H

#include <QGraphicsItem>
#include <QObject>
#include <QGraphicsPixmapItem>

/**
 * @class Enemy
 * @brief A Enemy object with the image of a ghost that moves towards the left.
 * The Enemy class is a QGraphicsPixmapItem which is a ghost icon that move towards the left.
 * When the Enemy collide with the player or the Bullet object they will all disappear.
*/

class Enemy : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    Enemy(QGraphicsItem * parent=0);
public slots:
    /**
    * @brief move the Enemy object.
    * Set the Enemy object to move at a constant speed.
    * When the object moves out of the leftmost side it gets deleted.
    */
    void move();

};

#endif // ENEMY_H
