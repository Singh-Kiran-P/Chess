#include "mainwindow.h"
#include "ui_mainwindow.h"

Piece::Piece(QColor color) {
    QString path;
    if (color == Qt::white)
        path = ":/images/white/pawn.png";
    else if (color == Qt::black)
        path = ":/images/black/pawn.png";

    QPixmap pawn(path);
    setPixmap(pawn);
    setFlags(QGraphicsItem::ItemIsSelectable);
}

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent) {

    scene = new QGraphicsScene{};
    view = new QGraphicsView{scene};

    view->setSceneRect(0, 0, 800, 800);
    setCentralWidget(view);

    view->show();
    BuildBoard();
    PlacePawns();
}

QGraphicsItem* MainWindow::getSelectedPawn() {
    return selectedpawn;
}

void MainWindow::BuildBoard() {
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            QColor color = Qt::black;
            if ((i + j) % 2 == 0)
                color = Qt::white;

            Tile *tile = new Tile(color, this->scene);
            scene->addItem(tile);
            tile->setPos(100*i, 100*j);
        }
    }
}

void MainWindow::PlacePawns() {
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {

            if (j == 1 || j == 6) {
                Piece* pawn;
                if (j == 1)
                    pawn = new Piece{Qt::black};
                else
                    pawn = new Piece{Qt::white};
                QGraphicsItem* tile = scene->itemAt(i*100, j*100, QTransform());
                pawn->setParentItem(tile);
            }
        }
    }
}

Tile::Tile(QColor color, QGraphicsScene* scene) : scene{scene} {
    setBrush(color);

    setRect(0, 0, 100, 100);
}

void Tile::mousePressEvent(QGraphicsSceneMouseEvent* event) {
    if (event->button() == Qt::LeftButton) {
        foreach (auto item, scene->selectedItems())
            item->setParentItem(this);
    }
    scene->clearSelection();
}
