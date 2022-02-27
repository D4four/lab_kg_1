#include "line.h"
#include <iostream>
#include <cmath>

void Line::draw(QPainter& painter, int matrixCor[2][2]){

    int deltaX = matrixCor[0][1] - matrixCor[0][0];
    int deltaY = matrixCor[1][1] - matrixCor[1][0];
    int absDeltaX = abs(deltaX);
    int absDeltaY = abs(deltaY);

    int accretion = 0;

    if (absDeltaX >= absDeltaY) {
        int y = matrixCor[1][0];
        int direction = deltaY != 0 ? (deltaY > 0 ? 1 : -1) : 0;
        for (int x = matrixCor[0][0]; deltaX > 0 ? x <= matrixCor[0][1] : x >= matrixCor[0][1]; deltaX > 0 ? x++ : x--) {
            painter.setPen(Qt::red);
            painter.drawPoint(x, y);
            painter.setPen(Qt::transparent);

            accretion += absDeltaY;

            if (accretion >= absDeltaX) {
                accretion -=absDeltaX;
                y += direction;
            }
        }
    } else {
        int x = matrixCor[0][0];
        int direction = deltaX != 0 ? (deltaX > 0 ? 1 : -1) : 0;
        for (int y = matrixCor[1][0]; deltaY > 0 ? y <= matrixCor[1][1] : y >= matrixCor[1][1]; deltaY > 0 ? y++ : y--) {
            painter.setPen(Qt::red);
            painter.drawPoint(x, y);
            painter.setPen(Qt::transparent);

            accretion += absDeltaX;

            if (accretion >= absDeltaY) {
                accretion -=absDeltaY;
                x += direction;
            }
        }
    }
};

void Line::spin(int matrixCor[2][2], int deg) {

    int rx;
    int ry;


    rx = matrixCor[0][0] + (matrixCor[0][1] - matrixCor[0][0])*cos(deg*3.1415/180) - (matrixCor[1][1] - matrixCor[1][0])*sin(deg*3.1415/180);
    ry = matrixCor[1][0] + (matrixCor[0][1] - matrixCor[0][0])*sin(deg*3.1415/180) +(matrixCor[1][1] - matrixCor[1][0])*cos(deg*3.1415/180);


    std::cout << rx << std::endl << ry;
    matrixCor[0][1] = rx;
    matrixCor[1][1] = ry;

}
