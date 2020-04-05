#include "pieceview.h"

PieceView::PieceView(QColor color, QString path) : m_color{color} {

    QPixmap piece(path);
    setPixmap(piece);

    m_selectEffect = new QGraphicsDropShadowEffect;
    m_selectEffect->setOffset(QPoint(0,0));
    m_selectEffect->setBlurRadius(50);
    m_selectEffect->setColor(QColor{100, 150, 255});
    m_selectEffect->setEnabled(false);
    this->setGraphicsEffect(m_selectEffect);

}

PieceView::~PieceView() {
    delete m_selectEffect;
}

QColor PieceView::color() const {
    return m_color;
}

void PieceView::select() {
    m_selectEffect->setEnabled(true);
}

void PieceView::deselect() {
    m_selectEffect->setEnabled(false);
}

void PieceView::setCheckEffect(bool toggle) {
    auto parent = static_cast<QGraphicsRectItem*>(parentItem());
    if (parent->brush().color() != Qt::darkRed)
        kingTileColor = parent->brush().color();

    if (toggle) {
        parent->setBrush(Qt::darkRed);
    }
    else {
        parent->setBrush(kingTileColor);
    }
}

void PieceView::mousePressEvent(QGraphicsSceneMouseEvent *event) {
    event->ignore();
}
