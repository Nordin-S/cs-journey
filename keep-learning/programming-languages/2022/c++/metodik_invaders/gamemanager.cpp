
#include "GameManager.h"
#include <QList>
#include <QTimer>
#include <QDebug>
#include "AlienShip.h"

GameManager::GameManager()
{
    groupX = 10;
    groupY = 50;
    advanceStepY = 30;
    aliensEdgeCounter = 1;
    speed = 6;
    groupDirection = 1;
    aliensGroup = new QGraphicsItemGroup();
    player = new PlayerSpaceship(aliensGroup);

    scene = new QGraphicsScene();
    view = new QGraphicsView(scene);
//    view->setFixedSize(800, 600);
    view->setSceneRect(0, 0, 800, 600);
    view->setBackgroundBrush(QBrush(Qt::black));
    view->setRenderHint(QPainter::Antialiasing);
    view->setRenderHint(QPainter::SmoothPixmapTransform);
    view->setViewportUpdateMode(QGraphicsView::BoundingRectViewportUpdate);
    view->setOptimizationFlag(QGraphicsView::DontAdjustForAntialiasing, true);
    view->setOptimizationFlag(QGraphicsView::DontSavePainterState, true);
    view->setFocusPolicy(Qt::StrongFocus);
    scene->addItem(player);
    player->setPos(view->width()/2, view->height()-50);
    //Creating Alien ships
    for(int row = 0; row < 4; row++)
    {
        for(int col = 0; col < 10; col++){
            AlienShip *alien = new AlienShip();
            alien->setPos(col*40, (1*row)*40);
            aliensGroup->addToGroup(alien);
        }
    }
    scene->addItem(aliensGroup);
    aliensGroup->setPos(100, groupY);

    connect(&moveTimer, &QTimer::timeout, this, &GameManager::update);
    moveTimer.start(40);
}
bool GameManager::eventFilter(QObject *obj, QEvent *event) {
    if (event->type() == QEvent::KeyPress) {
        QKeyEvent *keyEvent = static_cast<QKeyEvent*>(event);
        if (keyEvent->key() == Qt::Key_Left) {
            player->moveLeft();
            return true;
        }
        if (keyEvent->key() == Qt::Key_Right) {
            player->moveRight();
            return true;
        }
        if (keyEvent->key() == Qt::Key_Space) {
            player->shoot();
            return true;
        }
    } else if (event->type() == QEvent::KeyRelease) {
        QKeyEvent *keyEvent = static_cast<QKeyEvent*>(event);
        if (keyEvent->key() == Qt::Key_Left || keyEvent->key() == Qt::Key_Right) {
            player->stop();
            return true;
        }
    }
    return QObject::eventFilter(obj, event);
}
void GameManager::show()
{
    view->show();
    view->setFocus();
    view->installEventFilter(this);
}


void GameManager::update()
{
    if(aliensGroup->x() + aliensGroup->boundingRect().width() >= 800) {
        aliensGroup->setPos(aliensGroup->x() - aliensGroup->boundingRect().width() - 1, aliensGroup->y());
        aliensEdgeCounter++;
        groupDirection *= -1;
    }
    if(aliensGroup->x() <= 0) {
        aliensGroup->setPos(1, aliensGroup->y());
        aliensEdgeCounter++;
        groupDirection *= -1;
    }
    groupX += speed * groupDirection;
    aliensGroup->setPos(groupX, aliensGroup->y());

    if(aliensEdgeCounter % 4 == 0){
        aliensEdgeCounter = 1;
        moveDown();
    }

}

void GameManager::moveDown()
{
    if(aliensGroup->y() + aliensGroup->boundingRect().height() >= 400){
        qDebug("game over");
    }
    aliensGroup->setPos(aliensGroup->x(), groupY);
    groupY += advanceStepY;
}
