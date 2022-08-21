#ifndef LOADPORTCONTROLLER_H
#define LOADPORTCONTROLLER_H

#include <QObject>
#include "LoadPortComm.h"

class CLoadPortController : public QObject
{
    Q_OBJECT
public:
    CLoadPortController(CLogModel* log, QObject* parent = 0);
    void SetSettingData(CSettingData* data);
    bool OpenSerialCom();
    bool AddMessageToQueue(QString msg);
    void ChangeWaferSize(int type);
private:
    void sendLPEvent(QByteArray msg);

signals:
    void parserCommand(QByteArray);
    void sendCommand(QByteArray);
    void updateLPLog(QString, QString);

public slots:
    void OnHandleReceiveMsg();
    void OnLPLog(QString msg, QString dir);

private:
    QThread*            m_pSendCmdThread;
    CLoadPortComm*      m_pLPComm;
    QQueue<QByteArray>  m_queueReceiveMsg;
};

#endif // LOADPORTCONTROLLER_H
