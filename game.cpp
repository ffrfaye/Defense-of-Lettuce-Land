/**
  * @game.cpp
  * @brief Stores definitions for the Game class.
  * @author Rufei Fan
  * @3-10-2016
*/

#include "game.h"
#include "mainwindow.h"
#include <QApplication>
#include <QGraphicsScene>
#include <QGraphicsPixmapItem>
#include <QGraphicsView>
#include <QTimer>
#include <QBrush>
#include <QImage>
#include <QMediaPlayer>


#include "player.h"
#include "bullet.h"

Game::Game(QWidget * parent)
{

    // create a scene
    QGraphicsScene * scene = new QGraphicsScene();

    // create an item to adda to the scene
    Player* one = new Player;
    one->setPixmap(QPixmap(":/player2.tiff"));
    one->setScale(0.2);
    one->setPos(350,230);

    // add the item to the scene
    scene->addItem(one);
    one->setFlag(QGraphicsRectItem::ItemIsFocusable);
    one->setFocus();

    setScene(scene);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    scene->setSceneRect(0,0,1280,360);
    scene->setBackgroundBrush(QBrush(QImage(":/background copy.jpg")));

    // get falling objects
    QTimer* falling_timer = new QTimer();
    QObject::connect(falling_timer, SIGNAL(timeout()), one, SLOT(tomato_fall()));
    falling_timer->start(4000);

    // get doge objects to dodge
    QTimer* doge_timer = new QTimer();
    QObject::connect(doge_timer, SIGNAL(timeout()), one, SLOT(doge_fall()));
    doge_timer->start(4000);

    // get enemy
    QTimer* enemy_timer = new QTimer();
    QObject::connect(enemy_timer, SIGNAL(timeout()), one, SLOT(enemy_start()));
    enemy_timer->start((2500));

    // player background music
    QMediaPlayer* bgm = new QMediaPlayer();
    bgm->setMedia(QUrl("qrc:/Overworld.mp3"));
    bgm->play();

    show();
}
