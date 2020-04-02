#ifndef BUTTON_H
#define BUTTON_H

#include <QPen>
#include <QFont>
#include <QBrush>
#include <QString>
#include <QObject>
#include <QGraphicsRectItem>
#include <QGraphicsTextItem>
#include <QGraphicsSceneMouseEvent>

class Button : public QObject, public QGraphicsRectItem  {
     Q_OBJECT
public:
    Button(QString title, QGraphicsItem* parent = nullptr);
    void mousePressEvent(QGraphicsSceneMouseEvent *event);

signals:
    void clicked();
};

#endif // BUTTON_H
