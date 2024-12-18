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
    vector<sf::String> selectedSS;
    std::map<sf::String, sf::Texture> texture;

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

    const std::vector<sf::String>& getSelectedSkills() const;             
};




