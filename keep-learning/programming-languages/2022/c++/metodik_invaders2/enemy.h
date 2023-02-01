#ifndef METODIK_INVADERS2_ENEMY_H
#define METODIK_INVADERS2_ENEMY_H


#include <QObject>
#include <QGraphicsPixmapItem>
#include "settings.h"
#include "spacecraft.h"

namespace metodik_invaders2 {
  class Enemy : public SpaceCraft {
  Q_OBJECT
  public:
    explicit Enemy(int speed = settings::ShipSpeeds::FighterSpeed,
                   int health = settings::Healths::FighterHealth,
                   int fireRate = settings::UpdateMs::UMs01,
                   int bulletMoveStep = settings::MoveSteps::Move01,
                   settings::AmmoType ammoType = settings::AmmoType::TypeLaser,
                   settings::AmmoDmgLvl dmgLevel = settings::AmmoDmgLvl::Dmg10,
                   settings::ShipTypes shipType = settings::ShipTypes::Striker,
                   settings::EnemyShipType enemyShipType = settings::EnemyShipType::Fighter,
                   QGraphicsScene* scene = nullptr,
                   QObject *parent = nullptr);

    ~Enemy() override;

    settings::Faction getFaction() override;

  public slots:

    void move() override;

    void shoot() override;

  private:
    settings::EnemyShipType m_enemyType;
    QGraphicsScene* m_scene;

  signals:

  };

} // namespace metodik_invaders2
#endif //METODIK_INVADERS2_ENEMY_H