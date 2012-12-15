#include "qserver.h"

QServer::QServer(QWidget *parent, Qt::WFlags flags)
	: QMainWindow(parent, flags) , m_server(this)
{
	ui.setupUi(this);

	//To display messages on GUI
	connect(this,SIGNAL(sms(QString)),this,SLOT(readSMS(QString)));

	//Try to start the server, example name "test"
	if(m_server.listen("test"))
	{
		ui.statusBar->showMessage("Server Ready!");

		//Catch all new connections
		connect(&m_server, SIGNAL(newConnection()), this, SLOT(newConnection()));
	}
}

QServer::~QServer()
{
	//Delete stored sockets
	for each (QLocalSocket* socket in connection_list)
	{
		socket->close();
		socket->deleteLater();
	}
}

void QServer::newConnection()
{
	//Add all pending connection
	while (m_server.hasPendingConnections())
	{
		addToList(m_server.nextPendingConnection());
	}
}

void QServer::addToList(QLocalSocket* socket)
{
	//Store sockets & connect them for read & discard them on disconnect
	connection_list.push_back(socket);
	connect(socket, SIGNAL(readyRead()), this , SLOT(readSocket()));
	connect(socket, SIGNAL(disconnected()), this , SLOT(discardSocket()));
}

void QServer::readSocket()
{
	//Pointer to the signal sender
	QLocalSocket * socket = (QLocalSocket*)sender();

	//Read all data on the socket & store it on a QByteArray
	QByteArray block = socket->readAll();

	//Data stream to easy read all data
	QDataStream in(&block, QIODevice::ReadOnly);
	in.setVersion(QDataStream::Qt_4_0);

	while (!in.atEnd()) //loop needed cause some messages can come on a single packet
	{
		QString receiveString;
		in >> receiveString;
		receiveString.prepend(QString("%1 :: ").arg(socket->socketDescriptor()));
		emit sms(receiveString);
	}	
}

void QServer::discardSocket()
{
	//Pointer to the disconnecting socket
	QLocalSocket * ptrSender = (QLocalSocket*)sender();

	//Search on the connection list for the socket
	int index = 0;
	for (;index<connection_list.size();index++)
	{
		if (connection_list.at(index) == ptrSender)
			break;
	}
	//Remove the socket from the list
	connection_list.removeAt(index);

	//Delete the socket a soon as possible
	ptrSender->deleteLater();
}

void QServer::readSMS(QString sms)
{
	//Just display the message on GUI
	QListWidgetItem * item = new QListWidgetItem(ui.listWidget);
	item->setText(sms);	
}

void QServer::send()
{
	//Get the descriptor from the GUI input
	bool is_valid;
	int descriptor = ui.lineEdit->text().toInt(&is_valid,10);

	if(is_valid)
	{
		//Search for a socket on the connection list with the same descriptor
		QLocalSocket* conection = 0;
		for each (QLocalSocket* ptrSocket in connection_list)
		{
			if(ptrSocket->socketDescriptor() == descriptor)
			{
				conection = ptrSocket;
				break;
			}
		}
		QString str = ui.lineEdit_2->text();
		send(conection,str);
	}
}

void QServer::send(QLocalSocket * socket, QString sms)
{
	if(socket)
	{		
		if(socket->isOpen())
		{
			QByteArray block;
			QDataStream out(&block, QIODevice::WriteOnly);

			out.setVersion(QDataStream::Qt_4_0);
			out << sms;
			socket->write(block);
		}
	}
}