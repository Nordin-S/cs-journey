//
// Created by nordi on 1/30/2023.
//

#ifndef METODIK_INVADERS2_PLAYER_H
#define METODIK_INVADERS2_PLAYER_H

#include <QObject>
#include <QGraphicsPixmapItem>
#include "settings.h"
#include "spacecraft.h"

namespace metodik_invaders2 {
  /**
   * @brief The Player class
   * @details This class is used to create the player ship.
   */
  class Player : public SpaceCraft {
  Q_OBJECT
    Q_PROPERTY(QPointF pos READ pos WRITE setPos)
  private:
    int xDirection = 0;
    int yDirection = 0;
  public:
    /**
     * @brief Player
     * @details This constructor is used to create the player ship.
     * @param moveStep The moveStep of the player ship.
     * @param health The health of the player ship.
     * @param fireRate The fire rate of the player ship.
     * @param bulletMoveStep The bullet move step of the player ship.
     * @param ammoType The ammo type of the player ship.
     * @param dmgLevel The damage level of the bullet.
     * @param shipType The ship type of the player ship.
     * @param parent The parent of the player ship.
     */
    explicit Player(int moveStep = settings::ShipSpeeds::FighterSpeed,
                    int moveUpdate = settings::UpdateMs::UMs300,
                    int health = settings::Healths::FighterHealth,
                    int fireRate = settings::UpdateMs::UMs01,
                    int bulletMoveStep = settings::MoveSteps::Move01,
                    settings::AmmoType ammoType = settings::AmmoType::TypeLaser,
                    settings::AmmoDmgLvl dmgLevel = settings::AmmoDmgLvl::Dmg10,
                    settings::Faction faction = settings::Faction::Player,
                    settings::ShipClass shipClass = settings::ShipClass::Fighter,
                    settings::ShipTypes shipType = settings::ShipTypes::Striker,
                    QObject *parent = nullptr);

    ~Player() = default;

    /**
     * @brief setDirectionX
     * @details This method is used to set the x direction of the player ship.
     * @param xDirection The x direction of the player ship.
     */
    void setDirectionX(int xDirection);

    /**
     * @brief setDirectionY
     * @details This method is used to set the y direction of the player ship.
     * @param yDirection The y direction of the player ship.
     */
    void setDirectionY(int yDirection);

    /**
     * @brief setShooting
     * @details This method is used to set the shooting state of the player ship.
     * @param shooting The shooting state of the player ship.
     */
    void setShooting(bool shooting);

    settings::Faction getFaction() override;
    settings::ShipTypes getShipType() override;
    settings::ShipClass getShipClass() override;

    int getHealth();
    void setHealth(int health);

  public slots:

    void updatePosition() override;

    void move() override;

    void shoot() override;

  };

} // namespace metodik_invaders2
#endif //METODIK_INVADERS2_PLAYER_H
