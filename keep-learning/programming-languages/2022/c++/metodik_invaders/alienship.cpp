#include "AlienShip.h"
#include <QGraphicsScene>
#include <QBrush>

AlienShip::AlienShip()
{
    setRect(0,0,30,30);
    setBrush(QBrush(Qt::green));
    direction = 1;
    speed = 2;
}

//    void AlienShip::onCollision(AlienShip *alien){
//        // code to handle collision, for example remove the player from the scene
//        alien->parentItem()->scene()->removeItem(alien);
//        delete alien;
//    }
void AlienShip::move()
{
    if (direction == 1) {
        if(pos().x() + rect().width() < 800) {
            setPos(x()+speed, y());
        }
        else {
            setPos(0, y()+1);
            direction = -1;
        }
    } else {
        if (pos().x() > 0) {
            setPos(x()-speed, y());
        }
        else {
            setPos(800-rect().width(), y()+1);
            direction = 1;
        }
    }
}
