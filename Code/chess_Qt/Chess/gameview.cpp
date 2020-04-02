#include "gameview.h"

GameView::GameView(QWidget *parent) : QMainWindow(parent) {

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

//    m_board = new BoardView(scene);

}

void GameView::loadgame() {
    qDebug() << "Loading games has not been implemented";
}

void GameView::newgame() {
    for (auto item : scene->items())
        scene->removeItem(item);

    int xButtonPos;
    Button* PlayerButton = new Button("Player vs. Player");
    xButtonPos = view->sceneRect().width()/2 - PlayerButton->boundingRect().width()/2;
    PlayerButton->setPos(xButtonPos, 250);
    connect(PlayerButton, SIGNAL(clicked()), this, SLOT(gamestart()));
    scene->addItem(PlayerButton);

    Button* AIButton = new Button("Player vs. AI");
    xButtonPos = view->sceneRect().width()/2 - PlayerButton->boundingRect().width()/2;
    AIButton->setPos(xButtonPos, 400);
    connect(AIButton, SIGNAL(clicked()), this, SLOT(gamestartAI()));
    scene->addItem(AIButton);

}

void GameView::gamestartAI() {

}

void GameView::gamestart() {
    for (auto item : scene->items())
        scene->removeItem(item);

    m_board = new BoardView(scene);
}
