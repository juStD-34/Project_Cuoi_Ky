#include "gameEngine.h"
#include <conio.h>
#include <cmath>
#include <time.h>
#include <cstdlib>
#include <windows.h>
gameEngine::gameEngine(int width, int height, int SIZE_OF_ARRAY)
{
    countPlay =0;
    srand(time(NULL));
    arr = new Map(width,height);
    int goalX = rand () %(SIZE_OF_ARRAY-2 )+ 1;
    int goalY = rand () %(SIZE_OF_ARRAY-2 )+ 1;
    int ballX = rand () %(SIZE_OF_ARRAY-2 )+ 1;
    int ballY = rand () %(SIZE_OF_ARRAY-2 )+ 1;
    while (ballX == goalX && ballY == goalY)
    {
        srand(time(NULL));
        ballX = rand () %(SIZE_OF_ARRAY-2 )+ 1;
        ballY = rand () %(SIZE_OF_ARRAY-2 )+ 1;
    }
    for (int i =0 ; i < width; i++)
    {
        for (int j =0 ; j < height; j++)
        {
            if ( i ==0 || j == 0 || i == width-1|| j == height -1)
                arr->setCell(i,j,'w');
            else if ( i == ballX && j == ballY) {arr->setCell(i,j,'O'); Ball = new ball (i,j,0);}
            else if ( i == goalX && j == goalY) arr->setCell(i,j,'g');
            else arr->setCell(i,j,'*');
        }
    }
}

gameEngine::~gameEngine()
{
}

Coordinate gameEngine::getChange(SDLRender* renderer,int SIZE_OF_ARRAY)
{
    char getKey;
    int changeY = 1;
    int changeX = -1;
    Coordinate ballPosition = Ball->getPosition();
    if ( ballPosition.x == 1 && ballPosition.y == SIZE_OF_ARRAY-1) {changeX = -1; changeY = 1;}
    if (ballPosition.x == 1) changeX = 1;
    if (ballPosition.y == SIZE_OF_ARRAY -1) changeY = -1;
    Coordinate pick(ballPosition.x + changeX, ballPosition.y + changeY);
    if (arr->getCell(ballPosition.x + changeX , ballPosition.y + changeY) == 'w'  ||
        arr->getCell(ballPosition.x + changeX , ballPosition.y + changeY) == 'O'
        ) changeY --;
    drawLine(renderer, pick.x, pick.y);
    display(renderer);
    while (getKey != ENTER)
    {
        getKey =getch();
        if ( getKey == RIGHT && abs(changeX) <2 && abs(changeY) < 2)
        {
            if (changeY != 1&&
                arr->getCell(ballPosition.x + changeX , ballPosition.y + changeY+1) != 'w'  && 
                arr->getCell(ballPosition.x + changeX , ballPosition.y + changeY+1) != 'O'
               ) changeY ++; 
            eraseLine(renderer, pick.x, pick.y);
            pick = Coordinate (ballPosition.x + changeX, ballPosition.y + changeY);
            drawLine(renderer, pick.x, pick.y);
            display(renderer);
        }else
        if ( getKey == LEFT && abs(changeX) <=1 && abs(changeY) <=1) 
        {
            if (changeY != -1 &&
                arr->getCell(ballPosition.x + changeX , ballPosition.y + changeY-1) != 'w'  && 
                arr->getCell(ballPosition.x + changeX , ballPosition.y + changeY-1) != 'O'
               ) changeY --;
            eraseLine(renderer, pick.x, pick.y);
            pick = Coordinate (ballPosition.x + changeX, ballPosition.y + changeY);
            drawLine(renderer, pick.x, pick.y);
            display(renderer);
        }else
        if (getKey == UP && abs(changeX) <=1 && abs(changeY) <= 1) 
        {
            if ( changeX != -1 && 
                arr->getCell(ballPosition.x + changeX -1, ballPosition.y + changeY) != 'w'  && 
                arr->getCell(ballPosition.x + changeX -1, ballPosition.y + changeY) != 'O'
                ) 
                    changeX --;
            eraseLine(renderer, pick.x, pick.y);
            pick = Coordinate (ballPosition.x + changeX, ballPosition.y + changeY);
            drawLine(renderer, pick.x, pick.y);
            display(renderer);
        }else
        if (getKey == DOWN&& abs(changeX) <=1 && abs(changeY) <= 1) 
        {
            if (changeX != 1 && 
                arr->getCell(ballPosition.x + changeX +1, ballPosition.y + changeY) != 'w'  && 
                arr->getCell(ballPosition.x + changeX +1, ballPosition.y + changeY) != 'O'
                ) 
                    changeX ++;
            eraseLine(renderer, pick.x, pick.y);
            pick = Coordinate (ballPosition.x + changeX, ballPosition.y + changeY);
            drawLine(renderer, pick.x, pick.y);
            display(renderer);
        }
    }
    return Coordinate(changeX, changeY); 
}

bool gameEngine::stepOnWall( const Coordinate& position, const Coordinate& change)
{
    if (arr->getCell(position.x + change.x, position.y + change.y) == 'w') return true;
    return false;
}

void gameEngine::move( Coordinate& change)
{
    Coordinate position = Ball->getPosition();
    arr->setCell(position.x, position.y, '*');

    position.x += change.x;
    if (position.x >= arr->getWidht() -2) change.x *= -1;
    else
    if (position.x <= 1 ) change.x *=-1;

    position.y += change.y;
    if (position.y >= arr->getHeight() -2 ) change.y *= -1;
    else
    if (position.y <= 1) change.y *= -1;
    if (arr->getCell(position.x, position.y) != 'g') arr->setCell(position.x, position.y , 'O');
    Ball->moveTo(position);
}

bool gameEngine::checkWin()
{
    Coordinate position = Ball->getPosition();
    if ( arr->getCell(position.x, position.y) == 'g') return true;
    return false;
}

void gameEngine::display(SDLRender* renderer)
{
    renderer->render(arr, speed, countPlay);
}

void gameEngine::drawLine(SDLRender* renderer,int& x, int& y)
{
    Coordinate ballPosition = Ball->getPosition();
    renderer->drawLine(arr,ballPosition.x, ballPosition.y ,x, y);
}
void gameEngine::eraseLine(SDLRender* renderer, int& x, int& y)
{
    Coordinate ballPosition = Ball->getPosition();
    renderer->eraseLine(arr,ballPosition.x, ballPosition.y ,x, y);
}