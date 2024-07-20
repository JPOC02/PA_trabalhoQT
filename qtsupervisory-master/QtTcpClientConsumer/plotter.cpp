#include "plotter.h"
#include <QPainter>
#include <QBrush>
#include <QPen>
#include <iostream>

Plotter::Plotter(QWidget *parent): QWidget{parent}{

}

void Plotter::paintEvent(QPaintEvent *event){
  QPainter painter(this);
  QBrush brush;
  QPen pen;
  int x1,y1,x2,y2;
  int *points = new int[10];

  //*points = new int [max_points];


  points[0] = 2;
  points[1] = 3;
  points[2] = 1;
  points[3] = 5;
  points[4] = 0;
  points[5] = 8;
  points[6] = 4;
  points[7] = 2;
  points[8] = 7;
  points[9] = 9;

  brush.setColor(QColor(255,255,100));
  brush.setStyle(Qt::SolidPattern);

  pen.setColor(QColor(255,0,0));
  pen.setWidth(2);

  painter.setBrush(brush);
  painter.setPen(pen);
  painter.drawRect(0,0,width(),height());


  pen.setColor(QColor(20,20,255));
  pen.setWidth(3);
  painter.setPen(pen);

  x1 = 0;
  y1 = height();

  for(int i = 0, j = 0; j < 10; i+= 10, j++){
    x2 = i+10;
    y2 = height() - 50*points[j];

    painter.drawLine(x1,y1,x2,y2);

    x1 = x2;
    y1 = y2;
  }

  delete[] points;
}

void Plotter::setMax_points(int n)
{

}
