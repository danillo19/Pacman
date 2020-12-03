//
// Created by danil on 24.11.2020.
//

#include "ModelClass.h"

#include <iostream>
#include <unistd.h>
#include <ctime>
#include <vector>

time_t startIntimidationTime = 0;

void ModelClass::setStartPlayerPositionOnMap(Map &map, Player &player) {
    Point start = player.getStartPoint();
    player.setPlayerPoint(start);
    map.changePoint(player.getStartPoint().x, player.getStartPoint().y, 'V');
}

void ModelClass::setMonsterPositionOnMap(Map &map, Monster::Monster monster) {
    map.changePoint(monster.getMonsterPos().x, monster.getMonsterPos().y, monster.getSprite());
}

void ModelClass::changeMonstersPosOnMap(Map &map, Point target, Monster::Monster &monster) {
    map.changePoint(monster.getMonsterPos().x, monster.getMonsterPos().y, monster.getClosedMapItem());
    monster.move(target, map);
    monster.setClosedMapItem(map, monster.getMonsterPos());
    map.changePoint(monster.getMonsterPos().x, monster.getMonsterPos().y, monster.getSprite());
}

bool ModelClass::isCollisionPlayerWithMonster(Player player, Monster::Monster &monster) {
    return (player.getPlayerPoint().x == monster.getMonsterPos().x) &&
           (player.getPlayerPoint().y == monster.getMonsterPos().y);
}


Status
ModelClass::synchronize(ControllerClass &controller, Map &map, Player &player,
                        std::vector<std::shared_ptr<Monster::Monster>> &monstersList,
                        time_t startGame, sf::RenderWindow &window) {

    sf::Keyboard::Key key = controller.getKey(window);
    controller.chooseCommand(key, map, player, window);
    window.draw(player.sprite);
    if (player.isIntimidation()) {
        if (startIntimidationTime == 0)
            startIntimidationTime = clock();
        intimidation(map, player, monstersList);
        return OnGoing;
    }

    if (player.getScore() > SCORE_TO_PINK_MONSTER_ACTIVATE) monstersList[1]->makeActive();
    if (player.getScore() > SCORE_TO_BLUE_MONSTER_ACTIVATE) monstersList[2]->makeActive();
    if (player.getScore() > SCORE_TO_GREEN_MONSTER_ACTIVATE) monstersList[3]->makeActive();

    for (const auto &monster: monstersList) {
        if (this->isCollisionPlayerWithMonster(player, *monster)) {
            if (player.getHealth() == 0)
                return EndGame;
            else {
                endRound(map, player, monstersList, window);
                return EndRound;
            }
        }

        if (monster->isActive()) {
            if (isRecession(startGame))
                changeMonstersPosOnMap(map, monster->getRecessionPoint(), *monster);
            else
                changeMonstersPosOnMap(map, monster->getChasedTarget(player, monstersList[0]->getMonsterPos()),
                                       *monster);
        }

        if (this->isCollisionPlayerWithMonster(player, *monster)) {
            if (player.getHealth() == 0)
                return EndGame;
            else {
                endRound(map, player, monstersList, window);
                return EndRound;
            }
        }
    }
    return OnGoing;
}

bool ModelClass::isRecession(time_t &startGame) {
    time_t time = (clock() - startGame) / CLOCKS_PER_SEC;
    return time % (RECESSION_TIME + CHASING_TIME) > CHASING_TIME;
}


void ModelClass::intimidation(Map &map, Player &player, std::vector<std::shared_ptr<Monster::Monster>> &monstersList) {
    for (const auto &monster: monstersList) {
        if (isCollisionPlayerWithMonster(player, *monster)) {
            player.increaseScore(100);
            monster->reset();
            setMonsterPositionOnMap(map, *monster);
        }
    }
    if (((clock() - startIntimidationTime) / CLOCKS_PER_SEC) >= 4) {
        player.setIntimidation(false);
        startIntimidationTime = 0;
    }

}

void ModelClass::endRound(Map &map, Player &player, std::vector<std::shared_ptr<Monster::Monster>> &monstersList,
                          sf::RenderWindow &window) {
    player.decreaseHealth();
    map.changePoint(player.getPlayerPoint().x, player.getPlayerPoint().y, ' ');
    setStartPlayerPositionOnMap(map, player);

    sf::Vector2i playerStartPos = {player.getStartPoint().x * 20, player.getStartPoint().y * 20};
    player.setSprite(playerStartPos);

    for (const auto &monster: monstersList) {
        if (monster->isActive())
            map.changePoint(monster->getMonsterPos().x, monster->getMonsterPos().y, ' ');
        monster->reset();
    }
}

