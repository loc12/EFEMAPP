#include "RobotComm.h"
#include <windows.h>

typedef std::map<QString, int> MAPCMD;
MAPCMD MapRobotCmd = {
    {"INIT", eRBCmd_INIT},
    {"MTRS", eRBCmd_MTRS},
    {"MPNT", eRBCmd_MPNT},
    {"MCTR", eRBCmd_MCTR},
    {"MTCH", eRBCmd_MTCH},
    {"MABS", eRBCmd_MABS},
    {"MREL", eRBCmd_MREL},
    {"MMAP", eRBCmd_MMAP},
    {"MMCA", eRBCmd_MMCA},
    {"MALN", eRBCmd_MALN},
    {"MACA", eRBCmd_MACA},
    {"CSTP", eRBCmd_CSTP},
    {"CRSM", eRBCmd_CRSM},
    {"CSRV", eRBCmd_CSRV},
    {"CCLR", eRBCmd_CCLR},
    {"CSOL", eRBCmd_CSOL},
    {"SSPD", eRBCmd_SSPD},
    {"SSLV", eRBCmd_SSLV},
    {"SPOS", eRBCmd_SPOS},
    {"SABS", eRBCmd_SABS},
    {"SAPS", eRBCmd_SAPS},
    {"SPDL", eRBCmd_SPDL},
    {"SPSV", eRBCmd_SPSV},
    {"SPLD", eRBCmd_SPLD},
    {"SSTR", eRBCmd_SSTR},
    {"SPRM", eRBCmd_SPRM},
    {"SMSK", eRBCmd_SMSK},
    {"SSTD", eRBCmd_SSTD},
    {"SSTN", eRBCmd_SSTN},
    {"RSPD", eRBCmd_RSPD},
    {"RSLV", eRBCmd_RSLV},
    {"RPOS", eRBCmd_RPOS},
    {"RSTP", eRBCmd_RSTP},
    {"RSTR", eRBCmd_RSTR},
    {"RPRM", eRBCmd_RPRM},
    {"RSTS", eRBCmd_RSTS},
    {"RERR", eRBCmd_RERR},
    {"RMSK", eRBCmd_RMSK},
    {"RVER", eRBCmd_RVER},
    {"RMAP", eRBCmd_RMAP},
    {"RMPD", eRBCmd_RMPD},
    {"RMCA", eRBCmd_RMCA},
    {"RALN", eRBCmd_RALN},
    {"RACA", eRBCmd_RACA},
    {"RCCD", eRBCmd_RCCD},
    {"RLOG", eRBCmd_RLOG},
    {"RSTN", eRBCmd_RSTN},
    {"ACKN", eRBCmd_ACKN},
};
CRobotComm::CRobotComm(CLogModel *log, QObject *parent)
    : QObject(parent)
    , m_pLanConnection(NULL)
{
    m_pLogModel = log;
}

CRobotComm::~CRobotComm()
{
    m_pCommThread->quit();
    m_pCommThread->wait();
}

void CRobotComm::InitLanConnection()
{
    int portNo = m_pSettingData->lanPortNo();
    m_pLanConnection = new CLanConnection(portNo, NULL);
    connect(m_pLanConnection, SIGNAL(RecieveData(QByteArray)), this, SLOT(OnReceiveData(QByteArray)));
    connect(this, SIGNAL(SendData(QByteArray)), m_pLanConnection, SLOT(OnSendData(QByteArray)));
    InitializeCommunication();
}

void CRobotComm::InitializeCommunication()
{
    QNetworkProxyFactory::setUseSystemConfiguration(true);
    QNetworkProxy::setApplicationProxy(QNetworkProxy::NoProxy);
    m_pCommThread = new QThread();
    m_pLanConnection->moveToThread(m_pCommThread);
    connect(m_pLanConnection, SIGNAL(destroyed(QObject*)), m_pCommThread, SLOT(quit()));
    connect(m_pCommThread, SIGNAL(finished()), m_pCommThread, SLOT(deleteLater()));
    m_pCommThread->start();
}

void CRobotComm::SetQueueRMessage(QQueue<QByteArray> *queue)
{
    this->m_pQueueReceiveCmd = queue;
}

