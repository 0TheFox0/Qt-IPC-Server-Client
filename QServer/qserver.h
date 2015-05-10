#ifndef QSERVER_H
#define QSERVER_H

#include <QtGui>
#include <QtNetwork>
#include "ui_qserver.h"

class QServer : public QMainWindow
{
	Q_OBJECT

public:
    QServer(QWidget *parent = 0);
	~QServer();
signals:
	void sms(QString);
private slots:
	void send();
	void send(QLocalSocket *,QString);

	void newConnection();
	void readSocket();
	void readSMS(QString);

	void discardSocket();
private:
	Ui::QServerClass ui;
	QLocalServer m_server;
	QList<QLocalSocket*> connection_list;
	void addToList(QLocalSocket*);
};

#endif // QSERVER_H
