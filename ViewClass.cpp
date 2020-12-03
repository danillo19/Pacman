//
// Created by danil on 20.11.2020.
//

#include "ViewClass.h"
#include <iostream>
#include "RedMonster.h"
#include <unistd.h>
#include <time.h>
#include <cmath>
#include "SFML/Graphics.hpp"

int currentFrame = 0;

struct Wall {
    sf::RectangleShape rectangle;

    Wall(float x, float y) {
        rectangle.setSize(sf::Vector2f(20, 20));
        rectangle.setFillColor(sf::Color::Blue);
        rectangle.setPosition(x, y);
    }
};

struct Energizer {
    sf::Sprite sprite;

    Energizer(float x, float y, const sf::Texture &texture) {
        sprite.setTexture(texture);
        sprite.setTextureRect(sf::IntRect(60, 62, 20, 20));
        sprite.setPosition(x, y);
    }
};

struct Food {
    sf::CircleShape circle;
    float radius = 3;

    Food(float x, float y) {
        circle.setRadius(radius);
        circle.setPointCount(30);
        circle.setFillColor(sf::Color::Magenta);
        circle.setPosition(x, y);
    }
};


void ViewClass::showGame(ControllerClass controller, ModelClass model, Map &map, Player &player,
                         std::vector<std::shared_ptr<Monster::Monster>> &monstersList) {
    sf::RenderWindow window(sf::VideoMode(900, 1080), "PACMAN");

    time_t startGame = clock();
    sf::Vector2i startPos = player.getPosInWindow();
    player.sprite.setPosition(startPos.x, startPos.y);
    for(auto monster: monstersList) {
        sf::Vector2i startMonsterPos = monster->getPosOnWindow();
        monster->setWindowSprite(startMonsterPos);
    }

    while (window.isOpen()) {
        Status gameStatus = model.synchronize(controller, map, player, monstersList, startGame, window);
        if (gameStatus == EndGame) {
            showEndGame(window,player);
            break;
        }
        else if(gameStatus == EndRound) {
            showEndRound(window);
        }

        drawMap(window, map, player, monstersList);
        drawPlayerAnimation(window, map, player, monstersList);
        for(auto monster: monstersList) {
            sf::Vector2i startMonsterPos = monster->getPosOnWindow();
            monster->setWindowSprite(startMonsterPos);
        }
        sf::Vector2i playerPos = player.getPosInWindow();
        player.setSprite(playerPos);
    }
}

void
ViewClass::drawMap(sf::RenderWindow &window, Map &map, Player &player,
                   std::vector<std::shared_ptr<Monster::Monster>> &monstersList) {
    sf::Texture mainTexture;
    mainTexture.loadFromFile("C:/Users/danil/Downloads/sprites.png");

    window.clear();

    for (int i = 0; i < 29; i++) {
        for (int j = 0; j < 31; j++) {
            if (map.getMapElem(i, j) == '#') {
                Wall wall(i * 20, j * 20);

                window.draw(wall.rectangle);
            } else if (map.getMapElem(i, j) == '.') {
                Food food(i * 20 + 10 - food.radius + 1, j * 20 + 10 - food.radius);
                window.draw(food.circle);

            } else if (map.getMapElem(i, j) == 'o') {
                Energizer energizer(i * 20, j * 20, mainTexture);
                window.draw(energizer.sprite);
            }
        }
    }

}

