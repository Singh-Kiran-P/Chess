#include "gamewindow.h"

GameWindow::GameWindow(QWidget *parent) : QMainWindow(parent) {

    scene = new QGraphicsScene{};
    view = new QGraphicsView{scene};

    scene->installEventFilter(this);
    view->setSceneRect(0, 0, 800, 800);
    setFixedSize(850,850);
    view->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    view->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setCentralWidget(view);
    view->show();

    int xButtonPos;
    Button* newGameButton = new Button("New game");
    xButtonPos = view->sceneRect().width()/2 - newGameButton->boundingRect().width()/2;
    newGameButton->setPos(xButtonPos, 250);
    connect(newGameButton, SIGNAL(clicked()), this, SLOT(newgame()));
    scene->addItem(newGameButton);

    Button* LoadGamebutton = new Button("Load game");
    xButtonPos = view->sceneRect().width()/2 - LoadGamebutton->boundingRect().width()/2;
    LoadGamebutton->setPos(xButtonPos, 400);
    connect(LoadGamebutton, SIGNAL(clicked()), this, SLOT(loadgame()));
    scene->addItem(LoadGamebutton);

}

void GameWindow::loadgame() {
    qDebug() << "Loading games has not been implemented";
}

void GameWindow::newgame() {
    scene->clear();

    int xButtonPos;
    Button* PlayerButton = new Button("Player vs. Player");
    xButtonPos = view->sceneRect().width()/2 - PlayerButton->boundingRect().width()/2;
    PlayerButton->setPos(xButtonPos, 250);
    connect(PlayerButton, SIGNAL(clicked()), this, SLOT(gamestart()));
    scene->addItem(PlayerButton);

    Button* AIButton = new Button("Player vs. AI");
    xButtonPos = view->sceneRect().width()/2 - PlayerButton->boundingRect().width()/2;
    AIButton->setPos(xButtonPos, 400);
    connect(AIButton, SIGNAL(clicked()), this, SLOT(gamestart()));
    scene->addItem(AIButton);
}

void GameWindow::gamestart() {
    game = new Game{"P1", "P2", true}; // toggle betwween pvp and AI
    connect(game, SIGNAL(gameOver()), this, SLOT(gameOver()));

    scene->clear();
    BoardScene* board = new BoardScene{game};
    connect(board, SIGNAL(doMove(PieceView*, QGraphicsItem*)), this, SLOT(move(PieceView*, QGraphicsItem*)));
    scene = board;
    view->setScene(scene);

    if (auto AI = dynamic_cast<AIPlayer*>(game->currentPlayer()))
        game->move();
}

void GameWindow::move(PieceView* movingpiece, QGraphicsItem* nextpiece) {
    if (game->currentPlayer()->color() == movingpiece->color()) {
        QPoint currPos = movingpiece->scenePos().toPoint() / 100;
        QPoint nextPos = nextpiece->scenePos().toPoint() / 100;
        game->move(currPos, nextPos);
    }
}

void GameWindow::gameOver() {
    QMessageBox GameOver;
    GameOver.setText(game->currentPlayer()->name() + " has won!");
    GameOver.exec();
    scene->clear();
    QApplication::quit();
}

