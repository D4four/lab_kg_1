#include "line.h"
#include <QDebug>

Line::Line(double sx, double sy, double fx, double fy, QColor c, int a)
{
    start = QPointF(sx, sy);
    finish = QPointF(fx, fy);
    color = c;
    alghoritm = a;
}

void Line::draw(QPainter& p, int w, int h)
{
    switch (alghoritm) {
    case 0:
        BInt(p, w, h);
        break;
    case 1:
        Library(p, w, h);
        break;
    default:
        break;
    }
}

void Line::BInt(QPainter& p, int w, int h)
{
    p.setPen(QPen(color, 1));

    if (int(start.x()) == int(finish.x()) && int(start.y()) == int(finish.y())) {
        p.drawPoint(w / 2 + int(start.x()), h / 2 - int(start.y()));
        return;
    }

    int deltaX = int(finish.x()) - int(start.x());
    int deltaY = int(finish.y()) - int(start.y());
    int absDeltaX = abs(deltaX);
    int absDeltaY = abs(deltaY);

    int accretion = 0;

    if (absDeltaX >= absDeltaY) {
        int y = int(start.y());
        int direction = deltaY != 0 ? (deltaY > 0 ? 1 : -1) : 0;
        for (int x = int(start.x()); deltaX > 0 ? x <= int(finish.x()) : x >= int(finish.x()); deltaX > 0 ? x++ : x--) {
            p.drawPoint(w / 2 + x, h / 2 - y);

            accretion += absDeltaY;

            if (accretion >= absDeltaX) {
                accretion -=absDeltaX;
                y += direction;
            }
        }
    } else {
        int x = int(start.x());
        int direction = deltaX != 0 ? (deltaX > 0 ? 1 : -1) : 0;
        for (int y = int(start.y()); deltaY > 0 ? y <= int(finish.y()) : y >= int(finish.y()); deltaY > 0 ? y++ : y--) {

            p.drawPoint(w / 2 + x, h / 2 - y);


            accretion += absDeltaX;

            if (accretion >= absDeltaY) {
                accretion -=absDeltaY;
                x += direction;
            }
        }
    }

}

void Line::Library(QPainter& p, int w, int h)
{
    p.setPen(QPen(color, 1));
    p.drawLine(w / 2 + int(start.x()), h / 2 - int(start.y()),
               w / 2 + int(finish.x()), h / 2 - int(finish.y()));
}
