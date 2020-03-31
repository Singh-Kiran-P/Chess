#pragma once
#include <string>
#include <Qvector>
#include <tuple>
#include "position.h"
#include "color.h"
#include "board.h"

using namespace std;

class Player {
    public:
        Color color() const;
        std::string name() const;

        virtual tuple<Position, Position> getMove() = 0;
        void GenerateMoves();
        int numOfMoves() { return m_Possiblemoves.size(); }

        Player(string nameStr, Color color, Board* board);

    private:
        string m_playername;

    protected:
        Color m_color;
        Board* m_board;
        QVector<tuple<Position, Position>> m_Possiblemoves;

};
