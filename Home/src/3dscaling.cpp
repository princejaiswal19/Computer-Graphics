#include <graphics.h>
#include <conio.h>

// Function to project and draw a scaled 3D cube
void drawScaledCube(int x, int y, int z, float sx, float sy, float sz) {
    // Front face (scaled)
    rectangle(x * sx, y * sy, (x + 100) * sx, (y + 100) * sy);

    // Back face (scaled with z-depth)
    rectangle((x + z) * sx, (y + z) * sy, (x + 100 + z) * sx, (y + 100 + z) * sy);

    // Connecting lines between front and back face
    line(x * sx, y * sy, (x + z) * sx, (y + z) * sy);
    line((x + 100) * sx, y * sy, (x + 100 + z) * sx, (y + z) * sy);
    line(x * sx, (y + 100) * sy, (x + z) * sx, (y + 100 + z) * sy);
    line((x + 100) * sx, (y + 100) * sy, (x + 100 + z) * sx, (y + 100 + z) * sy);
}

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, NULL);

    int x = 100, y = 100, z = 50;   // Initial cube coordinates
    float sx = 1.0f, sy = 1.0f, sz = 1.0f;  // Initial scaling factors
    char ch;

    // Loop to continuously update scaling factors and redraw the cube
    while (true) {
        cleardevice();  // Clear the screen

        // Draw the cube with scaling applied
        drawScaledCube(x, y, z, sx, sy, sz);

        // Handle keyboard input to scale along different axes
        ch = getch();
        if (ch == 'x') sx += 0.1f;  // Increase scale along X-axis
        if (ch == 'X') sx -= 0.1f;  // Decrease scale along X-axis
        if (ch == 'y') sy += 0.1f;  // Increase scale along Y-axis
        if (ch == 'Y') sy -= 0.1f;  // Decrease scale along Y-axis
        if (ch == 'z') sz += 0.1f;  // Increase scale along Z-axis
        if (ch == 'Z') sz -= 0.1f;  // Decrease scale along Z-axis

        // Escape condition (press ESC to exit)
        if (ch == 27) break;
    }

    closegraph();  // Close the graphics window
    return 0;
}
