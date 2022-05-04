#include "consoleRenderer.h"
#include <windows.h>
void consoleRenderer::render(Map* map, int& speed)
{
    int width = map->getWidht();
    int height = map->getHeight();
    for (int i =0 ; i < width; i++)
    {
        for (int j =0 ; j < height; j++)
        {
            if (map->getCell(i,j) == 'O') cout<<'O';else
            if (map->getCell(i,j) == 'w') cout<<'w';else
            if (map->getCell(i,j) == 'g') cout<<'g';else
            if (map->getCell(i,j) == '*') cout<<'*';
        }
        cout<<endl;
    }
    Sleep(speed);
}
void drawLine (Map* map, int& pickX, int& pickY)
{
    map->setCell(pickX,pickY,'L');
}
void eraseLine(Map* map, int& pickX, int & pickY)
{
    map->setCell(pickX, pickY,'*');
}