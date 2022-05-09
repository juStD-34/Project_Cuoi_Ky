#include "SDLRender.h"

SDL_Color WHITE = {255 , 255 , 255, 255},
          BLACK = {0, 0, 0, 255},
          GREEN = {0, 255, 0, 255},
          RED = {255, 0, 0, 255},
          BLUE = {0, 0, 255, 255},
          WallColor = BLACK,
          GoalColor = {183, 183, 183 , 255},
          BallColor = {248, 248, 255, 255}
          ;
          
SDLRender::SDLRender(int width_, int height_)
{
    tile = 10;
    cout<<100<<endl;
    width = width_ * tile;
    height = height_ * tile;
    if (SDL_Init (SDL_INIT_VIDEO) <0)
    {
        cout<<"SDL couldn't init() "<<SDL_GetError();
    }
    else
    {
        gwindow = SDL_CreateWindow( "Ball game",SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, width, height, SDL_WINDOW_SHOWN);
        if (gwindow == NULL ) cout<<"Fall to init! "<<SDL_GetError();
        else
        {
            grenderer = SDL_CreateRenderer(gwindow, -1, SDL_RENDERER_ACCELERATED);
            if (grenderer == NULL) cout<<"Couldn't renderer!";
        }
    }
}

void SDLRender::render( Map* map, int& speed, int& countPlay)
{
    /*SDL_SetRenderDrawColor (grenderer, RED.r, RED.g, RED.b, RED.a);8
    SDL_RenderClear(grenderer);

    int height = map->getHeight();
    int width = map->getWidht();
    for (int i = 0 ; i < width ; i ++)
    {
        for (int j =0; j < height; j++)
        {
            if ((i+j) % 2 == 0)
            {
                drawRect (i,j,GREEN);
            }else
            {
                drawRect (i,j, WHITE);
            }

            switch (map->getCell(i,j))
            {
            case 'w':
                drawRect ( i,j, WallColor);
                break;
            case 'O':
                drawRect (i, j, BallColor);
                break;
            case 'g':
                drawRect (i, j, GoalColor);
                break;
            default:
                break;
            }
        }
    }
    SDL_RenderPresent (grenderer);*/

}

void SDLRender::drawRect(int& x, int& y, SDL_Color color)
{
    /*SDL_SetRenderDrawColor( grenderer, color.r, color.g, color.b, color.a);
    SDL_Rect rect = {x*tile, y*tile, tile, tile};
    SDL_RenderFillRect(grenderer, &rect);*/
}
void SDLRender::drawLine(Map* map, int& startX , int& startY, int& endX, int& endY)
{
   // drawRect(endX, endY, BLUE);
}
void SDLRender::eraseLine(Map* map, int& startX , int& startY, int& endX, int& endY)
{
   /* if ((endX+endY) % 2 == 0)
    {
        drawRect (endX, endY,GREEN);
    }else
    {
        drawRect (endX, endY, WHITE);
    }*/
}