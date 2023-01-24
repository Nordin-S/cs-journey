#ifndef METODIK_INVADERS2_BACKGROUNDMUSIC_H
#define METODIK_INVADERS2_BACKGROUNDMUSIC_H

#include <QMediaPlayer>

namespace metodik_invaders2 {
  class BackgroundMusic : public QObject {
  Q_OBJECT
  public:
    BackgroundMusic(QList<QString> bgMusicList, QObject *parent = nullptr);

    ~BackgroundMusic();

  public slots:

    void play();

    void stop();

    void setVolume(int volume);

  private:
    QMediaPlayer *player;
    QAudioOutput *audioOutput;
    QList<QString> m_musicPaths;
  };

} // namespace metodik_invaders2
#endif //METODIK_INVADERS2_BACKGROUNDMUSIC_H