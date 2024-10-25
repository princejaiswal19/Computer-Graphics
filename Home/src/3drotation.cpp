#include<graphics.h>
#include <iostream>
#include <math.h>

using namespace std;

struct Point3D {
    int x, y, z;
};

void drawLine(Point3D p1, Point3D p2) {
    int perspectiveX1 = p1.x - p1.z / 2;
    int perspectiveY1 = p1.y - p1.z / 2;
    int perspectiveX2 = p2.x - p2.z / 2;
    int perspectiveY2 = p2.y - p2.z / 2;
    line(perspectiveX1, perspectiveY1, perspectiveX2, perspectiveY2);
}

void drawCube(Point3D cube[8]) {
    drawLine(cube[0], cube[1]);
    drawLine(cube[1], cube[2]);
    drawLine(cube[2], cube[3]);
    drawLine(cube[3], cube[0]);
    drawLine(cube[4], cube[5]);
    drawLine(cube[5], cube[6]);
    drawLine(cube[6], cube[7]);
    drawLine(cube[7], cube[4]);
    drawLine(cube[0], cube[4]);
    drawLine(cube[1], cube[5]);
    drawLine(cube[2], cube[6]);
    drawLine(cube[3], cube[7]);
}

void translate3D(Point3D cube[8], int tx, int ty, int tz) {
    for (int i = 0; i < 8; i++) {
        cube[i].x += tx;
        cube[i].y += ty;
        cube[i].z += tz;
    }
}

void scale3D(Point3D cube[8], float sx, float sy, float sz) {
    for (int i = 0; i < 8; i++) {
        cube[i].x = int(cube[i].x * sx);
        cube[i].y = int(cube[i].y * sy);
        cube[i].z = int(cube[i].z * sz);
    }
}

void rotateX3D(Point3D cube[8], float angle) {
    float rad = angle * M_PI / 180;
    for (int i = 0; i < 8; i++) {
        int tempY = cube[i].y;
        cube[i].y = int(tempY * cos(rad) - cube[i].z * sin(rad));
        cube[i].z = int(tempY * sin(rad) + cube[i].z * cos(rad));
    }
}

void rotateY3D(Point3D cube[8], float angle) {
    float rad = angle * M_PI / 180;
    for (int i = 0; i < 8; i++) {
        int tempX = cube[i].x;
        cube[i].x = int(tempX * cos(rad) + cube[i].z * sin(rad));
        cube[i].z = int(-tempX * sin(rad) + cube[i].z * cos(rad));
    }
}

void rotateZ3D(Point3D cube[8], float angle) {
    float rad = angle * M_PI / 180;
    for (int i = 0; i < 8; i++) {
        int tempX = cube[i].x;
        cube[i].x = int(tempX * cos(rad) - cube[i].y * sin(rad));
        cube[i].y = int(tempX * sin(rad) + cube[i].y * cos(rad));
    }
}

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, NULL);

    Point3D cube[8] = {
        {100, 100, 100}, {200, 100, 100}, {200, 200, 100}, {100, 200, 100},
        {100, 100, 200}, {200, 100, 200}, {200, 200, 200}, {100, 200, 200}
    };

    drawCube(cube);
    delay(1000);
    translate3D(cube, 50, 50, 50);
    cleardevice();
    drawCube(cube);
    delay(1000);
    scale3D(cube, 1.5, 1.5, 1.5);
    cleardevice();
    drawCube(cube);
    delay(1000);
    rotateX3D(cube, 45);
    cleardevice();
    drawCube(cube);
    delay(1000);
    rotateY3D(cube, 45);
    cleardevice();
    drawCube(cube);
    delay(1000);
    rotateZ3D(cube, 45);
    cleardevice();
    drawCube(cube);
    delay(1000);

    getch();
    closegraph();
return 0;
}
