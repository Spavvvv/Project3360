#include "User.h"
#pragma once

#include <iostream>
#include <fstream>
#include <algorithm>
#include <string>
#include <vector>

#include <SFML/Graphics.hpp>

using namespace sf;
using namespace std;

User::User(int id, const string& name, const string& password, int score)
    : id(id), name(name), password(password), score(score) {
}

void User::saveUserData(const vector<User>& users, const string& filename) {
    ofstream file(filename);
    if (file.is_open()) {
        for (const auto& user : users) {
            file << user.id << "," << user.name << "," << user.password << "," << user.score << endl;
        }
        file.close();
    }
}
vector<User> User::loadUserData(const string& filename) {
    vector<User> users;
    ifstream file(filename);
    if (file.is_open()) {
        User user;
        string line;
        while (getline(file, line)) {
            size_t pos1 = line.find(',');
            size_t pos2 = line.find(',', pos1 + 1);
            size_t pos3 = line.rfind(',');

            if (pos1 != string::npos && pos2 != string::npos && pos3 != string::npos && pos1 != pos3) {
                user.id = stoi(line.substr(0, pos1));
                user.name = line.substr(pos1 + 1, pos2 - pos1 - 1);
                user.password = line.substr(pos2 + 1, pos3 - pos2 - 1);
                user.score = stoi(line.substr(pos3 + 1));
                users.push_back(user);
            }
        }
        file.close();
    }
    return users;
}

void User::displayUserIDsByScore(RenderWindow& window, const vector<User>& users) {

    vector<User> sortedUsers = users;
    sort(sortedUsers.begin(), sortedUsers.end(), [](const User& a, const User& b) {
        return a.score > b.score;
        });

    Font font;
    if (!font.loadFromFile("assets/Fonts/KGNeatlyPrinted.ttf")) {
        cout << "Font load failed!" << endl;
        return;
    }

    Text title("User Rankings", font, 50);
    title.setPosition(50, 20);
    title.setFillColor(Color::Cyan);

    vector<Text> userTexts;
    float yOffset = 100;

    for (const auto& user : sortedUsers) {
        Text userText;
        userText.setFont(font);
        userText.setString("ID: " + to_string(user.id) + "  Name: " + user.name + "  Score: " + to_string(user.score));
        userText.setCharacterSize(30);
        userText.setPosition(50, yOffset);
        userText.setFillColor(Color::Cyan);
        userTexts.push_back(userText);

        yOffset += 40;
    }

    while (window.isOpen()) {
        Event event;
        while (window.pollEvent(event)) {
            if (event.type == Event::Closed) {
                window.close();
                return;
            }
            if (Keyboard::isKeyPressed(Keyboard::Escape)) {
                return;
            }
        }

        window.clear();
        window.draw(title);
        for (const auto& text : userTexts) {
            window.draw(text);
        }
        window.display();
    }
}


