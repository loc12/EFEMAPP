#include "OCRIDController.h"

COCRIDController::COCRIDController(CLogModel *log, QObject *parent)
    :QObject(parent)
{
    m_pOCRIDComm = new COCRIDComm(log);
    m_pSendCmdThread    = new QThread();
    m_pOCRIDComm->moveToThread(m_pSendCmdThread);
    connect(m_pOCRIDComm, SIGNAL(destroyed(QObject*)), m_pSendCmdThread, SLOT(quit()));
    connect(m_pSendCmdThread, SIGNAL(finished()), m_pSendCmdThread, SLOT(deleteLater()));
    QObject::connect(this, SIGNAL(parserCommand(QByteArray)), m_pOCRIDComm, SLOT(OnParserCommand(QByteArray)));
    QObject::connect(m_pOCRIDComm, SIGNAL(handleOCRIDMsg()), this, SLOT(OnHandleReceiveMsg()));
    QObject::connect(m_pOCRIDComm, SIGNAL(addOperationLog(QString, QString)), this, SLOT(OnOCRIDLog(QString, QString)));
    m_pSendCmdThread->start();
    m_pOCRIDComm->SetQueueRMessage(&m_queueReceiveMsg);
}

void COCRIDController::SetSettingData(CSettingData *data)
{
    m_pOCRIDComm->SetSettingData(data);
}

bool COCRIDController::OpenSerialCom()
{
    return m_pOCRIDComm->OpenSerialCom();
}

void COCRIDController::OnHandleReceiveMsg()
{
    while(m_queueReceiveMsg.size() > 0){
        QByteArray msg = m_queueReceiveMsg.front();
        m_queueReceiveMsg.pop_front();
        // Handle the receive message
        // emit the signal to the Manipulator thread
        emit parserCommand(msg);
    }
}

void COCRIDController::OnOCRIDLog(QString msg, QString dir)
{
    updateOCRIDLog(msg, dir);
}
