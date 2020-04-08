#include "tileview.h"

TileView::TileView(QColor color) {
    setBrush(color);

    setRect(0, 0, 100, 100);
}

void TileView::mousePressEvent(QGraphicsSceneMouseEvent *event) {
    event->ignore();
}
