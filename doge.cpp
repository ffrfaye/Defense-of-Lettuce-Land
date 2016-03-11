/**
  * @doge.cpp
  * @brief Stores definitions for the Doge class.
  * @author Rufei Fan
  * @3-10-2016
*/

#include "doge.h"
#include <QTimer>
#include <QGraphicsScene>
#include <QDebug>
#include "stdlib.h"

Doge::Doge() {

    // set random position
    int random_number = rand() % 650; // 100 less than the width of the screen
    setPos(random_number,0);

    setPixmap(QPixmap(":/doge-head.png"));
    //setRect(0,0,10,10);

    QTimer* timer = new QTimer();
    connect(timer,SIGNAL(timeout()),this,SLOT(move()));

    timer->start(100);
}

void Doge::move() {
    setPos(x(), y()+8);
    if (pos().y() > 280) {
        scene()->removeItem(this);
        delete this;

        qDebug()<<"deleted";
    }
}
