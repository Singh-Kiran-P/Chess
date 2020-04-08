#pragma once
#include <QColor>
#include <iostream>

class Piece
{
public:
	QColor getColor() const;
    QPoint getPos() const;
    void setPos(const QPoint &p);

	char getId();
    virtual bool moveRestrictions(const Piece *nextpiece, const QPoint &nextPos) = 0;

    Piece(char id, QColor color, QPoint Pos);

protected:
    QPoint m_position;
	QColor m_color;

private:
	char m_id;
};
