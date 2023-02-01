#ifndef METODIK_INVADERS2_SPACECRAFT_H
#define METODIK_INVADERS2_SPACECRAFT_H

#include <QGraphicsPixmapItem>
#include <QObject>
#include <QPropertyAnimation>
#include <QGraphicsScene>
#include "settings.h"
#include "GameObject.h"
#include "SfxHandler.h"
#include "bullet.h"

namespace metodik_invaders2 {
  class SpaceCraft : public GameObject {
  Q_OBJECT
    Q_PROPERTY(QPointF pos READ pos WRITE setPos)
  public:
    explicit SpaceCraft(int speed = settings::ShipSpeeds::PlayerSpeed,
                        int health = settings::Healths::PlayerHealth,
                        int fireRate = settings::UpdateMs::UMs01,
                        int bulletMoveStep = settings::MoveSteps::Move01,
                        settings::AmmoType ammoType = settings::AmmoType::TypeLaser,
                        settings::AmmoDmgLvl dmgLevel = settings::AmmoDmgLvl::Dmg10,
                        settings::ShipTypes shipType = settings::ShipTypes::Striker,
                        QObject *parent = nullptr);

    ~SpaceCraft() override;
    virtual void setPosition(qreal xPos, qreal yPos) override;
    virtual void setDirectionX(int xDirection) override;
    virtual void setDirectionY(int yDirection) override;

    virtual void startShooting();

    virtual void stopShooting();

    virtual void setShipAnimations(settings::ShipTypes shipType);

    settings::Faction getFaction() override;

  protected:
    settings::ShipTypes m_shipType;
    QList<QString> m_shipCrusingAnims;
    QList<QString> m_shipAcceleratingAnims;
    QList<QString> m_shipDeceleratingAnims;
    QList<QString> m_shipExplodingAnims;
    settings::AmmoType m_ammoType;
    settings::AmmoDmgLvl m_dmgLevel;
    QTimer *shootTimer;
    QTimer *animationTimer;
    int m_speed;
    int m_health;
    int m_fireRate{};
    int m_bulletMoveStep;
    bool isShooting = false;
    SfxHandler *m_sfxHandler;

    settings::AnimationStates m_animState = settings::AnimationStates::Cruising;

    int animIndex = 0;

  public slots:

    virtual void updatePosition() override;
    virtual void move() override;
    virtual void checkCollision() override;

    virtual void shoot();

    virtual void animateShip();

    virtual void handlePlayerDied();
    virtual void handleEnemyDied();

  signals:
    void fireBulletSignal();
    void bulletHitSignal();
    void explodingSignal();
    void playerDiedSignal();
    void enemyDiedSignal();
  };

} // namespace metodik_invaders2
#endif //METODIK_INVADERS2_SPACECRAFT_H
