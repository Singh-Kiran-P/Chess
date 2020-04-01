#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent) {

    scene = new QGraphicsScene{};
    view = new QGraphicsView{scene};

    scene->installEventFilter(this);
    view->setSceneRect(-20, -20, 840, 840);
    setCentralWidget(view);

    m_board = new BoardView{scene};

    view->show();
}

bool MainWindow::eventFilter(QObject *target, QEvent *event)
{
    if (target == scene)
    {
        if (event->type() == QEvent::GraphicsSceneMousePress)
        {
            const QGraphicsSceneMouseEvent* const me = static_cast<const QGraphicsSceneMouseEvent*>(event);
            const QPointF position = me->scenePos();

            qDebug() << floor(position.x() / 100) * 100 << "," << floor(position.y() / 100) * 100 << endl;
        }
    }
    return QMainWindow::eventFilter(target, event);
}



