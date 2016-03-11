/**
  * @falling.cpp
  * @brief Stores definitions for the Falling class.
  * @author Rufei Fan
  * @3-10-2016
*/
#include "gameover.h"
#include "falling.h"
#include "game.h"
#include <QTimer>
#include <QGraphicsScene>
#include <QDebug>
#include "stdlib.h"

extern Game* game;

Falling::Falling() {

    // set random position
    int random_number = rand() % 700; // 100 less than the width of the screen
    setPos(random_number,0);

    setPixmap(QPixmap(":/Tomato-icon.png"));
    //setRect(0,0,10,10);

    QTimer* timer = new QTimer();
    connect(timer,SIGNAL(timeout()),this,SLOT(move()));

    timer->start(100);
}

void Falling::move() {

    setPos(x(), y()+10);
    if (pos().y() > 280) {

        //scene()->removeItem(game->player);
        scene()->removeItem(this);
        //delete game->player;
        delete this;

        qDebug()<<"deleted";
    }
}
