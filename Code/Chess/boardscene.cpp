#include "boardscene.h"

BoardScene::BoardScene(Game* game) {

    m_board = new Board{};
    connect(m_board, SIGNAL(moved(QPoint, QPoint)), this, SLOT(movedpiece(QPoint, QPoint)));
    connect(m_board, SIGNAL(placedPiece(Piece*)), this, SLOT(placePixMap(Piece*)));
    connect(m_board, SIGNAL(promoted(Piece*)), this, SLOT(promotePixMap(Piece*)));
    game->setBoard(m_board);

    for (int y = 0; y < 8; y++) {
        for (int x = 0; x < 8; x++) {

            TileView* tile;
            if ((x + y) % 2 == 0)
                tile = new TileView{Qt::black};
            else
                tile = new TileView{Qt::white};
            addItem(tile);
            tile->setPos(100*x, 100*y);
        }
    }

    m_board->placePieces();

    auto blackPlayer = new QGraphicsTextItem(game->blackPlayer());
    blackPlayer->setFont(QFont("Arial", 20, QFont::Bold));
    blackPlayer->setDefaultTextColor(Qt::black);
    blackPlayer->setPos(0, -blackPlayer->boundingRect().height());
    addItem(blackPlayer);

    auto whitePlayer = new QGraphicsTextItem(game->whitePlayer());
    whitePlayer->setFont(QFont("Arial", 20, QFont::Bold));
    whitePlayer->setDefaultTextColor(Qt::black);
    whitePlayer->setPos(width() - whitePlayer->boundingRect().width(), height() - whitePlayer->boundingRect().height());
    addItem(whitePlayer);

}

void BoardScene::movedpiece(QPoint curr, QPoint next) {
    QGraphicsItem* parent = itemAt(next, QTransform());
    if (auto i = dynamic_cast<QGraphicsPixmapItem*>(parent)) {
        parent = parent->parentItem();
        removeItem(itemAt(next, QTransform()));
    }
    else {
        for (auto child : parent->childItems())
            removeItem(child);
    }
    for (auto movingpiece : itemAt(curr, QTransform())->childItems())
        movingpiece->setParentItem(parent);
}

void BoardScene::placePixMap(Piece* piece) {
    QString path = ":/images/";
    if (piece->getColor() == Qt::white)
        path += "white/";
    else
        path += "black/";

    switch (piece->getId()) {

    case 'P':
        path += "pawn.png";
        break;
    case 'R':
        path += "rook.png";
        break;
    case 'N':
        path += "knight.png";
        break;
    case 'B':
        path += "bishop.png";
        break;
    case 'Q':
        path += "queen.png";
        break;
    case 'K':
        path += "king.png";
        break;
    }
    QPoint pos = piece->getPos() * 100;
    auto PieceItem = new PieceView(piece->getColor(), path);
    auto tile = itemAt(pos, QTransform());
    PieceItem->setParentItem(tile);
}

void BoardScene::promotePixMap(Piece* piece) {
    QString path = ":/images/";
    if (piece->getColor() == Qt::white)
        path += "white/queen.png";
    else
        path += "black/queen.png";

    auto tile = itemAt(piece->getPos() * 100, QTransform());
    PieceView* pawn = new PieceView(piece->getColor(), path);
    for (auto child : tile->childItems())
        delete child;
    pawn->setParentItem(tile);
}

void BoardScene::mousePressEvent(QGraphicsSceneMouseEvent *event) {
    if (event->button() == Qt::LeftButton) {
        auto item = itemAt(event->scenePos(), QTransform());
        if (m_movingpiece != nullptr && m_movingpiece != item) {
            m_nextpiece = item;
            emit doMove(static_cast<PieceView*>(m_movingpiece), m_nextpiece);
            m_movingpiece = nullptr;
            m_nextpiece = nullptr;
        }
        else if (m_movingpiece == item) {
            m_movingpiece = nullptr;
        }
        else {
            if (auto i = dynamic_cast<PieceView*>(item)) {
                m_movingpiece = i;
            }
            else {
                for (auto child : item->childItems()) {
                    m_movingpiece = static_cast<PieceView*>(child);
                }
            }
        }
    }
}
