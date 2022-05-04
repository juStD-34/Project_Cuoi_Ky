
#pragma
#include <iostream>

using namespace std;

class Map
{
private:
    int width, height;
    char** border;
public:
    Map(/* args */);
    Map( char** a);
    Map(int w, int h);
    Map(int w, int h, char arr[]);
    ~Map();
    void setCell(int x, int y, char symbol);
    char getCell(int x, int y);
    void printMap();
    int getWidht();
    int getHeight();
    void addMap(Map& map_ );
};