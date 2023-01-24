#ifndef PROJECTILE_H
#define PROJECTILE_H

#include "AlienShip.h"
#include "qgraphicsscene.h"

#include <QBrush>
#include <QGraphicsRectItem>
#include <QPropertyAnimation>

class Projectile : public QObject, public QGraphicsRectItem
{
    Q_OBJECT
    Q_PROPERTY(QPointF pos READ pos WRITE setPos);
public:
    Projectile(QGraphicsScene *scene, QPointF direction)
    {
        setRect(0, 0, 5, 20);
        setBrush(QBrush(Qt::yellow));
        setPos(direction);
        scene->addItem(this);
        startAnimation();
    }

    void startAnimation()
    {
        QPropertyAnimation *animation = new QPropertyAnimation(this, "pos");
        animation->setDuration(1000);
        animation->setStartValue(pos());
        animation->setEndValue(QPointF(pos().x(), 0));
        animation->start();
    }

        void update()
        {
            QList<QGraphicsItem*> listCollidingItems = collidingItems();
            for(auto const item : listCollidingItems) {
                AlienShip *alien = dynamic_cast<AlienShip*>(item);
                if(alien != nullptr){
                    scene()->removeItem(alien);
                    scene()->removeItem(this);

//                    emit sIncreaseScore();

                    delete alien;
                    delete this;
                }
            }
            if (y() <= 0) {
                scene()->removeItem(this);
//                    emit sDeacreaseScore();
                delete this;
                return;
            }
            setPos(mapToParent(0, -10));
        }

//signals:
};

#endif // PROJECTILE_H
