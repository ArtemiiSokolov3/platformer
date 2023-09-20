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

    void playerright_draw()
    {
        txTransparentBlt(txDC(), x, y, sizeX, sizeY, right);
    }

    void playerleft_draw()
    {
        txTransparentBlt(txDC(), x, y, sizeX, sizeY, left);
    }


};

class platform
{
public:
    int sizeX = 200;
    int sixeY = 75;
    HDC left = txLoadImage("platform.png");

    void platform_draw(int x, int y)
    {
        txTransparentBlt(txDC(), x, y, sizeX, sixeY, left);
    }
};
int main()
{
    cout << "Hello World!";

    return 0;
}
