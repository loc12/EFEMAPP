#include "RFIDController.h"

CRFIDController::CRFIDController(CLogModel *log, QObject *parent)
    :QObject(parent)
{
    for(int i = 0; i < eWaferSizeMax; i++){
        m_pRFIDComm[i] = new CRFIDComm(log, i);
        m_pSendCmdThread[i]    = new QThread();
        m_pRFIDComm[i]->moveToThread(m_pSendCmdThread[i]);
        connect(m_pRFIDComm[i], SIGNAL(destroyed(QObject*)), m_pSendCmdThread[i], SLOT(quit()));
        connect(m_pSendCmdThread[i], SIGNAL(finished()), m_pSendCmdThread[i], SLOT(deleteLater()));
        if(i == eWaferSize12inch){
            QObject::connect(this, SIGNAL(parserCommand(QByteArray)), m_pRFIDComm[i], SLOT(OnParserCommand(QByteArray)));
            QObject::connect(m_pRFIDComm[i], SIGNAL(handleRFIDMsg()), this, SLOT(OnHandleReceiveMsg()));
        }
        else {
            QObject::connect(this, SIGNAL(parserCommand8(QByteArray)), m_pRFIDComm[i], SLOT(OnParserCommand8(QByteArray)));
            QObject::connect(m_pRFIDComm[i], SIGNAL(handleRFIDMsg8()), this, SLOT(OnHandleReceiveMsg8()));
        }
        QObject::connect(m_pRFIDComm[i], SIGNAL(addOperationLog(QString, QString)), this, SLOT(OnRFIDLog(QString, QString)));
        m_pSendCmdThread[i]->start();
        m_pRFIDComm[i]->SetQueueRMessage(&m_queueReceiveMsg[i]);
    }
}

void CRFIDController::SetSettingData(CSettingData *data)
{
    m_pRFIDComm[eWaferSize12inch]->SetSettingData(data);
    m_pRFIDComm[eWaferSize8inch]->SetSettingData(data);
}

bool CRFIDController::OpenSerialCom()
{
    bool r = false;
    r = m_pRFIDComm[eWaferSize12inch]->OpenSerialCom();
    if(r) r = m_pRFIDComm[eWaferSize8inch]->OpenSerialCom();
    return r;
}

void CRFIDController::OnHandleReceiveMsg()
{
    while(m_queueReceiveMsg[eWaferSize12inch].size() > 0){
        QByteArray msg = m_queueReceiveMsg[eWaferSize12inch].front();
        m_queueReceiveMsg[eWaferSize12inch].pop_front();
        // Handle the receive message
        // emit the signal to the Manipulator thread
        emit parserCommand(msg);
    }
}

void CRFIDController::OnRFIDLog(QString msg, QString dir)
{
    updateRFIDLog(msg, dir);
}

void CRFIDController::OnHandleReceiveMsg8()
{
    while(m_queueReceiveMsg[eWaferSize8inch].size() > 0){
        QByteArray msg = m_queueReceiveMsg[eWaferSize8inch].front();
        m_queueReceiveMsg[eWaferSize8inch].pop_front();
        // Handle the receive message
        // emit the signal to the Manipulator thread
        emit parserCommand8(msg);
    }
}
