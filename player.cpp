/**
  * @player.cpp
  * @brief Stores definitions for the Player class.
  * @author Rufei Fan
  * @3-10-2016
*/

#include "player.h"
#include "gameover.h"
#include <QList>
#include <QTimer>
#include <QGraphicsScene>
#include <QDebug>
#include <QList>
#include <QLabel>

Player::Player(QGraphicsItem *parent): QGraphicsPixmapItem(parent)
{
    QTimer* falltimer = new QTimer();
    QTimer* enemytimer = new QTimer();
    QTimer* dogetimer = new QTimer();
    connect(falltimer,SIGNAL(timeout()),this,SLOT(catch_falls()));
    connect(enemytimer, SIGNAL(timeout()), this, SLOT(killed_by_enemy()));
    connect(dogetimer, SIGNAL(timeout()),this,SLOT(killed_by_doge()));
    falltimer->start(50);
    enemytimer->start(50);
    dogetimer->start(50);

}

void Player::keyPressEvent(QKeyEvent *event){
    if(event->key()==Qt::Key_Left){
        if(pos().x() > 0)
            setPos(x()-speed,y());
    }
    else if(event->key()==Qt::Key_Right){
        if(pos().x() + 80 < 1280)
            setPos(x()+speed,y());
    }
    else if(event->key()==Qt::Key_Space){
        Bullet* bullet = new Bullet();
        bullet->setPos(x()+50,y()+25);
        scene()->addItem(bullet);
    }
}

void Player::tomato_fall(){
    Falling* to_catch = new Falling();
    scene()->addItem(to_catch);
}

void Player::doge_fall(){
    Doge* to_catch = new Doge();
    scene()->addItem(to_catch);

}

void Player::catch_falls()
{
    // check whether the bullet hit the enemy, if so destroy both
    QList<QGraphicsItem*> catch_item = collidingItems();
    for(size_t i = 0, n = catch_item.size(); i<n; ++i) {
        if(typeid(*(catch_item[i])) == typeid(Falling)) {

            speed += 2;
            // remove item
            scene()->removeItem(catch_item[i]);

            // reallocate memory
            delete catch_item[i];
        }
    }
}


void Player::enemy_start()
{
    Enemy* enemy = new Enemy();
    scene()->addItem(enemy);
}

void Player::killed_by_enemy()
{
    // check whether the player hit the enemy, if so destroy both
    QList<QGraphicsItem*> killed_e = collidingItems();
    for(size_t i = 0, n = killed_e.size(); i<n; ++i) {
        if(typeid(*(killed_e[i])) == typeid(Enemy)) {


            // remove item
            scene()->removeItem(killed_e[i]);
            scene()->removeItem(this);

            // reallocate memory
            delete killed_e[i];
            delete this;

            GameOver* gg = new GameOver;
            gg->show();
        }
    }
}

void Player::killed_by_doge()
{
    // check whether the player hit the enemy, if so destroy both
    QList<QGraphicsItem*> killed_d = collidingItems();
    for(size_t i = 0, n = killed_d.size(); i<n; ++i) {
        if(typeid(*(killed_d[i])) == typeid(Doge)) {


            // remove item
            scene()->removeItem(killed_d[i]);
            scene()->removeItem(this);

            // reallocate memory
            delete killed_d[i];
            delete this;

            GameOver* gg = new GameOver;
            gg->show();
        }
    }
}


