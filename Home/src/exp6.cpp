#include <graphics.h>
#include <conio.h>
#include <iostream>

struct Point {
    float x, y;
};

// Define the clipping window boundaries
const float X_MIN = 100.0f;
const float X_MAX = 300.0f;
const float Y_MIN = 100.0f;
const float Y_MAX = 300.0f;

// Liang-Barsky line clipping algorithm
bool liangBarskyClip(Point p0, Point p1, Point& clippedP0, Point& clippedP1) {
    float dx = p1.x - p0.x;
    float dy = p1.y - p0.y;

    float p[4] = {-dx, dx, -dy, dy};
    float q[4] = {p0.x - X_MIN, X_MAX - p0.x, p0.y - Y_MIN, Y_MAX - p0.y};

    float t0 = 0.0f;
    float t1 = 1.0f;

    for (int i = 0; i < 4; i++) {
        if (p[i] == 0 && q[i] < 0) {
            return false; 
        }
        if (p[i] < 0) {
            float r = q[i] / p[i];
            if (r > t1) return false; // Line is outside
            else if (r > t0) t0 = r; // Update t0
        } else if (p[i] > 0) {
            float r = q[i] / p[i];
            if (r < t0) return false; // Line is outside
            else if (r < t1) t1 = r; // Update t1
        }
    }

   
    clippedP0.x = p0.x + t0 * dx;
    clippedP0.y = p0.y + t0 * dy;
    clippedP1.x = p0.x + t1 * dx;
    clippedP1.y = p0.y + t1 * dy;

    return true; // Line is within the clipping window
}

void drawClippingWindow() {
    rectangle(X_MIN, Y_MIN, X_MAX, Y_MAX);
}

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, ""); // Initialize graphics

    Point p0 = {50.0f, 150.0f};
    Point p1 = {350.0f, 250.0f};
    Point clippedP0, clippedP1;

    // Draw the original line segment
    setcolor(RED);
    line(p0.x, p0.y, p1.x, p1.y);

    // Draw the clipping window
    setcolor(WHITE);
    drawClippingWindow();

    // Clip the line segment
    if (liangBarskyClip(p0, p1, clippedP0, clippedP1)) {
        // Draw the clipped line segment
        setcolor(GREEN);
        line(clippedP0.x, clippedP0.y, clippedP1.x, clippedP1.y);
    } else {
        outtextxy(10, 10, "Line Segment is outside the clipping window.");
    }

    getch(); // Wait for a key press
    closegraph(); // Close the graphics window
return 0;
}