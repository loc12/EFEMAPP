#include "SerialConnection.h"

CSerialConnection::CSerialConnection(QObject *parent)
    :QObject(parent)
{
    m_pSerialPort = new QSerialPort();
    connect(m_pSerialPort, &QSerialPort::readyRead, this, &CSerialConnection::OnReceive);
}

CSerialConnection::~CSerialConnection()
{
}

bool CSerialConnection::OpenPortCom(QString comNo, int baudRate, QSerialPort::DataBits dataBits, QSerialPort::Parity parity)
{
    bool r = true;
    qDebug()<<"CSerialConnection::OpenPortCom";
    m_pSerialPort->setPortName(comNo);
    m_pSerialPort->setBaudRate(baudRate);
    m_pSerialPort->setDataBits(dataBits);
    m_pSerialPort->setParity(parity);
    m_pSerialPort->setStopBits(QSerialPort::OneStop);
    m_pSerialPort->setFlowControl(QSerialPort::NoFlowControl);
    if (m_pSerialPort->open(QIODevice::ReadWrite)) {
        qDebug()<<"CSerialConnection::OpenPortCom true";
        r = true;
    } else {
        qDebug()<<"CSerialConnection::OpenPortCom false";
        r = false;
    }
    return r;
}

void CSerialConnection::OnReceive()
{
    QByteArray data = m_pSerialPort->readAll();
    m_dataArray.append(data);
    bool bFinish = false;
    qDebug() << "CSerialConnection::OnReceive()";
    while (!bFinish && m_dataArray.size() > 0)
    {
        bool bIsValidData = true;
        // check start of message: Load Port Command
        if(m_dataArray.at(0) == START_CHAR_LP)
        {
            int end = 0;
            char ch = START_END_LP;
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
        else if(m_dataArray.at(0) == START_CHAR_RFID){
            int end = 0;
            char ch = START_END_RFID;
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
        else if(m_dataArray.at(0) == 'R'){
            int end = 0;
            char ch = START_END_OCRID;
            QByteArray endcharacter;
            endcharacter.append(ch);
            end = m_dataArray.indexOf(endcharacter, 0);
            qDebug() << "OnReceive";
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

void CSerialConnection::OnSendData(QByteArray data)
{
    qDebug() << "CSerialConnection::OnSendData ";
    qDebug() << data;

    m_pSerialPort->write(data);
}
