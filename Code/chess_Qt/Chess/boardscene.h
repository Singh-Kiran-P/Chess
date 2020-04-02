#ifndef BOARDVIEW_H
#define BOARDVIEW_H

#include "game.h"
#include "tileview.h"
#include "pieceview.h"
#include "board.h"

#include <QDebug>
#include <QGraphicsItem>
#include <QGraphicsScene>

class BoardScene : public QGraphicsScene
{
    Q_OBJECT
public:
    BoardScene(Game* game);
    void mousePressEvent(QGraphicsSceneMouseEvent *mouseEvent);

public slots:
    void movedpiece();

signals:
    void doMove(PieceView*, QGraphicsItem*);

private:
    Board* m_board;
    PieceView* m_movingpiece = nullptr;
    QGraphicsItem* m_nextpiece = nullptr;
};

#endif // BOARDVIEW_H
