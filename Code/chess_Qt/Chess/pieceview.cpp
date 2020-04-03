#include "pieceview.h"

PieceView::PieceView(QColor color, QString path) : m_color{color} {

    QPixmap pawn(path);
    setPixmap(pawn);
}

void PieceView::select() {
    QPen pen(Qt::red);
    QBrush brush(Qt::NoBrush);
    pen.setWidth(3);

    m_selection = new QGraphicsRectItem(0, 0, 100, 100);
    m_selection->setParentItem(this);
}

void PieceView::deselect() {
}

QColor PieceView::color() const {
    return m_color;
}

void PieceView::mousePressEvent(QGraphicsSceneMouseEvent *event) {

    event->ignore();
}
