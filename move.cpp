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
