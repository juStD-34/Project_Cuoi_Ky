
#include "Map.h"

using namespace std;



Map::Map(int w, int h)
{
    width =w;
    height =h;
    border = new char*[w];
    for ( int i =0 ; i < w; i++)
    {
        border[i] = new char[h];
    }
}
Map::Map (int w, int h, char arr[])
{
    width =w;
    height =h;
    border = new char*[w];
    for ( int i =0 ; i < w; i++)
    {
        border[i] = new char[h];
    }
    for (int i =0 ; i < w; i++)
    {
        for (int j =0 ; j < h; j++)
        {
            border[i][j] = arr[i*h +j];
        }
    }
}
Map::~Map()
{
    delete [] border;
}

void Map::setCell(int x, int y, char symbol)
{
    border[x][y] = symbol;
}

void Map::printMap()
{
    for ( int i =0; i < width; i++)
    {
        for ( int j =0; j< height;j++ )
        {
            cout<<border[i][j];
        }
        cout<<endl;
    }
}

char Map::getCell(int x, int y)
{
    return border[x][y];
}

int Map::getWidht()
{
    return width;
}

int Map::getHeight()
{
    return height;
}

void Map::addMap(Map& map_)
{
    for (int i =0 ;i < width; i ++)
    {
        for (int j = 0; j < height; j ++)
        {
            border[i][j] = map_.getCell(i,j);
        }
    }
}