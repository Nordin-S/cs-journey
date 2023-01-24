#ifndef ALIENSHIP_H
#define ALIENSHIP_H

#include <QGraphicsRectItem>

class AlienShip : public QObject, public QGraphicsRectItem
{
    Q_OBJECT
    public:
        AlienShip();
        void move();
private:
        int direction; // 1 for right, -1 for left
        int speed;
public slots:
//        void onCollision(AlienShip *alien);
};
#endif // ALIENSHIP_H
