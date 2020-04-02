#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QMainWindow>

#include "game.h"
#include "button.h"
#include "pieceview.h"
#include "boardscene.h"
#include "tileview.h"

#include <QGraphicsView>
#include <QGraphicsScene>
#include <QGraphicsSceneMouseEvent>

class GameWindow : public QMainWindow
{
    Q_OBJECT

public:
    GameWindow(QWidget *parent = nullptr);

public slots:
    void newgame();
    void gamestart();
    void loadgame();
    void move(PieceView* movingpiece, QGraphicsItem* nextpiece);

private:
    QGraphicsScene* scene;
    QGraphicsView* view;
    Game* game;

};

#endif // MAINWINDOW_H
