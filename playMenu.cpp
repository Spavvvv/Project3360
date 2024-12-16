#include "playMenu.h"

playMenu::playMenu(RenderWindow& window)
    : window(window),
    selectedSkills(3, -1),
    currentRow(0),
    currentCol(0) {
    if (!font.loadFromFile("assets/Fonts/KGNeatlyPrinted.ttf")) {
        cerr << "Font load failed!" <<endl; // mấy cái font load failed này chỉ để test có lỗi thôi
    }

    initializeBoxes();
}

void playMenu::initializeBoxes() {
    for (int i = 0; i < 3; ++i) {
       RectangleShape bigBox(Vector2f(50, 50));
        bigBox.setOutlineColor(Color::Black);
        bigBox.setOutlineThickness(2);
        bigBox.setFillColor(Color::Transparent);
        bigBox.setPosition(50, 50 + i * 100);
        bigBoxes.push_back(bigBox);

        Text xMark("X", font, 30);
        xMark.setFillColor(Color::Black);
        xMark.setPosition(bigBox.getPosition().x + 10, bigBox.getPosition().y);
        bigBoxX.push_back(xMark);
    }

    skillBoxes.resize(3, vector<RectangleShape>(3));
    for (int row = 0; row < 3; ++row) {
        for (int col = 0; col < 3; ++col) {
            sf::RectangleShape box(Vector2f(40, 40));
            box.setOutlineColor(Color::Black);
            box.setOutlineThickness(2);
            box.setFillColor(Color::Transparent);
            box.setPosition(150 + col * 50, 50 + row * 100);
            skillBoxes[row][col] = box;
        }
    }
}

void playMenu::handleEvents() {
    Event event;
    while (window.pollEvent(event)) {
        if (event.type == Event::Closed) {
            window.close();
        }

        if (event.type == Event::KeyPressed) {
            if (selectedSkills[currentRow] == -1) {
                if (event.key.code == Keyboard::Left) {
                    if (currentCol > 0) currentCol--;
                }
                if (event.key.code == Keyboard::Right) {
                    if (currentCol < 2) currentCol++;
                }
            }

            if (event.key.code == Keyboard::Enter) {
                if (selectedSkills[currentRow] == -1) {
                    selectedSkills[currentRow] = currentCol;
                    // chỗ này là nhét biến của Skill vào, tức là sau khi bấm Enter thì skill được giữ ở đây
                    if (currentRow < 2) currentRow++;
                }
            }

            if (event.key.code == Keyboard::BackSpace) {
                if (selectedSkills[currentRow] == -1 && currentRow > 0) {
                    currentRow--;
                    selectedSkills[currentRow] = -1;
                }
            }
        }
    }
}

void playMenu::draw() {
    window.clear(Color::White);

    for (int row = 0; row < 3; ++row) {
        window.draw(bigBoxes[row]);
        if (selectedSkills[row] != -1) {
            window.draw(bigBoxX[row]);
        }

        for (int col = 0; col < 3; ++col) {
            if (row == currentRow && col == currentCol && selectedSkills[row] == -1) {
                skillBoxes[row][col].setFillColor(Color(200, 200, 200));
            }
            else {
                skillBoxes[row][col].setFillColor(Color::Transparent);
            }
            window.draw(skillBoxes[row][col]);
        }
    }

    window.display();
}
void playMenu::run() {
    while (window.isOpen()) {
        handleEvents();
        draw();
    }
}