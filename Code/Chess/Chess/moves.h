#pragma once
#include <vector>
#include "position.h"
#include "color.h"
#include "board.h"
class Moves {
public:
	Moves() {};
	Moves(char id, Color color, Position currPos, Position nextPos);
	char getId() const;
	string getColor() const;
	Position getCurrPos() const;
	Position getNextPos() const;
	void addMove(char id,Color color,Position curr,Position next);
	void print() const;
private:
	char m_PieseId;
	Color m_color;
	Position m_currPos;
	Position m_nextPos;
	vector<Moves> m_moves;


};