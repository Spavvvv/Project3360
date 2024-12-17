#pragma once

#include <iostream>
#include <fstream>
#include <algorithm>
#include <string>
#include <SFML/Graphics.hpp>
#include <vector>
#include <map>


using namespace sf;
using namespace std;
class playMenu {
private:
    vector<RectangleShape> bigBoxes;
    vector<Text> bigBoxX;
    vector<vector<RectangleShape>> skillBoxes;
    vector<int> selectedSkills;
    std::map<sf::String, sf::Texture> textures;


    int currentRow, currentCol;
    Font font;
    RenderWindow& window;


public:
    playMenu(RenderWindow& window);
    void initTextures();
    void initializeBoxes();
    bool handleEvents();
    void draw();
    void run();

    ~playMenu();
};




