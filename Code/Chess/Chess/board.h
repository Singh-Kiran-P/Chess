IFNDEF BOARD
DEFINE BOARD
DEFINE BOARD_SIZE 8
#include "piece.h"

class Board {
    public:
        void printBoard;
        void resetBoard;
    private:
        Piece m_board[BOARD_SIZE][BOARD_SIZE];
};

ENDIF
