#include <graphics.h>
#include <conio.h>
#include <cmath>

// DDA Line Drawing Algorithm
void drawLineDDA(int x1, int y1, int x2, int y2) {
    int dx = x2 - x1;
    int dy = y2 - y1;

    int steps = abs(dx) > abs(dy) ? abs(dx) : abs(dy);  

    float xIncrement = dx / (float)steps;
    float yIncrement = dy / (float)steps;

    float x = x1;
    float y = y1;

    for (int i = 0; i <= steps; i++) {
        putpixel(round(x), round(y), WHITE);  
        x += xIncrement;  
        y += yIncrement; 
    }
}

// Bresenham's Circle Drawing Algorithm
void drawCircleBresenham(int xc, int yc, int r) {
    int x = 0, y = r;
    int d = 3 - 2 * r;

    auto drawSymmetricPoints = [&](int x, int y) {
        putpixel(xc + x, yc + y, WHITE);
        putpixel(xc - x, yc + y, WHITE);
        putpixel(xc + x, yc - y, WHITE);
        putpixel(xc - x, yc - y, WHITE);
        putpixel(xc + y, yc + x, WHITE);
        putpixel(xc - y, yc + x, WHITE);
        putpixel(xc + y, yc - x, WHITE);
        putpixel(xc - y, yc - x, WHITE);
    };

    while (y >= x) {
        drawSymmetricPoints(x, y);
        x++;

        if (d > 0) {
            y--;
            d = d + 4 * (x - y) + 10;
        } else {
            d = d + 4 * x + 6;
        }

        drawSymmetricPoints(x, y);
    }
}


void drawPendulum(int x1, int y1, int x2, int y2, int pendulumCenterX, int pendulumCenterY, float angle) {
    cleardevice(); 

   
    int bobX = pendulumCenterX + 100 * sin(angle); 
    int bobY = pendulumCenterY + 100 * cos(angle); 
    drawLineDDA(pendulumCenterX, pendulumCenterY, bobX, bobY);

   
    drawCircleBresenham(bobX, bobY, 30);  

    
    drawLineDDA(x1, y1, x1, y2); 
    drawLineDDA(x2, y1, x2, y2);
    for(int i = x1; i < x2; i++) {
        drawLineDDA(i, y1, i, y2);
    }
}

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");

   
    float angle = 0; 
    float angleVelocity = 0;  
    float angleAcceleration = 0;  
    const float gravity = 0.01;  

    int x1 = 200;
    int y1 = 100;
    int y2 = 300;
    int x2 = 210;

  
    int pendulumCenterX = (x1 + x2) / 2;  
    int pendulumCenterY = y1;  

  
    while (!kbhit()) {
       
        angleAcceleration = (-1 * gravity) * sin(angle);  
        angleVelocity += angleAcceleration;  
        angle += angleVelocity;  


        angleVelocity *= 0.99;

        
        drawPendulum(x1, y1, x2, y2, pendulumCenterX, pendulumCenterY, angle);

        delay(20);
    }

    getch();
    closegraph();
    return 0;
}
