#pragma once
#include <QString>
#include <QList>
#include <tuple>
#include <QColor>
#include "board.h"

using namespace std;

class Player
{
public:
    QColor color() const;
    QString name() const;

    virtual tuple<QPoint, QPoint> getMove() = 0;
    void GenerateMoves();
    int numOfMoves() { return m_Possiblemoves.size(); }

    Player(QString nameStr, QColor color, Board *board);

private:
    QString m_playername;

protected:
    QColor m_color;
    Board *m_board;
    QList<tuple<QPoint, QPoint>> m_Possiblemoves;
};
