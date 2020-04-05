#include "boardscene.h"

BoardScene::BoardScene(Game* game) {

    m_board = new Board{};
    connect(m_board, SIGNAL(moved(QPoint, QPoint)), this, SLOT(movedpiece(QPoint, QPoint)));
    connect(m_board, SIGNAL(placedPiece(Piece*)), this, SLOT(placePixMap(Piece*)));
    connect(game, SIGNAL(checkedKing(QColor)), this, SLOT(setCheckEffect(QColor)));
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
    m_whiteKing->setCheckEffect(false);
    m_blackKing->setCheckEffect(false);

    if (m_nexttile == nullptr)
        m_nexttile = getNextItem(next);
    for (auto childPieces : m_nexttile->childItems())
        delete childPieces;

    if (m_movingpiece == nullptr)
        m_movingpiece = getMovingPiece(curr);

    m_movingpiece->setParentItem(m_nexttile);
    clearSelection();
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

    if (piece->getId() == 'K') {
        if (piece->getColor() == Qt::white)
            m_whiteKing = PieceItem;
        else
            m_blackKing = PieceItem;
    }
}

void BoardScene::promotePixMap(QString type, Pawn* pawn) {
    QString path = ":/images/";

    if (m_movingpiece == nullptr)
        m_movingpiece = getMovingPiece(pawn->getPos() * 100);

    if (m_movingpiece->color() == Qt::white)
        path += "white/";
    else
        path += "black/";

    path += type.toLower();

    m_movingpiece->setPixmap(path);
    m_board->changePawn(type, pawn);
    clearSelection();
}

void BoardScene::clearSelection() {
    if (m_movingpiece != nullptr) {
    m_movingpiece->deselect();
    m_movingpiece = nullptr;
    m_nexttile = nullptr;
    }
}

void BoardScene::setCheckEffect(QColor color) {
    if (color == Qt::white)
        m_whiteKing->setCheckEffect(true);
    else if (color == Qt::black)
        m_blackKing->setCheckEffect(true);
}

PieceView* BoardScene::getMovingPiece(QPoint pos) {
    QGraphicsItem* selection = itemAt(pos, QTransform());
    if (auto selectedPiece = dynamic_cast<PieceView*>(selection))
        return selectedPiece;
    else {
        for (auto childPiece : selection->childItems()) {
            if (auto selectedPiece = dynamic_cast<PieceView*>(childPiece))
                return selectedPiece;
        }
    return nullptr;
    }
}

QGraphicsRectItem* BoardScene::getNextItem(QPoint pos) {
    QGraphicsItem* selection = itemAt(pos, QTransform());
    if (auto selectedSquare = dynamic_cast<QGraphicsRectItem*>(selection))
        return selectedSquare;
    else {
        if (auto parentSquare = dynamic_cast<QGraphicsRectItem*>(selection->parentItem()))
            return parentSquare;
        }
    return nullptr;
}

void BoardScene::mousePressEvent(QGraphicsSceneMouseEvent *event) {
    QPoint clickPos = event->scenePos().toPoint();
    if (clickPos.x() < 0 || clickPos.x() > 800 || clickPos.y() < 0 || clickPos.y() > 800)
        return;

    if (event->button() == Qt::LeftButton) {
        if (m_movingpiece == nullptr) {
            m_movingpiece = getMovingPiece(clickPos);
            if (m_movingpiece != nullptr)
                m_movingpiece->select();
        }
        else if (m_movingpiece == getMovingPiece(clickPos)) {
                 clearSelection();
        }
        else {
            m_nexttile = getNextItem(clickPos);
            doMove(m_movingpiece, m_nexttile);
        }
    }
}
