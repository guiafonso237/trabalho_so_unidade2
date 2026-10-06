/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.4.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QLabel *tremB;
    QLabel *label_trilho1;
    QLabel *label_trilho2;
    QLabel *label_trilho3;
    QLabel *label_trilho4;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QLabel *label_trilho4_2;
    QLabel *label_trilho1_2;
    QLabel *label_trilho2_2;
    QLabel *tremC;
    QLabel *label_trilho4_3;
    QLabel *label_trilho1_3;
    QLabel *label_trilho3_3;
    QLabel *label_trem3;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(1267, 523);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName("centralWidget");
        tremB = new QLabel(centralWidget);
        tremB->setObjectName("tremB");
        tremB->setGeometry(QRect(140, 170, 21, 17));
        tremB->setStyleSheet(QString::fromUtf8("QLabel { background: red}"));
        label_trilho1 = new QLabel(centralWidget);
        label_trilho1->setObjectName("label_trilho1");
        label_trilho1->setGeometry(QRect(160, 170, 250, 17));
        label_trilho1->setStyleSheet(QString::fromUtf8("QLabel { background: yellow}"));
        label_trilho2 = new QLabel(centralWidget);
        label_trilho2->setObjectName("label_trilho2");
        label_trilho2->setGeometry(QRect(160, 290, 250, 17));
        label_trilho2->setStyleSheet(QString::fromUtf8("QLabel { background: yellow}"));
        label_trilho3 = new QLabel(centralWidget);
        label_trilho3->setObjectName("label_trilho3");
        label_trilho3->setGeometry(QRect(410, 170, 21, 137));
        label_trilho3->setStyleSheet(QString::fromUtf8("QLabel { background: yellow}"));
        label_trilho4 = new QLabel(centralWidget);
        label_trilho4->setObjectName("label_trilho4");
        label_trilho4->setGeometry(QRect(140, 170, 21, 137));
        label_trilho4->setStyleSheet(QString::fromUtf8("QLabel { background: yellow}"));
        pushButton = new QPushButton(centralWidget);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(310, 320, 99, 27));
        pushButton_2 = new QPushButton(centralWidget);
        pushButton_2->setObjectName("pushButton_2");
        pushButton_2->setGeometry(QRect(430, 320, 98, 27));
        label_trilho4_2 = new QLabel(centralWidget);
        label_trilho4_2->setObjectName("label_trilho4_2");
        label_trilho4_2->setGeometry(QRect(680, 170, 21, 137));
        label_trilho4_2->setStyleSheet(QString::fromUtf8("QLabel { background: yellow}"));
        label_trilho1_2 = new QLabel(centralWidget);
        label_trilho1_2->setObjectName("label_trilho1_2");
        label_trilho1_2->setGeometry(QRect(430, 170, 250, 17));
        label_trilho1_2->setStyleSheet(QString::fromUtf8("QLabel { background: yellow}"));
        label_trilho2_2 = new QLabel(centralWidget);
        label_trilho2_2->setObjectName("label_trilho2_2");
        label_trilho2_2->setGeometry(QRect(430, 290, 250, 17));
        label_trilho2_2->setStyleSheet(QString::fromUtf8("QLabel { background: yellow}"));
        tremC = new QLabel(centralWidget);
        tremC->setObjectName("tremC");
        tremC->setGeometry(QRect(410, 170, 21, 17));
        tremC->setStyleSheet(QString::fromUtf8("QLabel { background: red}"));
        label_trilho4_3 = new QLabel(centralWidget);
        label_trilho4_3->setObjectName("label_trilho4_3");
        label_trilho4_3->setGeometry(QRect(140, 50, 21, 137));
        label_trilho4_3->setStyleSheet(QString::fromUtf8("QLabel { background: yellow}"));
        label_trilho1_3 = new QLabel(centralWidget);
        label_trilho1_3->setObjectName("label_trilho1_3");
        label_trilho1_3->setEnabled(true);
        label_trilho1_3->setGeometry(QRect(160, 50, 541, 17));
        label_trilho1_3->setStyleSheet(QString::fromUtf8("QLabel { background: yellow}"));
        label_trilho3_3 = new QLabel(centralWidget);
        label_trilho3_3->setObjectName("label_trilho3_3");
        label_trilho3_3->setGeometry(QRect(680, 50, 21, 137));
        label_trilho3_3->setStyleSheet(QString::fromUtf8("QLabel { background: yellow}"));
        label_trem3 = new QLabel(centralWidget);
        label_trem3->setObjectName("label_trem3");
        label_trem3->setGeometry(QRect(140, 50, 21, 17));
        label_trem3->setStyleSheet(QString::fromUtf8("QLabel { background: red}"));
        MainWindow->setCentralWidget(centralWidget);
        label_trilho3_3->raise();
        label_trilho4_3->raise();
        label_trilho1->raise();
        label_trilho2->raise();
        label_trilho3->raise();
        label_trilho4->raise();
        tremB->raise();
        pushButton->raise();
        pushButton_2->raise();
        label_trilho4_2->raise();
        label_trilho1_2->raise();
        label_trilho2_2->raise();
        tremC->raise();
        label_trilho1_3->raise();
        label_trem3->raise();
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName("menuBar");
        menuBar->setGeometry(QRect(0, 0, 1267, 27));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName("mainToolBar");
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName("statusBar");
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        tremB->setText(QCoreApplication::translate("MainWindow", "T1", nullptr));
        label_trilho1->setText(QString());
        label_trilho2->setText(QString());
        label_trilho3->setText(QString());
        label_trilho4->setText(QString());
        pushButton->setText(QCoreApplication::translate("MainWindow", "Ligar", nullptr));
        pushButton_2->setText(QCoreApplication::translate("MainWindow", "Parar", nullptr));
        label_trilho4_2->setText(QString());
        label_trilho1_2->setText(QString());
        label_trilho2_2->setText(QString());
        tremC->setText(QCoreApplication::translate("MainWindow", "T2", nullptr));
        label_trilho4_3->setText(QString());
        label_trilho1_3->setText(QString());
        label_trilho3_3->setText(QString());
        label_trem3->setText(QCoreApplication::translate("MainWindow", "T3", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
