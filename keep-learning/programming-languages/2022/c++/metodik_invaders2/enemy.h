#ifndef METODIK_INVADERS2_ENEMY_H
#define METODIK_INVADERS2_ENEMY_H


#include <QObject>
#include <QGraphicsPixmapItem>
#include "settings.h"

namespace metodik_invaders2 {
  class Enemy : public QObject, public QGraphicsPixmapItem {
  Q_OBJECT
  public:
    Enemy(int speed = static_cast<int>(settings::SHIP_SPEEDS::FIGHTER_SPEED),
          int health = static_cast<int>(settings::HEALTHS::FIGTHER_HEALTH),
          int fireRate = static_cast<int>(settings::UPDATE_MS::uMS01),
          int bulletMoveStep = static_cast<int>(settings::MOVE_STEPS::MOVE01),
          settings::ENEMY_SHIP_TYPE shipType = settings::ENEMY_SHIP_TYPE::FIGHTER,
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
    settings::AMMO_TYPE m_ammoType;
    settings::ENEMY_SHIP_TYPE shipType;

  signals:

  };

} // namespace metodik_invaders2
#endif //METODIK_INVADERS2_ENEMY_H