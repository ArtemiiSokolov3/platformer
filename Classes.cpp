#include <cmath>
#include <iostream>
#include "TXLib.h"
using namespace std;
class Player
{
    public:
    int jampOn = 0;
    int Hjamp = 250;
    int gampStep = 0;
    float dy = 0;
    int sizeX = 74;
    int sizeY = 81;
    int jump = 50;
    int speed = 10;
    int x = 41;
    int y = 38;
    int arrow = 1;
    int groundLevel = 500;
    HDC right = txLoadImage("playerright.bmp");
    HDC left = txLoadImage("playerleft.bmp");
    int Jamp()
    {
        gampStep = gampStep + Hjamp/8;
        if(Hjamp - gampStep > 0)
        {
            y = y -  Hjamp/8;

        }
        else
        {
            y = y +  Hjamp/8;

        }
        if (gampStep > Hjamp*2)
        {
            gampStep = 0;
            jampOn = 0;
        }
        x = x + sqrt(Hjamp);
    }
    Player(int sizeX1, int sizeY1, int x1, int y1)
    {
        sizeX = sizeX1;
        sizeY = sizeY1;
        x = x1;
        y = y1;
    }
    Player(int sizeX1, int sizeY1, int x1, int y1, string fileL, string fileR)
    {
        sizeX = sizeX1;
        sizeY = sizeY1;
        x = x1;
        y = y1;
        right = txLoadImage(fileR.c_str());
        left = txLoadImage(fileL.c_str());
    }
    int playerDraw()
    {
        if (arrow==0)
        {
            txTransparentBlt(txDC(), x, y, sizeX, sizeY, right, 0, 0, TX_WHITE);
        }
        else
        {
            txTransparentBlt(txDC(), x, y, sizeX, sizeY, left, 0, 0, TX_WHITE);
        }
    }
    int Move()
    {
        if (txGetAsyncKeyState(VK_LEFT))
        {
            if (x>0) {x=x-speed; arrow=1;}
        }
        if (txGetAsyncKeyState(VK_RIGHT))
        {
            if (x<750) {x=x+speed; arrow=0;}
        }
        if (txGetAsyncKeyState(VK_UP))
        {
            if(jampOn == 0)
            {
                jampOn = 1;
            }
        }
    }
    int Falling_Player(int level)
    {

        if (y < level)
        {
            dy += 0.5;
            y += dy;
        }
    }
    int OnPl (int pltformY, int platformX, int platformSizeX)
    {
        if (y < pltformY && x < platformX + platformSizeX && x > platformX)
        return 1;
        return 0;
    }
};
class Platform
{
    public:
    int sizeX = 200;
    int sizeY = 75;
    int x,y;
    HDC left = txLoadImage("platform.bmp");
    Platform(int sizeX1, int sizeY1, int x1, int y1)
    {
        sizeX=sizeX1;
        sizeY=sizeY1;
        x = x1;
        y = y1;
    }
    Platform(int sizeX1, int sizeY1,int x1, int y1, string fileK)
    {
        sizeX=sizeX1;
        sizeY=sizeY1;
        x = x1;
        y = y1;
        left = txLoadImage(fileK.c_str());
    }
    int platform_draw()
    {
        txTransparentBlt(txDC(), x, y, sizeX, sizeY, left,0,0, TX_WHITE);
    }
    int moveUPDOWN(int speed1)
    {
        y = y + speed1;
        if(y >= 599)
        {
            y = 20;
        }
    }
    int moveLEFTRIGHT(int speed2)
    {
        x = x + speed2;
        if(x >= 759)
        {
            x = 0;
        }
    }
};

int main()
{
    txCreateWindow(800, 600);
    Platform platform(200, 75,40,200);
    Player player(74, 81, 41, 38);
    Platform plat1(200,75,200,350);
    while(1)
    {
        player.playerDraw();
        player.Move();
        if(player.jampOn) player.Jamp();
        platform.platform_draw();
        plat1.platform_draw();
        plat1.moveLEFTRIGHT(5);
        platform.platform_draw();
        platform.moveLEFTRIGHT(5);
        if (player.OnPl(platform.y, platform.x, platform.sizeX))
        {
           if(!player.jampOn) player.Falling_Player(platform.y - platform.sizeY);
        }
        else
        {
          if(!player.jampOn)  player.Falling_Player(player.groundLevel);
        }
        txSleep(100);
        txClear();
    }
}
