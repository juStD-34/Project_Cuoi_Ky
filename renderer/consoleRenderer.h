#pragma
#include "../gameEngine/Map.h"
class consoleRenderer
{
public:
    consoleRenderer(/* args */){};
    void render(Map* map, int& speed, int& countPlay);
    void drawLine (Map* map, int& pickX, int & pickY);
    void eraseLine(Map* map, int& pickX, int & pickY);
};
