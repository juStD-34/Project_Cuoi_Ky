#pragma
#include "ball.h"
#include "../renderer/SDLRender.h"
//#include "../renderer/consoleRenderer.h"


class gameEngine
{
private:
    Map* arr;
    ball* Ball;
    GameObject* wall;
    GameObject* goal;
public:
    int countPlay = 0;
    int speed =0;
    gameEngine(/* args */){};
    gameEngine(int width, int height, int SIZE_OF_ARRAY);
    Coordinate getChange(SDLRender* render, int SIZE_OF_ARRAY);
    bool stepOnWall(const Coordinate& position, const Coordinate& change);
    bool stepOverWall(const Coordinate& position, const Coordinate& change);
    bool checkWin();
    void move (Coordinate& change );
    void display(SDLRender* render);
    void setSpeed();
    void eraseLine(SDLRender* renderer, int& x, int& y);
    void drawLine(SDLRender* renderer, int& x, int& y);
    ~gameEngine();
};
