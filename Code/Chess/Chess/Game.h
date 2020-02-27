#ifndef GAME
#define GAME
#include <ctime>
#include "player.h"
#include "board.h"
class Game
{
public:
	void initGame();

private:
	time_t m_time;
	Board m_board;
	Player m_player1;
	Player m_player2;
	Player m_turn;

};
#endif // !GAME
