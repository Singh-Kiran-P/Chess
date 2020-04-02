#pragma once
#include <QColor>
#include <iostream>

class Piece
{
public:
	QColor getColor() const;
    QPoint getPos();
    void setPos(QPoint p);

	char getId();
    virtual bool moveRestrictions(Piece *nextpiece, QPoint nextPos) = 0;

    Piece(char id, QColor color, QPoint Pos);

protected:
    QPoint m_position;
	QColor m_color;

private:
	char m_id;
};
