#ifndef BOARDVIEW_H
#define BOARDVIEW_H

#include "tileview.h"
#include "pieceview.h"
#include "board.h"

#include <QDebug>
#include <QGraphicsView>
#include <QMouseEvent>
#include <QGraphicsItem>
#include <QGraphicsScene>

class BoardView : public QGraphicsView
{
public:
    BoardView(QGraphicsScene *scene);

public slots:
    void movepiece(QPoint current, QPoint next);

private:
    QGraphicsScene *scene;
    Board* m_board;
    QGraphicsItem* m_movingpiece = nullptr;
    QGraphicsItem* m_nextpiece = nullptr;
};

#endif // BOARDVIEW_H
