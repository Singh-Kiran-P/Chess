#include "gamewindow.h"

GameWindow::GameWindow(QWidget *parent) : QMainWindow(parent) {

    scene = new QGraphicsScene{};
    view = new QGraphicsView{scene};

    scene->installEventFilter(this);
    view->setSceneRect(0, 0, 800, 800);
    setFixedSize(800, 900);
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
    QMessageBox LoadGame{};
    LoadGame.setIcon(QMessageBox::Warning);
    LoadGame.setText("Loading games has not been implemented yet");
    LoadGame.addButton(QMessageBox::Ok);
    LoadGame.exec();
}

void GameWindow::newgame() {
    scene->clear();

    int xButtonPos;
    Button* PlayerButton = new Button("Player vs. Player");
    xButtonPos = view->sceneRect().width()/2 - PlayerButton->boundingRect().width()/2;
    PlayerButton->setPos(xButtonPos, 250);

    QSignalMapper *PlayerMap = new QSignalMapper;
    connect(PlayerMap, SIGNAL(mapped(int)), this, SLOT(gamestart(int)));
    connect(PlayerButton, SIGNAL(clicked()), PlayerMap, SLOT(map()));
    PlayerMap->setMapping(PlayerButton, 0);

    scene->addItem(PlayerButton);


    Button* AIButton = new Button("Player vs. AI");
    xButtonPos = view->sceneRect().width()/2 - PlayerButton->boundingRect().width()/2;
    AIButton->setPos(xButtonPos, 400);

    QSignalMapper *AIMap = new QSignalMapper;
    connect(AIMap, SIGNAL(mapped(int)), this, SLOT(gamestart(int)));
    connect(AIButton, SIGNAL(clicked()), AIMap, SLOT(map()));
    AIMap->setMapping(AIButton, 1);

    scene->addItem(AIButton);
}

void GameWindow::gamestart(int vsAI) {
    QString player1;
    while (player1.isEmpty())
        player1 = QInputDialog::getText(nullptr, "Input player name", "Player 1");

    QString player2;
    if (vsAI == 0) {
        while (player2.isEmpty())
            player2 = QInputDialog::getText(nullptr, "Input player name", "Player 2");
    }
    else
        player2 = "AI";

    game = new Game{player1, player2, vsAI};
    connect(game, SIGNAL(gameOver()), this, SLOT(gameOver()));

    scene->clear();
    BoardScene* board = new BoardScene{game};
    connect(board, SIGNAL(doMove(PieceView*, QGraphicsItem*)), this, SLOT(move(PieceView*, QGraphicsItem*)));
    scene = board;
    view->setScene(scene);

    auto blackPlayer = new QGraphicsTextItem(game->blackPlayer());
    blackPlayer->setFont(QFont("Arial", 20, QFont::Bold));
    blackPlayer->setDefaultTextColor(Qt::black);
    blackPlayer->setPos(0, -blackPlayer->boundingRect().height());
    scene->addItem(blackPlayer);

    auto whitePlayer = new QGraphicsTextItem(game->whitePlayer());
    whitePlayer->setFont(QFont("Arial", 20, QFont::Bold));
    whitePlayer->setDefaultTextColor(Qt::black);
    whitePlayer->setPos(scene->width() - whitePlayer->boundingRect().width(), scene->height() - whitePlayer->boundingRect().height());
    scene->addItem(whitePlayer);

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
    QMessageBox GameOver{};
    GameOver.setWindowTitle("Checkmate");
    GameOver.setText(game->currentPlayer()->name() + " has won!");
    GameOver.exec();
    scene->clear();
    QApplication::quit();
}

