#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "line.h"

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
    QPainter p;
    p.begin(this);

    int arr[2][2] = {{20, 200}, {40, 40}};
    Line line;
    line.draw(p, arr);
    line.spin(arr, 45);
    line.draw(p, arr);
    line.spin(arr, 45);
    line.draw(p, arr);

    p.end();
}

