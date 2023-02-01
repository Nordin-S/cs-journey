#include "GameObject.h"

namespace metodik_invaders2 {
  GameObject::GameObject(int speed, QObject *parent) {

  }

  settings::Faction GameObject::getFaction() {
    return settings::Faction::GameObject;
  }

  void GameObject::setPosition(qreal xPos, qreal yPos) {
    // position based on center of pixmap
    this->setPos(xPos - pixmap().width() / 2,
           yPos - pixmap().height() - pixmap().height() / 2);
  }

  void GameObject::setDirectionX(int xDirection) {
    this->xDirection = xDirection;
  }

  void GameObject::setDirectionY(int yDirection) {
    this->yDirection = yDirection;
  }
} // metodik_invaders2
