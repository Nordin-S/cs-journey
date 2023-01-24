#include <QTimer>
#include <QGraphicsScene>

#include "bullet.h"

namespace metodik_invaders2 {
  Bullet::Bullet(settings::BULLET_OWNER ownerType, int bMoveStep,
                 QObject *parent)
    : myOwnersType(ownerType), m_bMoveStep(bMoveStep), QObject{parent} {
    setPixmap(QPixmap(":/resources/lasers/laserBlue05.png"));

    QTimer *timer = new QTimer();
    connect(timer, SIGNAL(timeout()), this, SLOT(move()));
    timer->start(bMoveStep);

  }

  settings::BULLET_OWNER Bullet::getOwner() {
    return myOwnersType;
  }

  void Bullet::move() {
    // player bullet
    if (myOwnersType == settings::BULLET_OWNER::PLAYER)
      setPos(x(), y() - static_cast<int>(settings::MOVE_STEPS::MOVE05));

    // enemy bullet
    if (myOwnersType == settings::BULLET_OWNER::ENEMY)
      setPos(x(), y() + static_cast<int>(settings::MOVE_STEPS::MOVE03));

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