#pragma once
#include<sstream>
#include<iomanip>
#include<stdio.h>
#include<stdlib.h>
#include<string>
#include <vector>
#include <ctime>
<<<<<<< HEAD

#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>

=======
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
>>>>>>> c7575d82ee2923d411cb421c4d86c1692109cefb
#include <iostream>
using namespace std;
using namespace sf;
#define Max_main_menu 4
class Mainmenu
{
public:
	Mainmenu(float width, float height);
	Text mainMenu[Max_main_menu];
	void draw(RenderWindow& window);
	void MoveUp();
	void MoveDown();
	void getSelected(int n);
	int MainMenuPressed() {
		return MainMenuSelected;
	}
	~Mainmenu();
private:
	int MainMenuSelected;
	Font font;
	
};

