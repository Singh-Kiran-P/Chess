#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QDebug>
#include <QMainWindow>

#include "pieceview.h"
#include "boardview.h"
#include "tileview.h"

#include <QGraphicsView>
#include <QGraphicsScene>

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    bool eventFilter(QObject *target, QEvent *event);

private:
    QGraphicsScene *scene;
    QGraphicsView *view;
    BoardView *m_board;
};

#endif // MAINWINDOW_H
