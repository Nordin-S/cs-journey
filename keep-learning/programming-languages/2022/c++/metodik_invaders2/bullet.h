#ifndef METODIK_INVADERS2_BULLET_H
#define METODIK_INVADERS2_BULLET_H


#include <QGraphicsPixmapItem>
#include <QObject>
#include "settings.h"

namespace metodik_invaders2 {
  class Bullet : public QObject, public QGraphicsPixmapItem {
  Q_OBJECT
  public:
    Bullet(settings::BULLET_OWNER ownerType = settings::BULLET_OWNER::PLAYER,
           int bMoveStep = static_cast<int>(settings::MOVE_STEPS::MOVE02),
           QObject *parent = nullptr);

    ~Bullet() = default;

    settings::BULLET_OWNER getOwner();

  private:
    settings::BULLET_OWNER myOwnersType;
    int m_bMoveStep;
  private slots:

    void move();

  signals:

  };

} // namespace metodik_invaders2
#endif //METODIK_INVADERS2_BULLET_H