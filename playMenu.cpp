#include "playMenu.h"

playMenu::playMenu(RenderWindow& window)
    : window(window),
    selectedSkills(3, -1),
    currentRow(0),
    currentCol(0) {
    if (!font.loadFromFile("assets/Fonts/KGNeatlyPrinted.ttf")) {
        cerr << "Font load failed!" << endl; // mấy cái font load failed này chỉ để test có lỗi thôi
    }

    initTextures();
    initializeBoxes();
}

void playMenu::initTextures()
{
    std::cout << "Called!" << '\n';

    if (!textures["SWORD"].loadFromFile("texture\\png\\weapon\\sword.png")) {
        std::cerr << "Error loading texture: SWORD" << std::endl;
    }

    if (!textures["KATANA"].loadFromFile("texture\\png\\weapon\\25.png")) {
        std::cerr << "Error loading texture: KATANA" << std::endl;
    }

    if (!textures["SURIKEN"].loadFromFile("texture\\png\\weapon\\40.png")) {
        std::cerr << "Error loading texture: SURIKEN" << std::endl;
    }

    std::cout << textures.size() << '\n';
}

void playMenu::initializeBoxes() {

    std::vector<sf::String> keysBigBoxes = { "SWORD", "KATANA", "SURIKEN" };

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

            if (this->textures.count(keysBigBoxes[col])) { // Kiểm tra key "SURIKEN" có tồn tại trong map
                box.setTexture(&textures[keysBigBoxes[col]]); // Lấy con trỏ và truyền vào setTexture()
            }
            else {
                std::cerr << "Texture not found in map!" << std::endl;
            }


            box.setPosition(150 + col * 50, 50 + row * 100);
            skillBoxes[row][col] = box;
        }
    }
}

bool playMenu::handleEvents() {
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
                    for (int i = 0; i < selectedSkills.size();i++) {
                        if (selectedSkills[i] == -1)
                            break;
                        else {
                            if (selectedSkills[2] != -1)
                                return true;
                        }
                    }
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
    return false;
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
        if (handleEvents() == false)
            draw();
        else
            break;
    }
}

playMenu::~playMenu()
{
    textures.clear();
}
