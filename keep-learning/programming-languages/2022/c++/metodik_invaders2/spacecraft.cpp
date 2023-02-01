#include <QTimer>
#include <QKeyEvent>
#include <QGraphicsScene>
#include <QMovie>
#include <QLabel>
#include <QTypeInfo>
#include "GameObject.h"
#include "spacecraft.h"
#include "background.h"
#include "bullet.h"
#include "enemy.h"
#include "player.h"


namespace metodik_invaders2 {
  SpaceCraft::SpaceCraft(int speed, int health, int fireRate,
                         int bulletMoveStep,
                         settings::AmmoType ammoType,
                         settings::AmmoDmgLvl dmgLevel,
                         settings::ShipTypes shipType, QObject *parent)
    : m_speed(speed), m_health(health), m_fireRate(fireRate),
      m_bulletMoveStep(bulletMoveStep), m_ammoType(ammoType),
      m_dmgLevel(dmgLevel),
      m_shipType(shipType),
      GameObject(speed, parent) {

    setShipAnimations(m_shipType);
    m_sfxHandler = new SfxHandler();
    connect(this, &Player::fireBulletSignal, m_sfxHandler,
            &SfxHandler::handleBulletFired);
    connect(this, &Player::bulletHitSignal, m_sfxHandler,
            &SfxHandler::handleBulletHit);
    connect(this, &Player::explodingSignal, m_sfxHandler,
            &SfxHandler::handleExplosion);

    // connect checkCollision() slot to games updatePosition updateTimer
    updateTimer = new QTimer();
    connect(updateTimer, SIGNAL(timeout()), this, SLOT(updatePosition()));
    updateTimer->start(m_speed);

    shootTimer = new QTimer();
    connect(shootTimer, SIGNAL(timeout()), this, SLOT(shoot()));
    shootTimer->start(m_fireRate);

    animationTimer = new QTimer();
    connect(animationTimer, SIGNAL(timeout()), this, SLOT(animateShip()));
    animationTimer->start(100);
  }

  void SpaceCraft::setPosition(qreal xPos, qreal yPos) {
    // position based on center of pixmap
    setPos(xPos - pixmap().width() / 2,
           yPos - pixmap().height() - pixmap().height() / 2);
  }

  void SpaceCraft::setDirectionX(int xDirection) {
    this->xDirection = xDirection;
  }

  void SpaceCraft::setDirectionY(int yDirection) {
    this->yDirection = yDirection;
  }

  void SpaceCraft::updatePosition() {
    checkCollision();
    if (xDirection != 0 || yDirection != 0) {
      move();
      return;
    }
    if (m_animState == settings::AnimationStates::Exploding)
      return;
    m_animState = settings::AnimationStates::Cruising;
  }

  void SpaceCraft::checkCollision() {
    if (m_health <= 0) {
      m_animState = settings::AnimationStates::Exploding;
      shootTimer->stop();
      updateTimer->stop();
      emit explodingSignal();
      return;
    }

    QList<QGraphicsItem *> colliding_items = collidingItems();

    for (int i = 0; i < colliding_items.size(); ++i) {
      if (auto* ship = dynamic_cast<SpaceCraft *>(colliding_items[i])) {
        if (getFaction() == ship->getFaction())
          continue;

        emit explodingSignal();
        m_health = 0;
      } else if (auto* bullet = dynamic_cast<Bullet *>(colliding_items[i])) {
        if (bullet->getOwner() != getFaction()) {
          emit bulletHitSignal();
          m_health -= bullet->getDamage();
          scene()->removeItem(bullet);
          bullet->deleteLater();
        }
      }
    }
  }

  void SpaceCraft::move() {
    if (xDirection < 0) {
      if (pos().x() > pixmap().width() / 2)
        setPos(pos().x() - m_speed, y());
    }
    if (xDirection > 0) {
      if (pos().x() + pixmap().width() <
          scene()->sceneRect().width() - pixmap().width() / 2)
        setPos(pos().x() + m_speed, y());
    }

    if (yDirection < 0) {
      m_animState = settings::AnimationStates::Accelerating;
      if (pos().y() > 0)
        setPos(pos().x(), y() - m_speed);
    }
    if (yDirection > 0) {
      m_animState = settings::AnimationStates::Decelerating;
      if (pos().y() + pixmap().height() <
          scene()->sceneRect().height() - pixmap().height() / 2)
        setPos(pos().x(), y() + m_speed);
    }
  }

  void SpaceCraft::animateShip() {
    switch (m_animState) {
      case settings::AnimationStates::Cruising:
        if (animIndex >= m_shipCrusingAnims.size()) {
          animIndex = 0;
        }
        setPixmap(QPixmap(m_shipCrusingAnims[animIndex]));
        animIndex++;
        break;
      case settings::AnimationStates::Accelerating:
        if (animIndex >= m_shipAcceleratingAnims.size()) {
          animIndex = 0;
        }
        setPixmap(QPixmap(m_shipAcceleratingAnims[animIndex]));
        animIndex++;
        break;
      case settings::AnimationStates::Decelerating:
        if (animIndex >= m_shipDeceleratingAnims.size()) {
          animIndex = 0;
        }
        setPixmap(QPixmap(m_shipDeceleratingAnims[animIndex]));
        animIndex++;
        break;
      case settings::AnimationStates::Exploding:
        animIndex++;
        if (animIndex >= m_shipExplodingAnims.size()) {
          animationTimer->stop();
          scene()->removeItem(this);
          deleteLater();
          return;
        }
        setPixmap(QPixmap(m_shipExplodingAnims[animIndex]));
        break;
    }
  }

  void SpaceCraft::startShooting() {
    isShooting = true;
  }

  void SpaceCraft::stopShooting() {
    isShooting = false;
  }

  void SpaceCraft::shoot() {
    if (m_health <= 0 || !isShooting)
      return;
    // create bullets and add to scene
    Bullet *bullet = new Bullet(settings::Faction::Player,
                                m_bulletMoveStep,
                                m_ammoType,
                                m_dmgLevel,
                                this);

    int shipsCenterX = x() + pixmap().width() / 2;

    //TODO: Resize functionality for bullets?
//    bullet->setPixmap(bullet->pixmap().scaled(bullet->pixmap().size().width() * 0.25,
//                            bullet->pixmap().size().height() * 0.25));
    int bulletsCenterX = bullet->boundingRect().width() / 2;

    bullet->setPos(shipsCenterX - bulletsCenterX, y());
    scene()->addItem(bullet);
    emit fireBulletSignal();
  }

  void SpaceCraft::setShipAnimations(settings::ShipTypes shipType) {
    m_shipType = shipType;
    m_shipCrusingAnims = settings::getShipAnimation(m_shipType,
                                                    settings::AnimationStates::Cruising);
    m_shipAcceleratingAnims = settings::getShipAnimation(m_shipType,
                                                         settings::AnimationStates::Accelerating);
    m_shipDeceleratingAnims = settings::getShipAnimation(m_shipType,
                                                         settings::AnimationStates::Decelerating);
    m_shipExplodingAnims = settings::getShipAnimation(m_shipType,
                                                      settings::AnimationStates::Exploding);
  }

  settings::Faction SpaceCraft::getFaction() {
    return settings::Faction::Player;
  }

  SpaceCraft::~SpaceCraft() {
    delete m_sfxHandler;
    delete animationTimer;
    delete shootTimer;
  }

  void SpaceCraft::handlePlayerDied() {

  }

  void SpaceCraft::handleEnemyDied() {

  }
} // namespace metodik_invaders2
