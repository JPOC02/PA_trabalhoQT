#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDateTime>
#include <cstdlib>
#include <QTimer>

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow)
{
    timer = new QTimer();
    ui->setupUi(this);
    socket = new QTcpSocket(this);
    tempos = new QStringList();
    valores = new QStringList();
    selectedProducer = "None";

    connect(ui->pushButtonGet,
            SIGNAL(clicked(bool)),
            this,
            SLOT(startConsumer()));
    connect(ui->pushButtonConnect,
            SIGNAL(clicked(bool)),
            this,
            SLOT(tcpConnect()));
    connect(ui->pushButtonDisconnnect,
            SIGNAL(clicked(bool)),
            this,
            SLOT(tcpDisconnect()));
    connect(ui->pushButtonStop,
            SIGNAL(clicked(bool)),
            this,
            SLOT(stopConsumer()));
    connect(ui->horizontalSliderTiming,
            SIGNAL(valueChanged(int)),
            this,
            SLOT(setTiming(int)));
    connect(ui->pushButtonUpdate,
            SIGNAL(clicked(bool)),
            this,
            SLOT(updateIps()));
    connect(timer,
            SIGNAL(timeout()),
            this,
            SLOT(getData()));
    connect(ui->listWidgetVisualizer,
            SIGNAL(itemClicked(QListWidgetItem*)),
            this,
            SLOT(selectProducer(QListWidgetItem*)));
}

void MainWindow::tcpConnect(){
    QString uri = ui->textEditIp->toPlainText();
    socket->connectToHost(uri, 1234);
    if(socket->waitForConnected(3000)){
        qDebug() << "Connected";
    }
    else{
        qDebug() << "Disconnected";
    }
}

void MainWindow::tcpDisconnect(){
    socket->disconnectFromHost();
    qDebug() << "Disconnected";

}

void MainWindow::getData(){
    QString str;
    QByteArray array;
    QStringList list;
    qint64 thetime;

    std::vector<long long> x;
    std::vector<int> y;
    qDebug() << "to get data...";
    if(socket->state() == QAbstractSocket::ConnectedState){
        if(socket->isOpen()){

            qDebug() << "reading...";
            QString uri = "get "+selectedProducer+" 10\r\n";
            socket->write(uri.toUtf8());
            socket->waitForBytesWritten();
            socket->waitForReadyRead();
            qDebug() << socket->bytesAvailable();
            while(socket->bytesAvailable()){
                str = socket->readLine().replace("\n","").replace("\r","");
                list = str.split(" ");
                if(list.size() == 2){
                    bool ok;
                    str = list.at(0);
                    x.push_back(str.toLongLong(&ok));
                    str = list.at(1);
                    y.push_back(str.toInt());
                }
            }

            ui->widget->setXY(x, y);
        }
    }
}

void MainWindow::startConsumer(){
    int interval = 1000*(ui->lcdTiming->value());

    if(timer->isActive()){
        timer->stop();
    }

    timer->start(interval);
}

void MainWindow::stopConsumer(){
    if(timer->isActive()){
        timer->stop();
        if(ui->listWidgetVisualizer->selectedItems().isEmpty()){
            ui->pushButtonGet->setEnabled(false);
            ui->pushButtonStop->setEnabled(false);
        }
    }
}

void MainWindow::updateIps(){
    QString str;

    if(socket->state() == QAbstractSocket::ConnectedState && socket->isOpen()){
        qDebug() << "reading...";
        socket->write("list\r\n");
        socket->waitForBytesWritten();
        socket->waitForReadyRead();
        qDebug() << socket->bytesAvailable();
        ui->listWidgetVisualizer->clear();
        while(socket->bytesAvailable()){
            str = socket->readLine().replace("\n","").replace("\r","");
            ui->listWidgetVisualizer->addItem(str);
        }
    }else{
        ui->pushButtonGet->setEnabled(false);
        ui->pushButtonStop->setEnabled(false);
    }
}

void MainWindow::setTiming(int timing){
    ui->lcdTiming->display(timing);
}

void MainWindow::selectProducer(QListWidgetItem* selected){
    selectedProducer = selected->text();
    ui->pushButtonGet->setEnabled(true);
    ui->pushButtonStop->setEnabled(true);

}


MainWindow::~MainWindow()
{
    delete socket;
    delete ui;
    delete timer;
    delete tempos;
    delete valores;
}
