#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDateTime>
#include <QHostAddress>
#include <QTimer>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent), ui(new Ui::MainWindow){
    ui->setupUi(this);
    socket = new QTcpSocket(this);
    timer = new QTimer(this);


    connect(ui->pushButtonConnect,
        SIGNAL(clicked(bool)),
        this,
        SLOT(tcpConnect()));

    connect(ui->pushButtonPut,
        SIGNAL(clicked(bool)),
        this,
        SLOT(startProducer()));

    connect(ui->pushButtonStop,
            SIGNAL(clicked(bool)),
            this,
            SLOT(stopProducer()));

    connect(ui->pushButtonDisconnect,
        SIGNAL(clicked(bool)),
        this,
        SLOT(tcpDisconnect()));

    connect(ui->horizontalSliderMin,
        SIGNAL(valueChanged(int)),
        this,
        SLOT(setMin_points(int)));

    connect(ui->horizontalSliderMax,
        SIGNAL(valueChanged(int)),
        this,
        SLOT(setMax_points(int)));

    connect(ui->horizontalSliderTiming,
        SIGNAL(valueChanged(int)),
        this,
        SLOT(setTiming(int)));

    connect(timer,
        SIGNAL(timeout()),
        this,
        SLOT(putData()));

}

void MainWindow::tcpConnect(){
    QString uri = ui->textEditIp->toPlainText();

    socket->connectToHost(uri, 1234);
    if(socket->waitForConnected(3000)){
        ui->textBrowserData->append("Connected to "+uri);
        ui->connectionLabel->setText("Connected");
    }
    else{
        ui->textBrowserData->append("Error, disconnected");
        ui->connectionLabel->setText("Disconnected");
    }
}

void MainWindow::tcpDisconnect(){
    socket->disconnectFromHost();

    ui->textBrowserData->append("Disconnected");
    ui->connectionLabel->setText("Disconnected");
}

void MainWindow::putData(){
    QString str;
    qint64 msecdate;

    int min = ui->horizontalSliderMin->value();
    int max = ui->horizontalSliderMax->value();

    if(socket->state()== QAbstractSocket::ConnectedState){
        msecdate = QDateTime::currentDateTime().toMSecsSinceEpoch();
        str = "set "+ QString::number(msecdate) + " " +
            QString::number(min + (rand()%(max-min)))+"\r\n";

        qDebug() << str;
        qDebug() << socket->write(str.toStdString().c_str())
            << " bytes written";
        if(socket->waitForBytesWritten(3000)){
            qDebug() << "wrote";
        }
        ui->textBrowserData->append(str);
    }
    else{
        ui->textBrowserData->append("Not connected to host.");
        stopProducer();
    }
}

void MainWindow::startProducer(){
    int interval = 1000*(ui->labelSelectedTiming->text().toInt());

    if(timer->isActive()){
        ui->textBrowserData->append("Producer stopped.");
        timer->stop();
    }

    timer->start(interval);
    ui->textBrowserData->append("Producer started. Interval: "+ui->labelSelectedTiming->text()+" s.");
}

void MainWindow::stopProducer(){
    timer->stop();
    ui->textBrowserData->append("Producer stopped.");
}

void MainWindow::setMin_points(int min){
    ui->lcdNumberMin->display(min);
}

void MainWindow::setMax_points(int max){
    ui->lcdNumberMax->display(max);
}

void MainWindow::setTiming(int timing){
    ui->labelSelectedTiming->setText(QString::number(timing));
}

MainWindow::~MainWindow(){
  delete socket;
  delete ui;
  delete timer;
}
