#ifndef TILEVIEW_H
#define TILEVIEW_H

#include <QGraphicsView>
#include <QGraphicsRectItem>
#include <position.h>
#include <QGraphicsSceneMouseEvent>
class TileView : public QGraphicsRectItem {
public:
    TileView(QColor color,Position postion);
    Position getPostion();
    void mousePressEvent(QGraphicsSceneMouseEvent *mouseEvent) ;

private:
    Position m_position;


};

#endif // TILEVIEW_H
