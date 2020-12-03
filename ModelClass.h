//
// Created by danil on 24.11.2020.
//

#ifndef PACMAN_MODELCLASS_H
#define PACMAN_MODELCLASS_H

#include "memory"
#include "Map.h"
#include "Player.h"
#include "RedMonster.h"
#include "ControllerClass.h"
#include "PinkMonster.h"

const int CHASING_TIME = 20;
const int RECESSION_TIME = 7;
const int SCORE_TO_PINK_MONSTER_ACTIVATE = 250;
const int SCORE_TO_BLUE_MONSTER_ACTIVATE = 500;
const int SCORE_TO_GREEN_MONSTER_ACTIVATE = 800;
enum Status {
    EndRound,
    EndGame,
    OnGoing,
};
class ModelClass {
public:
    ModelClass() = default;

    void changeMonstersPosOnMap(Map &map, Point target, Monster::Monster &monster);
    void setStartPlayerPositionOnMap(Map& map, Player& player);
    void setMonsterPositionOnMap(Map &map, Monster::Monster monster);

    bool isCollisionPlayerWithMonster(Player player, Monster::Monster &monster);

    Status
    synchronize(ControllerClass &controller, Map &map, Player &player, std::vector<std::shared_ptr<Monster::Monster>>& monstersList,
                time_t startGame,sf::RenderWindow& window);

    bool isRecession(time_t &startGame);
    void intimidation(Map &map, Player &player, std::vector<std::shared_ptr<Monster::Monster>>& monstersList);
    void endRound(Map& map,Player& player, std::vector<std::shared_ptr<Monster::Monster>>& monstersList,sf::RenderWindow& window);

};


#endif //PACMAN_MODELCLASS_H
