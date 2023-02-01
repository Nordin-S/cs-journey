//
// Created by nordi on 1/29/2023.
//

#ifndef METODIK_INVADERS2_GAMEOBJECT_H
#define METODIK_INVADERS2_GAMEOBJECT_H

#include <QObject>
#include <QGraphicsPixmapItem>
#include "settings.h"

namespace metodik_invaders2 {
  class GameObject : public QObject, public QGraphicsPixmapItem {
  Q_OBJECT
  public:
    explicit GameObject(int speed = 0, QObject *parent = nullptr);

    ~GameObject() override = default;

    virtual settings::Faction getFaction();

    virtual void setPosition(qreal xPos, qreal yPos);

    virtual void setDirectionX(int xDirection);

    virtual void setDirectionY(int yDirection);

  protected:
    int m_speed;
    int xDirection = 0;
    int yDirection = 0;
    QTimer *updateTimer;

  public slots:

    virtual void move() = 0;

    virtual void updatePosition() = 0;

    virtual void checkCollision() = 0;

  signals:
  };


} // metodik_invaders2

#endif //METODIK_INVADERS2_GAMEOBJECT_H
