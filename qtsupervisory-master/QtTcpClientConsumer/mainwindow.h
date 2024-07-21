#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTcpSocket>
#include <QDebug>
#include <QTimer>
#include <QListWidgetItem>

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
  void getData();
  void tcpConnect();
  void tcpDisconnect();
  void stopConsumer();
  void setTiming(int);
  void startConsumer();
  void updateIps();
  void selectProducer(QListWidgetItem*);

private:
  Ui::MainWindow *ui;
  QTcpSocket *socket;
  QTimer *timer;
  QStringList *tempos;
  QStringList *valores;
  QString selectedProducer;
};

#endif // MAINWINDOW_H
