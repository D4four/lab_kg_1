#ifndef LINE_H
#define LINE_H

#include <QPainter>
class Line
{
public:
    void draw (QPainter& painter, int matrixCor[2][2]);
    void spin (int matrixCor[2][2], int deg);
    void move (QPainter& painter, int matrixCor[2][2]);
};

#endif // LINE_H
