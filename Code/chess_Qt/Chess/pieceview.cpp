#include "pieceview.h"

PieceView::PieceView(QColor color, QString path) : m_color{color} {

    QPixmap pawn(path);
    setPixmap(pawn);
    setFlag(QGraphicsItem::ItemIsSelectable);
}

void PieceView::mousePressEvent(QGraphicsSceneMouseEvent *mouseEvent) {
        if(mouseEvent->modifiers() & Qt::ControlModifier)
            mouseEvent->ignore();
}
