#include "pieceview.h"
#include <QDebug>
PieceView::PieceView(QString path,Piece* piece) {

    QPixmap pawn(path);
    setPixmap(pawn);
    setFlag(QGraphicsItem::ItemIsSelectable);
    m_Piece = piece;
}

void PieceView::mousePressEvent(QGraphicsSceneMouseEvent *mouseEvent) {
        if(mouseEvent->modifiers() & Qt::ControlModifier)
            mouseEvent->ignore();
         qDebug() <<"x="<< m_Piece->getPos().getx()<<"y="<<m_Piece->getPos().gety()<<endl;

}
