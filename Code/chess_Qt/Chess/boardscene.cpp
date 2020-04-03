#include "boardscene.h"

BoardScene::BoardScene(Game* game) {

    m_board = new Board{};
    connect(m_board, SIGNAL(moved(QPoint, QPoint)), this, SLOT(movedpiece(QPoint, QPoint)));
    game->setBoard(m_board);

    for (int y = 0; y < 8; y++) {
        for (int x = 0; x < 8; x++) {

            TileView* tile;
            if ((x + y) % 2 == 0)
                tile = new TileView{Qt::black};
            else
                tile = new TileView{Qt::white};

            QString path;
            QColor color;
            if (y <= 1) {
                path += ":/images/black/";
                color = Qt::black;
            }
            if (y >= 6) {
                path += ":/images/white/";
                color = Qt::white;
            }
            if (y == 1 || y == 6)
                path += "pawn";
            else {
                if (x == 0 || x == 7)
                    path += "rook";
                else if (x == 1 || x == 6)
                    path += "knight";
                else if (x == 2 || x == 5)
                    path += "bishop";
                else if (x == 3)
                    path += "queen";
                else if (x == 4)
                    path += "king";
            }
            if (path != "") {
                PieceView* piece = new PieceView{color, path};
                piece->setParentItem(tile);
            }
            addItem(tile);
            tile->setPos(100*x, 100*y);
        }
    }
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

void BoardScene::mousePressEvent(QGraphicsSceneMouseEvent *event) {
    if (event->button() == Qt::LeftButton) {
        auto item = itemAt(event->scenePos(), QTransform());
        if (m_movingpiece != nullptr && m_movingpiece != item) {
            m_nextpiece = item;
            emit doMove(static_cast<PieceView*>(m_movingpiece), m_nextpiece);
            m_movingpiece = nullptr;
            m_nextpiece = nullptr;
        }
        else if (m_movingpiece == item)
                m_movingpiece = nullptr;
        else {
            if (auto i = dynamic_cast<PieceView*>(item)) {
                m_movingpiece = i;
            }
            else {
                for (auto child : item->childItems())
                    m_movingpiece = static_cast<PieceView*>(child);
            }
        }
    }
}
