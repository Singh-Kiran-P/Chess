#pragma once
#include "humanplayer.h"
#include "AIplayer.h"

#include <QObject>

class Game : public QObject
{ Q_OBJECT
public:
    Game(const QString&, const QString&, bool);
	~Game();

	void nextturn();
    Player* currentPlayer();
    QString whitePlayer() const {return m_whiteplayer->name();};
    QString blackPlayer() const {return m_blackplayer->name();};

    void move(const QPoint &currPos = QPoint{0, 0}, const QPoint &nextPos = QPoint{0, 0});

    void setBoard(Board* board);

signals:
    void gameOver();
    void promote(Pawn*);
    void checkedKing(QColor);

private:
    Board* m_board;
    Player *m_whiteplayer;
    Player *m_blackplayer;
	Player *m_turn;
};
