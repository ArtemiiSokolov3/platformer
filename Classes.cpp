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
    int arrow = 1;
    HDC right = txLoadImage("playerright.bmp");
    HDC left = txLoadImage("playerleft.bmp");

    Player(int sizeX1, int sizeY1, int x1, int y1)
    {
        sizeX=sizeX1;
        sizeY=sizeY1;
        x=x1;
        y=y1;
    }
    Player(int sizeX1, int sizeY1, int x1, int y1, string fileL, string fileR)
    {
        sizeX=sizeX1;
        sizeY=sizeY1;
        x=x1;
        y=y1;
        right = txLoadImage(fileR.c_str());
        left = txLoadImage(fileL.c_str());
    }
    int playerright_draw()
    {
        txTransparentBlt(txDC(), x, y, sizeX, sizeY, right, 0, 0, TX_WHITE);
    }

    int playerleft_draw()
    {
        txTransparentBlt(txDC(), x, y, sizeX, sizeY, left, 0, 0,TX_WHITE);
    }
    int Move()
    {
        if (txGetAsyncKeyState(VK_LEFT))
        {
            if (x>0) {x=x-5; arrow=1;}
        }
        if (txGetAsyncKeyState(VK_RIGHT))
        {
            if (x<750) {x=x+5; arrow=0;}
        }
        if (txGetAsyncKeyState(VK_UP))
        {
            if (y>300) y=y-5;
        }
    }
};
class Platform
{
public:
    int sizeX = 200;
    int sizeY = 75;
    int x = 120;
    int y = 160;
    HDC left = txLoadImage("platform.bmp");
    Platform(int sizeX1, int sizeY1)
    {
        sizeX=sizeX1;
        sizeY=sizeY1;
    }
    Platform(int sizeX1, int sizeY1, string fileK)
    {
        sizeX=sizeX1;
        sizeY=sizeY1;
        left = txLoadImage(fileK.c_str());
    }
    int platform_draw()
    {
        txTransparentBlt(txDC(), x, y, sizeX, sizeY, left);
    }
};

int main()
{
    txCreateWindow(800, 600);
    Platform b(200, 75);
    Player a(74, 81, 41, 38);
    while(1)
    {
        a.Move();
        a.playerright_draw();
        b.platform_draw();
        txSleep(100);
        txClear();
    }
}
