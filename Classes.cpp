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
        right = txLoadImage(fileR);
        left = txLoadImage(fileL);
    } 
    void playerright_draw()
    {
        txTransparentBlt(txDC(), x, y, sizeX, sizeY, right);
    }

    void playerleft_draw()
    {
        txTransparentBlt(txDC(), x, y, sizeX, sizeY, left);
    }


};

class Platform
{
public:
    int sizeX = 200;
    int sizeY = 75;
    HDC left = txLoadImage("platform.png");
    Platform(int sizeX1, int sizeY1)
    {
        sizeX=sizeX1;
        sizeY=sizeY1;
    }
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
