#include <QGraphicsScene>
#include "PlayerSpaceship.h"
#include "projectile.h"
#include <QPropertyAnimation>
#include <QBrush>
#include <QDebug>

PlayerSpaceship::PlayerSpaceship(QGraphicsItemGroup *aliens):aliens(aliens)
{
    setRect(0,0,40,40); // set the size of the spaceship
    setBrush(QBrush(Qt::red)); // set the color of the spaceship
    animation = new QPropertyAnimation(this, "pos");
}

void PlayerSpaceship::moveLeft() {
    if(pos().x() >= 0){
        animation->setDuration(500);
        animation->setStartValue(pos());
        animation->setEndValue(QPointF(x() - 220, y()));
        animation->start();
    }
}

void PlayerSpaceship::moveRight(){
    if(pos().x() + rect().width() <= 800){
    animation->setDuration(500);
    animation->setStartValue(pos());
    animation->setEndValue(QPointF(x() + 220, y()));
    animation->start();
    }
}

void PlayerSpaceship::stop(){
    animation->stop();
}

void PlayerSpaceship::shoot()
{
    Projectile *projectile = new Projectile(this->parentItem()->scene(), QPointF(pos().x(), 0));
}
