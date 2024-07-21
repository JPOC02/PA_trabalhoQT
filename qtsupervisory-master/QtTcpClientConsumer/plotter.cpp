#include "plotter.h"
#include <QPainter>
#include <QBrush>
#include <cstdlib>
#include <QPen>
#include <iostream>

Plotter::Plotter(QWidget *parent): QWidget{parent}{

}

void Plotter::paintEvent(QPaintEvent *event){
  QPainter painter(this);
  QBrush brush;
  QPen pen;
  long long x1,y1,x2,y2;

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

  if(x.size()>0){
      x1 = 0;
      y1 = height();
      auto maxX = std::max_element(x.begin(), x.end());
      auto minX = std::min_element(x.begin(), x.end());
      auto maxY = std::max_element(y.begin(), y.end());
      long long maxValorX = *maxX;
      long long minValorX = *minX;
      int maxValorY = *maxY;

      for(int i =  0; i< x.size();i++){
          x2 = width()*(x[i]-minValorX)/(maxValorX-minValorX);
          y2 = height() - (height()*y[i])/maxValorY;

            painter.drawLine(x1,y1,x2,y2);

            x1 = x2;
            y1 = y2;

      }
  }
}

void Plotter::setMax_points(int n)
{

}

void Plotter::setXY(std::vector<long long> x_, std::vector<int> y_){
    x = x_;
    y = y_;

    repaint();
}
