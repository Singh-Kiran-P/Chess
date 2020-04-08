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
    void mousePressEvent(QGraphicsSceneMouseEvent *mouseEvent) override;
    void promotePixMap(QString, Pawn* pawn);
    void clearSelection();

public slots:
    void movedpiece(QPoint, QPoint);
    void placePixMap(Piece*);
    void setCheckEffect(QColor);

signals:
    void doMove(PieceView*, QGraphicsRectItem*);

private:
    Board* m_board;
    PieceView* getMovingPiece(const QPoint &pos);
    QGraphicsRectItem* getNextTile(const QPoint &pos);
    PieceView* m_whiteKing;
    PieceView* m_blackKing;
    PieceView* m_movingpiece = nullptr;
    QGraphicsRectItem* m_nexttile = nullptr;
};

#endif // BOARDVIEW_H
