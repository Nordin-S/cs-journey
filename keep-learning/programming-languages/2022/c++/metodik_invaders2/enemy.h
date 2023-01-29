#ifndef METODIK_INVADERS2_ENEMY_H
#define METODIK_INVADERS2_ENEMY_H


#include <QObject>
#include <QGraphicsPixmapItem>
#include "settings.h"

namespace metodik_invaders2 {
  class Enemy : public QObject, public QGraphicsPixmapItem {
  Q_OBJECT
  public:
    Enemy(int speed = static_cast<int>(settings::ShipSpeeds::FighterSpeed),
          int health = static_cast<int>(settings::Healths::FighterHealth),
          int fireRate = static_cast<int>(settings::UpdateMs::UMs01),
          int bulletMoveStep = static_cast<int>(settings::MoveSteps::Move01),
          settings::AmmoType ammoType = settings::AmmoType::TypeLaser,
          settings::AmmoDmgLvl dmgLevel = settings::AmmoDmgLvl::Dmg10,
          settings::EnemyShipType shipType = settings::EnemyShipType::Fighter,
          QObject *parent = nullptr);

    int getHealth();

    void setHealth(int health);

  public slots:

    void move();

    void shoot();

  private:
    int m_speed;
    int m_health;
    int m_fireRate;
    int m_bulletMoveStep;
    settings::AmmoType m_ammoType;
    settings::AmmoDmgLvl m_dmgLevel;
    settings::EnemyShipType shipType;

  signals:

  };

} // namespace metodik_invaders2
#endif //METODIK_INVADERS2_ENEMY_H