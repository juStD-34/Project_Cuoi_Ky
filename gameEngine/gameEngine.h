#pragma
#include "ball.h"
#include "../renderer/consoleRenderer.h"
class gameEngine
{
private:
    Map* arr;
    ball* Ball;
    GameObject* wall;
    GameObject* goal;
public:
    gameEngine(/* args */){};
    gameEngine(int width, int height);
    Coordinate getChange(consoleRenderer* render);
    bool stepOnWall(const Coordinate& position, const Coordinate& change);
    bool stepOverWall(const Coordinate& position, const Coordinate& change);
    bool checkWin();
    void move (Coordinate& change );
    void display(consoleRenderer* render, int& speed);
    ~gameEngine();
};
