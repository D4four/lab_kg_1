#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>

int alg = 0;
int lineSel = 0;
bool key = false;
double scale = 0;
double rotate[2] = {0, 0};
double startX[2] = {0, 0};
double startY[2] = {0, 0};
double finishX[2] = {0, 0};
double finishY[2] = {0, 0};

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    color = Qt::black;
    currentBackgroundColor = Qt::white;

    QString qss = QString("background-color: %1").arg(color.name());
    ui->btnColor->setStyleSheet(qss);

    QString qssbg = QString("background-color: %1").arg(currentBackgroundColor.name());
    ui->btnBColor->setStyleSheet(qssbg);
    lines.append(Line(0, 0, 0, 0, currentBackgroundColor, 0));
    lines.append(Line(0, 0, 0, 0, currentBackgroundColor, 0));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::paintEvent(QPaintEvent*)
{
    QPainter p(this);

    int canvasWidht = width() - 210;
    int canvasHeight = height()-100;

    p.fillRect(0, 0, canvasWidht, canvasHeight, currentBackgroundColor);

    p.setPen(QPen(Qt::gray, 1, Qt::SolidLine));
    p.drawLine(canvasWidht / 2, 0, canvasWidht / 2, canvasHeight);
    p.drawLine(0, canvasHeight / 2, canvasWidht, canvasHeight / 2);

    for (Line line : lines) {

        p.setPen(QPen(Qt::gray, 1, Qt::SolidLine));
        p.drawLine(canvasWidht / 2, 0, canvasWidht / 2, canvasHeight);
        p.drawLine(0, canvasHeight / 2, canvasWidht, canvasHeight / 2);
        line.draw(p, canvasWidht, canvasHeight);
    }
}

void MainWindow::keyPressEvent(QKeyEvent *e)
{

    if (e->key() == Qt::Key_Up){
        ui->label_9->setText("ВВЕРХ");
        on_pushButtonUp_clicked();
    }
    if (e->key() == Qt::Key_Down){
        ui->label_9->setText("ВНИЗ");
        on_pushButtonDown_clicked();
    }
    if (e->key() == Qt::Key_Right){
        ui->label_9->setText("ВПРАВО");
        on_pushButtonRight_clicked();
    }
    if (e->key() == Qt::Key_Left){
        ui->label_9->setText("ВЛЕВО");
        on_pushButtonLeft_clicked();
    }
    if (e->key() == Qt::Key_Minus){
        ui->label_9->setText("ПОВОРОТ ПРОТИВ ЧС");
        lineSel = ui->comboBox->currentIndex();


        alg = ui->cmbAlghoritms->currentIndex();



        float rx = (startX[lineSel] + (finishX[lineSel] - startX[lineSel])*cos(5*3.1415/180)) - (finishY[lineSel] - startY[lineSel])*sin(5*3.1415/180);
        float ry = (startY[lineSel] + (finishX[lineSel] - startX[lineSel])*sin(5*3.1415/180)) +(finishY[lineSel] - startY[lineSel])*cos(5*3.1415/180);

        finishX[lineSel] = rx;
        finishY[lineSel] = ry;
        lines[lineSel] = (Line(startX[lineSel], startY[lineSel], rx, ry, currentLineColor[lineSel], alg));

        repaint();
    }

    if (e->key() == Qt::Key_Plus){
        ui->label_9->setText("ПОВОРОТ ПО ЧС");
        lineSel = ui->comboBox->currentIndex();


        alg = ui->cmbAlghoritms->currentIndex();



        float rx = (startX[lineSel] + (finishX[lineSel] - startX[lineSel])*cos(-5*3.1415/180)) - (finishY[lineSel] - startY[lineSel])*sin(-5*3.1415/180);
        float ry = (startY[lineSel] + (finishX[lineSel] - startX[lineSel])*sin(-5*3.1415/180)) +(finishY[lineSel] - startY[lineSel])*cos(-5*3.1415/180);

        finishX[lineSel] = rx;
        finishY[lineSel] = ry;
        lines[lineSel] = (Line(startX[lineSel], startY[lineSel], rx, ry, currentLineColor[lineSel], alg));

        repaint();
    }
}

void MainWindow::keyReleaseEvent(QKeyEvent *e)
{
    if (e->key() == Qt::Key_Up){
        ui->label_9->setText(" ");
    }
    if (e->key() == Qt::Key_Down){
        ui->label_9->setText(" ");
    }
    if (e->key() == Qt::Key_Right){
        ui->label_9->setText(" ");
    }
    if (e->key() == Qt::Key_Left){
        ui->label_9->setText(" ");
    }
    if (e->key() == Qt::Key_Plus){
        ui->label_9->setText(" ");
    }
    if (e->key() == Qt::Key_Minus){
        ui->label_9->setText(" ");
    }
}

void MainWindow::on_btnLine_clicked()
{
    lineSel = ui->comboBox->currentIndex();
    currentLineColor[lineSel] = color;



    alg = ui->cmbAlghoritms->currentIndex();

    key = false;
    startX[lineSel] = ui->lineStartX->text().toDouble(&key);
    if (!key) {
        QMessageBox::critical(this, "Ошибка", "Некорректный ввод!");
        return;
    }

    startY[lineSel] = ui->lineStartY->text().toDouble(&key);
    if (!key) {
        QMessageBox::critical(this, "Ошибка", "Некорректный ввод!");
        return;
    }

    finishX[lineSel] = ui->lineFinishX->text().toDouble(&key);
    if (!key) {
        QMessageBox::critical(this, "Ошибка", "Некорректный ввод!");
        return;
    }

    finishY[lineSel] = ui->lineFinishY->text().toDouble(&key);
    if (!key) {
        QMessageBox::critical(this, "Ошибка", "Некорректный ввод!");
        return;
    }

    lines[lineSel] = Line(startX[lineSel], startY[lineSel], finishX[lineSel], finishY[lineSel], currentLineColor[lineSel], alg);

    repaint();
}

