/**
  * @enemy.cpp
  * @brief Stores definitions for the Enemy class.
  * @author Rufei Fan
  * @3-10-2016
*/

#include "enemy.h"
#include "stdlib.h"
#include <QTimer>
#include <QGraphicsScene>
#include <QDebug>
#include "Game.h"

extern Game * game;

Enemy::Enemy(QGraphicsItem *parent): QObject(), QGraphicsPixmapItem(parent) {

    setPixmap(QPixmap(":/enemy.png"));
    setScale(0.1);
    setPos(1280,230);

    QTimer* timer = new QTimer();
    connect(timer,SIGNAL(timeout()),this,SLOT(move()));

    timer->start(50);
}

void Enemy::move() {
    setPos(x()-5, y());
    if (pos().x() < 0) {
        scene()->removeItem(this);
        delete this;
        qDebug()<<"deleted enemy";
    }
}

