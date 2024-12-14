#include <iostream>
#include <fstream>
#include <algorithm>
#include <SFML/Graphics.hpp>
#include <string>
#include <vector>
#include <iostream>
#pragma once
using namespace std;
using namespace sf;
class User {
public:
    int id;
    string name;
    string password;
    int score;

    User(int id = 0, const string& name = "", const string& password = "", int score = 0);

    static void saveUserData(const vector<User>& users, const string& filename);
    static vector<User> loadUserData(const string& filename);
    static void displayUserIDsByScore(RenderWindow& window,const vector<User>& users);
<<<<<<< HEAD
    static bool registerUser(RenderWindow& window,vector<User>& users);
=======
    static void registerUser(RenderWindow& window,vector<User>& users);
>>>>>>> c7575d82ee2923d411cb421c4d86c1692109cefb
    static bool loginUser(RenderWindow& window ,vector<User>& users);
    bool login(const string& inputName, const string& inputPassword) const;
};
