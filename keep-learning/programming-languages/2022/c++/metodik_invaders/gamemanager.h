#ifndef GAMEMANAGER_H
#define GAMEMANAGER_H
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QTimer>
#include "PlayerSpaceship.h"

class GameManager: public QObject
{
    Q_OBJECT
    public:
        GameManager();
        void show();
        bool eventFilter(QObject *obj, QEvent *event);
private:
        QGraphicsScene *scene;
        QGraphicsView *view;
        PlayerSpaceship *player;
        QGraphicsItemGroup *aliensGroup;
        int groupX;
        int groupY;
        int groupDirection;
        int speed;
        int advanceStepY;
        int aliensEdgeCounter;
        QTimer moveTimer;
    private slots:
        void update();
        void moveDown();
};
#endif // GAMEMANAGER_H
