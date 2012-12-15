#include "qclient.h"

QClient::QClient(QWidget *parent, Qt::WFlags flags)
	: QMainWindow(parent, flags)
{
	ui.setupUi(this);
	conection = new QLocalSocket(this);

	connect(conection,SIGNAL(readyRead()),this,SLOT(readSocket()));
	connect(conection,SIGNAL(disconnected()),this,SLOT(discardSocket()));

	connect(this,SIGNAL(sms(QString)),this,SLOT(readSMS(QString)));

	conection->connectToServer("test");
}

QClient::~QClient()
{
	if(conection)
		conection->close();	
}

void QClient::readSocket()
{
	QByteArray block = conection->readAll();
	QDataStream in(&block, QIODevice::ReadOnly);
	in.setVersion(QDataStream::Qt_4_0);
	while (!in.atEnd())
	{
		QString receiveString;
		in >> receiveString;
		receiveString.prepend(QString("%1 :: ").arg(conection->socketDescriptor()));
		emit sms(receiveString);
	}	
}

void QClient::readSMS(QString sms)
{
	QListWidgetItem * item = new QListWidgetItem(ui.listWidget);
	item->setText(sms);	
}

void QClient::discardSocket()
{
	ui.statusBar->showMessage("Disconnected!");
	conection->deleteLater();
	conection = 0;
}

void QClient::send()
{
	if(conection)
	{
		if(conection->isOpen())
		{
			QString str = ui.lineEdit->text();
			QByteArray block;
			QDataStream out(&block, QIODevice::WriteOnly);

			out.setVersion(QDataStream::Qt_4_0);
			out << str;
			conection->write(block);
		}
		else
		{
			ui.statusBar->showMessage("Connection isn't open!");
		}
	}
	else
	{
		ui.statusBar->showMessage("Not connected!");
	}
}