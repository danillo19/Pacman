//
// Created by danil on 20.11.2020.
//

#include "ControllerClass.h"
#include <conio.h>
#include <ctime>

//float currentFrame = 1;


void ControllerClass::OnLeftKey(Map &map, Player &player) {
    if (map.getMapElem(player.getPlayerPoint().x - 1, player.getPlayerPoint().y) != '#') {
        map.changePoint(player.getPlayerPoint().x, player.getPlayerPoint().y, ' ');
        player.goLeft();
        if (map.getMapElem(player.getPlayerPoint().x, player.getPlayerPoint().y) == '.') player.increaseScore(10);
        if (map.getMapElem(player.getPlayerPoint().x, player.getPlayerPoint().y) == 'o') {
            player.setIntimidation(true);
            player.increaseScore(50);
        }
        map.changePoint(player.getPlayerPoint().x, player.getPlayerPoint().y, '<');
        player.setDirection(Left);
    }
}

void ControllerClass::OnRightKey(Map &map, Player &player) {
    if (map.getMapElem(player.getPlayerPoint().x + 1, player.getPlayerPoint().y) != '#') {

        map.changePoint(player.getPlayerPoint().x, player.getPlayerPoint().y, ' ');
        player.goRight();
        if (map.getMapElem(player.getPlayerPoint().x, player.getPlayerPoint().y) == '.') player.increaseScore(10);
        if (map.getMapElem(player.getPlayerPoint().x, player.getPlayerPoint().y) == 'o') {
            player.setIntimidation(true);
            player.increaseScore(50);
        }
        map.changePoint(player.getPlayerPoint().x, player.getPlayerPoint().y, '>');
        player.setDirection(Right);
    }
}

void ControllerClass::OnUpKey(Map &map, Player &player) {
    if (map.getMapElem(player.getPlayerPoint().x, player.getPlayerPoint().y - 1) != '#') {

        map.changePoint(player.getPlayerPoint().x, player.getPlayerPoint().y, ' ');
        player.goUp();
        if (map.getMapElem(player.getPlayerPoint().x, player.getPlayerPoint().y) == '.') player.increaseScore(10);
        if (map.getMapElem(player.getPlayerPoint().x, player.getPlayerPoint().y) == 'o') {
            player.setIntimidation(true);
            player.increaseScore(50);
        }
        map.changePoint(player.getPlayerPoint().x, player.getPlayerPoint().y, '^');
        player.setDirection(Up);
    }
}

void ControllerClass::OnDownKey(Map &map, Player &player) {
    if (map.getMapElem(player.getPlayerPoint().x, player.getPlayerPoint().y + 1) != '#') {

        map.changePoint(player.getPlayerPoint().x, player.getPlayerPoint().y, ' ');
        player.goDown();
        if (map.getMapElem(player.getPlayerPoint().x, player.getPlayerPoint().y) == '.') player.increaseScore(10);
        if (map.getMapElem(player.getPlayerPoint().x, player.getPlayerPoint().y) == 'o') {
            player.setIntimidation(true);
            player.increaseScore(50);
        }
        map.changePoint(player.getPlayerPoint().x, player.getPlayerPoint().y, 'V');
        player.setDirection(Down);
    }
}

sf::Keyboard::Key ControllerClass::getKey(sf::Window &window) {
    sf::Clock time;
    sf::Event event;
    while (time.getElapsedTime().asSeconds() < 0.3) {
        if (window.pollEvent(event)) {
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) return sf::Keyboard::Right;
            else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) return sf::Keyboard::Left;
            else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) return sf::Keyboard::Up;
            else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) return sf::Keyboard::Down;

            if (event.type == sf::Event::Closed) window.close();

        }
    }

    return sf::Keyboard::Unknown;
}

void ControllerClass::chooseCommand(sf::Keyboard::Key key, Map &map, Player &player, sf::RenderWindow &window) {


    if (key == sf::Keyboard::Key::Left ||
        (key == sf::Keyboard::Key::Unknown && player.getDirection() == Left)) {


        this->OnLeftKey(map, player);
    } else if (key == sf::Keyboard::Key::Right ||
               (key == sf::Keyboard::Key::Unknown && player.getDirection() == Right)) {
        this->OnRightKey(map, player);
    } else if (key == sf::Keyboard::Key::Up ||
               (key == sf::Keyboard::Key::Unknown && player.getDirection() == Up)) {
        this->OnUpKey(map, player);
    } else if (key == sf::Keyboard::Key::Down ||
               (key == sf::Keyboard::Key::Unknown && player.getDirection() == Down)) {
        this->OnDownKey(map, player);
    }

}


