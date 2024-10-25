#include<graphics.h>
#include <conio.h>

// Function to simulate projection of 3D points onto a 2D screen
void drawCube(int x, int y, int z) {
    // Front face of the cube (projected as 2D coordinates)
    rectangle(x, y, x + 100, y + 100);

    // Back face (with z-offset)
    rectangle(x + z, y + z, x + 100 + z, y + 100 + z);

    // Connect the front and back faces
    line(x, y, x + z, y + z);
    line(x + 100, y, x + 100 + z, y + z);
    line(x, y + 100, x + z, y + 100 + z);
    line(x + 100, y + 100, x + 100 + z, y + 100 + z);
}

// Main function to demonstrate 3D translation
int main() {
    // Initialize the graphics system
    int gd = DETECT, gm;
    initgraph(&gd, &gm, NULL);

    int x = 100, y = 100, z = 50;  // Initial cube position
    char ch;

    // Loop to continuously update the cube's position
    while (true) {
        cleardevice();  // Clear the screen

        // Draw the cube with current x, y, z values
        drawCube(x, y, z);

        // Move the cube based on user input
        ch = getch();
        if (ch == 'w') y -= 10;     // Move up
        if (ch == 's') y += 10;     // Move down
        if (ch == 'a') x -= 10;     // Move left
        if (ch == 'd') x += 10;     // Move right
        if (ch == 'z') z -= 10;     // Move back (increase depth)
        if (ch == 'x') z += 10;     // Move forward (decrease depth)

        // Escape condition
        if (ch == 27) break;        // Press ESC to exit
    }

    // Close the graphics mode and return to text mode
    closegraph();
    return 0;
}
