#pragma once
#include <vector>
#include "move.h"

class Moves {
	public:
		void addMove(char id,Color color,Position curr,Position next);
		void print();

	private:
		vector<Move> m_moves;
};
