#include<SFML/Graphics.hpp>
#include"Mainmenu.h"
#include"User.h"
#include"playMenu.h"

using namespace sf;
using namespace std;


string filename = "user_data.txt";
vector<User> users = User::loadUserData(filename);

int choice;
int pagenum = 1000;
bool loggedIn = false;

int main() {
	string name;
	RenderWindow MENU(VideoMode(1400, 1000), string("Main Menu"), sf::Style::Close | sf::Style::Titlebar);
	Mainmenu mainMenu(1400, 1000);

	while (true) {
		if (pagenum == 1000) {
			while (MENU.isOpen()) {
				Event event;
				while (MENU.pollEvent(event)) {
					if (event.type == Event::Closed) {
						MENU.close();
					}
					if (event.type == Event::KeyPressed) {
						if (event.key.code == Keyboard::Up) {
							mainMenu.MoveUp();
							break;
						}
						if (event.key.code == Keyboard::Down) {
							mainMenu.MoveDown();
							break;
						}
						if (event.key.code == Keyboard::Enter) {
							if (mainMenu.MainMenuPressed() == 0) {
								pagenum = 0;
							}
							if (mainMenu.MainMenuPressed() == 1) {
								pagenum = 1;
							}
							if (mainMenu.MainMenuPressed() == 2) {
								pagenum = 2;
							}
							if (mainMenu.MainMenuPressed() == 3) {
								pagenum = -1;
							}
						}
					}
				}
				MENU.clear();
				if (pagenum != 1000) {
					break;
				}
				mainMenu.draw(MENU);
				MENU.display();

				if (event.Event::type == sf::Event::Closed)
					MENU.close();
				if (event.Event::KeyPressed && event.Event::key.code == sf::Keyboard::Escape)
					MENU.close();
			}
			if (pagenum == -1) {
				MENU.close();
				break;
			}
			if (pagenum == 0) {
				if (User::loginUser(MENU, users)) {
					loggedIn = true;
					pagenum = 10;
				}
				else {
					loggedIn = false;
					pagenum = 1000; 
				}
			}
			if (pagenum == 1) {
				if (User::registerUser(MENU, users)) {
					pagenum = 10; // Đăng ký thành công, chuyển sang trang tiếp theo
				}
				else {
					pagenum = 1000; // Đăng ký thất bại hoặc hủy
				}
			}


			if (pagenum == 2) {
				User::displayUserIDsByScore(MENU, users);
				pagenum = 1000;
			}
			if (pagenum == 3) {
				pagenum = 1000;

			}
		}
		if (pagenum == 10) {
			playMenu menu(MENU);
			menu.run();
			pagenum = 1000;
		}


	}
	return 0;
}