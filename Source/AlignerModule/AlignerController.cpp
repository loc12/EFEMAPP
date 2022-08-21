#include "AlignerController.h"

CAlignerController::CAlignerController(CLogModel* log, QObject *parent)
    :QObject(parent)
{
    m_pAlignerComm  = new CAlignerComm(log);
    m_pSendCmdThread    = new QThread();
    m_pAlignerComm->moveToThread(m_pSendCmdThread);
    connect(m_pAlignerComm, SIGNAL(destroyed(QObject*)), m_pSendCmdThread, SLOT(quit()));
    connect(m_pSendCmdThread, SIGNAL(finished()), m_pSendCmdThread, SLOT(deleteLater()));
    QObject::connect(this, SIGNAL(parserCommand(QByteArray)), m_pAlignerComm, SLOT(OnParserCommand(QByteArray)));
    QObject::connect(m_pAlignerComm, SIGNAL(handleReceiveMsg()), this, SLOT(OnHandleReceiveMsg()));
    QObject::connect(m_pAlignerComm, SIGNAL(updateGUI(int)), this, SLOT(OnUpdateGUI(int)));
    QObject::connect(m_pAlignerComm, SIGNAL(addOperationLog(QString, QString)), this, SLOT(OnAlignerLog(QString, QString)));

    m_pSendCmdThread->start();

    m_pAlignerComm->SetQueueRMessage(&m_queueReceiveMsg);
}

void CAlignerController::SetSettingData(CSettingData *data)
{
    m_pAlignerComm->SetSettingData(data);
}

void CAlignerController::OpenPortServer()
{
    m_pAlignerComm->InitLanConnection();
}

void CAlignerController::OnHandleReceiveMsg()
{
    while(m_queueReceiveMsg.size() > 0){
        QByteArray msg = m_queueReceiveMsg.front();
        m_queueReceiveMsg.pop_front();
        // Handle the receive message
        emit updateGUI(1);
        emit parserCommand(msg);
    }
}

void CAlignerController::OnUpdateGUI(int type)
{
    emit updateGUI(type);
}

void CAlignerController::OnAlignerLog(QString msg, QString dir)
{
    updateAlignerLog(msg, dir);
}
