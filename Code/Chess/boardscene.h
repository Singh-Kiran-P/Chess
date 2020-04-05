#ifndef BOARDVIEW_H
#define BOARDVIEW_H

#include "game.h"
#include "tileview.h"
#include "pieceview.h"
#include "board.h"

#include <QGraphicsItem>
#include <QGraphicsScene>

class BoardScene : public QGraphicsScene
{
    Q_OBJECT
public:
    BoardScene(Game* game);
    void mousePressEvent(QGraphicsSceneMouseEvent *mouseEvent);
    void clearSelection();

public slots:
    void movedpiece(QPoint, QPoint);
    void placePixMap(Piece*);
    void promotePixMap(QString, Pawn* pawn);

signals:
    void doMove(PieceView*, QGraphicsItem*);

private:
    Board* m_board;
    PieceView* m_movingpiece = nullptr;
    QGraphicsItem* m_nextpiece = nullptr;
};

#endif // BOARDVIEW_H
