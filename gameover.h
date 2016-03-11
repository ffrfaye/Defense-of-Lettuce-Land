/**
  * @gameover.h
  * @brief Stores declaration for the GameOver class.
  * @author Rufei Fan
  * @3-10-2016
*/

#ifndef GAMEOVER_H
#define GAMEOVER_H

#include <QWidget>

/**
 * @class GameOver
 * @brief The GameOver class reprsents the pop-up window containing the game over message.
 * This screen will be launched by any kind of death of the player.
 */

class GameOver : public QWidget
{
    Q_OBJECT
public:
    GameOver(QWidget * parent = 0);
};

#endif // GAMEOVER_H


