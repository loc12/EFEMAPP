#ifndef OCRIDCONTROLLER_H
#define OCRIDCONTROLLER_H

#include <QObject>
#include "OCRIDComm.h"

class COCRIDController : public QObject
{
    Q_OBJECT
public:
    COCRIDController(CLogModel* log, QObject* parent = 0);
    void SetSettingData(CSettingData* data);
    bool OpenSerialCom();
signals:
    void parserCommand(QByteArray);
    void updateOCRIDLog(QString, QString);

public slots:
    void OnHandleReceiveMsg();
    void OnOCRIDLog(QString msg, QString dir);

private:
    QThread*            m_pSendCmdThread;
    COCRIDComm*         m_pOCRIDComm;
    QQueue<QByteArray>  m_queueReceiveMsg;
};

#endif // OCRIDCONTROLLER_H
