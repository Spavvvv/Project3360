#pragma once

#include<sstream>
#include<iomanip>
#include<stdio.h>
#include<stdlib.h>
#include<string>
#include <vector>
#include <ctime>

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>


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

