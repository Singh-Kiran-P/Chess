#include "tileview.h"

TileView::TileView(QColor color) {
    setBrush(color);
    setPen(Qt::NoPen);

    setRect(0, 0, 100, 100);
}

void TileView::mousePressEvent(QGraphicsSceneMouseEvent *event) {
    event->ignore();
}