void CRobotComm::SetSettingData(CSettingData *settingData)
{
    m_pSettingData = settingData;
}

void CRobotComm::OnReceiveData(QByteArray data)
{
//    m_mutexReceive.lock();
    // Add the receive data to queue
    m_pQueueReceiveCmd->push_back(data);
    emit handleReceiveMsg();            // emit to Robot Controller thread
//    m_mutexReceive.unlock();
}

void CRobotComm::OnParserCommand(QByteArray msg)
{
    QString content = msg;
    QString cmdName = content.mid(4, 4);
    int len = content.length();
    qDebug()<< "CRobotComm::OnParserCommand" << msg;
    if(len >= MP_RECEIVE_MIN_SIZE){
        if(MapRobotCmd.find(cmdName) == MapRobotCmd.end()){
            return;
        }
        char    rcsum[4], buff[1000];
        int     rsum, msum;
        strcpy_s( rcsum, content.right(3).toStdString().c_str());
        sscanf_s( rcsum, "%2x", &rsum );

        strcpy_s( buff, content.mid(1, len - 4).toStdString().c_str());
        msum = MakeCheckSum(buff, len - 4);
        if(rsum != msum){

        }
        else {
            int cmdNo = MapRobotCmd[cmdName];
            emit addOperationLog(msg, "App->RB");
            switch (cmdNo) {
            case eRBCmd_INIT:
                this->SendRobotCommand_INIT(msg);
                break;
            case eRBCmd_MTRS:
                this->SendRobotCommand_MTRS(msg);
                break;
            case eRBCmd_MPNT:
                this->SendRobotCommand_MPNT(msg);
                break;
            case eRBCmd_MCTR:
                break;
            case eRBCmd_MTCH:
                break;
            case eRBCmd_MABS:
                break;
            case eRBCmd_MREL:
                break;
            case eRBCmd_MMAP:
                break;
            case eRBCmd_MMCA:
                break;
            case eRBCmd_MALN:
                break;
            case eRBCmd_MACA:
                break;
            case eRBCmd_CSTP:
                break;
            case eRBCmd_CRSM:
                break;
            case eRBCmd_CSRV:
                this->SendRobotCommand_CSRV(msg);
                break;
            case eRBCmd_CCLR:
                this->SendRobotCommand_CCLR(msg);
                break;
            case eRBCmd_CSOL:
                this->SendRobotCommand_CSOL(msg);
                break;
            case eRBCmd_SSPD:
                this->SendRobotCommand_SSPD(msg);
                break;
            case eRBCmd_SSLV:
                break;
            case eRBCmd_SPOS:
                break;
            case eRBCmd_SABS:
                break;
            case eRBCmd_SAPS:
                break;
            case eRBCmd_SPDL:
                break;
            case eRBCmd_SPSV:
                break;
            case eRBCmd_SPLD:
                break;
            case eRBCmd_SSTR:
                break;
            case eRBCmd_SPRM:
                this->SendRobotCommand_SPRM(msg);
                break;
            case eRBCmd_SMSK:
                break;
            case eRBCmd_SSTD:
                break;
            case eRBCmd_SSTN:
                break;
            case eRBCmd_RSPD:
                break;
            case eRBCmd_RSLV:
                break;
            case eRBCmd_RPOS:
                this->SendRobotCommand_RPOS(msg);
                break;
            case eRBCmd_RSTP:
                break;
            case eRBCmd_RSTR:
                break;
            case eRBCmd_RPRM:
                break;
            case eRBCmd_RSTS:
                this->SendRobotCommand_RSTS(/*msg*/);
                break;
            case eRBCmd_RERR:
                break;
            case eRBCmd_RMSK:
                break;
            case eRBCmd_RVER:
                break;
            case eRBCmd_RMAP:
                break;
            case eRBCmd_RMPD:
                break;
            case eRBCmd_RMCA:
                break;
            case eRBCmd_RALN:
                break;
            case eRBCmd_RACA:
                break;
            case eRBCmd_RCCD:
                break;
            case eRBCmd_RLOG:
                break;
            case eRBCmd_RSTN:
                break;
            case eRBCmd_ACKN:
                break;
            default:
                break;
            }
        }
    }
}

