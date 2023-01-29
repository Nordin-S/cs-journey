#ifndef METODIK_INVADERS2_PLAYER_H
#define METODIK_INVADERS2_PLAYER_H

#include <QGraphicsPixmapItem>
#include <QObject>
#include <QPropertyAnimation>
#include <QGraphicsScene>
#include "settings.h"

namespace metodik_invaders2 {
  class Player : public QObject, public QGraphicsPixmapItem {
  Q_OBJECT
    Q_PROPERTY(QPointF pos READ pos WRITE setPos)
  public:
    Player(int speed = settings::ShipSpeeds::PlayerSpeed,
           int health = settings::Healths::PlayerHealth,
           int fireRate = settings::UpdateMs::UMs01,
           int bulletMoveStep = settings::MoveSteps::Move01,
           settings::AmmoType ammoType = settings::AmmoType::TypeLaser,
           settings::AmmoDmgLvl dmgLevel = settings::AmmoDmgLvl::Dmg10,
           settings::ShipTypes shipType = settings::ShipTypes::Striker,
           QObject *parent = nullptr);

    void setPosition(qreal xPos, qreal yPos);

    void startShooting();

    void stopShooting();

  private:
    settings::ShipTypes m_shipType;
    QList<QString> m_shipCrusingAnims;
    QList<QString> m_shipAcceleratingAnims;
    QList<QString> m_shipDeceleratingAnims;
    QList<QString> m_shipExplodingAnims;
    settings::AmmoType m_ammoType;
    settings::AmmoDmgLvl m_dmgLevel;
    QTimer *updateTimer;
    QTimer *shootTimer;
    QTimer *animationTimer;
//    QList<Bullet*> bullets;
    int m_speed;
    int m_health;
    int m_fireRate;
    int m_bulletMoveStep;
    bool isShooting = false;
    int xDirection = 0;
    int yDirection = 0;

    settings::AnimationStates m_animState = settings::AnimationStates::Cruising;

    int animIndex = 0;

  public:
    void setDirectionX(int xDirection);

    void setDirectionY(int yDirection);
    void setShipAnimations(settings::ShipTypes shipType);

  public slots:

    void checkCollision();

    void move();

    void shoot();

    void animateShip();

    void updatePosition();

  signals:

  };

} // namespace metodik_invaders2
#endif //METODIK_INVADERS2_PLAYER_H
