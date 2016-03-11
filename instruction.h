/**
  * @instruction.h
  * @brief Stores declaration for the Instruction class.
  * @author Rufei Fan
  * @3-10-2016
*/

#ifndef INSTRUCTION_H
#define INSTRUCTION_H

#include <QWidget>

/**
 * @class Instruction
 * @brief The Instruction class reprsents the pop-up window containing the game instrution.
 * This screen will be launched by clicking "instruction" button on the welcome page.
 */

class Instruction : public QWidget
{
    Q_OBJECT
public:
    Instruction(QWidget * parent = 0);
};

#endif // INSTRUCTION_H
