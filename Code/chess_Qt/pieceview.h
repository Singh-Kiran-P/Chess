#ifndef PIECEVIEW_H
#define PIECEVIEW_H

#include <QPen>
#include <QBrush>
#include <QGraphicsPixmapItem>
#include <QGraphicsRectItem>
#include <QGraphicsSceneMouseEvent>
#include <QGraphicsDropShadowEffect>
#include <QGraphicsColorizeEffect>

class PieceView : public QGraphicsPixmapItem {
public:
    PieceView(QColor color, QString path);
    ~PieceView();
    QColor color() const;
    void select();
    void deselect();
    void setCheckEffect(bool);
    void mousePressEvent(QGraphicsSceneMouseEvent *event);
private:
    QColor m_color;
    QGraphicsDropShadowEffect* m_selectEffect;
    QColor kingTileColor;
};

#endif // PIECEVIEW_H
