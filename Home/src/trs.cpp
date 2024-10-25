#include<stdio.h> 
#include<graphics.h> 
#include<math.h> 
#include<iostream>
using namespace std;

int main() 
{ 
    int gd=0, gm, x1, y1, x2, y2; 
    double s, c, angle; 
    initgraph(&gd, &gm, NULL); 

    // Set random coordinates for the line
    x1 = 100; y1 = 150; 
    x2 = 300; y2 = 250;

    // Predefined rotation angle (e.g., 45 degrees)
    angle = 45;

    setbkcolor(WHITE); 
    cleardevice(); 

    // Draw the original line in RED
    setcolor(RED); 
    line(x1, y1, x2, y2); 

    // Rotation calculations
    c = cos(angle * M_PI / 180); 
    s = sin(angle * M_PI / 180); 

    // Applying rotation transformation to the points
    int x1_new = floor(x1 * c + y1 * s); 
    int y1_new = floor(-x1 * s + y1 * c); 

    int x2_new = floor(x2 * c + y2 * s); 
    int y2_new = floor(-x2 * s + y2 * c); 

    // Draw the rotated line in GREEN
    setcolor(GREEN); 
    line(x1_new, y1_new, x2_new, y2_new); 

    getch(); 
    closegraph(); 

    return 0; 
}
