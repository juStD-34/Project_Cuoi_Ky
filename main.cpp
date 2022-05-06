#include <iostream>
#include "gameEngine/gameEngine.h"
#include <windows.h>

const int SIZE_OF_MAP = 10;
int main()
{
    gameEngine* engine = new gameEngine (SIZE_OF_MAP, SIZE_OF_MAP,SIZE_OF_MAP);
    consoleRenderer* render = new consoleRenderer();
    while (engine->checkWin() == false)
    {
        engine->countPlay++;
        engine->display(render);
        Coordinate change= engine->getChange(render);
        engine->setSpeed();
        while ( engine->speed < 1000 && engine->checkWin() == false )
        {
            engine->move(change);
            engine->display(render);
            engine->speed += 100;
        }
    }
    return 0;
}