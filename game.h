/**
  * @game.h
  * @brief Stores declaration for the Game class.
  * @author Rufei Fan
  * @3-10-2016
*/

#ifndef GAME_H
#define GAME_H

#include <QGraphicsView>
#include <QWidget>
#include <QGraphicsScene>
#include "Player.h"

/**
 * @class Game
 * @brief Stores a game board.
 * The Game class is a QGraphicView which has a background.
 * It stores a scene and a player.
*/

class Game: public QGraphicsView{
public:
    Game(QWidget * parent=0);

    QGraphicsScene * scene;
    Player * player;


};

#endif // GAME_H