void ViewClass::drawPlayerAnimation(sf::RenderWindow &window, Map &map, Player &player,
                                    std::vector<std::shared_ptr<Monster::Monster>> &monstersList) {

    for (int i = 0; i < 20; i += 1) {
        currentFrame += 1;
        if (currentFrame >= 2) currentFrame -= 2;
        drawMap(window, map, player, monstersList);

        if (player.getPosInWindow().x - player.sprite.getPosition().x > 0) {
            sf::Vector2i newPos = {(int) player.sprite.getPosition().x + 1, (int) player.sprite.getPosition().y};
            player.sprite.setTextureRect(sf::IntRect(int(currentFrame) * 20, 0, 20, 20));
            player.setSprite(newPos);
        } else if (player.getPosInWindow().x - player.sprite.getPosition().x < 0) {
            sf::Vector2i newPos = {(int) player.sprite.getPosition().x - 1, (int) player.sprite.getPosition().y};
            player.sprite.setTextureRect(sf::IntRect(int(currentFrame * 20), 20, 20, 20));
            player.setSprite(newPos);
        } else if (player.getPosInWindow().y - player.sprite.getPosition().y < 0) {
            sf::Vector2i newPos = {(int) player.sprite.getPosition().x, (int) player.sprite.getPosition().y - 1};
            player.sprite.setTextureRect(sf::IntRect((int) currentFrame * 20, 40, 20, 20));
            player.setSprite(newPos);
        } else if (player.getPosInWindow().y - player.sprite.getPosition().y > 0) {
            sf::Vector2i newPos = {(int) player.sprite.getPosition().x, (int) player.sprite.getPosition().y + 1};
            player.sprite.setTextureRect(sf::IntRect((int) currentFrame * 20, 60, 20, 20));
            player.setSprite(newPos);
        }

        for(const auto& monster: monstersList) {
            drawMonsterAnimation(window,map,player,*monster);
            window.draw(monster->getSpriteOnWindow());
        }
        window.draw(player.sprite);
        window.display();
    }
}

void ViewClass::drawMonsterAnimation(sf::RenderWindow &window, Map &map, Player &player, Monster::Monster &moster) {
    moster.currentFrame += 1;
    if(moster.currentFrame >= 2) moster.currentFrame -= 2;

    if (moster.getPosOnWindow().x - moster.windowSprite.getPosition().x > 0) {
        sf::Vector2i newPos = {(int)moster.windowSprite.getPosition().x,(int)moster.windowSprite.getPosition().y};
        moster.windowSprite.setTextureRect(sf::IntRect(20*moster.currentFrame,moster.topOnTexture,20,20));
        newPos.x += 1;
        moster.setWindowSprite(newPos);
    } else if (moster.getPosOnWindow().x - moster.windowSprite.getPosition().x < 0) {
        sf::Vector2i newPos = {(int)moster.windowSprite.getPosition().x,(int)moster.windowSprite.getPosition().y};
        moster.windowSprite.setTextureRect(sf::IntRect(20*moster.currentFrame + 40,moster.topOnTexture,20,20));
        newPos.x -= 1;
        moster.setWindowSprite(newPos);
    } else if (moster.getPosOnWindow().y - moster.windowSprite.getPosition().y > 0) {
        sf::Vector2i newPos = {(int)moster.windowSprite.getPosition().x,(int)moster.windowSprite.getPosition().y};
        moster.windowSprite.setTextureRect(sf::IntRect(20*moster.currentFrame + 120,moster.topOnTexture,20,20));
        newPos.y += 1;
        moster.setWindowSprite(newPos);
    } else if (moster.getPosOnWindow().y - moster.windowSprite.getPosition().y < 0) {
        sf::Vector2i newPos = {(int)moster.windowSprite.getPosition().x,(int)moster.windowSprite.getPosition().y};
        moster.windowSprite.setTextureRect(sf::IntRect(20*moster.currentFrame + 80,moster.topOnTexture,20,20));
        newPos.y -= 1;
        moster.setWindowSprite(newPos);
    }

}

void ViewClass::showEndRound(sf::RenderWindow &window) {
    sf::Text text;
    sf::Font font;
    font.loadFromFile("C:/Users/danil/Downloads/arial/arial.ttf");
    text.setFont(font);
    text.setString("READY?");
    text.setCharacterSize(24);
    text.setFillColor(sf::Color::Cyan);
    text.setPosition(240,220);
    window.draw(text);
    window.display();

    sleep(1);
    text.setString("GO!!!");
    text.setFillColor(sf::Color::Green);
    text.setPosition(260,220);
    window.draw(text);
    window.display();
    sleep(1);
}

void ViewClass::showEndGame(sf::RenderWindow &window, Player &player) {
    sf::Text text;
    sf::Font font;
    font.loadFromFile("C:/Users/danil/Downloads/arial/arial.ttf");
    text.setFont(font);
    text.setString("YOU LOSE :)");
    text.setCharacterSize(24);
    text.setFillColor(sf::Color(127,255,0));
    text.setPosition(200,220);
    window.draw(text);
    window.display();
    sleep(1);

    std::string scoreString = "YOUR SCORE: " + std::to_string(player.getScore());
    text.setString(scoreString);
    text.setFillColor(sf::Color(255,165,0));
    window.draw(text);
    window.display();
    sleep(1);
}
