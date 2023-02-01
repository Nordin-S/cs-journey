#ifndef METODIK_INVADERS2_SETTINGS_H
#define METODIK_INVADERS2_SETTINGS_H

#include <string>
#include <vector>
#include <QList>
#include <QString>
#include <map>
#include <QMap>

namespace metodik_invaders2 {
  namespace settings {
    enum Healths {
      PlayerHealth = 100,
      FighterHealth = 50,
      BomberHealth = 250,
      BossHealth = 500
    };
    enum ShipSpeeds {
      PlayerSpeed = 10, FighterSpeed = 8, BomberSpeed = 6, BossSpeed = 4
    };
    enum UpdateMs {
      UMs01 = 1,
      UMs02 = 2,
      UMs03 = 3,
      UMs04 = 4,
      UMs05 = 5,
      UMs06 = 6,
      UMs07 = 7,
      UMs08 = 8,
      UMs09 = 9,
      UMs10 = 10,
      UMs15 = 15,
      UMs20 = 20,
      UMs25 = 25,
      UMs30 = 30,
      UMs35 = 35,
      UMs40 = 40,
      UMs45 = 45,
      UMs50 = 50,
      UMs60 = 60,
      UMs70 = 70,
      UMs80 = 80,
      UMs90 = 90,
      UMs100 = 100,
      UMs150 = 150,
      UMs200 = 200,
      UMs300 = 300,
    };
    enum MoveSteps {
      Move01 = 1,
      Move02 = 2,
      Move03 = 3,
      Move04 = 4,
      Move05 = 5,
      Move06 = 6,
      Move07 = 7,
      Move08 = 8,
      Move09 = 9,
      Move10 = 10,
      Move11 = 11,
      Move12 = 12,
      Move13 = 13,
      Move14 = 14,
      Move15 = 15,
      Move16 = 16,
      Move17 = 17,
      Move18 = 18,
      Move19 = 19,
      Move20 = 20,
      Move30 = 30,
      Move40 = 40,
      Move50 = 50,
      Move60 = 60,
      Move70 = 70,
      Move80 = 80,
      Move90 = 90,
      Move100 = 100
    };

    enum Faction {
      Player, Enemy, GameObject
    };
    enum AmmoType {
      TypeLaser, TypeMissile
    };
    enum AmmoDmgLvl {
      Dmg01 = 1,
      Dmg02,
      Dmg03,
      Dmg04,
      Dmg05,
      Dmg06,
      Dmg07,
      Dmg08,
      Dmg09,
      Dmg10
    };

    enum EnemyShipType {
      Fighter, Bomber, Boss
    };

    enum ShipTypes {
      // player
      Striker, // NightHawk,  Fury,
      // fighter
      Viper, Enforcer, // Sabre, Avenger, Nemesis,
      //bomber
      Bombardier, // Pummeler, Oblivion, Annihilator,
      //boss
      // Leviathan,
      Behemoth, // Colossus, Titan, Apocalypse
    };

    const std::map<ShipTypes, QString> shipTypes = {
      //playerships
      {Striker,     "striker"},
//      {NightHawk,   "nighthawk"},
//      {Fury,        "fury"},
      // fighter ships
      {Viper,       "viper"},
      {Enforcer,    "enforcer"},
//      {Sabre,       "sabre"},
//      {Avenger,     "avenger"},
//      {Nemesis,     "nemesis"},
      // Bomber ships
      {Bombardier,  "bombardier"},
//      {Pummeler,    "pummeler"},
//      {Oblivion,    "oblivion"},
//      {Annihilator, "annihilator"},
      // Boss ships
//      {Leviathan,   "leviathan"},
      {Behemoth,    "behemoth"},
    };

    enum AnimationStates {
      Cruising,
      Accelerating,
      Decelerating,
      Exploding
    };
    const std::map<AnimationStates, QString> animationStates = {
      {Cruising,     "cruising"},
      {Accelerating, "accelerating"},
      {Decelerating, "decelerating"},
      {Exploding,    "exploding"}
    };

