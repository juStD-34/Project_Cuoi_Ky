#pragma
#include <SDL.h>
#include "../gameEngine/Map.h"

using namespace std;

class SDLRender
{
private:
    int width;
    int height;
    SDL_Window* gwindow;
    SDL_Renderer* grenderer;
    int tile;

public:
    SDLRender(/* args */){};
    SDLRender ( int width, int height);
    void render (Map* map, int& speed, int& countPlay);
    void drawBall (int x, int y);
    void drawRect ( int& x, int& y, SDL_Color color);
    ~SDLRender();
    void drawLine (Map* map, int& startX , int& startY, int& endX, int& endY);
    void eraseLine (Map* map, int& startX , int& startY, int& endX, int& endY);
};