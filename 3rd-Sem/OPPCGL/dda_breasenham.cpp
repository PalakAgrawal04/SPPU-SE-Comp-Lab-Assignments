  #include "mainwindow.h"
#include "ui_mainwindow.h"
QImage img(400,400, QImage::Format_RGB888);
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


void MainWindow::on_pushButton_clicked()
{
    float x1,y1,x2,y2;
    x1 = ui -> textEdit -> toPlainText().toFloat();
    y1 = ui -> textEdit_2 -> toPlainText().toFloat();
    x2 = ui -> textEdit_3 -> toPlainText().toFloat();
    y2 = ui -> textEdit_4 -> toPlainText().toFloat();
   DDA(x1,y1,x2,y2);
}

void MainWindow::DDA(float x1, float y1, float x2, float y2)
{
    float dx,dy,step,x_inc,y_inc;
    dy = y2 - y1;
    dx = x2 - x1;
    if(abs(dy)>abs(dx))
        step = abs(dy);
    else
        step = abs(dx);
    x_inc = dx/step;
    y_inc = dy/step;
    float x = x1;
    float y = y1;
    int i = 0;
    while(i<=step)
    {
        img.setPixel(x,y,qRgb(0,255,255));
        x = x + x_inc;
        y = y + y_inc;
        i++;
    }

    ui->label->setPixmap(QPixmap::fromImage(img));
}

void MainWindow::on_pushButton_2_clicked()
{
    int x3,y3,r;
    x3 = ui -> textEdit_5 -> toPlainText().toInt();
    y3 = ui -> textEdit_6 -> toPlainText().toInt();
    r = ui -> textEdit_7 -> toPlainText().toInt();
    Bcircle(x3,y3,r);
    Smile(x3,y3,r);
}

void MainWindow::Bcircle(int x3, int y3, int r)
{
    int x,y,d;
    x = 0;
    y = r;
    d = 3 - (2*r);
    while(x<=y)
    {
        img.setPixel(x3+x,y3+y,qRgb(0,255,255));
        img.setPixel(x3-x,y3+y,qRgb(0,0,255));
        img.setPixel(x3+x,y3-y,qRgb(255,0,255));
        img.setPixel(x3-x,y3-y,qRgb(255,255,0));
        img.setPixel(x3+y,y3+x,qRgb(0,255,0));
        img.setPixel(x3+y,y3-x,qRgb(0,0,255));
        img.setPixel(x3-y,y3+x,qRgb(255,255,255));
        img.setPixel(x3-y,y3-x,qRgb(255,0,0));
        if(d<0)
            d = d + 4*x + 6;
        else
        {
            d = d + 4*(x-y) +10;
            y = y - 1;
        }
        x = x+1;
    }
    ui->label->setPixmap(QPixmap::fromImage(img));
}

void MainWindow::on_pushButton_3_clicked()
{
    DDA(100,0,186.6,150);
    DDA(13.4,150,186.6,150);
    DDA(100,0,13.4,150);
    Bcircle(100,100,50);
    Bcircle(100,100,100);
}

void MainWindow::on_pushButton_4_clicked()
{
    DDA(250,0,350,0);
    DDA(350,0,350,50);
    DDA(250,50,350,50);
    DDA(250,0,250,50);
    DDA(300,0,350,25);
    DDA(350,25,300,50);
    DDA(300,50,250,25);
    DDA(250,25,300,0);
    Bcircle(300,25,22);
}

void MainWindow::Smile(int x3, int y3, int r)
{
    int x,y,d;
    x = 0;
    y = r;
    d = 3 - (2*r);
    while(x<=y)
    {
        img.setPixel(x3+x,y3+y,qRgb(0,255,255));
        img.setPixel(x3-x,y3+y,qRgb(0,0,255));
        //img.setPixel(x3+x,y3-y,qRgb(255,0,255));
        //img.setPixel(x3-x,y3-y,qRgb(255,255,0));
        img.setPixel(x3+y,y3+x,qRgb(0,255,0));
        //img.setPixel(x3+y,y3-x,qRgb(0,0,255));
        img.setPixel(x3-y,y3+x,qRgb(255,255,255));
        //img.setPixel(x3-y,y3-x,qRgb(255,0,0));
        if(d<0)
            d = d + 4*x + 6;
        else
        {
            d = d + 4*(x-y) +10;
            y = y - 1;
        }
        x = x+1;
    }
    ui->label->setPixmap(QPixmap::fromImage(img));
}


void MainWindow::on_pushButton_5_clicked()
{
    Bcircle(100,100,100);
    Bcircle(70,70,20);
    Bcircle(130,70,20);
    Smile(100,100,55);
}

void MainWindow::on_pushButton_6_clicked()
{
    Bcircle(100,100,100);
    Bcircle(100,100,75);
    DDA(100,25,100,175);
    DDA(25,100,175,100);
}

void MainWindow::G(int x3, int y3, int r)
{
    int x,y,d;
    x = 0;
    y = r;
    d = 3 - (2*r);
    while(x<=y)
    {
        img.setPixel(x3+x,y3+y,qRgb(0,255,255));
        img.setPixel(x3-x,y3+y,qRgb(0,0,255));
        //img.setPixel(x3+x,y3-y,qRgb(255,0,255));
        img.setPixel(x3-x,y3-y,qRgb(255,255,0));
        img.setPixel(x3+y,y3+x,qRgb(0,255,0));
        //img.setPixel(x3+y,y3-x,qRgb(0,0,255));
        img.setPixel(x3-y,y3+x,qRgb(255,255,255));
        img.setPixel(x3-y,y3-x,qRgb(255,0,0));
        if(d<0)
            d = d + 4*x + 6;
        else
        {
            d = d + 4*(x-y) +10;
            y = y - 1;
        }
        x = x+1;
    }
    ui->label->setPixmap(QPixmap::fromImage(img));
}

void MainWindow::on_pushButton_7_clicked()
{
    G(100,100,75);
    Bcircle(100,100,100);
    Bcircle(75,75,10);
    DDA(125,100,175,100);
    DDA(100,60,100,140);
    DDA(100,140,125,140);
}
