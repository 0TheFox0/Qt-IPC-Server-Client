/********************************************************************************
** Form generated from reading UI file 'qclient.ui'
**
** Created: Sat 15. Dec 18:30:22 2012
**      by: Qt User Interface Compiler version 4.8.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_QCLIENT_H
#define UI_QCLIENT_H

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

class Ui_QClientClass
{
public:
    QWidget *centralWidget;
    QGridLayout *gridLayout;
    QListWidget *listWidget;
    QLineEdit *lineEdit;
    QPushButton *pushButton;
    QMenuBar *menuBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *QClientClass)
    {
        if (QClientClass->objectName().isEmpty())
            QClientClass->setObjectName(QString::fromUtf8("QClientClass"));
        QClientClass->resize(332, 476);
        centralWidget = new QWidget(QClientClass);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        gridLayout = new QGridLayout(centralWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        listWidget = new QListWidget(centralWidget);
        listWidget->setObjectName(QString::fromUtf8("listWidget"));

        gridLayout->addWidget(listWidget, 0, 0, 1, 2);

        lineEdit = new QLineEdit(centralWidget);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));

        gridLayout->addWidget(lineEdit, 1, 0, 1, 1);

        pushButton = new QPushButton(centralWidget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));

        gridLayout->addWidget(pushButton, 1, 1, 1, 1);

        QClientClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(QClientClass);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 332, 21));
        QClientClass->setMenuBar(menuBar);
        statusBar = new QStatusBar(QClientClass);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        QClientClass->setStatusBar(statusBar);

        retranslateUi(QClientClass);
        QObject::connect(pushButton, SIGNAL(clicked()), QClientClass, SLOT(send()));

        QMetaObject::connectSlotsByName(QClientClass);
    } // setupUi

    void retranslateUi(QMainWindow *QClientClass)
    {
        QClientClass->setWindowTitle(QApplication::translate("QClientClass", "Client", 0, QApplication::UnicodeUTF8));
        pushButton->setText(QApplication::translate("QClientClass", "PushButton", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class QClientClass: public Ui_QClientClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QCLIENT_H
