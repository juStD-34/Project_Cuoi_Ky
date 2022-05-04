#include <iostream>
#include "gameEngine/gameEngine.h"
#include <windows.h>
int main()
{
    gameEngine* engine = new gameEngine (10,10);
    consoleRenderer* render = new consoleRenderer();
    while (engine->checkWin() == false)
    {
        int speed = 200;
        engine->display(render, speed);
        Coordinate change= engine->getChange(render);
        while ( speed < 1000 && engine->checkWin() == false)
        {
            engine->move(change);
            engine->display(render, speed);
            speed += 100;
        }
    }
    return 0;
}