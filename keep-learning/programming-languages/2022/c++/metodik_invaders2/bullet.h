#ifndef METODIK_INVADERS2_BULLET_H
#define METODIK_INVADERS2_BULLET_H


#include <QGraphicsPixmapItem>
#include <QObject>
#include "settings.h"

namespace metodik_invaders2 {
  class Bullet : public QObject, public QGraphicsPixmapItem {
  Q_OBJECT
  public:
    Bullet(settings::Faction ownerType = settings::Faction::Player,
           int bMoveStep = static_cast<int>(settings::MoveSteps::Move02),
           settings::AmmoType ammoType = settings::AmmoType::TypeLaser,
           settings::AmmoDmgLvl dmgLevel = settings::AmmoDmgLvl::Dmg10,
           QObject *parent = nullptr);

    ~Bullet() = default;

    settings::Faction getOwner();

  private:
    settings::Faction myOwnersType;
    settings::AmmoType m_ammoType;
    settings::AmmoDmgLvl m_dmgLevel;
    QTimer *updateTimer;
    int m_bMoveStep;

  private slots:

    void move();
  public slots:
    int getDamage();
  signals:

  };

} // namespace metodik_invaders2
#endif //METODIK_INVADERS2_BULLET_H