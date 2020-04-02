#ifndef TILEVIEW_H
#define TILEVIEW_H

#include <QDebug>
#include <QGraphicsView>
#include <QGraphicsRectItem>
#include <QGraphicsSceneMouseEvent>

class TileView : public QGraphicsRectItem {
public:
    TileView(QColor color);
    void mousePressEvent(QGraphicsSceneMouseEvent* event);
};

#endif // TILEVIEW_H
