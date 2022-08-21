#ifndef RFIDCONTROLLER_H
#define RFIDCONTROLLER_H

#include <QObject>
#include "RFIDComm.h"

class CRFIDController : public QObject
{
    Q_OBJECT
public:
    CRFIDController(CLogModel* log, QObject* parent = 0);
    void SetSettingData(CSettingData* data);
    bool OpenSerialCom();
signals:
    void parserCommand(QByteArray);
    void parserCommand8(QByteArray);
    void updateRFIDLog(QString, QString);
    void updateRFIDLog8(QString, QString);

public slots:
    void OnHandleReceiveMsg();
    void OnRFIDLog(QString msg, QString dir);
    void OnHandleReceiveMsg8();

private:
    QThread*            m_pSendCmdThread[eWaferSizeMax];
    CRFIDComm*          m_pRFIDComm[eWaferSizeMax];
    QQueue<QByteArray>  m_queueReceiveMsg[eWaferSizeMax];
};

#endif // RFIDCONTROLLER_H
