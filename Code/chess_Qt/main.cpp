#include "gamewindow.h"

#include <QApplication>
#include "game.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    GameWindow game;
    game.buildMenuBar();
    game.show();
    return a.exec();
}
