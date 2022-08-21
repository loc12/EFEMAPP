#include "LanConnection.h"

CLanConnection::CLanConnection(qint32 iPort, QObject *parent)
    :QObject(parent),
      m_pServer(NULL),
      m_pClientSocket(NULL)
{
    m_iPort = iPort;
    CreateTcpServer();
}

CLanConnection::~CLanConnection()
{
    if(m_pClientSocket)
    {
        m_pClientSocket->deleteLater();
    }
    if(m_pServer){
        delete m_pServer;
        m_pServer = nullptr;
    }
}

void CLanConnection::SendData(QByteArray data)
{
    if(m_pClientSocket)
    {
        m_pClientSocket->write(data);
        qDebug() << "Send data: " + data;
    }
}

void CLanConnection::CreateTcpServer()
{
    bool bCreateSuccess = false;
    while (bCreateSuccess == false)
    {
        if(m_pServer == NULL)
        {
            m_pServer = new QTcpServer(this);
            m_pServer->setProxy(QNetworkProxy::NoProxy);
        }
        bCreateSuccess = m_pServer->listen(QHostAddress::Any, m_iPort);
        connect(m_pServer, SIGNAL(newConnection()), this, SLOT(OnNewConnection()));
    }
}

void CLanConnection::OnNewConnection()
{
    if(m_pClientSocket != NULL)
    {
        return;
    }
    m_pClientSocket = m_pServer->nextPendingConnection();
    if(m_pClientSocket != NULL)
    {
        connect(m_pClientSocket, SIGNAL(readyRead()), this, SLOT(OnReciveCommand()), Qt::QueuedConnection);
        connect(m_pClientSocket, SIGNAL(disconnected()), this, SLOT(OnDisconnect()), Qt::QueuedConnection);
        //        emit ConnectSuccess();
    }
}

void CLanConnection::OnReciveCommand()
{
//    disconnect(m_pClientSocket, SIGNAL(readyRead()), this, SLOT(OnReciveCommand()));
    QTcpSocket* socket = qobject_cast<QTcpSocket*>(sender());
    while(socket->bytesAvailable())
    {
        QByteArray data = socket->readAll();
        m_dataArray.append(data);
        bool bFinish = false;

        while (!bFinish && m_dataArray.size() > 0)
        {
            bool bIsValidData = true;
            qDebug() << "OnReceiveData: " + m_dataArray;
            // check start of message
            if(m_dataArray.at(0) == START_CHAR_1)
            {
                int end = 0;
                char ch = END_CHAR_1;
                QByteArray endcharacter;
                endcharacter.append(ch);
                end = m_dataArray.indexOf(endcharacter, 0);
                if(end > 0){
                    QByteArray data1 = m_dataArray.mid(0, end + 1);
                    emit RecieveData(data1);
                    m_dataArray.clear();
                }
                bFinish = true;
            }
            else
            {
                bIsValidData = false;
            }
            // check end of message
            if(!bIsValidData)
            {
                m_dataArray.clear();
                bFinish = true;
            }
        }

    }
//    connect(m_pClientSocket, SIGNAL(readyRead()), this, SLOT(OnReciveCommand()), Qt::QueuedConnection);
    return;
}

void CLanConnection::OnDisconnect()
{
    m_pClientSocket->deleteLater();
    m_pClientSocket = NULL;
    emit DisconnectConn();
}

void CLanConnection::OnSendData(QByteArray data)
{
    SendData(data);
}