void MainWindow::on_btnRotate_clicked()
{
    lineSel = ui->comboBox->currentIndex();


    alg = ui->cmbAlghoritms->currentIndex();

    rotate[lineSel] = ui->lineLengthBundle->text().toDouble(&key);
    if (!key) {
        QMessageBox::critical(this, "Ошибка", "Некорректный ввод!");
        return;
    }
    int rx = (startX[lineSel] + (finishX[lineSel] - startX[lineSel])*cos(rotate[lineSel]*3.1415/180)) - (finishY[lineSel] - startY[lineSel])*sin(rotate[lineSel]*3.1415/180);
    int ry = (startY[lineSel] + (finishX[lineSel] - startX[lineSel])*sin(rotate[lineSel]*3.1415/180)) +(finishY[lineSel] - startY[lineSel])*cos(rotate[lineSel]*3.1415/180);

    finishX[lineSel] = rx;
    finishY[lineSel] = ry;
    lines[lineSel] = (Line(startX[lineSel], startY[lineSel], rx, ry, currentLineColor[lineSel], alg));

    repaint();
}



void MainWindow::on_pushButtonScale_clicked()
{
    scale = ui->lineScale->text().toDouble(&key);
    if (!key) {
        QMessageBox::critical(this, "Ошибка", "Некорректный ввод!");
        return;
    }

    alg = ui->cmbAlghoritms->currentIndex();


    int x0 = (startX[lineSel] + finishX[lineSel])/2;

    int x1 = x0*(1-scale) + startX[lineSel] * scale;
    int x2 = x0*(1-scale) + finishX[lineSel] * scale;

    int y0 = (startY[lineSel] + finishY[lineSel])/2;

    int y1 = y0*(1-scale) + startY[lineSel] * scale;
    int y2 = y0*(1-scale) + finishY[lineSel] * scale;

    lines[lineSel] = (Line(x1, y1, x2, y2, currentLineColor[lineSel], alg));

    repaint();
    startX[lineSel] = x1;
    startY[lineSel] = y1;
    finishX[lineSel] = x2;
    finishY[lineSel] = y2;

}

void MainWindow::on_pushButtonUp_clicked(){
    lineSel = ui->comboBox->currentIndex();

    alg = ui->cmbAlghoritms->currentIndex();



    startY[lineSel] += 5;
    finishY[lineSel] += 5;

    lines[lineSel] = (Line(startX[lineSel], startY[lineSel], finishX[lineSel], finishY[lineSel], currentLineColor[lineSel], alg));

    repaint();

};
void MainWindow::on_pushButtonDown_clicked(){
    lineSel = ui->comboBox->currentIndex();

    alg = ui->cmbAlghoritms->currentIndex();



    startY[lineSel] -= 5;
    finishY[lineSel] -= 5;

    lines[lineSel] = (Line(startX[lineSel], startY[lineSel], finishX[lineSel], finishY[lineSel], currentLineColor[lineSel], alg));

    repaint();
};
void MainWindow::on_pushButtonLeft_clicked(){
    lineSel = ui->comboBox->currentIndex();

    alg = ui->cmbAlghoritms->currentIndex();



    startX[lineSel] -= 5;
    finishX[lineSel] -= 5;

    lines[lineSel] = (Line(startX[lineSel], startY[lineSel], finishX[lineSel], finishY[lineSel], currentLineColor[lineSel], alg));

    repaint();
};
void MainWindow::on_pushButtonRight_clicked(){
    lineSel = ui->comboBox->currentIndex();

    alg = ui->cmbAlghoritms->currentIndex();



    startX[lineSel] += 5;
    finishX[lineSel] += 5;

    lines[lineSel] = (Line(startX[lineSel], startY[lineSel], finishX[lineSel], finishY[lineSel], currentLineColor[lineSel], alg));

    repaint();
};

void MainWindow::on_btnClear_clicked() {

    alg = 0;
    lineSel = 0;
    key = false;
    scale = 0;

    for (int i = 0; i < 2; i++) {
        rotate[i] = 0;
        startX[i] = 0;
        startY[i] = 0;
        finishX[i] = 0;
        finishY[i] = 0;
    }

    lines = QList<Line>();
    lines.append(Line(0, 0, 0, 0, currentBackgroundColor, 0));
    lines.append(Line(0, 0, 0, 0, currentBackgroundColor, 0));
    repaint();
}

void MainWindow::on_btnColor_clicked()
{
    QColorDialog* q = new QColorDialog();
    q->open();
    color = q->getColor();
    QString qss = QString("background-color: %1").arg(color.name());
    ui->btnColor->setStyleSheet(qss);
    delete q;
}

void MainWindow::on_btnBColor_clicked()
{
    QColorDialog* q = new QColorDialog();
    q->open();
    currentBackgroundColor = q->getColor();
    QString qss = QString("background-color: %1").arg(currentBackgroundColor.name());
    ui->btnBColor->setStyleSheet(qss);
    delete q;

    repaint();
}

void MainWindow::on_pushButton_clicked()
{
    color = currentBackgroundColor;
    QString qss = QString("background-color: %1").arg(color.name());
    ui->btnColor->setStyleSheet(qss);
}
