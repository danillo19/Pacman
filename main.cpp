#include <iostream>
#include "Map.h"
#include "ControllerClass.h"
#include "ViewClass.h"
#include "ModelClass.h"
#include "BlueMonster.h"
#include "OrangeMonster.h"
#include "memory"
#include <vector>

int main() {
    Map map;
    map.initMap();
    sf::Texture texture;
    texture.loadFromFile("C:/Users/danil/Downloads/sprites.png");
    Player player(texture);

    std::shared_ptr<Monster::Monster> Binky(new RedMonster(texture));
    std::shared_ptr<Monster::Monster> Pinky(new PinkMonster(texture));
    std::shared_ptr<Monster::Monster> Inky(new BlueMonster(texture));
    std::shared_ptr<Monster::Monster> Clyde(new OrangeMonster(texture));

    std::vector<std::shared_ptr<Monster::Monster>> monstersList;
    monstersList.emplace_back(Binky);
    monstersList.emplace_back(Pinky);
    monstersList.emplace_back(Inky);
    monstersList.emplace_back(Clyde);

    ModelClass model;

    model.setStartPlayerPositionOnMap(map, player);
    for (const auto &monster: monstersList) {
        model.setMonsterPositionOnMap(map, *monster);
    }

    ViewClass view;
    ControllerClass controller;

    view.showGame(controller, model, map, player, monstersList);
    return EXIT_SUCCESS;
}
