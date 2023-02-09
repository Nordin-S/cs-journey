//
// Created by nordi on 2/9/2023.
//

#ifndef METODIK_INVADERS2_SCENEMAKER_H
#define METODIK_INVADERS2_SCENEMAKER_H

#include <QGraphicsScene>
#include "background.h"

namespace metodik_invaders2 {

  class SceneMaker : public QGraphicsScene {
      Q_OBJECT
  public:
    explicit SceneMaker(QObject *parent = nullptr) : QGraphicsScene(parent) {}

    virtual void addBackground(Background *background) {
      m_backgrounds.append(background);
      for (auto &instance : background->getInstances()) {
        addItem(instance);
      }
    }

    virtual void buildScene() = 0;

    virtual void activate() {
      for (auto &background : m_backgrounds) {
        background->startTimer();
      }
    }
    virtual void deactivate() {
      for (auto &background : m_backgrounds) {
        background->stopTimer();
      }
    }

    ~SceneMaker() override {
      for (auto &background : m_backgrounds) {
        delete background;
      }
    }

  protected:
    QList<Background *> m_backgrounds;
  };

} // metodik_invaders2

#endif //METODIK_INVADERS2_SCENEMAKER_H
