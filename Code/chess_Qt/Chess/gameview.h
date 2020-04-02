#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QMainWindow>

#include "button.h"
#include "pieceview.h"
#include "boardview.h"
#include "tileview.h"

#include <QGraphicsView>
#include <QGraphicsScene>

class GameView : public QMainWindow
{
    Q_OBJECT

public:
    GameView(QWidget *parent = nullptr);

private:
    QGraphicsScene* scene;
    QGraphicsView* view;
    BoardView* m_board;

public slots:
    void newgame();
    void gamestart();
    void gamestartAI();
    void loadgame();

};

#endif // MAINWINDOW_H
