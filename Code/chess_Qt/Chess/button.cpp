#include "button.h"

Button::Button(QString title, QGraphicsItem* parent) : QGraphicsRectItem(parent) {
    setRect(0,0,250,70);
    QBrush brush(Qt::darkGray);
    QPen pen;
    pen.setWidth(5);
    brush.setStyle(Qt::SolidPattern);
    setPen(pen);
    setBrush(brush);

    auto text = new QGraphicsTextItem(title,this);
    text->setFont(QFont("Arial", 20, QFont::Bold));
    text->setDefaultTextColor(Qt::white);
    int xPos = rect().width()/2 - text->boundingRect().width()/2;
    int yPos = rect().height()/2 - text->boundingRect().height()/2;
    text->setPos(xPos,yPos);

    setFlag(QGraphicsItem::ItemIsMovable);
}

void Button::mousePressEvent(QGraphicsSceneMouseEvent* event)
{
    if((event->button() == Qt::LeftButton))
        emit pressed();
}
