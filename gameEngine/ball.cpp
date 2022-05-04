#include "ball.h"
#include <conio.h>
//#include "gameEngine.h"

ball::ball(Coordinate position_, int radius_)
{
    position = position_;
    radius =radius_;
}
ball::ball(int x, int y, int radius_)
{
    position = Coordinate(x,y);
    radius = radius_;
}

ball::~ball()
{
    position = Coordinate(-1,-1);
    radius = 0;
}

Coordinate ball::getPosition()
{
    return this->position;
}

int ball::getRaidus()
{
    return radius;
}

void ball::moveTo(Coordinate newPosition)
{
    position = newPosition;
}