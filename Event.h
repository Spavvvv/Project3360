#pragma once
#ifndef EVENT_H
#define EVENT_H

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

public:
    EventManager();
    void run();
};

#endif