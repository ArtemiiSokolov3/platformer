#include "TXLib.h"
int main()
{
    txCreateWindow(800, 600);
    txSetFillColor(TX_WHITE);
    txClear();
    txSetColor(TX_BLACK);
    txSetFillColor(TX_BLACK);
    txRectangle(100,100,350,150);
}
