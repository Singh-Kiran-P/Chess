#pragma once
#include "piece.h"

class Pawn : public Piece {
	public:

		int turnCount() const;
		void increaseTurnCount();

		bool moveRestrictions(Piece* movingpiece, Piece* nextpiece, int next_x, int next_y);

	private:
		int m_turnCount = 0;
};
