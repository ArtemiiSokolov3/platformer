#include <cmath>
#include <iostream>
#include "TXLib.h"
using namespace std;
class Player
{
    public:
    int x1 = 0;
    int dead = 0;
    string dead1 = "";
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
    int level=500;
    HDC right = txLoadImage("playerright.bmp");
    HDC left = txLoadImage("playerleft.bmp");
    string toString(int a)
    {
        string s = "";
        while( a > 0)
        {
            if (a % 10 == 0) s = "0" + s;
            if (a % 10 == 1) s = "1" + s;
            if (a % 10 == 2) s = "2" + s;
            if (a % 10 == 3) s = "3" + s;
            if (a % 10 == 4) s = "4" + s;
            if (a % 10 == 5) s = "5" + s;
            if (a % 10 == 6) s = "6" + s;
            if (a % 10 == 7) s = "7" + s;
            if (a % 10 == 8) s = "8" + s;
            if (a % 10 == 9) s = "9" + s;
            a = a / 10;
        }
        return s;
    }
    int Jamp()
    {

       if  (jampOn)
       {
        if (arrow==0)
        {
            if (x1/3<3)
            {
                y=y-(20-x1/3);
            }
            else
            {
                if(OnPl(y, x, sizeX) == 0)
                {
                    y=y+(x1+1)/3-20;
                }




            }
            x1=x1+5;
            x=x+5;
        }
        else
        {
            if (x1/3<3)
            {
                y=y-(20-x1/3);
            }
            else
            {
                if(OnPl(y, x, sizeX) == 0)
                {
                    y=y+(x1+1)/3-20;
                }
            }
            x1=x1+5;
            x=x-5;
        }
        }
        if (y>=level)
        {
          x1 = 0;
          jampOn = 0;
        }
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
    int Falling_Player()
    {
        if (y < level)
        {
            if (dy<=4) dy += 0.5;
            y += dy;
        }
    }
    int OnPl (int pltformY, int platformX, int platformSizeX)
    {
        if (y < pltformY + 75 && x < platformX + platformSizeX && x > platformX  )
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
int menu_deco()
{

    txSetFillColor(TX_RED);
    txCircle(40,40,20);
    txCircle(600,500,35);
    txSetFillColor(TX_GREEN);
    txCircle(170,200,80);
    txCircle(700,350,50);
    txSetFillColor(TX_YELLOW);
    txCircle(95,400,60);
    txCircle(630,150,100);
    txSetFillColor(TX_BLUE);
    txCircle(225,525,30);
    txCircle(740,550,10);
    txSetFillColor(TX_BLACK);
    txDrawText(20,550,160,600,"V. 1.0.0");
}
int main()
{
    int deco = 1;
    int ifer = 0;
    setlocale(LC_ALL,"Russian");
    txCreateWindow(800, 600);
    txSetColor(TX_BLACK);
    Platform platform(200, 75,40,200);
    Player player(74, 81, 41, 38);
    Platform plat1(200,75,200,350);
    int mode = 0;
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
            if(!player.jampOn)
            {
                player.level=platform.y - platform.sizeY;
                player.Falling_Player();
                player.dy = 0;
            }
        }
        else
        {
            if(!player.jampOn)
            {
                player.level=player.groundLevel;
                player.Falling_Player();

            }
        }
        if (player.y >= player.groundLevel)
        {
            player.y = 38;
            player.x = 41;
            player.dead = player.dead + 1;
        }
        player.dead1 = player.toString(player.dead);
        txTextOut (10, 100, player.dead1.c_str());
        txSleep(100);
        txClear();
         //0 - menu; 1 - game; 2 - settings; 3 - creators
        while(mode == 0)
        {
            txBegin();
            txClear();
            if(deco == 1)
            {
                menu_deco();
            }
            txSetColor(TX_BLACK);
            txDrawText(50,50,750,200,"ewg9ugfwwu9");
            txSetFillColor(TX_WHITE);
            txRectangle(300,200,500,300);
            txDrawText(300,200,500,300,"Играть");
            txRectangle(300,350,500,450);
            txDrawText(300,350,500,450,"Создатели");
            txRectangle(670,10,790,50);
            txDrawText(670,10,790,50,"Settings");
            txEnd();
            if(txMouseX()>=300 && txMouseX()<=500 && txMouseY()>=200 && txMouseY()<=300 && txMouseButtons() == 1)
            {
                mode = 1;
            }
            if(txMouseX()>=670 && txMouseX()<=790 && txMouseY()>=10 && txMouseY()<=50 && txMouseButtons() == 1)
            {
                mode = 2;
            }
            if(txMouseX()>=300 && txMouseX()<=500 && txMouseY()>=350 && txMouseY()<=450 && txMouseButtons() == 1)
            {
                mode = 3;
            }
        }
        while(mode==3)
        {
            txBegin();
            txClear();
            if(deco == 1)
            {
                menu_deco();
            }
            txSetFillColor(TX_WHITE);
            txRectangle(10,10,50,50);
            txDrawText(10,10,50,50,"||");
            if(txMouseX()>=10 && txMouseX()<=50 && txMouseY()>=10 && txMouseY()<=50 && txMouseButtons() == 1)
            {
                mode = 0;
            }
            txDrawText(50,50,750,100,"Создатели программировать не умеют поэтому эту игру");
            txDrawText(50,100,750,150,"написали ученики 1Ъ класса в надежде что им");
            txDrawText(50,150,750,200,"задонатят в бравл старс на леона!");
            txDrawText(50,200,750,250,"Сейчас они разрабатывают шарики v2");
            txDrawText(50,300,750,350,"Список изменений:");
            txDrawText(50,350,750,400,"Version 1.0.0:");
            txDrawText(50,400,750,450,"- Игра наконец-то вышла в релиз! УРА!!!");
            txEnd();
        }
        while(mode == 2)
        {
            txBegin();
            txRectangle(10,10,50,50);
            txDrawText(10,10,50,50,"||");
            txDrawText(10,10,800,100,"Settings");
            txRectangle(200,100,250,150);
            txDrawText(275,100,500,150,"Beautiful Menu");
            if(deco == 1)
            {
                txDrawText(200,100,250,150,"+");
            }
            txEnd();
            txClear();
            if(txMouseX()>=10 && txMouseX()<=50 && txMouseY()>=10 && txMouseY()<=50 && txMouseButtons() == 1)
            {
                mode = 0;
            }
            if(txMouseX()>=200 && txMouseX()<=250 && txMouseY()>=100 && txMouseY()<=150 && txMouseButtons() == 1)
            {
                if(deco == 0) {deco = 1;ifer = 1;}
                if(deco == 1 && ifer == 0) {deco = 0;}
                ifer = 0;

                txRectangle(10,10,50,50);
                txDrawText(10,10,50,50,"||");
                txDrawText(10,10,800,100,"Settings");
                txRectangle(200,100,250,150);
                txDrawText(275,100,500,150,"Beautiful Menu");

                txSleep(100);
            }

        }
    }
}
