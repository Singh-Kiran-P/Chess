#include "tileview.h"
#include <QtDebug>
TileView::TileView(QColor color, Position postion)
{
    setBrush(color);
    setRect(0, 0, 100, 100);

    m_position = postion;
}

void TileView::mousePressEvent(QGraphicsSceneMouseEvent *mouseEvent) {
        if(mouseEvent->button() == Qt::LeftButton)
            qDebug() <<"x="<< m_position.getx()<<"y="<<m_position.gety()<<endl;

}

