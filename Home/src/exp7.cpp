#include <graphics.h>
#include <conio.h> // for getch()

#define INSIDE 0  // 0000
#define LEFT 1    // 0001
#define RIGHT 2   // 0010
#define BOTTOM 4   // 0100
#define TOP 8      // 1000

const int x_min = 100;
const int y_min = 100;
const int x_max = 400;
const int y_max = 400;

int computeCode(float x, float y) {
    int code = INSIDE;

    if (x < x_min)      // to the left of the clipping window
        code |= LEFT;
    else if (x > x_max) // to the right of the clipping window
        code |= RIGHT;
    if (y < y_min)      // below the clipping window
        code |= BOTTOM;
    else if (y > y_max) // above the clipping window
        code |= TOP;

    return code;
}

void cohenSutherland(float x1, float y1, float x2, float y2) {
    int code1 = computeCode(x1, y1);
    int code2 = computeCode(x2, y2);
    bool accept = false;

    while (true) {
        if ((code1 | code2) == 0) { // both points inside
            accept = true;
            break;
        } else if ((code1 & code2) != 0) { // both points outside
            break;
        } else {
            float x, y;
            int code_out = code1 ? code1 : code2;

            // Find the intersection point using the clipping boundary
            if (code_out & TOP) {
                x = x1 + (x2 - x1) * (y_max - y1) / (y2 - y1);
                y = y_max;
            } else if (code_out & BOTTOM) {
                x = x1 + (x2 - x1) * (y_min - y1) / (y2 - y1);
                y = y_min;
            } else if (code_out & RIGHT) {
                y = y1 + (y2 - y1) * (x_max - x1) / (x2 - x1);
                x = x_max;
            } else if (code_out & LEFT) {
                y = y1 + (y2 - y1) * (x_min - x1) / (x2 - x1);
                x = x_min;
            }

            // Replace outside point with intersection point
            if (code_out == code1) {
                x1 = x;
                y1 = y;
                code1 = computeCode(x1, y1);
            } else {
                x2 = x;
                y2 = y;
                code2 = computeCode(x2, y2);
            }
        }
    }

    if (accept) {
        // Draw the clipped line
        line(int(x1), int(y1), int(x2), int(y2));
    }
}

int main() {
    // Initialize the graphics system
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");

    // Draw clipping window
    rectangle(x_min, y_min, x_max, y_max);

    // Define some lines to clip
    cohenSutherland(50, 150, 450, 150); // Outside left
    cohenSutherland(150, 50, 150, 450); // Outside top
    cohenSutherland(200, 200, 300, 300); // Inside
    cohenSutherland(400, 400, 500, 500); // Outside right

    // Wait for user input
    getch();
    closegraph();
return 0;
}
