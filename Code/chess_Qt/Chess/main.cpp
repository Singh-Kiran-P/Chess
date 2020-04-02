#include "gameview.h"

#include <QApplication>
#include "Game.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    GameView game;
    game.show();
    return a.exec();
}
