#ifndef QCLIENT_H
#define QCLIENT_H

#include <QtGui>
#include <QtNetwork>

#include "ui_qclient.h"

class QClient : public QMainWindow
{
	Q_OBJECT

public:
    QClient(QWidget *parent = 0);
	~QClient();
signals:
	void sms(QString);
private slots:
	void send();

	void readSocket();
	void readSMS(QString);

	void discardSocket();
private:
	Ui::QClientClass ui;
	QLocalSocket* conection;
};

#endif // QCLIENT_H
