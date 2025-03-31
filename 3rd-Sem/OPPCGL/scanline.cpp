#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QMouseEvent"
#include<QColorDialog>
QImage img(400, 400, QImage::Format_RGB888);
QColor Color;
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ver = 0;
    start = true;
}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::mousePressEvent(QMouseEvent *ev)
{

    if(start)
    {
        int p = ev -> pos().x();
        int q = ev -> pos().y();
        a[ver] = p;
        b[ver] = q;
        if(ev->button() == Qt:: RightButton)
        {
            DDA(a[0], b[0], a[ver-1], b[ver-1]);
            start = false;
        }
        else
        {
            if(ver>0)
            {
                DDA(a[ver],b[ver],a[ver-1],b[ver-1]);
            }
        }
        ver++;
    }
}


void MainWindow::on_pushButton_clicked()
{
    ver = 0;
    Color = QColorDialog::getColor();
    start = true;
    ui->label->setPixmap(QPixmap::fromImage(img));
}

void MainWindow::DDA(float x1, float y1, float x2, float y2)
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
        img.setPixel(x,y,Color.rgb());

        x = x+x_inc;
        y = y+y_inc;
        i++;
    }
    ui->label->setPixmap(QPixmap::fromImage(img));
}

void MainWindow::on_pushButton_2_clicked()
{
    int y_min=400,y_max=0;
//    cout<<ver;
    for(int i = 0;i<ver-1;i++)
    {
        if(b[i]>y_max)
            y_max=b[i];
        if(b[i]<y_min)
            y_min=b[i];
    }
    a[ver-1]=a[0];
    b[ver-1]=b[0];
//    cout<<"\n Y_max = "<<y_max;
//    cout<<"\n Y_min = "<<y_min;
    for(int i = 0;i<ver-1;i++)
    {
        dy = b[i+1]-b[i];
        dx = a[i+1]-a[i];
        if(dy==0.0)
            slope[i]=1.0;
        if(dx==0.0)
            slope[i]=1.0;
        if((dy!=0.0)&&(dx!=0.0))
        {
            slope[i]=float(dx/dy);
        }
    }
    for(int y = y_min;y<y_max;y++)
    {
        k=0;
        for(int i = 0;i<ver-1;i++)
        {
            if(((b[i]<=y)&&(b[i+1]>y))||((b[i]>y)&&(b[i+1]<=y)))
            {
                xi[k]=int(a[i]+(slope[i]*(y-b[i])));
                        k++;
            }
        }
        for(j=0;j<k-1;j++)
        {
            for(int i=0;i<k-j-1;i++)
            {
                if(xi[i]>xi[i+1])
                {
                    temp=xi[i];
                    xi[i]=xi[i+1];
                    xi[i+1]=temp;
                }
            }

            for(int i = 0;i<k;i+=2)
            {
                DDA(xi[i],y,xi[i+1]+1,y);
            }
        }
   }
}