void CRobotComm::SendRobotCommand_INIT(QByteArray receiveCommand)
{
    char Terminate[4];
    char ErrClr = receiveCommand.at(9);
    char SrvOn  = receiveCommand.at(11);
    char Home   = receiveCommand.at(13);
    // Send Response message to Top EFEM App
    QByteArray bSendData;
    bSendData.append("$,1,00,0000,INIT,");
    bSendData.append(ErrClr);
    bSendData.append(",");
    bSendData.append(SrvOn);
    bSendData.append(",");
    bSendData.append(Home);
    bSendData.append(",");
    int sum = MakeCheckSum(bSendData);
    sprintf( Terminate, "%02X", sum );
    Terminate[2] = 0x0d;
    Terminate[3] = 0x00;
    bSendData.append(Terminate);
    // Send the response message to EFEM App
    emit addOperationLog(bSendData, "RB->App");
    emit SendData(bSendData);
    // Run Origin function
    // Update the UI

    // sleep
    Sleep(500);
    // Send End of Execution to Top EFEM App
    bSendData.clear();
    bSendData.append("!,1,00,0000,INIT,001000,");
    int sum2 = MakeCheckSum(bSendData);
    sprintf( Terminate, "%02X", sum2 );
    Terminate[2] = 0x0d;
    Terminate[3] = 0x00;
    bSendData.append(Terminate);
    emit addOperationLog(bSendData, "RB->App");
    emit SendData(bSendData);
}

void CRobotComm::SendRobotCommand_MTRS(QByteArray receiveCommand)
{
    char Terminate[4];
    char Mtn        = receiveCommand.at(9);
    QString TrsSt   = receiveCommand.mid(11, 3);
    QString Slot    = receiveCommand.mid(15, 2);
    char Posture    = receiveCommand.at(18);
    char Hand       = receiveCommand.at(20);
    QString TrsPnt  = receiveCommand.mid(22, 2);
    // Send Response message to Top EFEM App
    QByteArray bSendData;
    bSendData.append("$,1,00,0000,MTRS,");
    bSendData.append(Mtn);
    bSendData.append(",");
    bSendData.append(TrsSt);
    bSendData.append(",");
    bSendData.append(Slot);
    bSendData.append(",");
    bSendData.append(Posture);
    bSendData.append(",");
    bSendData.append(Hand);
    bSendData.append(",");
    int sum = MakeCheckSum(bSendData);
    sprintf( Terminate, "%02X", sum );
    Terminate[2] = 0x0d;
    Terminate[3] = 0x00;
    bSendData.append(Terminate);
    // Send the response message to EFEM App
    emit addOperationLog(bSendData, "RB->App");
    emit SendData(bSendData);
    // Run MTRS function
    // Update the UI

    // sleep
    Sleep(500);
    // Send End of Execution to Top EFEM App
    bSendData.clear();
    bSendData.append("!,1,00,0000,MTRS,001000,");
    int sum2 = MakeCheckSum(bSendData);
    sprintf( Terminate, "%02X", sum2 );
    Terminate[2] = 0x0d;
    Terminate[3] = 0x00;
    bSendData.append(Terminate);
    emit addOperationLog(bSendData, "RB->App");
    emit SendData(bSendData);
}

void CRobotComm::SendRobotCommand_MPNT(QByteArray receiveCommand)
{
    char Terminate[4];
    QString TrsSt   = receiveCommand.mid(9, 2);
    // Send Response message to Top EFEM App
    QByteArray bSendData;
    bSendData.append("$,1,00,0000,MPNT,");
    bSendData.append(TrsSt);
    bSendData.append(",");
    int sum = MakeCheckSum(bSendData);
    sprintf( Terminate, "%02X", sum );
    Terminate[2] = 0x0d;
    Terminate[3] = 0x00;
    bSendData.append(Terminate);
    // Send the response message to EFEM App
    emit addOperationLog(bSendData, "RB->App");
    emit SendData(bSendData);
    // Run MPNT function
    // Update the UI

    // sleep
    Sleep(500);
    // Send End of Execution to Top EFEM App
    bSendData.clear();
    bSendData.append("!,1,00,0000,MPNT,001000,");
    int sum2 = MakeCheckSum(bSendData);
    sprintf( Terminate, "%02X", sum2 );
    Terminate[2] = 0x0d;
    Terminate[3] = 0x00;
    bSendData.append(Terminate);
    emit addOperationLog(bSendData, "RB->App");
    emit SendData(bSendData);
}

