//
// Created by nordi on 1/30/2023.
//

#include "player.h"
#include "bullet.h"

namespace metodik_invaders2 {
  Player::Player(int speed, int health, int fireRate, int bulletMoveStep,
               settings::AmmoType ammoType, settings::AmmoDmgLvl dmgLevel,
               settings::ShipTypes shipType, QObject *parent) : SpaceCraft(
    speed, health, fireRate, bulletMoveStep, ammoType, dmgLevel, shipType,
    parent) {}

  settings::Faction Player::getFaction() {
    return settings::Faction::Player;
  }

  Player::~Player() {
  }
} // metodik_invaders2