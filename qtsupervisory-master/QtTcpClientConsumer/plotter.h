#ifndef PLOTTER_H
#define PLOTTER_H

#include <QWidget>
#include <QList>

class Plotter : public QWidget
{
    Q_OBJECT

private:
    int max_points;
    std::vector<long long> x;
    std::vector<int> y;
public:
    explicit Plotter(QWidget *parent = nullptr);
    void paintEvent(QPaintEvent *event);
    void setXY(std::vector<long long> x_, std::vector<int> y_);
signals:

public slots:
    void setMax_points(int n);


};

#endif // PLOTTER_H
