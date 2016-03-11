/**
  * @gameover.cpp
  * @brief Stores definitions for the GameOver class.
  * @author Rufei Fan
  * @3-10-2016
*/

#include "gameover.h"
#include "game.h"
#include <QString>
#include <QLabel>
#include <QPushButton>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QFont>

GameOver::GameOver(QWidget * parent)
{
    QLabel* gg = new QLabel(this);

    QString ggtext(QString("<font size=40 color=red>GAME OVER!</font>"));
    gg->setText(ggtext);
    gg->setFixedSize(300,300);
    gg->setAlignment(Qt::AlignCenter);
}

