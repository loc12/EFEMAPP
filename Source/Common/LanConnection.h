#ifndef CLANCONNECTION_H
#define CLANCONNECTION_H

#include <QObject>
#include <QTcpServer>
#include <QTcpSocket>
#include <QNetworkProxy>
#include <QMutex>
#include <QDebug>           // TNN-TODO: Need to remove this line
#include <QEventLoop>
#include <QTimer>
#include "../DefConstant.h"

class CLanConnection : public QObject
{
    Q_OBJECT
public:
    explicit CLanConnection(qint32 iPort = 9999, QObject *parent = nullptr);
    ~CLanConnection();

    void SendData(QByteArray data);
    void CreateTcpServer();

    // inline function
    inline void SetPortNumber(quint32 iPort){m_iPort = iPort;}

signals:
    void RecieveData(QByteArray data);
    void ConnectSuccess();
    void DisconnectConn();

public slots:
    void OnNewConnection();
    void OnReciveCommand();
    void OnDisconnect();
    void OnSendData(QByteArray data);
private:
    QTcpServer* m_pServer;
    QTcpSocket* m_pClientSocket;
    quint32     m_iPort;
    QByteArray  m_dataArray;
    QMutex      m_mutexSend;

};

#endif // CLANCONNECTION_H
