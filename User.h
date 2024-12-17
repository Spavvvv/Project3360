#pragma once

#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <string>

#include <SFML/Graphics.hpp>

class User
{
public:
    int id;
    std::string name;
    std::string password;
    int score;

    User(int id = 0, const std::string& name = "", const std::string& password = "", int score = 0);

    static void saveUserData(const std::vector<User>& users, const std::string& filename);
    static std::vector<User> loadUserData(const std::string& filename);
    static void displayUserIDsByScore(sf::RenderWindow& window, const std::vector<User>& users);
    static bool registerUser(sf::RenderWindow& window, std::vector<User>& users);
    static bool loginUser(sf::RenderWindow& window, std::vector<User>& users);
    bool login(const std::string& inputName, const std::string& inputPassword) const;

};

