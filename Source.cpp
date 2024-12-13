#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>
#include"Game.h"

int main()
{
    srand(static_cast<unsigned>(time(0)));
    Game *game = new Game();
    //game->choosingSkill();
    game->run();
    delete game;
    return 0;
}