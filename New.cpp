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

int main()
{
    int deco = 1;
    int ifer = 0;
    setlocale(LC_ALL,"Russian");
    txCreateWindow(800, 600);
    Platform platform(200, 75,40,200);
    Player player(74, 81, 41, 38);
    Platform plat1(200,75,200,350);
    int mode = 0;
    while(1)
    {
        while(mode == 1)
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
            txRectangle(10,10,50,50);
            txDrawText(10,10,50,50,"||");
            if(txMouseX()>=10 && txMouseX()<=50 && txMouseY()>=10 && txMouseY()<=50 && txMouseButtons() == 1)
            {
                mode = 0;
            }
            txSleep(100);
            txClear();
        }
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
