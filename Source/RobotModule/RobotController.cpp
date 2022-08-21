#include "RobotController.h"

CRobotController::CRobotController(CLogModel* log, QObject *parent)
    :QObject(parent)
{
    m_pRobotComm  = new CRobotComm(log);
    m_pSendCmdThread    = new QThread();
    m_pRobotComm->moveToThread(m_pSendCmdThread);
    connect(m_pRobotComm, SIGNAL(destroyed(QObject*)), m_pSendCmdThread, SLOT(quit()));
    connect(m_pSendCmdThread, SIGNAL(finished()), m_pSendCmdThread, SLOT(deleteLater()));
    QObject::connect(this, SIGNAL(parserCommand(QByteArray)), m_pRobotComm, SLOT(OnParserCommand(QByteArray)));
    QObject::connect(m_pRobotComm, SIGNAL(handleReceiveMsg()), this, SLOT(OnHandleReceiveMsg()));
    QObject::connect(m_pRobotComm, SIGNAL(updateGUI(int)), this, SLOT(OnUpdateGUI(int)));
    QObject::connect(m_pRobotComm, SIGNAL(addOperationLog(QString, QString)), this, SLOT(OnRBLog(QString, QString)));

    m_pSendCmdThread->start();

    m_pRobotComm->SetQueueRMessage(&m_queueReceiveMsg);
}

void CRobotController::SetSettingData(CSettingData *data)
{
    m_pRobotComm->SetSettingData(data);
}

void CRobotController::OpenPortServer()
{
    m_pRobotComm->InitLanConnection();
}

void CRobotController::OnHandleReceiveMsg()
{
    while(m_queueReceiveMsg.size() > 0){
        QByteArray msg = m_queueReceiveMsg.front();
        m_queueReceiveMsg.pop_front();
        // Handle the receive message
        emit updateGUI(1);
        emit parserCommand(msg);
    }
}

void CRobotController::OnUpdateGUI(int type)
{
    emit updateGUI(type);
}

void CRobotController::OnRBLog(QString msg, QString dir)
{
    updateRBLog(msg, dir);
}
