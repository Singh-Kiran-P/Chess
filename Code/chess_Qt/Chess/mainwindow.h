#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QDebug>
#include <QMainWindow>

#include <QGraphicsView>
#include <QGraphicsScene>
#include <QGraphicsRectItem>
#include <QGraphicsSceneMouseEvent>
#include <QGraphicsPixmapItem>

class Piece : public QGraphicsPixmapItem {
public:
    Piece(QColor color);
};

class BoardView : public QGraphicsView {
public:
    BoardView();
};

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    void BuildBoard();
    void PlacePawns();
    QGraphicsItem* getSelectedPawn();

private:
    QGraphicsScene* scene;
    QGraphicsView* view;
    QGraphicsItem* selectedpawn;

};

class Tile : public QGraphicsRectItem {
public:
    Tile(QColor color, QGraphicsScene* scene);
    void mousePressEvent(QGraphicsSceneMouseEvent* event);

private:
    QGraphicsScene* scene;
};

#endif // MAINWINDOW_H
