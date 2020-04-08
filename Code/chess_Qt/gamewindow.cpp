#include "gamewindow.h"

GameWindow::GameWindow(QWidget *parent) : QMainWindow(parent) {

    mainMenu();
}

void GameWindow::buildMenuBar() {
    QAction* menuSave = new QAction("save");
    menuBar()->addAction(menuSave);
    connect(menuSave, SIGNAL(triggered()), this, SLOT(savegame()));

    QAction* menuLoad = new QAction("load");
    menuBar()->addAction(menuLoad);
    connect(menuLoad, SIGNAL(triggered()), this, SLOT(loadgame()));

    QAction* menuQuit = new QAction("quit");
    menuBar()->addAction(menuQuit);
    connect(menuQuit, SIGNAL(triggered()), this, SLOT(quitgame()));
}

void GameWindow::mainMenuButtons() {
    int xButtonPos;
    Button* newGameButton = new Button("New game");
    xButtonPos = view->sceneRect().width()/2 - newGameButton->boundingRect().width()/2;
    newGameButton->setPos(xButtonPos, 250);
    connect(newGameButton, SIGNAL(pressed()), this, SLOT(newgame()));
    scene->addItem(newGameButton);

    Button* LoadGamebutton = new Button("Load game");
    xButtonPos = view->sceneRect().width()/2 - LoadGamebutton->boundingRect().width()/2;
    LoadGamebutton->setPos(xButtonPos, 350);
    connect(LoadGamebutton, SIGNAL(pressed()), this, SLOT(loadgame()));
    scene->addItem(LoadGamebutton);

    Button* quitButton = new Button("Quit");
    connect(quitButton, SIGNAL(pressed()), this, SLOT(quitgame()));
    xButtonPos = view->sceneRect().width()/2 - quitButton->boundingRect().width()/2;
    quitButton->setPos(xButtonPos, 450);
    scene->addItem(quitButton);
}

void GameWindow::mainMenu() {
    game = nullptr;
    scene = new QGraphicsScene{};
    view = new QGraphicsView{scene};

    view->setSceneRect(0, 0, 800, 800);
    setFixedSize(800, 900);
    view->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    view->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setCentralWidget(view);
    view->show();

    mainMenuButtons();
}

void GameWindow::loadgame() {
    QMessageBox LoadGame{};
    LoadGame.setIcon(QMessageBox::Warning);
    LoadGame.setText("Loading games has not been implemented yet.");
    LoadGame.addButton(QMessageBox::Ok);
    LoadGame.exec();
}

void GameWindow::savegame() {
    QMessageBox saveGame{};
    saveGame.setIcon(QMessageBox::Warning);
    if (game == nullptr)
        saveGame.setText("A game has not been started yet.");
    else
        saveGame.setText("Saving games has not been implemented yet.");
    saveGame.addButton(QMessageBox::Ok);
    saveGame.exec();
}

void GameWindow::newgame() {
    scene->clear();
    delete game;
    game = nullptr;

    int xButtonPos;
    Button* PlayerButton = new Button("Player vs. Player");
    xButtonPos = view->sceneRect().width()/2 - PlayerButton->boundingRect().width()/2;
    PlayerButton->setPos(xButtonPos, 250);
    scene->addItem(PlayerButton);
    connect(PlayerButton, &Button::pressed, [=] { gamestart(false); });

    Button* AIButton = new Button("Player vs. AI");
    xButtonPos = view->sceneRect().width()/2 - PlayerButton->boundingRect().width()/2;
    AIButton->setPos(xButtonPos, 350);
    scene->addItem(AIButton);
    connect(AIButton, &Button::pressed, [=] { gamestart(true); });

    Button* backButton = new Button("Back");
    connect(backButton, SIGNAL(pressed()), this, SLOT(backButton()));
    xButtonPos = view->sceneRect().width()/2 - PlayerButton->boundingRect().width()/2;
    backButton->setPos(xButtonPos, 450);
    scene->addItem(backButton);
}

void GameWindow::gamestart(bool vsAI) {
    QString player1;
    player1 = QInputDialog::getText(nullptr, "Input player name", "Player 1's name", QLineEdit::Normal, "", nullptr, Qt::MSWindowsFixedSizeDialogHint | Qt::WindowSystemMenuHint | Qt::WindowTitleHint);
    if (player1 == "") {
        return;
    }
    QString player2;
    if (vsAI == 0) {
        player2 = QInputDialog::getText(nullptr, "Input player name", "Player 2's name",  QLineEdit::Normal, "", nullptr, Qt::MSWindowsFixedSizeDialogHint | Qt::WindowSystemMenuHint | Qt::WindowTitleHint);
        if (player2 == "") {
            return;
        }
    }
    else
        player2 = "AI";

    gameStarted = true;
    game = new Game{player1, player2, vsAI};
    connect(game, SIGNAL(gameOver()), this, SLOT(gameOver()));
    connect(game, SIGNAL(promote(Pawn*)), this, SLOT(getPromotionPiece(Pawn*)));

    BoardScene* board = new BoardScene{game};
    connect(board, SIGNAL(doMove(PieceView*, QGraphicsRectItem*)), this, SLOT(move(PieceView*, QGraphicsRectItem*)));
    scene = board;
    view->setScene(scene);

    if (auto AI = dynamic_cast<AIPlayer*>(game->currentPlayer()))
        game->move();
}

void GameWindow::move(PieceView* movingpiece, QGraphicsRectItem* nextpiece) {
    if (game->currentPlayer()->color() == movingpiece->color()) {
        QPoint currPos = movingpiece->scenePos().toPoint() / 100;
        QPoint nextPos = nextpiece->scenePos().toPoint() / 100;
        game->move(currPos, nextPos);
        }
    if (gameStarted) {
        auto boardScene = static_cast<BoardScene*>(scene);
        boardScene->clearSelection();
    }
}

void GameWindow::getPromotionPiece(Pawn* pawn) {
    QString selection = "Queen";
    if (auto humanplayer = dynamic_cast<HumanPlayer*>(game->currentPlayer())) {
        QMessageBox ChoosePromotion{QMessageBox::NoIcon, "Promotion", "Pick a piece to promote your pawn to:"};
        ChoosePromotion.addButton("Queen", QMessageBox::AcceptRole);
        ChoosePromotion.addButton("Rook", QMessageBox::AcceptRole);
        ChoosePromotion.addButton("Knight", QMessageBox::AcceptRole);
        ChoosePromotion.addButton("Bishop", QMessageBox::AcceptRole);
        ChoosePromotion.show();
        ChoosePromotion.exec();
        selection = ChoosePromotion.clickedButton()->text();
    }

    auto boardScene = static_cast<BoardScene*>(scene);
    boardScene->promotePixMap(selection, pawn);
}

void GameWindow::gameOver() {
    gameStarted = false;
    QMessageBox GameOver;
    GameOver.setWindowTitle("Checkmate");
    GameOver.setText(game->currentPlayer()->name() + " has won!");
    GameOver.setMinimumSize(250, 100);
    GameOver.exec();
    mainMenu();
}

void GameWindow::backButton() {
    scene->clear();
    mainMenuButtons();
}

void GameWindow::quitgame() {
    QApplication::quit();
}

