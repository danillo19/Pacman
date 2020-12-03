//
// Created by danil on 20.11.2020.
//

#ifndef PACMAN_CONTROLLERCLASS_H
#define PACMAN_CONTROLLERCLASS_H

#include "Map.h"
#include "Player.h"
#include "vector"

class ControllerClass {
public:
    ControllerClass() = default;

    sf::Keyboard::Key getKey(sf::Window& window);
    void OnLeftKey(Map& map, Player& player);
    void OnRightKey(Map& map, Player& player);
    void OnUpKey(Map& map, Player& player);
    void OnDownKey(Map& map, Player& player);
    void chooseCommand(sf::Keyboard::Key key,Map& map, Player& player,sf::RenderWindow& window);
};


#endif //PACMAN_CONTROLLERCLASS_H
