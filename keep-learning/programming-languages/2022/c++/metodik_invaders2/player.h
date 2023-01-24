#ifndef METODIK_INVADERS2_PLAYER_H
#define METODIK_INVADERS2_PLAYER_H


#include <QGraphicsPixmapItem>
#include <QObject>
#include <QPropertyAnimation>
#include <QGraphicsScene>
#include "settings.h"

namespace metodik_invaders2 {
  class Player : public QObject, public QGraphicsPixmapItem {
  Q_OBJECT
    Q_PROPERTY(QPointF pos READ pos WRITE setPos)
  public:
    Player(int speed = static_cast<int>(settings::SHIP_SPEEDS::PLAYER_SPEED),
           int health = static_cast<int>(settings::HEALTHS::PLAYER_HEALTH),
           int fireRate = static_cast<int>(settings::UPDATE_MS::uMS01),
           int bulletMoveStep = static_cast<int>(settings::MOVE_STEPS::MOVE01),
           settings::AMMO_TYPE ammoType = settings::AMMO_TYPE::LASER_SMALL,
           QString playerShip = settings::PLAYER_SHIP[0], QObject *parent = nullptr);

//    bool event(QEvent *event) override;
//    void keyPressEvent(QKeyEvent * event) override;
    void setPosition(qreal xPos, qreal yPos);

    void startShooting();

    void stopShooting();

    void stop();

  private:
    QPropertyAnimation *animation;
    settings::AMMO_TYPE m_ammoType;
    QTimer *moveTimer;
    QTimer *shootTimer;
//    QList<Bullet*> bullets;
    int m_speed;
    int m_health;
    int m_fireRate;
    int m_bulletMoveStep;
    bool isShooting = false;
    bool isMovingLeft = false;
    bool isMovingRight = false;

  public slots:

    void checkCollision();

    void move();

    void moveLeft();

    void moveRight();

    void stopMoveLeft();

    void stopMoveRight();

    void shoot();

    void update();

  signals:

  };

} // namespace metodik_invaders2
#endif //METODIK_INVADERS2_PLAYER_H
