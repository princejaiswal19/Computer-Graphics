#include <graphics.h>
#include <iostream>
#include <cmath>


void plot(int x, int y) {
    putpixel(x, y, WHITE);  
}

// Bresenham's line algorithm using graphics
void bresenhamLine(int x0, int y0, int x1, int y1) {
    int dx = abs(x1 - x0);
    int dy = abs(y1 - y0);
    int sx = (x0 < x1) ? 1 : -1;
    int sy = (y0 < y1) ? 1 : -1; 
    int err = dx - dy;

    while (true) {
        plot(x0, y0);  // Plot the pixel
        if (x0 == x1 && y0 == y1) break;
        int e2 = 2 * err;
        if (e2 > -dy) {
            err -= dy;
            x0 += sx;
        }
        if (e2 < dx) {
            err += dx;
            y0 += sy;
        }
    }
}

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, NULL);  // Initialize the graphics system

    int x0, y0, x1, y1;
    
    x0=10;
    y0=15;
    x1=50;
    y1=65;

   
    bresenhamLine(x0, y0, x1, y1);

   
    getch();
    closegraph();  

    return 0;
}
