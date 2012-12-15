/********************************************************************************
** Form generated from reading UI file 'qserver.ui'
**
** Created: Sat 15. Dec 19:17:03 2012
**      by: Qt User Interface Compiler version 4.8.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_QSERVER_H
#define UI_QSERVER_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QGridLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLineEdit>
#include <QtGui/QListWidget>
#include <QtGui/QMainWindow>
#include <QtGui/QMenuBar>
#include <QtGui/QPushButton>
#include <QtGui/QStatusBar>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_QServerClass
{
public:
    QWidget *centralWidget;
    QGridLayout *gridLayout;
    QListWidget *listWidget;
    QLineEdit *lineEdit;
    QLineEdit *lineEdit_2;
    QPushButton *pushButton;
    QMenuBar *menuBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *QServerClass)
    {
        if (QServerClass->objectName().isEmpty())
            QServerClass->setObjectName(QString::fromUtf8("QServerClass"));
        QServerClass->resize(371, 463);
        centralWidget = new QWidget(QServerClass);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        gridLayout = new QGridLayout(centralWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        listWidget = new QListWidget(centralWidget);
        listWidget->setObjectName(QString::fromUtf8("listWidget"));

        gridLayout->addWidget(listWidget, 0, 0, 1, 3);

        lineEdit = new QLineEdit(centralWidget);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setMaximumSize(QSize(50, 16777215));

        gridLayout->addWidget(lineEdit, 1, 0, 1, 1);

        lineEdit_2 = new QLineEdit(centralWidget);
        lineEdit_2->setObjectName(QString::fromUtf8("lineEdit_2"));

        gridLayout->addWidget(lineEdit_2, 1, 1, 1, 1);

        pushButton = new QPushButton(centralWidget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));

        gridLayout->addWidget(pushButton, 1, 2, 1, 1);

        QServerClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(QServerClass);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 371, 21));
        QServerClass->setMenuBar(menuBar);
        statusBar = new QStatusBar(QServerClass);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        QServerClass->setStatusBar(statusBar);

        retranslateUi(QServerClass);
        QObject::connect(pushButton, SIGNAL(clicked()), QServerClass, SLOT(send()));

        QMetaObject::connectSlotsByName(QServerClass);
    } // setupUi

    void retranslateUi(QMainWindow *QServerClass)
    {
        QServerClass->setWindowTitle(QApplication::translate("QServerClass", "Server", 0, QApplication::UnicodeUTF8));
        pushButton->setText(QApplication::translate("QServerClass", "PushButton", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class QServerClass: public Ui_QServerClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QSERVER_H
