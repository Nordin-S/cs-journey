//
// Created by nordi on 2/6/2023.
//

#include "GameMenu.h"
#include "game.h"

namespace metodik_invaders2 {

  GameMenu::GameMenu(QObject *parent) : QGraphicsScene(parent) {}

  void GameMenu::buildMenu() {
    addItem(m_title);
    // loop through buttons list and add them to the scene
    for (auto &button : m_buttons) {
      addItem(button);
    }

    // Determine the scene rect
    QRect sceneRect = this->sceneRect().toRect();

    // Calculate the center of the screen
    qreal centerX = sceneRect.width() / 2;
    qreal centerY = sceneRect.height() / 2;

    // Set the position for each item TODO: make this constant
    int margin = 20;

    int y = centerY - m_title->boundingRect().height();
    m_title->setPos(centerX - m_title->boundingRect().width() / 2, y);

    y += m_title->boundingRect().height();

    // loop through buttons list and set their position
    for (auto &button : m_buttons) {
      button->setPos(centerX - button->boundingRect().width() / 2, y + margin);
      y += button->boundingRect().height();
    }
  }

  void GameMenu::setTitleImg(QString title) {
    // Set the m_title text
    m_title = new QGraphicsPixmapItem(
      QPixmap(title));
  }

  void GameMenu::addButton(MenuButton *button) {
    m_buttons.append(button);
  }

  GameMenu::~GameMenu() {
    delete m_title;
    for (auto &button : m_buttons) {
      delete button;
    }
  }
} // metodik_invaders2