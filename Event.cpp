#include<SFML/Graphics.hpp>

#include "Event.h"
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


EventManager::EventManager()
    : MENU(sf::VideoMode(1400, 1000), "Game", sf::Style::Close | sf::Style::Titlebar),
    mainMenu(1400, 1000),
    filename("user_data.txt"),
    users(User::loadUserData(filename)),
    pagenum(1000),
    loggedIn(false) {
    user = new User;
}

playMenu* EventManager::getPlayMenu() const
{
    return menu;
}

User* EventManager::getUser() const
{
    return user;
}



void EventManager::handleMainMenu() {
    while (MENU.isOpen()) {
        sf::Event event;
        while (MENU.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                MENU.close();
            }
            if (event.type == sf::Event::KeyPressed) {
                if (event.key.code == sf::Keyboard::Up) {
                    mainMenu.MoveUp();
                    break;
                }
                if (event.key.code == sf::Keyboard::Down) {
                    mainMenu.MoveDown();
                    break;
                }
                if (event.key.code == sf::Keyboard::Enter) {
                    int selected = mainMenu.MainMenuPressed();
                    if (selected == 0) pagenum = 0;
                    if (selected == 1) pagenum = 1;
                    if (selected == 2) pagenum = 2;
                    if (selected == 3) pagenum = -1;
                }
            }
        }

        MENU.clear();
        if (pagenum != 1000) break;
        mainMenu.draw(MENU);
        MENU.display();
    }
}

void EventManager::handleLoginPage() {
    if (User::loginUser(MENU, users,*user)) {
        loggedIn = true;
        pagenum = 10;
    }
    else {
        loggedIn = false;
        pagenum = 1000;
    }
}

void EventManager::handleRegisterPage() {
    if (User::registerUser(MENU, users,*user)) {
        pagenum = 10;
    }
    else {
        pagenum = 1000;
    }
}

void EventManager::handleDisplayScores() {
    User::displayUserIDsByScore(MENU, users);
    pagenum = 1000;
}

void EventManager::handlePlayMenu() {
    menu = new playMenu(MENU);
    menu->run();
    pagenum = 1000;
    //MENU.close();
}

bool EventManager::run() {
    while (true) {
        if (pagenum == 1000) {
            handleMainMenu();
            if (MENU.isOpen() == false) {
                return false;
            }
        }
        if (pagenum == -1) {
            MENU.close();
            return false;
        }
        if (pagenum == 0) {
            handleLoginPage();
        }
        if (pagenum == 1) {
            handleRegisterPage();
        }
        if (pagenum == 2) {
            handleDisplayScores();
        }
        if (pagenum == 10) {
            handlePlayMenu();
            return true;
        }
    }
    return false;
}

EventManager::~EventManager()
{
    //delete menu;
}

