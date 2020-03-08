#include "AIPlayer.h"

Position AIPlayer::moveFrom(Color playerColor) {
    int curr_x{};
    int curr_y{};
    Position currPos{};
    bool invalid_piece = true;

    do {
        curr_x = rand() % 8;
        curr_y = rand() % 8;
        currPos.setpos(curr_x, curr_y);

        if (m_board->getPiece(currPos) != nullptr) {
            if (m_board->getPiece(currPos)->getColor() == playerColor)
                invalid_piece = false;
        }

    } while (invalid_piece);

    return currPos;
};

Position AIPlayer::moveTo(Position currPos, Color playerColor) {
    int next_x{};
	int next_y{};
	Position nextPos{};
    int attemps{ 0 };

	do {
        attemps++;
		next_x = rand() % 8;
		next_y = rand() % 8;
		nextPos.setpos(next_x, next_y);

	} while (!(m_board->getPiece(currPos))->moveRestrictions((m_board->getPiece(nextPos)), nextPos) && attemps < m_attemptCount);
    return nextPos;
};

AIPlayer::AIPlayer(string nameStr, Color color, Board& board) : Player(nameStr, color), m_board{&board} {};
