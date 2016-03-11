/**
  * @main.cpp
  * @brief Stores the main page.
  * @author Rufei Fan
  * @3-10-2016
*/

#include <QApplication>
#include "game.h"
#include "welcomepage.h"
#include <QWidget>
#include <QLabel>

Game * game;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    WelcomePage page;
    page.setMinimumSize(800,600);
    page.show();

    return a.exec();
}
