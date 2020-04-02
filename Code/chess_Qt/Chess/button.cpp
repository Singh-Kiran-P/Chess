#include "button.h"

Button::Button(QString title, QGraphicsItem* parent) : QGraphicsRectItem(parent) {
    //draw the rect
    setRect(0,0,250,70);
    QBrush brush;
    brush.setStyle(Qt::SolidPattern);
    brush.setColor(Qt::darkGray);
    setBrush(brush);

    //draw Text
    auto text = new QGraphicsTextItem(title,this);
    text->setFont(QFont("Arial", 20, QFont::Bold));
    text->setDefaultTextColor(Qt::white);
    int xPos = rect().width()/2 - text->boundingRect().width()/2;
    int yPos = rect().height()/2 - text->boundingRect().height()/2;
    text->setPos(xPos,yPos);
}

void Button::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    if((event->type() == QEvent::GraphicsSceneMousePress))
        emit clicked();
}
