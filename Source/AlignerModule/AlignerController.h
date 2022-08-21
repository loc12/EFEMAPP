#ifndef CALIGNERCONTROLLER_H
#define CALIGNERCONTROLLER_H

#include <QObject>

#include "AlignerComm.h"

class CAlignerController : public QObject
{
    Q_OBJECT
public:
    CAlignerController(CLogModel* log, QObject* parent = 0);

    void SetSettingData(CSettingData* data);
    void OpenPortServer();

signals:
    void parserCommand(QByteArray);
    void updateGUI(int type);
    void updateAlignerLog(QString msg, QString dir);

public slots:
    void OnHandleReceiveMsg();
    void OnUpdateGUI(int);
    void OnAlignerLog(QString msg, QString dir);


private:
    QThread*               m_pSendCmdThread;
    CAlignerComm*          m_pAlignerComm;
    QQueue<QByteArray>     m_queueReceiveMsg;
};

#endif // CALIGNERCONTROLLER_H
