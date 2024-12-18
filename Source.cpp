#include"Game.h"

int main()
{
    srand(static_cast<unsigned>(time(0)));
    Game *game = new Game();
    
    if (game->getEndGame() == false)
    {
        game->run();
        delete game;
    }
    else {
        delete game;
    }

    return 0;
}