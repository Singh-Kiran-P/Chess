#include "moves.h"

void Moves::addMove(char id, Color color, Position curr, Position next) {
	Move m(id, color, curr, next);
	m_moves.push_back(m);
};

void Moves::print() {
	for (int i = 0; i < m_moves.size(); i++) {
		std::cout << i << ")\t";
		(m_moves.at(i)).print();
	}
};
