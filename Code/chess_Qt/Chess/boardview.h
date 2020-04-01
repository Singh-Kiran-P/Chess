#ifndef BOARDVIEW_H
#define BOARDVIEW_H

#include "tileview.h"
#include "pieceview.h"

#include <QGraphicsView>
#include <QGraphicsSceneMouseEvent>
#include <QGraphicsScene>


class BoardView : public QGraphicsView {
public:
    BoardView(QGraphicsScene* scene);
private:
    QGraphicsScene* scene;

};

#endif // BOARDVIEW_H
