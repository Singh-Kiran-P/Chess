#include "boardview.h"

BoardView::BoardView(QGraphicsScene* scene) : scene{scene} {
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {

            TileView* tile;
            if ((i + j) % 2 == 0)
                tile = new TileView{Qt::black};
            else
                tile = new TileView{Qt::white};

            QString path;
            QColor color;
            if (j <=1) {
                path += ":/images/black/";
                color = Qt::black;
            }
            if (j >= 6) {
                path += ":/images/white/";
                color = Qt::white;
            }

            if (j == 1 || j == 6)
                path += "pawn";
            else {
                if (i == 0 || i == 7)
                    path += "rook";
                else if (i == 1 || i == 6)
                    path += "bishop";
                else if (i == 2 || i == 5)
                    path += "knight";
                else if (i == 3)
                    path += "queen";
                else if (i == 4)
                    path += "king";
            }

            if (path != "") {
                PieceView* piece = new PieceView{color, path};
                piece->setParentItem(tile);
            }


            scene->addItem(tile);
            tile->setPos(100*i, 100*j);
        }
    }
}
