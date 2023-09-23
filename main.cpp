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
    HDC right = txLoadImage("playerright.png");
    HDC left = txLoadImage("playerleft.png");

    Player(int sizeX1, int sizeY1, int x1, int y1, string fileL, string fileR)
    {
        sizeX=sizeX1;
        sizeY=sizeY1;
        x=x1;
        y=y1;
        right = txLoadImage(fileR);
        left = txLoadImage(fileL);
    } 
    void player_draw()
    {
        if (txGetAsyncKeyState(VK_RIGHT))
        {
            txTransparentBlt(txDC(), x, y, sizeX, sizeY, right);
        }
        if (txGetAsyncKeyState(VK_LEFT))
        {
            txTransparentBlt(txDC(), x, y, sizeX, sizeY, left);
        }
    }
    void player_control()
    {
        if (txGetAsyncKeyState(VK_RIGHT))
        {
            x = x + 5;
        }
        if (txGetAsyncKeyState(VK_LEFT))
        {
            x = x - 5;
        }
    }

};

class Platform
{
public:
    int sizeX = 200;
    int sizeY = 75;
    HDC left = txLoadImage("platform.png");
    Platform(int sizeX1, int sizeY1, string fileK)
    {
        sizeX=sizeX1;
        sizeY=sizeY1;
        left = txLoadImage(fileK);
    }
    void platform_draw(int x, int y)
    {
        txTransparentBlt(txDC(), x, y, sizeX, sizeY, left);
    }
};

int main()
{
    Platform platform(200, 75, "platform.png");
    Player player(74,81,38,42,"playerleft.png","playerright.png");
    txCreateWindow(800, 600);
    while (1)
    {
        player.player_control();
        player.player_draw();
        if (player.y > 38)
        {
            player.y = player.y - 2;
        }
        if (player.y < 38)
        {
            player.y = 38;
        }
        if (txGetAsyncKeyState(VK_UP))
        {
            if (player.y == 38)
            {
                for (int i; i >= 10; i++)
                {
                    player.y = player.y + 4;
                }
            }
        }
    }


    return 0;
}
