#include "consoleRenderer.h"
#include <windows.h>
void consoleRenderer::render(Map* map, int& speed, int& countPlay)
{
    system("cls");
    int width = map->getWidht();
    int height = map->getHeight();
    for (int i =0 ; i < width; i++)
    {
        for (int j =0 ; j < height; j++)
        {
            if (map->getCell(i,j) == 'O') cout<<'O';else
            if (map->getCell(i,j) == 'w') cout<<'w';else
            if (map->getCell(i,j) == 'g') cout<<'g';else
            if (map->getCell(i,j) == 'L') cout<<'L';else
            if (map->getCell(i,j) == '*') cout<<'*';
        }
        cout<<endl;
    }
    cout<<countPlay<<endl;
    Sleep(speed);
}
void consoleRenderer::drawLine (Map* map, int& pickX, int& pickY)
{
    map->setCell(pickX,pickY,'L');
}
void consoleRenderer::eraseLine(Map* map, int& pickX, int & pickY)
{
    map->setCell(pickX, pickY,'*');
}