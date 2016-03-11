/**
  * @doge.h
  * @brief Stores declaration for the Doge class.
  * @author Rufei Fan
  * @3-10-2016
*/

#ifndef DOGE_H
#define DOGE_H

#include <QGraphicsPixmapItem>
#include <QObject>

/**
 * @class Doge
 * @brief A Doge object with the image of a doge icon that moves downward.
 * The Doge class is a QGraphicsPixmapItem which is a doge icon that move downward.
 * When the player or a bullet collide with a Doge object they will both disappear.
*/

class Doge : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    Doge(); 
public slots:
     /**
     * @brief move the Doge object.
     * Set the Doge object to fall at a constant speed.
     * When the object falls out of the lowerbound it gets deleted.
     */
    void move();

};


#endif // DOGE_H
