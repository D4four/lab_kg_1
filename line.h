#ifndef LINE_H
#define LINE_H

#include <QPainter>
#include <QPoint>
#include <QList>
#include <QColor>
#include <cmath>

class Line
{
private:
    QPointF start;
    QPointF finish;
    QColor color;
    int alghoritm;
    void BInt(QPainter&, int, int);
    void Library(QPainter&, int, int);
public:
    Line(double, double, double, double, QColor, int);
    void draw(QPainter&, int, int);
};

#endif // LINE_H
