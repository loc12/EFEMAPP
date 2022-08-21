#ifndef CSERIALCONNECTION_H
#define CSERIALCONNECTION_H

#include <QObject>
#include <QtSerialPort/QSerialPort>
#include <QThread>
#include <QDebug>
#include "../DefConstant.h"

class CSerialConnection : public QObject
{
    Q_OBJECT
public:
    CSerialConnection(QObject* parent = 0);
    ~CSerialConnection();
    bool OpenPortCom(QString comNo, int baudRate, QSerialPort::DataBits dataBits = QSerialPort::Data8, QSerialPort::Parity parity = QSerialPort::NoParity);
signals:
    void RecieveData(QByteArray data);
public slots:
    void OnReceive();
    void OnSendData(QByteArray data);
private:
    QSerialPort*    m_pSerialPort;
    QByteArray      m_dataArray;
};

#endif // CSERIALCONNECTION_H
