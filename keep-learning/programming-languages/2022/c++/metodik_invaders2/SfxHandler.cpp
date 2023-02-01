//
// Created by nordi on 1/30/2023.
//

#include "SfxHandler.h"
#include <QList>
#include <QMediaPlayer>
#include <QUrl>
#include <QDebug>


namespace metodik_invaders2 {

  SfxHandler::SfxHandler() {
  }

  SfxHandler::~SfxHandler() {
    for (auto sound: m_sounds)
      delete sound;
  }

  void SfxHandler::playSound(const QString &soundFilePath) {
    auto *sound = new QMediaPlayer(this);
    // QSoundEffect set source
    sound->setSource(QUrl::fromLocalFile(soundFilePath));
    auto *audioOutput = new QAudioOutput;
    sound->setAudioOutput(audioOutput);
    sound->audioOutput()->setVolume(0.55f);
    m_sounds.append(sound);
    connect(sound, &QMediaPlayer::playbackStateChanged, [sound, audioOutput, this](QMediaPlayer::PlaybackState state) {
      if (state == QMediaPlayer::StoppedState) {
        sound->deleteLater();
        audioOutput->deleteLater();
        m_sounds.removeOne(sound);
      }});
    sound->play();
  }
} // metodik_invaders2