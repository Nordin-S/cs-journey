#include "player.h"
#include "bullet.h"
#include "enemy.h"

#include <QTimer>
#include <QKeyEvent>
#include <QGraphicsScene>


namespace metodik_invaders2 {
  Player::Player(int speed, int health, int fireRate, int bulletMoveStep,
                 settings::AMMO_TYPE ammoType,
                 QString playerShip, QObject *parent)
    : m_speed(speed), m_health(health), m_fireRate(fireRate),
      m_bulletMoveStep(bulletMoveStep), m_ammoType(ammoType), QObject{parent} {
    setPixmap(QPixmap(playerShip));

    // animation for position remove? TODO: remove this?
    animation = new QPropertyAnimation(this, "pos");

    // connect checkCollision() slot to games update timer
    QTimer * timer = new QTimer();
    connect(timer, SIGNAL(timeout()), this, SLOT(update()));
    timer->start(10);
  }

  void Player::setPosition(qreal xPos, qreal yPos) {
    // position to bottom center of screen minus a margin
    setPos(xPos / 2 - pixmap().width() / 2, yPos - pixmap().height() - 20);
  }

  void Player::update() {
    checkCollision();
    if (isMovingLeft || isMovingRight)
      move();
    if (isShooting)
      shoot();
  }

  void Player::moveLeft() {
    isMovingLeft = true;
  }

  void Player::moveRight() {
    isMovingRight = true;
  }

  void Player::stopMoveLeft() {
    isMovingLeft = false;
  }

  void Player::stopMoveRight() {
    isMovingRight = false;
  }

  void Player::move() {
    if (isMovingLeft) {
      if (pos().x() > pixmap().width() / 2)
        setPos(pos().x() - m_speed, y());
    }
    if (isMovingRight) {
      if (pos().x() + pixmap().width() <
          scene()->sceneRect().width() - pixmap().width() / 2)
        setPos(pos().x() + m_speed, y());
    }
  }

  void Player::stop() {
    isMovingLeft = false;
    isMovingRight = false;
  }

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
          settings::BULLET_OWNER::ENEMY) {
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
    if (m_health <= 0)
      return;
    // create bullets and add to scene
    Bullet *bullet = new Bullet(settings::BULLET_OWNER::PLAYER, m_fireRate,
                                this);

    int shipsCenterX = x() + pixmap().width() / 2;
    int bulletsCenterX = bullet->pixmap().width() / 2;

    bullet->setPos(shipsCenterX - bulletsCenterX, y());
    scene()->addItem(bullet);
//    bullets.append(bullet);
  }
} // namespace metodik_invaders2
