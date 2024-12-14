#include "Mainmenu.h"
<<<<<<< HEAD

using namespace std;
using namespace sf;

=======
#include<SFML/Graphics.hpp>
using namespace std;
using namespace sf;
>>>>>>> c7575d82ee2923d411cb421c4d86c1692109cefb
Mainmenu::Mainmenu(float width, float height) {
	font.loadFromFile("assets/Fonts/Freedom-10eM.ttf");

	mainMenu[0].setFont(font);
	mainMenu[0].setFillColor(Color::White);
	mainMenu[0].setString("Login");
	mainMenu[0].setCharacterSize(70);
<<<<<<< HEAD
	mainMenu[0].setPosition(sf::Vector2f(400.f,200.f));
=======
	mainMenu[0].setPosition(Vector2f(400, 200));
>>>>>>> c7575d82ee2923d411cb421c4d86c1692109cefb

	mainMenu[1].setFont(font);
	mainMenu[1].setFillColor(Color::White);
	mainMenu[1].setString("Register");
	mainMenu[1].setCharacterSize(70);
<<<<<<< HEAD
	mainMenu[1].setPosition(sf::Vector2f(400.f, 300.f));
=======
	mainMenu[1].setPosition(Vector2f(400, 300));
>>>>>>> c7575d82ee2923d411cb421c4d86c1692109cefb

	mainMenu[2].setFont(font);
	mainMenu[2].setFillColor(Color::White);
	mainMenu[2].setString("Ranking");
	mainMenu[2].setCharacterSize(70);
	mainMenu[2].setPosition(Vector2f(400, 400));

	mainMenu[3].setFont(font);
	mainMenu[3].setFillColor(Color::White);
	mainMenu[3].setString("Exit");
	mainMenu[3].setCharacterSize(70);
	mainMenu[3].setPosition(Vector2f(400, 500));			


	MainMenuSelected = -1;
}
Mainmenu::~Mainmenu()
{

}
void Mainmenu::draw(RenderWindow& window) {
	for (int i = 0; i < 4; ++i) {
		window.draw(mainMenu[i]);
	}
}
void Mainmenu::MoveUp() {
	mainMenu[MainMenuSelected].setFillColor(Color::White);
	MainMenuSelected = (MainMenuSelected + 3) % 4;
	mainMenu[MainMenuSelected].setFillColor(Color::Cyan);
}

void Mainmenu::MoveDown() {
	mainMenu[MainMenuSelected].setFillColor(Color::White);
	MainMenuSelected = (MainMenuSelected + 1) % 4; 
	mainMenu[MainMenuSelected].setFillColor(Color::Cyan);
}

void Mainmenu::getSelected(int n) {
	MainMenuSelected = n;
}