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

    void setBoard(Board* board);
    void GenerateMoves();
    bool possibleMove(const tuple<QPoint, QPoint> &move);
    int numOfMoves() { return m_Possiblemoves.size(); }

    virtual void doMove(const QPoint &currPos, const QPoint &nextPos) = 0;

    Player(QString nameStr, QColor color, Board *board);

private:
    QString m_playername;

protected:
    QColor m_color;
    Board *m_board;
    QList<tuple<QPoint, QPoint>> m_Possiblemoves;
};
