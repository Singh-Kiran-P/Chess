#ifndef PIECEVIEW_H
#define PIECEVIEW_H

#include <QGraphicsPixmapItem>
#include <QGraphicsSceneMouseEvent>
#include <QString>

class PieceView : public QGraphicsPixmapItem {
public:
    PieceView(QString path);
protected:
    void mousePressEvent(QGraphicsSceneMouseEvent *mouseEvent);
};

#endif // PIECEVIEW_H
