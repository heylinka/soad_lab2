/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created: Thu 22. Feb 05:09:05 2018
**      by: Qt User Interface Compiler version 4.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QMainWindow>
#include <QtGui/QMenuBar>
#include <QtGui/QPushButton>
#include <QtGui/QRadioButton>
#include <QtGui/QStatusBar>
#include <QtGui/QTextBrowser>
#include <QtGui/QToolBar>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QLabel *label;
    QLabel *label_2;
    QRadioButton *radioSimple;
    QRadioButton *radioNatural;
    QTextBrowser *textInput;
    QLabel *label_4;
    QTextBrowser *textOutput;
    QLabel *label_5;
    QLabel *label_6;
    QLabel *label_7;
    QTextBrowser *txtSimpleN;
    QTextBrowser *txtSimpleT;
    QTextBrowser *txtNaturalN;
    QTextBrowser *txtNaturalT;
    QLabel *label_9;
    QLabel *label_10;
    QPushButton *pushLoad;
    QPushButton *pushDone;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(741, 456);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        label = new QLabel(centralWidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(20, 20, 111, 20));
        QFont font;
        font.setFamily(QString::fromUtf8("Times New Roman"));
        font.setPointSize(14);
        font.setBold(true);
        font.setWeight(75);
        label->setFont(font);
        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(20, 230, 81, 20));
        label_2->setFont(font);
        radioSimple = new QRadioButton(centralWidget);
        radioSimple->setObjectName(QString::fromUtf8("radioSimple"));
        radioSimple->setGeometry(QRect(20, 50, 91, 18));
        radioNatural = new QRadioButton(centralWidget);
        radioNatural->setObjectName(QString::fromUtf8("radioNatural"));
        radioNatural->setGeometry(QRect(20, 80, 101, 18));
        textInput = new QTextBrowser(centralWidget);
        textInput->setObjectName(QString::fromUtf8("textInput"));
        textInput->setGeometry(QRect(270, 50, 191, 341));
        label_4 = new QLabel(centralWidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(270, 20, 111, 20));
        label_4->setFont(font);
        textOutput = new QTextBrowser(centralWidget);
        textOutput->setObjectName(QString::fromUtf8("textOutput"));
        textOutput->setGeometry(QRect(530, 50, 191, 341));
        label_5 = new QLabel(centralWidget);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(530, 20, 111, 20));
        label_5->setFont(font);
        label_6 = new QLabel(centralWidget);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(20, 270, 101, 16));
        QFont font1;
        font1.setFamily(QString::fromUtf8("Times New Roman"));
        font1.setPointSize(10);
        font1.setBold(false);
        font1.setWeight(50);
        label_6->setFont(font1);
        label_7 = new QLabel(centralWidget);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setGeometry(QRect(20, 310, 101, 16));
        label_7->setFont(font1);
        txtSimpleN = new QTextBrowser(centralWidget);
        txtSimpleN->setObjectName(QString::fromUtf8("txtSimpleN"));
        txtSimpleN->setGeometry(QRect(120, 260, 61, 31));
        txtSimpleT = new QTextBrowser(centralWidget);
        txtSimpleT->setObjectName(QString::fromUtf8("txtSimpleT"));
        txtSimpleT->setGeometry(QRect(190, 260, 61, 31));
        txtNaturalN = new QTextBrowser(centralWidget);
        txtNaturalN->setObjectName(QString::fromUtf8("txtNaturalN"));
        txtNaturalN->setGeometry(QRect(120, 300, 61, 31));
        txtNaturalT = new QTextBrowser(centralWidget);
        txtNaturalT->setObjectName(QString::fromUtf8("txtNaturalT"));
        txtNaturalT->setGeometry(QRect(190, 300, 61, 31));
        label_9 = new QLabel(centralWidget);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        label_9->setGeometry(QRect(130, 240, 31, 16));
        QFont font2;
        font2.setFamily(QString::fromUtf8("Times New Roman"));
        font2.setPointSize(12);
        font2.setBold(true);
        font2.setWeight(75);
        label_9->setFont(font2);
        label_10 = new QLabel(centralWidget);
        label_10->setObjectName(QString::fromUtf8("label_10"));
        label_10->setGeometry(QRect(190, 240, 61, 16));
        label_10->setFont(font2);
        pushLoad = new QPushButton(centralWidget);
        pushLoad->setObjectName(QString::fromUtf8("pushLoad"));
        pushLoad->setGeometry(QRect(470, 140, 51, 21));
        pushDone = new QPushButton(centralWidget);
        pushDone->setObjectName(QString::fromUtf8("pushDone"));
        pushDone->setGeometry(QRect(470, 170, 51, 20));
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 741, 20));
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
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("MainWindow", "Type of sort:", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("MainWindow", "Results:", 0, QApplication::UnicodeUTF8));
        radioSimple->setText(QApplication::translate("MainWindow", "Simple Merging", 0, QApplication::UnicodeUTF8));
        radioNatural->setText(QApplication::translate("MainWindow", "Natural Merging", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("MainWindow", "Input data:", 0, QApplication::UnicodeUTF8));
        label_5->setText(QApplication::translate("MainWindow", "Output data:", 0, QApplication::UnicodeUTF8));
        label_6->setText(QApplication::translate("MainWindow", "Simple Merging:", 0, QApplication::UnicodeUTF8));
        label_7->setText(QApplication::translate("MainWindow", "Natural Merging:", 0, QApplication::UnicodeUTF8));
        label_9->setText(QApplication::translate("MainWindow", "n:", 0, QApplication::UnicodeUTF8));
        label_10->setText(QApplication::translate("MainWindow", "time, s:", 0, QApplication::UnicodeUTF8));
        pushLoad->setText(QApplication::translate("MainWindow", "Load", 0, QApplication::UnicodeUTF8));
        pushDone->setText(QApplication::translate("MainWindow", "Done", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
