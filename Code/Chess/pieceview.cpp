#include "pieceview.h"

PieceView::PieceView(QColor color, QString path) : m_color{color} {

    QPixmap piece(path);
    setPixmap(piece);

    auto selectEffect = new QGraphicsDropShadowEffect;
    selectEffect->setOffset(QPoint(0,0));
    selectEffect->setBlurRadius(50);
    selectEffect->setColor(QColor{100, 150, 255});
    selectEffect->setEnabled(false);
    this->setGraphicsEffect(selectEffect);

}

PieceView::~PieceView() {
    delete graphicsEffect();
}

QColor PieceView::color() const {
    return m_color;
}

void PieceView::select() {
    graphicsEffect()->setEnabled(true);
}

void PieceView::deselect() {
    graphicsEffect()->setEnabled(false);
}

void PieceView::mousePressEvent(QGraphicsSceneMouseEvent *event) {
    event->ignore();
}
