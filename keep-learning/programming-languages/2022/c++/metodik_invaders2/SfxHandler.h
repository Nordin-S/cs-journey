//
// Created by nordi on 1/30/2023.
//
#ifndef METODIK_INVADERS2_SFXHANDLER_H
#define METODIK_INVADERS2_SFXHANDLER_H

#include <QList>
#include <QMediaPlayer>
#include <QAudioOutput>
#include <QUrl>
#include <QObject>

namespace metodik_invaders2 {
  class SfxHandler : public QObject {
  Q_OBJECT

  public:
    SfxHandler();

    ~SfxHandler();

    void playSound(const QString &soundFilePath);

  private:
//    QAudioOutput *audioOutput;
    QList<QMediaPlayer *> m_sounds;

  signals:

    void bulletFired();

    void bulletHit();

    void explosion();

    void miscSFX();

  public slots:
    void handleBulletFired() { playSound("qrc:/resources/sfx/sfx_laser1.wav"); }
    void handleBulletHit() {
    QString random = QString::number(rand() % 3 + 1);
    QString path = "qrc:/resources/sfx/sfx_hit0" + random + ".wav";
    playSound(path);
  }
    void handleExplosion() {
      QString random = QString::number(rand() % 3 + 1);
      QString path = "qrc:/resources/sfx/sfx_explosion0" + random + ".wav";
    playSound(path);
  }
    //TODO: add more sfx
    void handleMiscSFX() { playSound("qrc:/resources/sfx/sfx_laser1.wav"); }
  };


} // metodik_invaders2

#endif //METODIK_INVADERS2_SFXHANDLER_H