void CRobotComm::SendRobotCommand_CSRV(QByteArray receiveCommand)
{
    char Terminate[4];
    char Sw   = receiveCommand.at(9);
    // Send Response message to Top EFEM App
    QByteArray bSendData;
    bSendData.append("$,1,00,0000,CSRV,");
    bSendData.append(Sw);
    bSendData.append(",");
    int sum = MakeCheckSum(bSendData);
    sprintf( Terminate, "%02X", sum );
    Terminate[2] = 0x0d;
    Terminate[3] = 0x00;
    bSendData.append(Terminate);
    // Send the response message to EFEM App
    emit addOperationLog(bSendData, "RB->App");
    emit SendData(bSendData);
    // Run CSRV function
    // Update the UI

    // sleep
    Sleep(500);
    // Send End of Execution to Top EFEM App
    bSendData.clear();
    bSendData.append("!,1,00,0000,CSRV,001000,");
    int sum2 = MakeCheckSum(bSendData);
    sprintf( Terminate, "%02X", sum2 );
    Terminate[2] = 0x0d;
    Terminate[3] = 0x00;
    bSendData.append(Terminate);
    emit addOperationLog(bSendData, "RB->App");
    emit SendData(bSendData);
}

void CRobotComm::SendRobotCommand_CCLR(QByteArray receiveCommand)
{
    char Terminate[4];
    char CMode   = receiveCommand.at(9);
    // Send Response message to Top EFEM App
    QByteArray bSendData;
    bSendData.append("$,1,00,0000,CCLR,");
    bSendData.append(CMode);
    bSendData.append(",");
    int sum = MakeCheckSum(bSendData);
    sprintf( Terminate, "%02X", sum );
    Terminate[2] = 0x0d;
    Terminate[3] = 0x00;
    bSendData.append(Terminate);
    // Send the response message to EFEM App
    emit addOperationLog(bSendData, "RB->App");
    emit SendData(bSendData);
    // Run MPNT function
    // Update the UI

    // sleep
    Sleep(500);
    // Send End of Execution to Top EFEM App
    bSendData.clear();
    bSendData.append("!,1,00,0000,CCLR,001000,");
    int sum2 = MakeCheckSum(bSendData);
    sprintf( Terminate, "%02X", sum2 );
    Terminate[2] = 0x0d;
    Terminate[3] = 0x00;
    bSendData.append(Terminate);
    emit addOperationLog(bSendData, "RB->App");
    emit SendData(bSendData);
}

void CRobotComm::SendRobotCommand_CSOL(QByteArray receiveCommand)
{
    char Terminate[4];
    char Sol    = receiveCommand.at(9);
    char Sw     = receiveCommand.at(11);
    char Wait   = receiveCommand.at(13);
    // Send Response message to Top EFEM App
    QByteArray bSendData;
    bSendData.append("$,1,00,0000,CSOL,");
    bSendData.append(Sol);
    bSendData.append(",");
    bSendData.append(Sw);
    bSendData.append(",");
    bSendData.append(Wait);
    bSendData.append(",");
    int sum = MakeCheckSum(bSendData);
    sprintf( Terminate, "%02X", sum );
    Terminate[2] = 0x0d;
    Terminate[3] = 0x00;
    bSendData.append(Terminate);
    // Send the response message to EFEM App
    emit addOperationLog(bSendData, "RB->App");
    emit SendData(bSendData);
    // Run CSOL function
    // Update the UI

    // sleep
    Sleep(500);
    // Send End of Execution to Top EFEM App
    bSendData.clear();
    bSendData.append("!,1,00,0000,CSOL,001000,");
    int sum2 = MakeCheckSum(bSendData);
    sprintf( Terminate, "%02X", sum2 );
    Terminate[2] = 0x0d;
    Terminate[3] = 0x00;
    bSendData.append(Terminate);
    emit addOperationLog(bSendData, "RB->App");
    emit SendData(bSendData);
}

