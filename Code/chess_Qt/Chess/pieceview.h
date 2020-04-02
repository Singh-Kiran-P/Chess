#ifndef PIECEVIEW_H
#define PIECEVIEW_H

#include <QGraphicsPixmapItem>
#include <QGraphicsSceneMouseEvent>
#include <QString>

class PieceView : public QGraphicsPixmapItem {
public:
    PieceView(QColor color, QString path);
protected:
    void mousePressEvent(QGraphicsSceneMouseEvent *mouseEvent);
private:
    QColor m_color;
};

#endif // PIECEVIEW_H
