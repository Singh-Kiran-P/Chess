#include "pieceview.h"

PieceView::PieceView(QString path) {

    QPixmap pawn(path);
    setPixmap(pawn);
    setFlag(QGraphicsItem::ItemIsSelectable);
}

void PieceView::mousePressEvent(QGraphicsSceneMouseEvent *mouseEvent) {
        if(mouseEvent->modifiers() & Qt::ControlModifier)
            mouseEvent->ignore();
}