void CRobotComm::SendRobotCommand_RPOS(QByteArray receiveCommand)
{
    char Terminate[4];
    char PType    = receiveCommand.at(9);
    // Send Response message to Top EFEM App
    QByteArray bSendData;
    bSendData.append("$,1,00,0000,RPOS,");
    bSendData.append(PType);
    bSendData.append(",");
    int sum = MakeCheckSum(bSendData);
    sprintf( Terminate, "%02X", sum );
    Terminate[2] = 0x0d;
    Terminate[3] = 0x00;
    bSendData.append(Terminate);
    // Send the response message to EFEM App
    emit addOperationLog(bSendData, "RB->App");
    emit SendData(bSendData);
}

void CRobotComm::SendRobotCommand_SSPD(QByteArray receiveCommand)
{
    char Terminate[4];
    char Level      = receiveCommand.at(9);
    char Type       = receiveCommand.at(11);
    char Axis       = receiveCommand.at(13);
    QString Speed   = receiveCommand.mid(15, 8);
    // Send Response message to Top EFEM App
    QByteArray bSendData;
    bSendData.append("$,1,00,0000,RPOS,");
    bSendData.append(Level);
    bSendData.append(",");
    bSendData.append(Type);
    bSendData.append(",");
    bSendData.append(Axis);
    bSendData.append(",");
    bSendData.append(Speed);
    bSendData.append(",");
    int sum = MakeCheckSum(bSendData);
    sprintf( Terminate, "%02X", sum );
    Terminate[2] = 0x0d;
    Terminate[3] = 0x00;
    bSendData.append(Terminate);
    // Send the response message to EFEM App
    emit addOperationLog(bSendData, "RB->App");
    emit SendData(bSendData);
}

void CRobotComm::SendRobotCommand_SPRM(QByteArray receiveCommand)
{
    char Terminate[4];

    QString Type   = receiveCommand.mid(9, 3);
    QString PrmNo   = receiveCommand.mid(13, 4);
    QString Value   = receiveCommand.mid(18, 12);
    // Send Response message to Top EFEM App
    QByteArray bSendData;
    bSendData.append("$,1,00,0000,SPRM,");
    bSendData.append(Type);
    bSendData.append(",");
    bSendData.append(PrmNo);
    bSendData.append(",");
    bSendData.append(Value);
    bSendData.append(",");
    int sum = MakeCheckSum(bSendData);
    sprintf( Terminate, "%02X", sum );
    Terminate[2] = 0x0d;
    Terminate[3] = 0x00;
    bSendData.append(Terminate);
    // Send the response message to EFEM App
    emit addOperationLog(bSendData, "RB->App");
    emit SendData(bSendData);
}

void CRobotComm::SendRobotCommand_RSTS(/*QByteArray receiveCommand*/)
{
    char Terminate[4];
    static int i = 0;
    // Send Response message to Top EFEM App
    QByteArray bSendData;
    if(i == 0){
        bSendData.append("$,1,00,0000,RSTS,0000,0000");
    }
    else {
        bSendData.append("$,1,00,0000,RSTS,0000,A000");
    }
    bSendData.append(",");
    int sum = MakeCheckSum(bSendData);
    sprintf( Terminate, "%02X", sum );
    Terminate[2] = 0x0d;
    Terminate[3] = 0x00;
    bSendData.append(Terminate);
    // Send the response message to EFEM App
    emit addOperationLog(bSendData, "RB->App");
    emit SendData(bSendData);
    // Run Origin function
    i++;
}

int CRobotComm::MakeCheckSum(char *P, int n)
{
    int	i;
    int	sum = 0;

    for( i = 0 ; i < n ; i++ ){
        sum += P[i];
    }
    sum &= 0xff;

    return sum;
}
int CRobotComm::MakeCheckSum(QByteArray bArray)
{
    int	i;
    int	sum = 0;

    for( i = 1 ; i < bArray.length() ; i++ ){
        sum += bArray[i];
    }
    sum &= 0xff;

    return sum;
}
