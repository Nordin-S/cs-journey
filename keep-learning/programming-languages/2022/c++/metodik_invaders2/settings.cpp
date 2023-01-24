#include "settings.h"

namespace metodik_invaders2 {
  namespace settings {
    extern QList<QString> PLAYER_SHIP = {
      ":/resources/playerships/playerShip1_red.png"};

    extern QList<QString> LASER_S = {":/resources/lasers/laserBlue05.png",
                                     ":/resources/lasers/laserGreen05.png",
                                     ":/resources/lasers/laserRed05.png"};
    extern QList<QString> LASER_M = {":/resources/lasers/laserBlue06.png"};
    extern QList<QString> LASER_L = {":/resources/lasers/laserBlue07.png"};

    extern QList<QString> MISSILE_S = {":/resources/lasers/laserBlue08.png"};
    extern QList<QString> MISSILE_M = {":/resources/lasers/laserBlue09.png"};
    extern QList<QString> MISSILE_L = {":/resources/lasers/laserBlue10.png"};


    extern QList<QString> ENEMY_FIGHTER_SHIPS = {
      ":/resources/enemies/enemyBlack1.png",
      ":/resources/enemies/enemyBlack2.png",
      ":/resources/enemies/enemyBlack3.png",
      ":/resources/enemies/enemyBlue1.png",
      ":/resources/enemies/enemyBlue2.png",
      ":/resources/enemies/enemyBlue3.png"};
    extern QList<QString> ENEMY_BOMBER_SHIPS = {
      ":/resources/enemies/enemyGreen1.png"};
    extern QList<QString> ENEMY_BOSS_SHIPS = {
      ":/resources/enemies/enemyRed1.png"};
  }
}
