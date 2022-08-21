#ifndef COCRIDINTERFACE_H
#define COCRIDINTERFACE_H

#include <QObject>
#include <QTimer>
#include <QQueue>
#include <QThread>
#include <QMutex>
#include <QMap>
#include "../Common/SerialConnection.h"
#include "../DefConstant.h"
#include "../Model/LogModel.h"
#include "../Model/SettingData.h"

class COCRIDComm : public QObject
{
    Q_OBJECT
public:
    COCRIDComm(CLogModel* model, QObject* parent = 0);
    ~COCRIDComm();
    void    SetQueueRMessage(QQueue<QByteArray> *queue);
    void    SetSettingData(CSettingData* data);
    bool    OpenSerialCom();
signals:
    void    handleOCRIDMsg();
    void    sendCommand(int cmdNo, QByteArray data);
    void    SendData(QByteArray data);          // Send Data to via socket
    void    addOperationLog(QString msg, QString dir);
public slots:
    // slot handle from CommunicationSocket class
    void    OnReceiveData(QByteArray data);
    void    OnParserCommand(QByteArray data);
protected:
    // Check sum calculator
    bool 	RecvChecksumCalculator(QByteArray data, int length);
    bool 	SendChecksumCalculator(QString data, char& CSH, char& CSI);
//    bool	MakeCommandString(int CmdCode, char* CommandLine, bool retry);
private:
    CSerialConnection*      m_pSerialConnection;
    QThread*                m_pCommThread;
    QTimer                  m_pTimer;
    QQueue<QByteArray>*     m_pQueueReceiveCmd;
    QMutex                  m_mutexReceive;
    bool                    m_bWaitToCommand;
    CLogModel*              m_pLogModel;
    CSettingData*           m_pSettingData;
};

#endif // COCRIDINTERFACE_H
