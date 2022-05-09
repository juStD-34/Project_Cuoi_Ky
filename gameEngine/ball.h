#pragma
#include <iostream>
#include "GameObject.h"
using namespace std;

const int ENTER=13, UP = 72, DOWN = 80, LEFT = 75, RIGHT = 77, SPACE = 32;

class ball
{
private:
    Coordinate position;
    int radius;
public:
    ball();
    ball(Coordinate position_, int radius_);
    ball (int x, int y, int radius);
    void moveTo(Coordinate newPosition);
    Coordinate getPosition();
    int getRaidus();
    ~ball();
    bool checkWin( Coordinate goal);
};