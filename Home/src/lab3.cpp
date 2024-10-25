// C-program for circle drawing
// using Bresenham’s Algorithm
// in computer-graphics
#include <stdio.h>
#include <dos.h>
#include <math.h> 
#include <graphics.h>

// Function to put pixels
// at subsequence points
void drawCircle(int xc, int yc, int x, int y)
{
    putpixel(xc+x, yc+y, RED);
    putpixel(xc-x, yc+y, RED);
    putpixel(xc+x, yc-y, RED);
    putpixel(xc-x, yc-y, RED);
    putpixel(xc+y, yc+x, RED);
    putpixel(xc-y, yc+x, RED);
    putpixel(xc+y, yc-x, RED);
    putpixel(xc-y, yc-x, RED);
}

// Function for circle-generation
// using Bresenham's algorithm
void circleBres(int xc, int yc, int r)
{
    int x = 0, y = r;
    int d = 3 - 2 * r;
    drawCircle(xc, yc, x, y);
    while (y >= x)
    {
        // for each pixel we will
        // draw all eight pixels
        
        x++;

        // check for decision parameter
        // and correspondingly 
        // update d, x, y
        if (d > 0)
        {
            y--; 
            d = d + 4 * (x - y) + 10;
        }
        else
            d = d + 4 * x + 6;
        drawCircle(xc, yc, x, y);
        delay(100);
    }
}

void bresenhamLine(int x1, int y1, int x2, int y2) {
    int dx = x2 - x1;
    int dy = y2 - y1;

    int x = x1, y = y1;

    int p = 2 * dy - dx;
    while (x <= x2) {
        putpixel(x, y, WHITE);
        x++;
        if (p < 0) {
            p = p + 2 * dy;
        } else {
            y++;
            p = p + 2 * dy - 2 * dx;
        }
    }
}


// Driver code
int main()
{
    int xc = 50, yc = 200, r = 50;
    int xc2 = 200, yc2 = 200, r2 = 50;

    int gd = DETECT, gm;
    initgraph(&gd, &gm, NULL);  // initialize graph
    circleBres(xc, yc, r);    // function call
    circleBres(xc2,yc2,r2);
    
  
    //  int gd = DETECT, gm;
    // initgraph(&gd, &gm, "");

    int x1 = -100, y1 = 250, x2 = 300, y2 = 250;
    bresenhamLine(x1, y1, x2, y2);
    int x4 = -50, y4 = 350, x5 = 200, y5 = 350;
    bresenhamLine(x4, y4, x5, y5);
    int x7 = -100, y7 = 250, x8 = -50, y8 = 350;
    bresenhamLine(x7, y7, x8, y8);

    getch();
    closegraph(); 
    return 0;
}
