//
// Created by nordi on 2/6/2023.
//

#include "InputHandler.h"

namespace metodik_invaders2 {
  InputHandler::InputHandler(QObject *parent) : QObject(parent) {}

  void InputHandler::keyPressEvent(QKeyEvent *event) {
    if (event->key() == Qt::Key_Left) {
//      player->setDirectionX(-1);
      emit moveLeftDown();
    }
    if (event->key() == Qt::Key_Right) {
//      player->setDirectionX(1);
      emit moveRightDown();
    }
    if (event->key() == Qt::Key_Up) {
//      player->setDirectionY(-1);
      emit moveUpDown();
    }
    if (event->key() == Qt::Key_Down) {
//      player->setDirectionY(1);
      emit moveDownDown();
    }
    if (event->key() == Qt::Key_Space) {
//      player->startShooting();
      emit shootDown();
    }
  }

  void InputHandler::keyReleaseEvent(QKeyEvent *event) {
    if (event->key() == Qt::Key_Space) {
//      player->stopShooting();
      emit shootUp();
    }
    if (event->key() == Qt::Key_Left) {
//      player->setDirectionX(0);
      emit moveLeftUp();
    }
    if (event->key() == Qt::Key_Right) {
//      player->setDirectionX(0);
      emit moveRightUp();
    }
    if (event->key() == Qt::Key_Up) {
//      player->setDirectionY(0);
      emit moveUpUp();
    }
    if (event->key() == Qt::Key_Down) {
//      player->setDirectionY(0);
      emit moveDownUp();
    }
    if (event->key() == Qt::Key_Escape) {
      emit pausePressed();
    }
  }
} // metodik_invaders2