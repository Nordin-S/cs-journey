//
// Created by nordi on 1/30/2023.
//


#ifndef METODIK_INVADERS2_PLAYER_H
#define METODIK_INVADERS2_PLAYER_H

#include "spacecraft.h"

namespace metodik_invaders2 {

  class Player : public SpaceCraft {
  Q_OBJECT
    Q_PROPERTY(QPointF pos READ pos WRITE setPos)
  public:
    explicit Player(int speed = settings::ShipSpeeds::FighterSpeed,
                   int health = settings::Healths::FighterHealth,
                   int fireRate = settings::UpdateMs::UMs01,
                   int bulletMoveStep = settings::MoveSteps::Move01,
                   settings::AmmoType ammoType = settings::AmmoType::TypeLaser,
                   settings::AmmoDmgLvl dmgLevel = settings::AmmoDmgLvl::Dmg10,
                   settings::ShipTypes shipType = settings::ShipTypes::Striker,
                   QObject *parent = nullptr);

    ~Player() override;
    settings::Faction getFaction() override;

  public slots:
  };

} // metodik_invaders2

#endif //METODIK_INVADERS2_PLAYER_H
