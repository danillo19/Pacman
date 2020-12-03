//
// Created by danil on 20.11.2020.
//

#ifndef PACMAN_VIEWCLASS_H
#define PACMAN_VIEWCLASS_H

#include "ControllerClass.h"
#include "Map.h"
#include "ModelClass.h"
#include "memory"
class ViewClass {

public:
   void drawMap(sf::RenderWindow& window,Map& map,Player& player, std::vector<std::shared_ptr<Monster::Monster>>& monstersList);
   void showGame(ControllerClass controller,ModelClass model,Map& map, Player& player, std::vector<std::shared_ptr<Monster::Monster>>& monstersList);
   void drawPlayerAnimation(sf::RenderWindow& window,Map& map, Player& player, std::vector<std::shared_ptr<Monster::Monster>>& monstersList);
   void drawMonsterAnimation(sf::RenderWindow& window, Map& map, Player& player, Monster::Monster& monster);
   void  showEndRound(sf::RenderWindow& window);
   void showEndGame(sf::RenderWindow &window, Player &player);


};



#endif //PACMAN_VIEWCLASS_H
