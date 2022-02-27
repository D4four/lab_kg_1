#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::paintEvent(QPaintEvent *)
{
    QPainter painter;
    painter.begin(this);

        QPen color (Qt::red);
        color.setWidth(5);

        QPen color2 (Qt::black);
        color2.setWidth(2);

        QPoint p1;
        p1.setX(25);
        p1.setY(25);

        QPoint p2;
        p2.setX(100);
        p2.setY(100);

        painter.setPen(color2);
        painter.drawLine(p1, p2);

        painter.setPen(color);
        painter.drawPoint(p1);
        painter.drawPoint(p2);

        QFont font("Times", 10, 700);
        painter.setFont(font);
        painter.setPen(Qt::black);
        painter.drawText(p1, "A");
        painter.drawText(p2, "B");

    painter.end();
}

