#ifndef PIECEVIEW_H
#define PIECEVIEW_H

#include <QPen>
#include <QBrush>
#include <QGraphicsPixmapItem>
#include <QGraphicsRectItem>
#include <QGraphicsSceneMouseEvent>
#include <QString>

class PieceView : public QGraphicsPixmapItem {
public:
    PieceView(QColor color, QString path);
    QColor color() const;
    void mousePressEvent(QGraphicsSceneMouseEvent *event);
private:
    QColor m_color;
};

#endif // PIECEVIEW_H
