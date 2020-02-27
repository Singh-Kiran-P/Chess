#ifndef PAWN
#define PAWN
#include "piece.h"
#include "position.h"
class Pawn : public Piece {
public:
	bool check_move(Position moveTo);	
};


#endif // !PAWN
