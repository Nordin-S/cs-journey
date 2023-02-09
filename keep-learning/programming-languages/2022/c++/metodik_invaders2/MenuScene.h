//
// Created by nordi on 2/6/2023.
//

#ifndef METODIK_INVADERS2_MENUSCENE_H
#define METODIK_INVADERS2_MENUSCENE_H

#include <QGraphicsScene>
#include "MenuButton.h"
#include "background.h"
#include "SceneMaker.h"

namespace metodik_invaders2 {
  class MenuScene : public SceneMaker {
  Q_OBJECT
  public:
    explicit MenuScene(QObject *parent = nullptr);

    void setTitleImg(QString title);

    void addButton(MenuButton *button);

    void buildScene() override;

    void activate() override;

    void deactivate() override;

    ~MenuScene() override;

  private:
    QGraphicsPixmapItem *m_title{};
    QList<MenuButton *> m_buttons;
  };
} // metodik_invaders2
#endif //METODIK_INVADERS2_MENUSCENE_H
