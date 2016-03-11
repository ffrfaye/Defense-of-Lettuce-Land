/**
  * @player.h
  * @brief Stores declaration for the Player class.
  * @author Rufei Fan
  * @3-10-2016
*/

#ifndef PLAYER_H
#define PLAYER_H

#include <QDebug>
#include <QKeyEvent>
#include <QGraphicsPixmapItem>
#include <QGraphicsItem>
#include <QGraphicsScene>
#include <QGraphicsTextItem>
#include <QTimer>
#include <QObject>

#include "bullet.h"
#include "falling.h"
#include "enemy.h"
#include "doge.h"


static bool* top = new bool;

/**
 * @class Player
 * @brief The Player class represents the player.
 * The player moves according to the keyboard event.
 * It catches falling tomatoes for speed bonus.
 * It dies (disappears) when colliding with falling doges and coming ghosts.
 * It shoots bullet when users pressing space bar.
 * The class stores an int value indicate the player's moving speed.
 */

class Player: public QObject, public QGraphicsPixmapItem {
        Q_OBJECT
public:
    Player(QGraphicsItem * parent=0);

    /**
     * @brief keyPressEvent moves the player if left/right is pressed.
     * @param event describeds the key pressed.
     */
    void keyPressEvent(QKeyEvent* event);

public slots:

    /**
     * @brief tomato_fall creates new falling tomato objects.
     * Add them to the scene for the player to collect.
     */
    void tomato_fall();

    /**
     * @brief doge_fall creates new falling doge objects.
     * Add them to the scene for the player to dodge.
     */
    void doge_fall();

    /**
     * @brief catch_falls enables the player to catch the falling tomatoes.
     * When the player collides with the tomato, the tomato object get deleted.
     * The player gets speed bonus.
     */
    void catch_falls();

    /**
     * @brief enemy_start creates new Enemy objects
     * Add them to the scene for the player to shoot and dodge.
     */
    void enemy_start();

    /**
     * @brief killed_by_enemy deletes the player and the colliding Enemy object.
     * Game over.
     */
    void killed_by_enemy();

    /**
     * @brief killed_by_doge deletes the player and the colliding Doge object.
     * Game over.
     */
    void killed_by_doge();

private:
    int speed = 10;

};

#endif // PLAYER_H