bool User::login(const string& inputName, const string& inputPassword) const {
    return name == inputName && password == inputPassword;
}
bool User::registerUser(RenderWindow& window, vector<User>& users) {
    string name, password, tempInput;
    int id = 0;

    Font font;
    if (!font.loadFromFile("assets/Fonts/KGNeatlyPrinted.ttf")) {
        cerr << "Font load failed!" << endl;
        return false;
    }

    Text prompt("Register", font, 50);
    prompt.setPosition(50, 50);
    prompt.setFillColor(Color::Cyan);
    Text enter("Enter ID: ", font, 50);
    enter.setPosition(50, 100);
    enter.setFillColor(Color::Cyan);
    Text input("", font, 50);
    input.setPosition(50, 150);
    input.setFillColor(Color::White);

    int field = 0;

    while (window.isOpen()) {
        Event event;
        while (window.pollEvent(event)) {
            if (event.type == Event::Closed) {
                window.close();
                return false;

            }

            if (event.type == Event::TextEntered) {
                if (event.text.unicode == '\b' && !tempInput.empty()) {
                    tempInput.pop_back();
                }
                else if (event.text.unicode < 128 && event.text.unicode != '\r' && event.text.unicode != 27) {
                    tempInput += static_cast<char>(event.text.unicode);
                }
                else if (event.text.unicode == '\r') {
                    if (field == 0) {
                        try {
                            id = stoi(tempInput);
                            bool idExists = any_of(users.begin(), users.end(), [&](const User& user) {
                                return user.id == id;
                                });

                            if (idExists) {
                                prompt.setString("ID exists. Enter a new ID:");
                                tempInput.clear();
                            }
                            else {
                                field = 1;
                                prompt.setString("Enter Password :");
                                tempInput.clear();
                            }
                        }
                        catch (...) {
                            prompt.setString("Invalid ID. Enter a numeric value:");
                            tempInput.clear();
                        }
                    }
                    else if (field == 1) {
                        try {
                            stoi(tempInput);
                            password = tempInput;
                            field = 2;
                            prompt.setString("Enter Name:");
                            tempInput.clear();
                        }
                        catch (...) {
                            prompt.setString("Invalid Password. Enter a numeric value:");
                            tempInput.clear();
                        }
                    }
                    else if (field == 2) {
                        name = tempInput;
                        users.emplace_back(id, name, password, 0);
                        saveUserData(users, "user_data.txt");
                        prompt.setString("Registration successful!");
                        tempInput.clear();
                        return true;
                    }
                }
                else if (event.text.unicode == 27) {
                    return false;
                }
            }
        }

        input.setString(tempInput);

        window.clear();
        window.draw(prompt);
        window.draw(input);
        if (field == 0) window.draw(enter);
        window.display();
    }
}



bool User::loginUser(RenderWindow& window, vector<User>& users) {
    string inputPassword, tempInput;
    int inputID = 0, field = 0;

    Font font;
    if (!font.loadFromFile("assets/Fonts/KGNeatlyPrinted.ttf")) {
        cerr << "Font load failed!" << endl;
        return false;
    }

    Text prompt("Login: Enter ID (numeric)", font, 50);
    prompt.setPosition(50, 50);
    prompt.setFillColor(Color::Cyan);

    Text input("", font, 40);
    input.setPosition(50, 150);
    input.setFillColor(Color::White);

    while (window.isOpen()) {
        Event event;
        while (window.pollEvent(event)) {
            if (event.type == Event::Closed) {
                window.close();
                return false;
            }

            if (event.type == Event::TextEntered) {
                if (event.text.unicode == '\b' && !tempInput.empty()) {
                    tempInput.pop_back();
                }
                else if (event.text.unicode < 128 && event.text.unicode != '\r' && event.text.unicode != 27) {
                    tempInput += static_cast<char>(event.text.unicode);
                }
                else if (event.text.unicode == '\r') {
                    if (field == 0) {
                        try {
                            inputID = stoi(tempInput);
                            field = 1;
                            prompt.setString("Enter Password:");
                            tempInput.clear();
                        }
                        catch (...) {
                            prompt.setString("Invalid ID. Enter a numeric value:");
                            tempInput.clear();
                        }
                    }
                    else if (field == 1) {
                        try {
                            stoi(tempInput);
                            inputPassword = tempInput;

                            auto it = find_if(users.begin(), users.end(), [&](const User& user) {
                                return user.id == inputID && user.password == inputPassword;
                                });

                            if (it != users.end()) {
                                prompt.setString("Login Successful!");
                                window.clear();
                                window.draw(prompt);
                                window.display();
                                sleep(milliseconds(2000));
                                return true;
                            }
                            else {
                                prompt.setString("Invalid ID or Password. Try Again:");
                                tempInput.clear();
                                field = 0;
                            }
                        }
                        catch (...) {
                            prompt.setString("Invalid Password. Enter a numeric value:");
                            tempInput.clear();
                        }
                    }
                }
                else if (event.text.unicode == 27) {
                    return false;
                }
            }
        }

        input.setString(tempInput);

        window.clear();
        window.draw(prompt);
        window.draw(input);
        window.display();
    }

    return false;
}

