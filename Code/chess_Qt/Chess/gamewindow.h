#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QMainWindow>
#include <QApplication>

#include "game.h"
#include "button.h"
#include "pieceview.h"
#include "boardscene.h"
#include "tileview.h"

#include <QGraphicsView>
#include <QGraphicsScene>
#include <QMessageBox>
#include <QInputDialog>
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
    void gameOver();

private:
    QGraphicsScene* scene;
    QGraphicsView* view;
    Game* game;

};

#endif // MAINWINDOW_H
