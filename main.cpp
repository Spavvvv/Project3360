//#include <SFML/Graphics.hpp>
//#include <vector>
//#include <cstdlib> // For rand()
//#include <ctime>   // For seeding rand()
//#include <iostream> // For debugging
//#include "Enemy.h"  // Include your Enemy class

//int main() {
//    // Initialize random seed
//    std::srand(static_cast<unsigned>(std::time(nullptr)));
//
//    // Create a window
//    sf::RenderWindow window(sf::VideoMode(1400, 1000), "Enemy Test with Random Textures", sf::Style::Close);
//    window.setFramerateLimit(60);
//
//    // Load textures for enemies
//    std::map<sf::String, sf::Texture*> enemyTextures;    // Texture for the enemies
//    enemyTextures["ENEMY_1"] = new sf::Texture();
//    enemyTextures["ENEMY_1"]->loadFromFile("little-golem-game-sprite_22191-148.png");
//
//    enemyTextures["ENEMY_2"] = new sf::Texture();
//    enemyTextures["ENEMY_2"]->loadFromFile("orc-archer-game-sprites_22191-221.png");
//
//    enemyTextures["ENEMY_3"] = new sf::Texture();
//    enemyTextures["ENEMY_3"]->loadFromFile("cute-witch-game-sprites_22191-229.png");
//
//    // Vector to store enemies
//    std::vector<Enemy*> enemies;
//
//    // Enemy spawn timer
//    sf::Clock spawnTimer;
//
//    uint16_t point;
//
//    // Main loop
//    while (window.isOpen()) {
//        sf::Event event;
//        while (window.pollEvent(event)) {
//            if (event.type == sf::Event::Closed)
//                window.close();
//        }
//
//        // Spawn enemies every 3 seconds
//        if (spawnTimer.getElapsedTime().asSeconds() > 3.f) {
//            float dirX = -1.f;
//            float dirY = 0.f; // Random vertical direction
//            float startX = static_cast<float>(window.getSize().x);
//            float startY = static_cast<float>(rand() % window.getSize().y);
//            // Randomly select a texture for the enemy
//            int randomType = rand() % 3;											//choose random between 3 types
//            if (randomType == 0) {
//                enemies.push_back(new Enemy(enemyTextures["ENEMY_1"], 0.1f, 0.1f, dirX, dirY, startX, startY, 100, 1.5f, 30, 10));
//            }
//            else if (randomType == 1) {
//                enemies.push_back(new Enemy(enemyTextures["ENEMY_2"], 0.1f, 0.1f, dirX, dirY, startX, startY, 200, 2.0f, 40, 20));
//            }
//            else if (randomType == 2) {
//                enemies.push_back(new Enemy(enemyTextures["ENEMY_3"], 0.1f, 0.1f, dirX, dirY, startX, startY, 300, 2.5f, 50, 30));
//            }
//            spawnTimer.restart();
//        }
//
//        // Update enemies
//        for (int i = enemies.size() - 1; i >= 0; --i) {
//            enemies[i]->update();
//
//            // Remove enemies off-screen
//            if (enemies[i]->getBounds().left + enemies[i]->getBounds().width < 0.f) {
//                delete enemies[i];
//                enemies.erase(enemies.begin() + i);
//            }
//        }
//
//        // Render enemies
//        window.clear();
//        for (auto* enemy : enemies) {
//            enemy->render(&window);
//        }
//        window.display();
//    }
//
//    // Clean up remaining enemies and textures
//    for (auto* enemy : enemies) {
//        delete enemy;
//    }
//
//    for (auto& textTure : enemyTextures) {
//        delete textTure.second;
//    }
//
//    return 0;
//}


#include"Game.h"

int main()
{
    srand(static_cast<unsigned>(time(0)));
    Game* game = new Game();
    //game->choosingSkill();
    game->run();
    delete game;
    return 0;
}
