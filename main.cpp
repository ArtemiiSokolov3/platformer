#include <iostream>
#include "TXLib.h"
using namespace std;

class Player
{
public:
    int sizeX = 74;
    int sizeY = 81;
    int jump = 50;
    int speed = 10;
    int x = 41;
    int y = 38;
    int turn = -1;
    Player(int sizeX1, int sizeY1, int x1, int y1)
    {
        sizeX=sizeX1;
        sizeY=sizeY1;
        x=x1;
        y=y1;

    } 
    void player_draw()
    {
        if (turn == 1)
        {
            txTransparentBlt(txDC(), x, y, sizeX, sizeY, "playerright.bmp");
        }
        if (turn == 0)
        {
            txTransparentBlt(txDC(), x, y, sizeX, sizeY, "playerleft.bmp");
        }
    }
    void player_control()
    {
        if (txGetAsyncKeyState(VK_RIGHT))
        {
            x = x + 5;
            turn = 1;
        }
        if (txGetAsyncKeyState(VK_LEFT))
        {
            x = x - 5;
            turn = 0;
        }
        if (y < 562)
        {
            y = y + 2;
        }
        if (y > 562)
        {
            y = 562;
        }
        if (txGetAsyncKeyState(VK_UP))
        {
            if (y == 562)
            {
                for (int i; i >= 10; i++)
                {
                    y = y - 4;
                }
            }
        }
    }
    void updatescreen()
    {
        txClear();
    }

};

class Platform
{
public:
    int sizeX = 200;
    int sizeY = 75;
    Platform(int sizeX1, int sizeY1)
    {
        sizeX=sizeX1;
        sizeY=sizeY1;
    }
    void platform_draw(int x, int y)
    {
        txTransparentBlt(txDC(), x, y, sizeX, sizeY, "platform.bmp");
    }
};

int main()
{
    Platform platform(200, 75);
    Player player(74,81,38,42);
    txCreateWindow(800, 600);
    while (1)
    {
        player.player_control();
        player.player_draw();
        player.updatescreen();
    }


    return 0;
}
