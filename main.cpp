#include <iostream>
#include "gameEngine/gameEngine.h"
#include <windows.h>

const int SIZE_OF_MAP = 10;
int main(int argc, char* argv[])
{
    gameEngine* engine = new gameEngine (SIZE_OF_MAP, SIZE_OF_MAP,SIZE_OF_MAP);
    //SDLRender* render = new SDLRender(SIZE_OF_MAP, SIZE_OF_MAP);
    cout<<"TTTT"<<endl;
   /* while (engine->checkWin() == false)
    {
        engine->countPlay++;
        engine->display(render);
        Coordinate change= engine->getChange(render, SIZE_OF_MAP);
        engine->speed =0;
        while ( engine->speed < 1000 && engine->checkWin() == false )
        {
            engine-> move(change);
            engine->display(render);
            engine->speed += 100;
        }
    }*/
    return 0;
}