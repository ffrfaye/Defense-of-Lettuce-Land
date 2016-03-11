/**
  * @bullet.cpp
  * @brief Stores definitions for the Bullet class.
  * @author Rufei Fan
  * @3-10-2016
*/

#include "bullet.h"
#include "enemy.h"
#include <QTimer>
#include <QGraphicsScene>
#include <QDebug>
#include <QList>
#include "game.h"

#include "doge.h"

extern Game * game;

Bullet::Bullet(QGraphicsItem *parent): QObject(), QGraphicsPixmapItem(parent)
{
    // setRect(425,325,10,10);
    setPixmap(QPixmap(":/bullet.png"));

    setScale(0.01);

    QTimer* timer = new QTimer();
    connect(timer,SIGNAL(timeout()),this,SLOT(move()));

    timer->start(50);
}

void Bullet::move() {

    // check whether the bullet hit the enemy, if so destroy both
    QList<QGraphicsItem*> colliding_item = collidingItems();
    for(size_t i = 0, n = colliding_item.size(); i<n; ++i) {
        if(typeid(*(colliding_item[i])) == typeid(Enemy) || typeid(*(colliding_item[i])) == typeid(Doge)) {

            // remove item
            scene()->removeItem(colliding_item[i]);
            scene()->removeItem(this);

            // reallocate memory
            delete colliding_item[i];
            delete this;

            return;
        }
    }

    setPos(x()+10, y());
    if (pos().x() > 1000) {
        scene()->removeItem(this);
        delete this;
        qDebug()<<"deleted";
    }
}
