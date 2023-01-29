#include <QTimer>
#include <QGraphicsScene>

#include "enemy.h"
#include "bullet.h"

namespace metodik_invaders2 {
  Enemy::Enemy(int speed, int health, int fireRate, int bulletMoveStep,
               settings::AmmoType ammoType,
               settings::AmmoDmgLvl dmgLevel,
               settings::EnemyShipType shipType, QObject *parent)
    : m_speed(speed), m_health(health), m_fireRate(fireRate),
      m_bulletMoveStep(bulletMoveStep), m_ammoType(ammoType), m_dmgLevel(dmgLevel),
      shipType(shipType),
      QObject{parent} {

    int screenMarginX = 400;
    int aboveScreen = 200;
    //TODO: fix set pos for enemy
//    setPos(
//      rand() % static_cast<int>(scene()->sceneRect().width()) - screenMarginX,
    setPos(screenMarginX, aboveScreen);

//    switch (shipType) {
//      case settings::EnemyShipType::Fighter:
//        setPixmap(QPixmap(settings::fighterShips[0]));
//        break;
//      case settings::EnemyShipType::Bomber:
//        setPixmap(QPixmap(settings::bomberShips[1]));
//        break;
//      case settings::EnemyShipType::Boss:
//        setPixmap(QPixmap(settings::BossShips[2]));
//        break;
//    }

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
      case settings::EnemyShipType::Fighter:
        setPos(x(),
               y() + static_cast<int>(settings::ShipSpeeds::FighterSpeed));
        break;
      case settings::EnemyShipType::Bomber:
        setPos(x(),
               y() + static_cast<int>(settings::ShipSpeeds::BomberSpeed));
        break;
      case settings::EnemyShipType::Boss:
        setPos(x(),
               y() + static_cast<int>(settings::ShipSpeeds::BossSpeed));
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
      Bullet *bullet = new Bullet(settings::Faction::Enemy,
                                  m_bulletMoveStep,
                                  m_ammoType,
                                  m_dmgLevel,
                                  this);
      int shipsCenterX = x() + pixmap().width() / 2;
      int bulletsCenterX = bullet->pixmap().width() / 2;

      bullet->setPos(shipsCenterX - bulletsCenterX, y());
      scene()->addItem(bullet);
    }
  }
} // namespace metodik_invaders2