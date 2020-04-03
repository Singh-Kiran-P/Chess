#pragma once
#include <ctime>
#include "humanplayer.h"
#include "AIplayer.h"

#include <QObject>

class Game : public QObject
{ Q_OBJECT
public:
    Game(QString, QString, bool);
	~Game();

	void nextturn();
    Player* currentPlayer();

	void run();
    void move(const QPoint &currPos = QPoint{0, 0}, const QPoint &nextPos = QPoint{0, 0});

    void setBoard(Board* board);

signals:
    void gameOver();

private:
    Board* m_board;
    Player *m_player1;
    Player *m_player2;
	Player *m_turn;
//	Moves m_moves;
};
