#pragma once
#include <vector>
#include "move.h"
#include <QColor>

class Moves {
	public:
        void addMove(char id, QColor color, Position curr, Position next);
		void print();

	private:
        std::vector<Move> m_moves;
};
