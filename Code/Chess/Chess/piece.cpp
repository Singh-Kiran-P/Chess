#include "piece.h"

//char Piece::getId() const {
//	return m_id;
//};
//
//void Piece::setId(char id) {
//	m_id = id;
//};

void Piece::setColor(Color color) {
	m_color = color;
};

Color Piece::getColor() const {
	return m_color;
};

Position Piece::getPos() {
	return m_position;
};

void Piece::setPos(Position p) {
	m_position = p;
};
