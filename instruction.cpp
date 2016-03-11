/**
  * @instruction.cpp
  * @brief Stores definitions for the Instruction class.
  * @author Rufei Fan
  * @3-10-2016
*/

#include "instruction.h"
#include "game.h"
#include <QString>
#include <QLabel>
#include <QPushButton>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QFont>

Instruction::Instruction(QWidget * parent)
{
    QLabel* instruction = new QLabel(this);

    QString instructiontext(QString("Instruction: <br> <br>")+
                            QString("Move with the left and right keys on your keyboard.<br>Shoot with spacebar.<br>") +
                            QString("<br>")+
                            QString("Getting tomoatoes will speed you up!<br>")+
                            QString("Shoot the ghost and dodge the doge!<br>")+
                            QString("You can also shoot doge if you want.<br>")
                            );

    instruction->setText(instructiontext);
    instruction->setFixedSize(600,400);
    instruction->setAlignment(Qt::AlignCenter);
}
