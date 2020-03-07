#pragma once
#include "piece.h"

class Pawn : public Piece {
	public:

		int turnCount() const;
		void increaseTurnCount();

		bool moveRestrictions(Piece* nextpiece, Position nextPos, const Color &playerColor);

		Pawn(char id, Color color, Position Pos);
	private:
		int m_turnCount = 0;
};
