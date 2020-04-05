#pragma once
#include "pawn.h"
#include "rook.h"
#include "king.h"
#include "queen.h"
#include "knight.h"
#include "bishop.h"

#include <QObject>
#include<QPoint>

class Board : public QObject {
    Q_OBJECT
public:
    bool Validmove(QPoint current, QPoint next, QColor playercolor);
    void move(QPoint current, QPoint next, bool realMove = false);

    void changePawn(QString type, Pawn *);
    Pawn* checkPromotions();

    void placePieces();
	~Board();

signals:
    void moved(QPoint, QPoint);
    void placedPiece(Piece*);

private:
	static const int SIZE_BOARD = 8;

	Piece *m_board[SIZE_BOARD][SIZE_BOARD];
    Piece *getPiece(const QPoint &p) const;
	Piece *FindKing(QColor color);
    bool SafePos(const Piece *movingpiece, const QPoint &next);
    bool noBlockers(const QPoint &current,const QPoint &next) const;
};
