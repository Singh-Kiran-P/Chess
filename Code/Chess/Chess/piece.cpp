#include "piece.h"

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

char Piece::Id() {
	return m_id;
};

Piece::Piece(char id, Color color, Position Pos) : m_id{ id }, m_color{ color }, m_position{ Pos } {};
