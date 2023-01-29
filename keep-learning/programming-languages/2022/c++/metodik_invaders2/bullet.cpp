#include <QTimer>
#include <QGraphicsScene>
#include "bullet.h"

namespace metodik_invaders2 {
  Bullet::Bullet(settings::Faction ownerType, int bMoveStep,
                 settings::AmmoType ammoType,
                 settings::AmmoDmgLvl dmgLevel,
                 QObject *parent)
    : myOwnersType(ownerType), m_bMoveStep(bMoveStep), m_ammoType(ammoType),
      QObject{parent} {

    if (m_ammoType == settings::AmmoType::TypeLaser)
      setPixmap(QPixmap(settings::ammoLasers[rand() % settings::ammoLasers.size()]));
    if (m_ammoType == settings::AmmoType::TypeMissile)//TODO: add missile
      setPixmap(QPixmap(settings::ammoMissiles[rand() % settings::ammoMissiles.size()]));

    QTimer *timer = new QTimer();
    connect(timer, SIGNAL(timeout()), this, SLOT(move()));
    timer->start(bMoveStep / 4);
  }

  settings::Faction Bullet::getOwner() {
    return myOwnersType;
  }

  void Bullet::move() {
    // player bullet
    if (myOwnersType == settings::Faction::Player)
      setPos(x(), y() - m_bMoveStep);

    // enemy bullet
    if (myOwnersType == settings::Faction::Enemy)
      setPos(x(), y() + m_bMoveStep);

//    if(pos().y() + pixmap().height() < parentObject()->boundingRect().top() || pos().y() > parentObject()->boundingRect().height()){
////        scene()->removeItem(this);
//        qDebug() << "test";
//        this->deleteLater();
//    }

//    if (y() < 0 || y() > 1000) {
////        scene()->removeItem(this);
//        this->deleteLater();
//    }
  }

} // metodik_invaders2