/**
  * @welcomepage.cpp
  * @brief Stores definitions for the WelcomePage class.
  * @author Rufei Fan
  * @3-10-2016
*/

#include "welcomepage.h"
#include "game.h"
#include "instruction.h"
#include <QString>
#include <QLabel>
#include <QPushButton>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QFont>

WelcomePage::WelcomePage(QWidget *parent)
{
    QLabel* title = new QLabel("<font size=40 color=red>Defense of Lettuce Land</font>", this);
    QLabel* instruction = new QLabel(this);

    QPushButton* play = new QPushButton("GO!", this);
    QPushButton* inst = new QPushButton("Instruction", this);

    title->setAlignment(Qt::AlignCenter);
    instruction->setAlignment(Qt::AlignCenter);

    QVBoxLayout* layout = new QVBoxLayout(this);
    layout->addWidget(title);
    layout->addWidget(instruction);
    layout->addSpacing(50);
    layout->addWidget(inst);
    layout->addWidget(play);

    setLayout(layout);

    connect(play, SIGNAL(clicked()), this, SLOT(play()));
    connect(inst, SIGNAL(clicked()), this, SLOT(instruct()));
}

void WelcomePage::play()
{
    Game* game = new Game();
    close();
}

void WelcomePage::instruct()
{
    Instruction* instruction_page = new Instruction();
    instruction_page->show();
}
