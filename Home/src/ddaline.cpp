#include <graphics.h>
#include <iostream>
#include <cmath>

// Function to draw a line using DDA algorithm
void ddaLine(int x0, int y0, int x1, int y1) {
    int dx = x1 - x0;
    int dy = y1 - y0;

    int steps = abs(dx) > abs(dy) ? abs(dx) : abs(dy);

    float Xinc = dx / static_cast<float>(steps);
    float Yinc = dy / static_cast<float>(steps);

    float x = x0;
    float y = y0;

    for (int i = 0; i <= steps; i++) {
        putpixel(round(x), round(y), WHITE); // Plot the pixel
        x += Xinc;
        y += Yinc;
    }
}

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, NULL);  // Initialize the graphics system

    int x0=50, y0=60, x1=100, y1=120;
    // std::cout << "Enter the coordinates of the first point (x0 y0): ";
    // std::cin >> x0 >> y0;
    // std::cout << "Enter the coordinates of the second point (x1 y1): ";
    // std::cin >> x1 >> y1;

    // Draw the line using DDA algorithm
    ddaLine(x0, y0, x1, y1);

    // Pause to view the output
    getch();
    closegraph();  // Close the graphics system

    return 0;
}
