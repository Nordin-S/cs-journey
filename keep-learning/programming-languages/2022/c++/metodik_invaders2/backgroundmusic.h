#ifndef METODIK_INVADERS2_BACKGROUNDMUSIC_H
#define METODIK_INVADERS2_BACKGROUNDMUSIC_H

#include <QMediaPlayer>

namespace metodik_invaders2 {
  class BackgroundMusic : public QObject {
  Q_OBJECT
  public:
    explicit BackgroundMusic(QObject *parent = nullptr);

    ~BackgroundMusic();

  public slots:

    void play();

    void stop();

    void setVolume(int volume);

    void setMusicPath(QString songPath);

  private:
    QMediaPlayer *player;
    QAudioOutput *audioOutput;
    QString m_songPath;
  };

} // namespace metodik_invaders2
#endif //METODIK_INVADERS2_BACKGROUNDMUSIC_H