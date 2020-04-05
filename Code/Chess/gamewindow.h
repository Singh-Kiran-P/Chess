#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QMainWindow>
#include <QApplication>
#include <QMenuBar>

#include "game.h"
#include "button.h"
#include "pieceview.h"
#include "boardscene.h"
#include "tileview.h"

#include <QDebug>
#include <QGraphicsView>
#include <QSignalMapper>
#include <QGraphicsScene>
#include <QMessageBox>
#include <QInputDialog>
#include <QPushButton>
#include <QDialog>

class GameWindow : public QMainWindow
{
    Q_OBJECT

public:
    GameWindow(QWidget *parent = nullptr);
    void buildMenuBar();
    void mainMenu();
    void mainMenuButtons();

public slots:

    void newgame();
    void gamestart(int);
    void loadgame();
    void savegame();
    void move(PieceView* movingpiece, QGraphicsRectItem* nextpiece);
    void getPromotionPiece(Pawn*);
    void gameOver();
    void quitgame();
    void backButton();

private:
    QGraphicsScene* scene = nullptr;
    QGraphicsView* view = nullptr;
    Game* game = nullptr;
    bool gameStarted = false;

};

#endif // MAINWINDOW_H
