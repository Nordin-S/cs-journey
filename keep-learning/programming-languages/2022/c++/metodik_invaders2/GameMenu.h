//
// Created by nordi on 2/6/2023.
//

#ifndef METODIK_INVADERS2_GAMEMENU_H
#define METODIK_INVADERS2_GAMEMENU_H

#include <QGraphicsScene>
#include "MenuButton.h"

namespace metodik_invaders2 {

  class GameMenu : public QGraphicsScene {
  Q_OBJECT

  public:
    explicit GameMenu(QObject *parent = nullptr);

    void setTitleImg(QString title);

    void addButton(MenuButton *button);

    void buildMenu();

    ~GameMenu();

  private:
    QGraphicsPixmapItem *m_title{};
    QList<MenuButton *> m_buttons;
  };

} // metodik_invaders2
#endif //METODIK_INVADERS2_GAMEMENU_H
