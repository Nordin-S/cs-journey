#include "backgroundmusic.h"

#include <QMediaPlayer>
#include <QAudioOutput>
#include <QURL>

namespace metodik_invaders2 {
  BackgroundMusic::BackgroundMusic(QList<QString> filePaths, QObject *parent)
    : m_musicPaths(filePaths), QObject(parent) {
    player = new QMediaPlayer(this);
    player->setSource(QUrl(m_musicPaths[0]));
    audioOutput = new QAudioOutput;
    player->setAudioOutput(audioOutput);
    player->audioOutput()->setVolume(0.25f);
    //TODO: background music douse not seem to loop
    player->setLoops(QMediaPlayer::Infinite);
    // loop the music
    connect(player, &QMediaPlayer::mediaStatusChanged, [this](QMediaPlayer::MediaStatus status) {
      if (status == QMediaPlayer::EndOfMedia) {
        player->play();
      }
    });
    player->play();
  }

  void BackgroundMusic::play() {
    player->play();
  }

  void BackgroundMusic::stop() {
    player->stop();
  }

  void BackgroundMusic::setVolume(int volume) {
    player->audioOutput()->setVolume(volume);
  }

  BackgroundMusic::~BackgroundMusic() {
    delete audioOutput;
    delete player;
  }
} // namespace metodik_invaders2