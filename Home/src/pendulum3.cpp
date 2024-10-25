#include <graphics.h>
#include <conio.h>
#include <cmath>

const float GRAVITY = 9.8;
const float ANGLE_AMPLITUDE = 0.5;  
const float TIME_STEP = 0.05;

void drawpendulum(){
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

} 
}


int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");

 
    int x = 200;
    int y1 = 100;
    int y2 = 300;

  
    drawLineDDA(x, y1, x, y2); 
    drawLineDDA(210, y1, 210, y2);

    
    for(int i = x; i < 210; i++) {
        drawLineDDA(i, y1, i, y2);
    }


    int pendulumCenterX = (x + 210) / 2;  
    int pendulumCenterY = y2;             
    
    
    
    for(int i=0;i<30;i++){
        drawCircleBresenham(pendulumCenterX, pendulumCenterY + 30, i);

    }  
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

    getch(); 
    closegraph();  
 return 0;
}