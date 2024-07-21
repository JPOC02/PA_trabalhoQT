/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.15.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLCDNumber>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QHBoxLayout *horizontalLayout_8;
    QHBoxLayout *horizontalLayout_7;
    QVBoxLayout *verticalLayout_2;
    QVBoxLayout *verticalLayout;
    QTextEdit *textEditIp;
    QHBoxLayout *horizontalLayout;
    QPushButton *pushButtonConnect;
    QPushButton *pushButtonDisconnect;
    QHBoxLayout *horizontalLayout_2;
    QSlider *horizontalSliderMin;
    QLabel *labelMin;
    QLCDNumber *lcdNumberMin;
    QHBoxLayout *horizontalLayout_3;
    QSlider *horizontalSliderMax;
    QLabel *labelMax;
    QLCDNumber *lcdNumberMax;
    QHBoxLayout *horizontalLayout_4;
    QLabel *labelTiming;
    QSlider *horizontalSliderTiming;
    QLabel *labelSelectedTiming;
    QHBoxLayout *horizontalLayout_5;
    QPushButton *pushButtonPut;
    QPushButton *pushButtonStop;
    QVBoxLayout *verticalLayout_3;
    QLabel *connectionLabel;
    QHBoxLayout *horizontalLayout_6;
    QTextBrowser *textBrowserData;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(627, 408);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        horizontalLayout_8 = new QHBoxLayout(centralWidget);
        horizontalLayout_8->setSpacing(6);
        horizontalLayout_8->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_8->setObjectName(QString::fromUtf8("horizontalLayout_8"));
        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setSpacing(6);
        horizontalLayout_7->setObjectName(QString::fromUtf8("horizontalLayout_7"));
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        textEditIp = new QTextEdit(centralWidget);
        textEditIp->setObjectName(QString::fromUtf8("textEditIp"));
        textEditIp->setMaximumSize(QSize(16777215, 30));

        verticalLayout->addWidget(textEditIp);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        pushButtonConnect = new QPushButton(centralWidget);
        pushButtonConnect->setObjectName(QString::fromUtf8("pushButtonConnect"));

        horizontalLayout->addWidget(pushButtonConnect);

        pushButtonDisconnect = new QPushButton(centralWidget);
        pushButtonDisconnect->setObjectName(QString::fromUtf8("pushButtonDisconnect"));

        horizontalLayout->addWidget(pushButtonDisconnect);


        verticalLayout->addLayout(horizontalLayout);


        verticalLayout_2->addLayout(verticalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalSliderMin = new QSlider(centralWidget);
        horizontalSliderMin->setObjectName(QString::fromUtf8("horizontalSliderMin"));
        horizontalSliderMin->setOrientation(Qt::Horizontal);

        horizontalLayout_2->addWidget(horizontalSliderMin);

        labelMin = new QLabel(centralWidget);
        labelMin->setObjectName(QString::fromUtf8("labelMin"));

        horizontalLayout_2->addWidget(labelMin);

        lcdNumberMin = new QLCDNumber(centralWidget);
        lcdNumberMin->setObjectName(QString::fromUtf8("lcdNumberMin"));
        lcdNumberMin->setMaximumSize(QSize(16777215, 50));
        lcdNumberMin->setSegmentStyle(QLCDNumber::Flat);

        horizontalLayout_2->addWidget(lcdNumberMin);


        verticalLayout_2->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        horizontalSliderMax = new QSlider(centralWidget);
        horizontalSliderMax->setObjectName(QString::fromUtf8("horizontalSliderMax"));
        horizontalSliderMax->setOrientation(Qt::Horizontal);

        horizontalLayout_3->addWidget(horizontalSliderMax);

        labelMax = new QLabel(centralWidget);
        labelMax->setObjectName(QString::fromUtf8("labelMax"));

        horizontalLayout_3->addWidget(labelMax);

        lcdNumberMax = new QLCDNumber(centralWidget);
        lcdNumberMax->setObjectName(QString::fromUtf8("lcdNumberMax"));
        lcdNumberMax->setMaximumSize(QSize(16777215, 50));
        lcdNumberMax->setSegmentStyle(QLCDNumber::Flat);

        horizontalLayout_3->addWidget(lcdNumberMax);


        verticalLayout_2->addLayout(horizontalLayout_3);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        labelTiming = new QLabel(centralWidget);
        labelTiming->setObjectName(QString::fromUtf8("labelTiming"));

        horizontalLayout_4->addWidget(labelTiming);

        horizontalSliderTiming = new QSlider(centralWidget);
        horizontalSliderTiming->setObjectName(QString::fromUtf8("horizontalSliderTiming"));
        horizontalSliderTiming->setOrientation(Qt::Horizontal);

        horizontalLayout_4->addWidget(horizontalSliderTiming);

        labelSelectedTiming = new QLabel(centralWidget);
        labelSelectedTiming->setObjectName(QString::fromUtf8("labelSelectedTiming"));
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(labelSelectedTiming->sizePolicy().hasHeightForWidth());
        labelSelectedTiming->setSizePolicy(sizePolicy);

        horizontalLayout_4->addWidget(labelSelectedTiming);


        verticalLayout_2->addLayout(horizontalLayout_4);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setSpacing(6);
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        pushButtonPut = new QPushButton(centralWidget);
        pushButtonPut->setObjectName(QString::fromUtf8("pushButtonPut"));

        horizontalLayout_5->addWidget(pushButtonPut);

        pushButtonStop = new QPushButton(centralWidget);
        pushButtonStop->setObjectName(QString::fromUtf8("pushButtonStop"));

        horizontalLayout_5->addWidget(pushButtonStop);


        verticalLayout_2->addLayout(horizontalLayout_5);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        connectionLabel = new QLabel(centralWidget);
        connectionLabel->setObjectName(QString::fromUtf8("connectionLabel"));
        sizePolicy.setHeightForWidth(connectionLabel->sizePolicy().hasHeightForWidth());
        connectionLabel->setSizePolicy(sizePolicy);

        verticalLayout_3->addWidget(connectionLabel);


        verticalLayout_2->addLayout(verticalLayout_3);

        verticalLayout_2->setStretch(0, 15);
        verticalLayout_2->setStretch(1, 25);
        verticalLayout_2->setStretch(2, 25);
        verticalLayout_2->setStretch(3, 25);
        verticalLayout_2->setStretch(4, 20);

        horizontalLayout_7->addLayout(verticalLayout_2);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setSpacing(0);
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        textBrowserData = new QTextBrowser(centralWidget);
        textBrowserData->setObjectName(QString::fromUtf8("textBrowserData"));

        horizontalLayout_6->addWidget(textBrowserData);


        horizontalLayout_7->addLayout(horizontalLayout_6);


        horizontalLayout_8->addLayout(horizontalLayout_7);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 627, 22));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        pushButtonConnect->setText(QCoreApplication::translate("MainWindow", "Connect", nullptr));
        pushButtonDisconnect->setText(QCoreApplication::translate("MainWindow", "Disconnect", nullptr));
        labelMin->setText(QCoreApplication::translate("MainWindow", "Min", nullptr));
        labelMax->setText(QCoreApplication::translate("MainWindow", "Max", nullptr));
        labelTiming->setText(QCoreApplication::translate("MainWindow", "Timing(s)", nullptr));
        labelSelectedTiming->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        pushButtonPut->setText(QCoreApplication::translate("MainWindow", "Start", nullptr));
        pushButtonStop->setText(QCoreApplication::translate("MainWindow", "Stop", nullptr));
        connectionLabel->setText(QCoreApplication::translate("MainWindow", "Disconnected", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
