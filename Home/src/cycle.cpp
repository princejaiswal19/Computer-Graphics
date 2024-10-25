#include <graphics.h>

int main() {
    // Initialize graphics mode
    int gd = DETECT, gm;
    initgraph(&gd, &gm, NULL);

    // Draw the body of the car
    rectangle(150, 200, 450, 300);
    rectangle(200, 150, 400, 200);

    // Draw the windows
    line(200, 150, 200, 200);
    line(400, 150, 400, 200);
    line(300, 150, 300, 200);

    // Draw the wheels
    circle(225, 310, 25);
    circle(375, 310, 25);

    // Draw the roof of the car
    line(250, 150, 350, 150);

    // Keep the window open
    getch();

    // Close the graphics mode
    closegraph();
    return 0;
}