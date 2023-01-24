#include <QTimer>
#include <QGraphicsScene>

#include "enemy.h"
#include "bullet.h"

namespace metodik_invaders2 {
  Enemy::Enemy(int speed, int health, int fireRate, int bulletMoveStep,
               settings::AMMO_TYPE ammoType,
               settings::ENEMY_SHIP_TYPE shipType, QObject *parent)
    : m_speed(speed), m_health(health), m_fireRate(fireRate),
      m_bulletMoveStep(bulletMoveStep), m_ammoType(ammoType),
      shipType(shipType),
      QObject{parent} {

    int screenMarginX = 200;
    int aboveScreen = 200;
    //TODO: fix set pos for enemy
//    setPos(
//      rand() % static_cast<int>(scene()->sceneRect().width()) - screenMarginX,
    setPos(screenMarginX, aboveScreen);

    switch (shipType) {
      case settings::ENEMY_SHIP_TYPE::FIGHTER:
        setPixmap(QPixmap(settings::ENEMY_FIGHTER_SHIPS[0]));
        break;
      case settings::ENEMY_SHIP_TYPE::BOMBER:
        setPixmap(QPixmap(settings::ENEMY_BOMBER_SHIPS[1]));
        break;
      case settings::ENEMY_SHIP_TYPE::BOSS:
        setPixmap(QPixmap(settings::ENEMY_BOSS_SHIPS[2]));
        break;
    }

    QTimer *timer = new QTimer();
    connect(timer, SIGNAL(timeout()), this, SLOT(move()));
    connect(timer, SIGNAL(timeout()), this, SLOT(shoot()));
    timer->start(m_fireRate);

  }

  int Enemy::getHealth() {
    return m_health;
  }

  void Enemy::setHealth(int health) {
    this->m_health = health;
  }

  void Enemy::move() {
    // choose m_speed based on ship type
    switch (shipType) {
      case settings::ENEMY_SHIP_TYPE::FIGHTER:
        setPos(x(),
               y() + static_cast<int>(settings::SHIP_SPEEDS::FIGHTER_SPEED));
        break;
      case settings::ENEMY_SHIP_TYPE::BOMBER:
        setPos(x(),
               y() + static_cast<int>(settings::SHIP_SPEEDS::BOMBER_SPEED));
        break;
      case settings::ENEMY_SHIP_TYPE::BOSS:
        setPos(x(),
               y() + static_cast<int>(settings::SHIP_SPEEDS::BOSS_SPEED));
        break;
    }
//    if(pos().y() > scene()->sceneRect().height()){
//        scene()->removeItem(this);
//        this->deleteLater();
//    }
  }


  void Enemy::shoot() {
    int randomNum = rand() % 100 + 1;
    if (randomNum >= 90) {
      // create bullets and add to scene
      Bullet *bullet = new Bullet(settings::BULLET_OWNER::ENEMY,
                                  m_bulletMoveStep,
                                  this);
      int shipsCenterX = x() + pixmap().width() / 2;
      int bulletsCenterX = bullet->pixmap().width() / 2;

      bullet->setPos(shipsCenterX - bulletsCenterX, y());
      scene()->addItem(bullet);
    }
  }
} // namespace metodik_invaders2