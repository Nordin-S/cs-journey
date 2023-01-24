#ifndef PLAYERSPACESHIP_H
#define PLAYERSPACESHIP_H

#include "AlienShip.h"
#include "imovable.h"
#include "projectile.h"

#include <QGraphicsRectItem>
#include <QKeyEvent>
#include <QPropertyAnimation>

class PlayerSpaceship : public QObject, public QGraphicsRectItem, public IMovable
{
    Q_OBJECT
    Q_PROPERTY(QPointF pos READ pos WRITE setPos);

    public:
    PlayerSpaceship(QGraphicsItemGroup *aliens);
    void moveLeft() override;

    void moveRight() override;

    void stop() override;
    void shoot();
private:
    QPropertyAnimation *animation;
    QGraphicsItemGroup *aliens;
public slots:
//    static void onCollision(Projectile* projectile);
//    protected:
//        void keyPressEvent(QKeyEvent *event) override;
};
#endif // PLAYERSPACESHIP_H
