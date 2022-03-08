#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPainter>
#include <QMessageBox>
#include <QColorDialog>
#include <QKeyEvent>

#include "line.h"

#define RADIANS 57.2958
#define PI 3.1415926535

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void paintEvent(QPaintEvent*);
    void keyPressEvent(QKeyEvent *e) override;
    void keyReleaseEvent(QKeyEvent *e) override;

private slots:
    void on_btnLine_clicked();

    void on_btnRotate_clicked();

    void on_btnClear_clicked();

    void on_pushButtonScale_clicked();
    void on_pushButtonUp_clicked();
    void on_pushButtonDown_clicked();
    void on_pushButtonLeft_clicked();
    void on_pushButtonRight_clicked();

    void on_btnColor_clicked();

    void on_btnBColor_clicked();

    void on_pushButton_clicked();

private:
    Ui::MainWindow *ui;
    QList<Line> lines;

    QColor currentLineColor[2];
    QColor currentBackgroundColor;
    QColor color;
};

#endif // MAINWINDOW_H
