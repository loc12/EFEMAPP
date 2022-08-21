#ifndef LOADPORTINTERFACE_H
#define LOADPORTINTERFACE_H

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
#include "../Global.h"

enum TypeOfMessage {
    eSetMessage = 0,
    eGetMessage = 1,
    eMovMessage = 2,
};

class CLoadPortComm : public QObject
{
    Q_OBJECT
public:
    CLoadPortComm(CLogModel* model, QObject* parent = 0);
    ~CLoadPortComm();
    void    SetQueueRMessage(QQueue<QByteArray> *queue);
    void    SetWaferSize(int size);
    //////////////////////////////////////////////////////////////////////
    // Utility
//    void Char2HexString(const char* src,QString& dst,unsigned int len)
//    {
//        QString buf;
//        for(unsigned int i = 0;i < len;++i){
////            buf.Format("0x%02X , ",src[i]);
////            dst += buf;
//        }
//    }
    void Char2CommandString(const char* src,QString& dst,unsigned int len)
    {
        for(unsigned int i = 5;i < len;++i){
            if (src[i] == ';') {
                break;
            }
            dst += src[i];
        }
    }

    void    SetSettingData(CSettingData* data);
    bool    OpenComPort();
signals:
    void    handleLPMsg();
    void    sendCommand(int cmdNo, QByteArray data);
    void    SendData(QByteArray data);          // Send Data to via socket
    void    addOperationLog(QString msg, QString dir);
public slots:
    // slot handle from CommunicationSocket class
    void    OnReceiveData(QByteArray data);
    void    OnParserCommand(QByteArray data);
    void    OnSendCommand(QByteArray data);

protected:
    // Check sum calculator
    bool 	RecvChecksumCalculator(QByteArray data, int length);
    bool 	SendChecksumCalculator(QString data, char& CSH, char& CSI);
    QString	GetCommandString(int CmdCode);

private:
    CSerialConnection*      m_pSerialConnection;
    QThread*                m_pCommThread;
    QTimer                  m_pTimer;
    QQueue<QByteArray>*     m_pQueueReceiveCmd;
    int                     m_waferSize;
    QMutex                  m_mutexReceive;
    bool                    m_bWaitToCommand;
    CLogModel*              m_pLogModel;
    CSettingData*           m_pSettingData;

    // private function
private:
    bool    SendResponseMessage(int cmdNo, int typeMsg = eSetMessage);       // ACK: normal response, NAK: rejection response
    bool    SendTerminationMessage(int cmd);      // INF: normal termination, ABS: abnormal termication


    bool    SendLPCommand_SET_RESET();
    bool    SendLPCommand_SET_BLLOD();
    bool    SendLPCommand_SET_BLULD();
    bool    SendLPCommand_SET_LPULD();
    bool    SendLPCommand_SET_LOLOD();

    bool    SendLPCommand_SET_LPLOD();
    bool    SendLPCommand_SET_LOULD();
    bool    SendLPCommand_GET_VERSN();
    bool    SendLPCommand_GET_STATE();
    bool    SendLPCommand_GET_MAPRD();
    bool    SendLPCommand_MOV_ABORG();
    bool    SendLPCommand_MOV_PODCL();
    bool    SendLPCommand_MOV_YDOOR();

    bool    SendLPCommand_MOV_CULYD();
    bool    SendLPCommand_MOV_CLDMP();
    bool    SendLPCommand_MOV_CULOD();


    bool    SendLPCommand_MOV_CLOAD();

};

#endif // LOADPORTINTERFACE_H
