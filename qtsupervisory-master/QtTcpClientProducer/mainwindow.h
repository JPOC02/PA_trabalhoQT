#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTcpSocket>
#include <QDebug>
#include <QTimer>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
  Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();


public slots:
    void startProducer();
    void setMin_points(int min);
    void setMax_points(int max);
    void setTiming(int timing);
    void tcpConnect();
    void tcpDisconnect();
    void stopProducer();
    void putData();
private:
  int min_points, max_points, timing;
  Ui::MainWindow *ui;
  QTcpSocket *socket;
  QTimer *timer;
};

#endif // MAINWINDOW_H
