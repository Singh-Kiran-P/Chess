#ifndef BOARD
#define BOARD
#define BOARD_SIZE 8
#include "pawn.h"
class Board {
    public:
        Pawn getPiece(Position position);
        void move(Position currentpos, Position moveTo);
        void printBoard();
        void resetBoard();
<<<<<<< HEAD

=======
        Board();
    
>>>>>>> e65d8478c8dfd27ce2b4f72a84dcf5fe1eaf09c3
    private:
        Pawn m_board[BOARD_SIZE][BOARD_SIZE];
};

#endif
