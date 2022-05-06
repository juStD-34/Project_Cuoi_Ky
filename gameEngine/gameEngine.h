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
    int countPlay = 0;
    int speed =0;
    gameEngine(/* args */){};
    gameEngine(int width, int height, int SIZE_OF_ARRAY);
    Coordinate getChange(consoleRenderer* render);
    bool stepOnWall(const Coordinate& position, const Coordinate& change);
    bool stepOverWall(const Coordinate& position, const Coordinate& change);
    bool checkWin();
    void move (Coordinate& change );
    void display(consoleRenderer* render);
    void setSpeed();
    void eraseLine(consoleRenderer* renderer, int& x, int& y);
    void drawLine(consoleRenderer* renderer, int& x, int& y);
    ~gameEngine();
};
