<<<<<<< HEAD
#pragma once
=======
>>>>>>> c7575d82ee2923d411cb421c4d86c1692109cefb

#include <iostream>
#include <fstream>
#include <algorithm>
#include <string>
#include <iostream>
#include <SFML/Graphics.hpp>
#include <vector>
<<<<<<< HEAD


=======
>>>>>>> c7575d82ee2923d411cb421c4d86c1692109cefb
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




