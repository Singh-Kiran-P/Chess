#include "pieceview.h"

PieceView::PieceView(QColor color, QString path) : m_color{color} {

    QPixmap piece(path);
    setPixmap(piece);
}

QColor PieceView::color() const {
    return m_color;
}

void PieceView::mousePressEvent(QGraphicsSceneMouseEvent *event) {

    event->ignore();
}
