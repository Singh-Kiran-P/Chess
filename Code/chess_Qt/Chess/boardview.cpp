#include "boardview.h"

BoardView::BoardView(QGraphicsScene* scene) : scene{scene} {

    m_board = new Board{};
    connect(m_board, SIGNAL(moved()), this, SLOT(movepiece()));

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
                    path += "bishop";
                else if (x == 2 || x == 5)
                    path += "knight";
                else if (x == 3)
                    path += "queen";
                else if (x == 4)
                    path += "king";
            }

            if (path != "") {
                PieceView* piece = new PieceView{color, path};
                piece->setParentItem(tile);
            }


            scene->addItem(tile);
            tile->setPos(100*x, 100*y);
        }
    }
}

void BoardView::movepiece(QPoint current, QPoint next) {
    m_movingpiece->setParentItem(m_nextpiece);
}
