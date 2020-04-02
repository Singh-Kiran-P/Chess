#pragma once
#include <iostream>
#include <string>
#include <stdlib.h>
#include <stdio.h>
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

//	void printBoard() const;
    Piece *getPiece(QPoint p);

//	void changePawn(Pawn *);

	Board();
	~Board();

signals:
    void moved(QPoint current, QPoint next);
    void placedpiece(Piece* piece);

private:
	static const int SIZE_BOARD = 8;

	Piece *m_board[SIZE_BOARD][SIZE_BOARD];
    void changePawn(Pawn *);
	Piece *FindKing(QColor color);
    bool SafePos(Piece *movingpiece, QPoint next);
    bool noBlockers(QPoint current, QPoint next) const;
};
