#ifndef PIECEVIEW_H
#define PIECEVIEW_H

#include <QGraphicsPixmapItem>
#include <QGraphicsSceneMouseEvent>
#include <QString>
#include <piece.h>
class PieceView : public QGraphicsPixmapItem
{
public:
    PieceView(QString path, Piece *piece);

protected:
    Piece *m_Piece;
    void mousePressEvent(QGraphicsSceneMouseEvent *mouseEvent);
};

#endif // PIECEVIEW_H
