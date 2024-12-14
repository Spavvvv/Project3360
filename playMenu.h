#pragma once

#include <iostream>
#include <fstream>
#include <algorithm>
#include <string>
#include <iostream>
#include <SFML/Graphics.hpp>
#include <vector>


using namespace sf;
using namespace std;
class playMenu {
    private:
        vector<RectangleShape> bigBoxes;
        vector<Text> bigBoxX;
        vector<vector<RectangleShape>> skillBoxes;
        vector<int> selectedSkills;
        int currentRow, currentCol;
        Font font;
        RenderWindow& window;
    public:
        playMenu(RenderWindow& window); 
        void initializeBoxes();
        void handleEvents();
        void draw();
        void run();
};




