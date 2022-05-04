#include "gameEngine.h"
#include <conio.h>
//#include "charArr.h"

/*const Map mapRound[] = {Map(10 , 10, {'w','w','w'} )};
const  charArr mapRounf[] = {
                            charArr("wwwwwwwwww"
                                    "w********w"
                                    "w***g****w"
                                    "w********w"
                                    "w********w"
                                    "w********w"
                                    "w***B****w"
                                    "w********w"
                                    "w********w"
                                    "wwwwwwwwww")
};*/
gameEngine::gameEngine(int width, int height)
{
    arr = new Map(width,height);
    for (int i =0 ; i < width; i++)
    {
        for (int j =0 ; j < height; j++)
        {
            if ( i ==0 || j == 0 || i == width-1|| j == height -1)
                arr->setCell(i,j,'w');
            else if ( i == 6 && j == 4) {arr->setCell(i,j,'O'); Ball = new ball (i,j,1);}
            else if ( i == 2 && j == 4) arr->setCell(i,j,'g');
            else arr->setCell(i,j,'*');
        }
    }
}

gameEngine::~gameEngine()
{
}

Coordinate gameEngine::getChange(consoleRenderer* render)
{
    cout<<"control the ball: ";
    char getKey;
    int changeY = 1;
    int changeX = 1;
    Coordinate ballPosition = Ball->getPosition();
    Coordinate pick(ballPosition.x + changeX, ballPosition.y + changeY);
    render->drawLine(arr, pick.x, pick.y);
    while (getKey != ENTER)
    {
        getKey =getch();
        if ( getKey == RIGHT)
        {
            changeY ++; 
            render->eraseLine(arr, pick.x,  pick.y);
            pick = Coordinate (ballPosition.x + changeX, ballPosition.y + changeY);
            render->drawLine(arr, pick.x, pick.y);
        }
        if ( getKey == LEFT ) 
        {
            changeY --;
            render->eraseLine(arr, pick.x,  pick.y);
            pick = Coordinate (ballPosition.x + changeX, ballPosition.y + changeY);
            render->drawLine(arr, pick.x, pick.y);
        }
        if (getKey == UP ) 
        {
            changeX --;
            render->eraseLine(arr, pick.x,  pick.y);
            pick = Coordinate (ballPosition.x + changeX, ballPosition.y + changeY);
            render->drawLine(arr, pick.x, pick.y);
        }
        if (getKey == DOWN) 
        {
            changeX ++;
            render->eraseLine(arr, pick.x,  pick.y);
            pick = Coordinate (ballPosition.x + changeX, ballPosition.y + changeY);
            render->drawLine(arr, pick.x, pick.y);
        }
    }
    return Coordinate(changeX, changeY); 
}

bool gameEngine::stepOnWall( const Coordinate& position, const Coordinate& change)
{
    if (arr->getCell(position.x + change.x, position.y + change.y) == 'w') return true;
    return false;
}

bool gameEngine::stepOverWall( const Coordinate& position, const Coordinate& change)
{
    if (change.y >0)
        for ( int i = position.y; i <= position.y + change.y; i++)
        {
            if (arr->getCell(position.x, i) == 'w') return true;
        }
    if (change.y < 0)
        for (int  i = position.y; i >= position.y + change.y ; i--)
        {
            if (arr->getCell(position.x, i) == 'w') return true;
        }
    return false;
}

void gameEngine::move( Coordinate& change)
{
    Coordinate position = Ball->getPosition();
    arr->setCell(position.x, position.y, '*');

    position.x += change.x;
    if (position.x >= arr->getWidht() - Ball->getRaidus()-1) change.x *= -1;
    else
    if (position.x <= Ball->getRaidus() ) change.x *=-1;

    position.y += change.y;
    if (position.y >= arr->getHeight() - Ball->getRaidus()-1 ) change.y *= -1;
    else
    if (position.y <= Ball->getRaidus()) change.y *= -1;
    if (arr->getCell(position.x, position.y) != 'g') arr->setCell(position.x, position.y , 'O');
    Ball->moveTo(position);
    /*if ( stepOnWall(position, change) == false && stepOverWall(position, change) == false)
    {
        arr->setCell(position.x, position.y,'*');
        Ball->moveTo(Coordinate(position.x + change.x, position.y + change.y));
        if (arr->getCell(position.x + change.x, position.y + change.y) != 'g') arr->setCell(position.x + change.x, position.y + change.y,'B'); 
    }
    if (stepOnWall (position, change) == true)
    {
        cout<<"on"<<endl;
        Ball->moveTo(Coordinate ( position.x + change.x, position.y + change.y ));
        change.x = -change.x;
        //Ball->moveTo(Coordinate ( position.x + change.x, position.y + change.y ));
    }else
    /*if ( ballPosition.x >= 1) changeX =1;else
    if ( ballPosition.x == arr->getWidht()) changeX = -1;
    if ( ballPosition.y == 1 && changeY < 0) changeY =  - changeY ;
    else if ( ballPosition.y == arr->getHeight() && changeY >0) changeY = -changeY;
    if (stepOverWall (position, change ) == true)
    {
        cout<<"over"<<endl;
        if (change.y > 0)
            for (int i = position.y; i <= position.y +change.y; i++)
            {
                if (arr->getCell(position.x, i) == 'w')
                {
                    arr->setCell(position.x, position.y, '*');
                    Ball->moveTo(Coordinate(change.x + position.x,i-1));
                    arr->setCell(position.x + change.x, i-1,'B' );
                    change.y = (i - position.y) - change.y +1;
                }
            }
        else
            for (int i = position.y + change.y ; i <= position.y; i ++)
            {
                if (arr->getCell(position.x, i) == 'w')
                {
                    arr->setCell(position.x, position.y, '*');
                    Ball->moveTo(Coordinate(change.x + position.x, i+1));
                    arr->setCell(position.x +change.x, i+1, 'B');
                    change.y = (position.y - i) - change.y -1;
                }
            }
        //cout<<change.x<<" "<<change.y<<endl;
    }*/
}

bool gameEngine::checkWin()
{
    Coordinate position = Ball->getPosition();
    if ( arr->getCell(position.x, position.y) == 'g') return true;
    return false;
}

void gameEngine::display(consoleRenderer* renderer, int& speed)
{
    renderer->render(arr,speed);
}