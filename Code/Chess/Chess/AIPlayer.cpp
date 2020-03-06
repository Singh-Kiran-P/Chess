#include "AIPlayer.h"

Position AIPlayer::moveFrom(Board &board, Color playerColor) {
    int curr_x{};
    int curr_y{};
    Position currPos{};
    bool invalid_piece = true;

    do {
        curr_x = rand() % 8;
        curr_y = rand() % 8;
        currPos.setpos(curr_x, curr_y);

        if (board.getPiece(currPos) != nullptr) {
            if (board.getPiece(currPos)->getColor() == playerColor)
                invalid_piece = false;
        }

    } while (invalid_piece);

    return currPos;
};

Position AIPlayer::moveTo(Position currPos, Board &board, Color playerColor) {
    int next_x{};
	int next_y{};
	Position nextPos{};
    int attemps{ 0 };

	do {
        attemps++;
		next_x = rand() % 8;
		next_y = rand() % 8;
		nextPos.setpos(next_x, next_y);

	} while (!(board.getPiece(currPos))->moveRestrictions((board.getPiece(nextPos)), nextPos, playerColor) && attemps < m_attemptCount);
    return nextPos;
};

AIPlayer::AIPlayer(string nameStr, Color color) : Player(nameStr, color) {};
