#include <graphics.h>
#include <math.h>
#include <conio.h>
#include <dos.h>

// Constants
const int WINDOW_WIDTH = 640;
const int WINDOW_HEIGHT = 480;
const int PIVOT_X = 320;  
const int PIVOT_Y = 100;  
const int LENGTH = 200;   
const int RADIUS = 20;    


const float GRAVITY = 9.8;
const float ANGLE_AMPLITUDE = 0.5;  
const float TIME_STEP = 0.05;       


void drawDDALine(int x0, int y0, int x1, int y1) {
    int dx = x1 - x0;
    int dy = y1 - y0;
    int steps = abs(dx) > abs(dy) ? abs(dx) : abs(dy);
    float xInc = dx / (float)steps;
    float yInc = dy / (float)steps;
    float x = x0, y = y0;

    for (int i = 0; i <= steps; i++) {
        putpixel(round(x), round(y), WHITE);
        x += xInc;
        y += yInc;
    }
}

void drawPendulum(float angle) {
   
    cleardevice();

  
    int bobX = PIVOT_X + LENGTH * sin(angle);
    int bobY = PIVOT_Y + LENGTH * cos(angle);

    
    drawDDALine(PIVOT_X, PIVOT_Y, bobX, bobY);

    
    setcolor(RED);
    circle(bobX, bobY, RADIUS);
    floodfill(bobX, bobY, RED);

   
    setcolor(WHITE);
    setfillstyle(SOLID_FILL, WHITE);
    circle(PIVOT_X, PIVOT_Y, 5);
    
}

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, NULL);

   
    float angle = ANGLE_AMPLITUDE;  
    float angularVelocity = 0;
    float angularAcceleration = 0;

    
    while (!kbhit()) {
       
        angularAcceleration = -(GRAVITY / LENGTH) * sin(angle);
        angularVelocity += angularAcceleration * TIME_STEP;
        angle += angularVelocity * TIME_STEP;

        
        drawPendulum(angle);

       
        delay(20);
    }

    closegraph();
    return 0;
}