    const QList<QList<QList<bool>>> formations = {
      {
        {0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 1, 1, 1, 1, 1, 0, 0},
        {0, 0, 1, 1, 1, 1, 1, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0}
      },
      {
        {0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 1, 1, 0, 0, 0, 1, 1, 0},
        {0, 1, 1, 1, 1, 1, 1, 1, 0},
        {0, 0, 1, 1, 1, 1, 1, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0}
      },
      {
        {0, 0, 0, 0, 1, 0, 0, 0, 0},
        {0, 0, 0, 0, 1, 0, 0, 0, 0},
        {0, 0, 0, 0, 1, 0, 0, 0, 0},
        {0, 0, 0, 0, 1, 0, 0, 0, 0},
        {0, 0, 0, 0, 1, 0, 0, 0, 0}
      },
      {
        {0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 1, 0, 0, 0, 0},
        {0, 0, 0, 1, 1, 1, 0, 0, 0},
        {0, 0, 0, 0, 1, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0}
      },
      {
        {0, 0, 0, 1, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 1, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 1, 0, 0, 0},
        {0, 0, 0, 0, 1, 0, 0, 0, 0},
        {0, 0, 0, 1, 0, 0, 0, 0, 0}
      },
      {
        {0, 0, 0, 0, 1, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 1, 0, 0, 0},
        {0, 0, 0, 1, 1, 1, 0, 0, 0},
        {0, 0, 0, 0, 0, 1, 0, 0, 0},
        {0, 0, 0, 0, 1, 0, 0, 0, 0}
      },
      {
        {0, 0, 0, 0, 1, 0, 0, 0, 0},
        {0, 0, 0, 1, 1, 1, 0, 0, 0},
        {0, 0, 1, 1, 1, 1, 1, 0, 0},
        {0, 0, 0, 1, 1, 1, 0, 0, 0},
        {0, 0, 0, 0, 1, 0, 0, 0, 0}
      },
      {
        {0, 0, 0, 0, 0, 1, 1, 0, 0},
        {0, 0, 0, 0, 0, 1, 1, 0, 0},
        {0, 0, 0, 0, 1, 1, 0, 0, 0},
        {0, 0, 0, 0, 1, 1, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0}
      },
      {
        {0, 0, 0, 0, 0, 1, 1, 0, 0},
        {0, 0, 0, 0, 1, 1, 0, 0, 0},
        {0, 0, 0, 1, 1, 0, 0, 0, 0},
        {0, 0, 0, 1, 1, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0}
      },
      {
        {0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 1, 1, 0, 0},
        {0, 0, 0, 1, 1, 1, 1, 0, 0},
        {0, 0, 0, 0, 0, 1, 1, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0}
      },
      {
        {0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 1, 1, 0, 0, 0},
        {0, 0, 0, 1, 1, 1, 1, 0, 0},
        {0, 0, 0, 0, 1, 1, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0}
      },
      {
        {0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 1, 1, 0, 0},
        {0, 0, 0, 0, 1, 1, 1, 1, 0},
        {0, 0, 0, 0, 0, 1, 1, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0}
      },
      {
        {1, 1, 1, 0, 0, 0, 1, 1, 1},
        {0, 0, 0, 1, 1, 1, 0, 0, 0},
        {1, 0, 0, 1, 1, 1, 0, 0, 1},
        {0, 1, 0, 1, 1, 1, 0, 1, 0},
        {0, 0, 1, 1, 1, 1, 1, 0, 0}
      },
      {
        {0, 0, 1, 1, 0, 1, 1, 0, 0},
        {0, 1, 0, 1, 1, 1, 0, 1, 0},
        {1, 1, 1, 1, 1, 1, 1, 1, 1},
        {0, 1, 0, 1, 1, 1, 0, 1, 0},
        {0, 0, 1, 1, 0, 1, 1, 0, 0}
      },
      {
        {1, 0, 0, 0, 0, 0, 0, 0, 1},
        {0, 1, 0, 0, 0, 0, 0, 1, 0},
        {0, 0, 1, 0, 0, 0, 1, 0, 0},
        {0, 0, 0, 1, 1, 1, 0, 0, 0},
        {1, 0, 0, 0, 0, 0, 0, 0, 1}
      },
      {
        {0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 1, 0, 0, 0, 0},
        {0, 0, 0, 1, 1, 1, 0, 0, 0},
        {0, 0, 1, 1, 1, 1, 1, 0, 0},
      },
      {
        {0, 0, 0, 0, 1, 0, 0, 0, 0},
        {0, 0, 0, 1, 1, 1, 0, 0, 0},
        {0, 0, 1, 1, 0, 1, 1, 0, 0},
        {0, 1, 1, 0, 1, 0, 1, 1, 0},
        {1, 1, 0, 1, 0, 1, 0, 1, 1},
      },
      {
        {0, 0, 1, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 1, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 1, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 1, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 1, 0, 0},
      },
      {
        {0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 1, 0, 0, 0, 1, 0, 0},
        {0, 1, 0, 1, 0, 1, 0, 1, 0},
        {0, 0, 1, 0, 1, 0, 1, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0},
      },
      {
        {0, 0, 0, 0, 1, 0, 0, 0, 0},
        {0, 0, 1, 1, 0, 1, 1, 0, 0},
        {0, 1, 0, 1, 1, 1, 0, 1, 0},
        {1, 0, 1, 1, 0, 1, 1, 0, 1},
        {0, 1, 0, 1, 1, 1, 0, 1, 0},
      },
    };



    extern const QList<QString> ammoLasers;
    extern const QList<QString> ammoMissiles;

    extern QList<QString>
    getShipAnimation(ShipTypes shipType, AnimationStates animState);
  }; // metodik_invaders2
}
#endif //METODIK_INVADERS2_SETTINGS// _H