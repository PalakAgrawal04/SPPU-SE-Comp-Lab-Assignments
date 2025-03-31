#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<cmath>
QImage img(400, 400, QImage::Format_RGB888);

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    DDA(0,200,400,200);
    DDA(200,0,200,400);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    x1 = ui->textEdit->toPlainText().toFloat();
    y1 = ui->textEdit_2->toPlainText().toFloat();
    x2 = ui->textEdit_3->toPlainText().toFloat();
    y2 = ui->textEdit_4->toPlainText().toFloat();
    x3 = ui->textEdit_10->toPlainText().toFloat();
    y3 = ui->textEdit_11->toPlainText().toFloat();
    Triangle(x1+200,y1+200,x2+200,y2+200,x3+200,y3+200);

}

void MainWindow::DDA(float x1,float y1,float x2,float y2)
{
    float dy = y2-y1;
        float dx = x2-x1;
        float length = 0;
        if(abs(dy)>abs(dx))
                length = abs(dy);
        else
                length = abs(dx);
        float x_inc = dx/length;
        float y_inc = dy/length;
        float x = x1;
        float y = y1;
        int i=0;
        while(i<length)
        {
            img.setPixel(x,y,qRgb(255,0,0));        
            x = x+x_inc;
            y = y+y_inc;
            i++;
        }
        ui->label->setPixmap(QPixmap::fromImage(img));
}


void MainWindow::on_pushButton_2_clicked()
{
    float p,q,r,s,t,u;
    tx = ui->textEdit_5->toPlainText().toFloat();
    ty = ui->textEdit_6->toPlainText().toFloat();
    p = x1+tx;
    q = y1+ty;
    r = x2+tx;
    s = y2+ty;
    t = x3+tx;
    u = y3+ty;
//    DDA(p+200,q+200,r+200,s+200);
    Triangle(p+200,q+200,r+200,s+200,t+200,u+200);
}


void MainWindow::on_pushButton_3_clicked()
{
    float p,q,r,s,t,u;
    sx = ui->textEdit_7->toPlainText().toFloat();
    sy = ui->textEdit_8->toPlainText().toFloat();
    p = sx * x1;
    q = sy * y1;
    r = sx * x2;
    s = sy * y2;
    t = sx * x3;
    u = sy * y3;
//    DDA(p+200,q+200,r+200,s+200);
    Triangle(p+200,q+200,r+200,s+200,t+200,u+200);
}


void MainWindow::on_pushButton_4_clicked()
{
    float p2,q2,r2,s2,ang,t2,u2;
    ang = ui->textEdit_9->toPlainText().toFloat();
    double angle = (ang*22)/(180*7);
    p2 = (x1*cos(angle)) - (y1*sin(angle));
    q2 = (y1*cos(angle)) + (x1*sin(angle));
    r2 = (x2*cos(angle)) - (y2*sin(angle));
    s2 = (y2*cos(angle)) + (x2*sin(angle));
    t2 = (x3*cos(angle)) - (y3*sin(angle));
    u2 = (y3*cos(angle)) + (x3*sin(angle));
//    DDA(p2+200,q2+200,r2+200,s2+200);
    Triangle(p2+200,q2+200,r2+200,s2+200,t2+200,u2+200);
}


void MainWindow::Triangle(float x1,float y1,float x2,float y2,float x3,float y3)
{
    DDA(x1,y1,x2,y2);
    DDA(x2,y2,x3,y3);
    DDA(x3,y3,x1,y1);
}
