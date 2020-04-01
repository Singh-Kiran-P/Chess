#ifndef TILEVIEW_H
#define TILEVIEW_H

#include <QGraphicsView>
#include <QGraphicsRectItem>

class TileView : public QGraphicsRectItem {
public:
    TileView(QColor color);
};

#endif // TILEVIEW_H
