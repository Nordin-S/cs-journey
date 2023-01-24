#ifndef METODIK_INVADERS2_SETTINGS_H
#define METODIK_INVADERS2_SETTINGS_H

#include <string>
#include <vector>
#include <QList>
#include <QString>

namespace metodik_invaders2 {
  namespace settings {
    enum class HEALTHS {
      PLAYER_HEALTH = 100,
      FIGTHER_HEALTH = 50,
      BOMBER_HEALTH = 250,
      BOSS_HEALTH = 500
    };
    enum class SHIP_SPEEDS {
      PLAYER_SPEED = 60, FIGHTER_SPEED = 20, BOMBER_SPEED = 10, BOSS_SPEED = 10
    };
    enum class UPDATE_MS {
      uMS01 = 1,
      uMS02 = 2,
      uMS03 = 3,
      uMS04 = 4,
      uMS05 = 5,
      uMS06 = 6,
      uMS07 = 7,
      uMS08 = 8,
      uMS09 = 9,
      uMS10 = 10,
      uMS15 = 15,
      uMS20 = 20,
      uMS25 = 25,
      uMS30 = 30,
      uMS35 = 35,
      uMS40 = 40,
      uMS45 = 45,
      uMS50 = 50
    };

    enum class BULLET_OWNER {
      PLAYER, ENEMY
    };
    enum class MOVE_STEPS {
      MOVE01 = 1,
      MOVE02 = 2,
      MOVE03 = 3,
      MOVE04 = 4,
      MOVE05 = 5,
      MOVE06 = 6,
      MOVE07 = 7,
      MOVE08 = 8,
      MOVE09 = 9,
      MOVE10 = 10,
      MOVE11 = 11,
      MOVE12 = 12,
      MOVE13 = 13,
      MOVE14 = 14,
      MOVE15 = 15,
      MOVE16 = 16,
      MOVE17 = 17,
      MOVE18 = 18,
      MOVE19 = 19,
      MOVE20 = 20
    };
    enum class AMMO_TYPE {
      LASER_SMALL, LASER_MEDIUM, LASER_LARGE,
      MISSILE_SMALL, MISSILE_MEDIUM, MISSILE_LARGE
    };
    enum class ENEMY_SHIP_TYPE {
      FIGHTER, BOMBER, BOSS
    };


    extern QList<QString> PLAYER_SHIP;

    extern QList<QString> LASER_S;
    extern QList<QString> LASER_M;
    extern QList<QString> LASER_L;

    extern QList<QString> MISSILE_S;
    extern QList<QString> MISSILE_M;
    extern QList<QString> MISSILE_L;


    extern QList<QString> ENEMY_FIGHTER_SHIPS;
    extern QList<QString> ENEMY_BOMBER_SHIPS;
    extern QList<QString> ENEMY_BOSS_SHIPS;

//    void savePlayerScore(std::string gameTime, std::string score,
//                         std::string playerName) {
//      // save to file row depending on score
//    }
//
//    std::vector<std::string>
//    getPlayerScore(std::string gameTime, std::string score,
//                   std::string playerName) {
//      // read and return score file
//      return {};
//    }
  } // metodik_invaders2
}
#endif //METODIK_INVADERS2_SETTINGS// _H