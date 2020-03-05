#ifndef PAWN
#define PAWN
#include "color.h"
#include "position.h"
#include "piece.h"

class Pawn : public Piece {
	public:

		int turnCount() const;
		void increaseTurnCount();

		bool moveRestrictions(int curr_x, int curr_y, int next_x, int next_y, Piece* movingpiece, Piece* nextpiece);

	private:
		int m_turnCount = 0;
};

#endif
