#include "player.h"
#include "bullet.h"
#include "enemy.h"

#include <QTimer>
#include <QKeyEvent>
#include <QGraphicsScene>
#include <QMovie>
#include <QLabel>
#include <utility>
#include <iostream>


namespace metodik_invaders2 {
  Player::Player(int speed, int health, int fireRate, int bulletMoveStep,
                 settings::AmmoType ammoType,
                 settings::AmmoDmgLvl dmgLevel,
                 settings::ShipTypes shipType, QObject *parent)
    : m_speed(speed), m_health(health), m_fireRate(fireRate),
      m_bulletMoveStep(bulletMoveStep), m_ammoType(ammoType),
      m_dmgLevel(dmgLevel),
      m_shipType(std::move(shipType)),
      QObject{parent} {

    setShipAnimations(m_shipType);

    // connect checkCollision() slot to games updatePosition updateTimer
    updateTimer = new QTimer();
    connect(updateTimer, SIGNAL(timeout()), this, SLOT(updatePosition()));
    updateTimer->start(m_speed);

    shootTimer = new QTimer();
    connect(shootTimer, SIGNAL(timeout()), this, SLOT(shoot()));
    shootTimer->start(m_fireRate);

    animationTimer = new QTimer();
    connect(animationTimer, SIGNAL(timeout()), this, SLOT(animateShip()));
    animationTimer->start(50);
  }

  void Player::setPosition(qreal xPos, qreal yPos) {
    // position based on center of pixmap
    setPos(xPos - pixmap().width() / 2, yPos - pixmap().height() - pixmap().height() / 2);
  }

  void Player::setDirectionX(int xDirection) {
    this->xDirection = xDirection;
  }

  void Player::setDirectionY(int yDirection) {
    this->yDirection = yDirection;
  }

  void Player::updatePosition() {
    checkCollision();
    if (xDirection != 0 || yDirection != 0) {
      move();
      return;
    }
    m_animState = settings::AnimationStates::Cruising;
  }

  void Player::move() {
    if (xDirection < 0) {
      if (pos().x() > pixmap().width() / 2)
        setPos(pos().x() - m_speed, y());
    }
    if (xDirection > 0) {
      if (pos().x() + pixmap().width() <
          scene()->sceneRect().width() - pixmap().width() / 2)
        setPos(pos().x() + m_speed, y());
    }
// TODO: change with the code above?
//    if (xDirection != 0) {
//      //
//      bool notLeftOfScreen = pos().x() > (pixmap().width() / 2);
//      bool notRightOfScreen = pos().x() + pixmap().width() <
//                              scene()->sceneRect().width();
//      if (notLeftOfScreen && notRightOfScreen)
//        setPos((pos().x() - m_speed) * xDirection, y());
//      if (yDirection = 0)
//        m_animState = settings::AnimationStates::Cruising;
//    }

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

  void Player::animateShip() {
    switch (m_animState) {
      case settings::AnimationStates::Cruising:
        if (animIndex >= m_shipCrusingAnims.size()) {
          animIndex = 0;
        }
        setPixmap(QPixmap((m_shipCrusingAnims[animIndex])));
        animIndex++;
        break;
      case settings::AnimationStates::Accelerating:
        if (animIndex >= m_shipAcceleratingAnims.size()) {
          animIndex = 0;
        }
        setPixmap(QPixmap((m_shipAcceleratingAnims[animIndex])));
        animIndex++;
        break;
      case settings::AnimationStates::Decelerating:
        if (animIndex >= m_shipDeceleratingAnims.size()) {
          animIndex = 0;
        }
        setPixmap(QPixmap((m_shipDeceleratingAnims[animIndex])));
        animIndex++;
        break;
      case settings::AnimationStates::Exploding:
        if (animIndex >= m_shipExplodingAnims.size()) {
          animIndex = 0;
        }
        setPixmap(QPixmap((m_shipExplodingAnims[animIndex])));
        animIndex++;
        break;
    }
  }

  // TODO: damage should be given by bullet
  void Player::checkCollision() {
    // all items collding with player
    QList<QGraphicsItem *> colliding_items = collidingItems();

    //check for colliding item types and apply damage
    for (int i = 0; i < colliding_items.size(); ++i) {
      if (colliding_items[i] != nullptr &&
          typeid(*(colliding_items[i])) == typeid(Enemy))
        m_health -= 25;
      if (colliding_items[i] != nullptr &&
          typeid(*(colliding_items[i])) == typeid(Bullet) &&
          ((Bullet *) colliding_items[i])->getOwner() ==
          settings::Faction::Enemy) {
        m_health -= 10;
        scene()->removeItem(colliding_items[i]);
      }
      if (m_health <= 0) {
        scene()->removeItem(this);
        this->deleteLater();
        return;
      }
    }
  }

  void Player::startShooting() {
    isShooting = true;
  }

  void Player::stopShooting() {
    isShooting = false;
  }

  void Player::shoot() {
    if (m_health <= 0 || !isShooting)
      return;
    // create bullets and add to scene
    Bullet *bullet = new Bullet(settings::Faction::Player,
                                m_bulletMoveStep,
                                m_ammoType,
                                m_dmgLevel,
                                this);

    int shipsCenterX = x() + pixmap().width() / 2;


    // resize bullet
//    bullet->pixmap().scaled(bullet->pixmap().size().width() * 4,
//                            bullet->pixmap().size().height() * 4);
    //TODO: Resize functionality for bullets?
//    bullet->setPixmap(bullet->pixmap().scaled(bullet->pixmap().size().width() * 0.25,
//                            bullet->pixmap().size().height() * 0.25));
    int bulletsCenterX = bullet->boundingRect().width() / 2;

    bullet->setPos(shipsCenterX - bulletsCenterX, y());
    scene()->addItem(bullet);
//    bullets.append(bullet);
  }

  void Player::setShipAnimations(settings::ShipTypes shipType) {
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
} // namespace metodik_invaders2
