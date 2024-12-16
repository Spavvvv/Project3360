#include <SFML/Graphics.hpp>
#include <vector>
#include "Mainmenu.h"
#include "User.h"
#include "playMenu.h"
#include "Event.h"
using namespace std;
using namespace sf;
int main() {
    EventManager eventManager;
    eventManager.run();
    return 0;
}
