#pragma once

#include <SFML/Graphics.hpp>
#include <vector>
#include "Mainmenu.h"
#include "User.h"
#include "playMenu.h"

using namespace std;
using namespace sf;

class EventManager {
private:
    RenderWindow MENU;
    Mainmenu mainMenu;
    string filename = "user_data.txt";
    vector<User> users = User::loadUserData(filename);

    int choice;
    int pagenum = 1000;
    bool loggedIn = false;

    void handleMainMenu();
    void handleLoginPage();
    void handleRegisterPage();
    void handleDisplayScores();
    void handlePlayMenu();

    playMenu* menu;
    User* user;

public:
    EventManager();

    playMenu* getPlayMenu() const;

    User* getUser() const;

    bool run();

    ~EventManager();
};