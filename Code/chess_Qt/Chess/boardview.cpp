#include "boardview.h"
#include "pawn.h"
#include "rook.h"
#include "king.h"
#include "queen.h"
#include "knight.h"
#include "bishop.h"
BoardView::BoardView(QGraphicsScene *scene) : scene{scene}
{
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            TileView *tile;
            Position pos = Position(i, j);
            QColor color;
            Piece *piece = nullptr;
            if ((i + j) % 2 == 0)
                tile = new TileView{Qt::black, pos};
            else
                tile = new TileView{Qt::white, pos};

            QString path;
            if (j <= 1)
            {
                path += ":/images/black/";
                color = Qt::black;
            }
            if (j >= 6)
            {
                path += ":/images/white/";
                color = Qt::white;
            }

            if (j == 1 || j == 6)
            {
                path += "pawn";
                piece = new Pawn('p', color, pos);
            }
            else
            {
                if (i == 0 || i == 7)
                {
                    path += "rook";
                    piece = new Rook('r', color, pos);
                }
                else if (i == 1 || i == 6)
                {
                    path += "bishop";
                    piece = new Bishop('b', color, pos);
                }
                else if (i == 2 || i == 5)
                {
                    path += "knight";
                    piece = new Knight('n', color, pos);
                }
                else if (i == 3)
                {
                    path += "queen";
                    piece = new Queen('q', color, pos);
                }
                else if (i == 4)
                {
                    path += "king";
                    piece = new King('k', color, pos);
                }
            }

            if (path != "")
            {
                PieceView *piecev = new PieceView{path, piece};
                piecev->setParentItem(tile);
            }

            scene->addItem(tile);
            tile->setPos(100 * i, 100 * j);
        }
    }
}
