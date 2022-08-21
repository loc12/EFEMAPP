#ifndef CROBOTCONTROLLER_H
#define CROBOTCONTROLLER_H

#include <QObject>

#include "RobotComm.h"

class CRobotController : public QObject
{
    Q_OBJECT
public:
    CRobotController(CLogModel* log, QObject* parent = 0);

    void SetSettingData(CSettingData* data);
    void OpenPortServer();

signals:
    void parserCommand(QByteArray);
    void updateGUI(int type);
    void updateRBLog(QString msg, QString dir);

public slots:
    void OnHandleReceiveMsg();
    void OnUpdateGUI(int);
    void OnRBLog(QString msg, QString dir);


private:
    QThread*               m_pSendCmdThread;
    CRobotComm*            m_pRobotComm;
    QQueue<QByteArray>     m_queueReceiveMsg;
};

#endif // CROBOTCONTROLLER_H
