#include "board.h"

Position Board::getPiece(Position position) {
    int x = position.getx();
    int y = position.gety();

    return m_board[x][y];
}

void Board::move(Position currentpos, Position moveTo) {
    Pawn piece = getPiece(currentpos);
    if (getName(piece) != "." ) {
        m_board[moveTo.getx()][moveTo.gety()] = piece;
        Pawn emptypawn;
        m_board[currentpos.getx()][currentpos.gety()] = emptypawn;
    }
}

void Board::printBoard()
{
}

//rest and init board
void Board::resetBoard()
{

}
