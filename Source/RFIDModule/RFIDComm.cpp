#include "RFIDComm.h"

CRFIDComm::CRFIDComm(CLogModel *model, int wfSize, QObject *parent)
    :QObject(parent)
    , m_wfSize(wfSize)
{
    m_pLogModel = model;
}

CRFIDComm::~CRFIDComm()
{

}

void CRFIDComm::SetQueueRMessage(QQueue<QByteArray> *queue)
{
    this->m_pQueueReceiveCmd = queue;
}

void CRFIDComm::SetSettingData(CSettingData *data)
{
    this->m_pSettingData = data;
}

bool CRFIDComm::OpenSerialCom()
{
    bool r = true;
    QString comName;
    QString strBaudRate;
    m_pSerialConnection = new CSerialConnection();
    if(m_wfSize == eWaferSize12inch){
        comName = reverse_mapComName[m_pSettingData->rfidComName()];
        strBaudRate = reverse_mapComName[m_pSettingData->rfidBaudRate()];
    }
    else {
        comName = reverse_mapComName[m_pSettingData->rfid8ComName()];
        strBaudRate = reverse_mapComName[m_pSettingData->rfid8BaudRate()];
    }
    int iBaudRate = strBaudRate.toUInt();
    r = m_pSerialConnection->OpenPortCom(comName, iBaudRate);
    connect(m_pSerialConnection, SIGNAL(RecieveData(QByteArray)), this, SLOT(OnReceiveData(QByteArray)));
    connect(this, SIGNAL(SendData(QByteArray)), m_pSerialConnection, SLOT(OnSendData(QByteArray)));
    return r;
}

void CRFIDComm::OnReceiveData(QByteArray data)
{
    m_pQueueReceiveCmd->push_back(data);
    if(m_wfSize == eWaferSize12inch){
        emit handleRFIDMsg();            // emit to RFID Controller thread
    }
    else {
        emit handleRFIDMsg8();
    }
}

void CRFIDComm::OnParserCommand(QByteArray data)
{
    //    int len = data.size();
    qDebug() << data;
    QString cmdName = "Read RFID Wafer 12 inch";
    emit addOperationLog(cmdName, "App->RFID");

    char 	CommandLine[1000] = {0};
    // Clear command buffer
    memset(CommandLine, 0, sizeof(CommandLine));
    // Make command string
    char Terminate[3] = {0};
    Terminate[0] = 0x0d;
    Terminate[1] = 0x00;

    QString cmd = "S04x0013233343541424344";
    // Build sending command
    for (int i = 0; i < cmd.length(); i++) {
        CommandLine[i] = (char)cmd[i].toLatin1();
    }
    CommandLine[23] = Terminate[0];
    CommandLine[24] = '3';
    CommandLine[25] = '3';
    CommandLine[26] = 'a';
    CommandLine[27] = 'd';

    // Send command to Load port
    QByteArray br = QByteArray(reinterpret_cast<char*>(CommandLine), 28);
    emit addOperationLog(cmd, "RFID->App");
    emit SendData(br);
}

void CRFIDComm::OnParserCommand8(QByteArray data)
{
    //    int len = data.size();
    qDebug() << data;
    QString cmdName = "Read RFID Wafer 8 inch";
    emit addOperationLog(cmdName, "App->RFID");

    char 	CommandLine[1000] = {0};
    // Clear command buffer
    memset(CommandLine, 0, sizeof(CommandLine));
    // Make command string
    char Terminate[3] = {0};
    Terminate[0] = 0x0d;
    Terminate[1] = 0x00;

    QString cmd = "S04x0013233343541424344";
    // Build sending command
    for (int i = 0; i < cmd.length(); i++) {
        CommandLine[i] = (char)cmd[i].toLatin1();
    }
    CommandLine[23] = Terminate[0];
    CommandLine[24] = '3';
    CommandLine[25] = '3';
    CommandLine[26] = 'a';
    CommandLine[27] = 'd';

    // Send command to Load port
    QByteArray br = QByteArray(reinterpret_cast<char*>(CommandLine), 28);
    emit addOperationLog(cmd, "RFID->App");
    emit SendData(br);
}

bool CRFIDComm::RecvChecksumCalculator(QByteArray data, int length)
{
    const char* tempData = data.constData();
    bool result = true;
    int sum = 0;
    QString chkSum;
    for (int i = 1; i < length - 3; i++) {
        sum += (int)tempData[i];
    }
    chkSum.asprintf("%3X", sum);
    chkSum = chkSum.right(2);
    char char1Sum = (char)chkSum.at(0).toLatin1();
    char char2Sum = (char)chkSum.at(1).toLatin1();
    if(char1Sum != tempData[length - 3] || char2Sum != tempData[length - 2])
    {
        result = false;
    }
    return result;
}

bool CRFIDComm::SendChecksumCalculator(QString data, char &CSH, char &CSI)
{
    bool r = true;
    QString chkSum;
    int length = data.length();
    int sum = 0;
    for (int i = 0; i < length; i++) {
        sum += (int)data.at(i).toLatin1();
    }
    chkSum.asprintf("%3X", sum);
    chkSum = chkSum.right(2);
    qDebug() << "Send Sum: " + chkSum;
    CSH = chkSum.at(0).toLatin1();
    CSI = chkSum.at(1).toLatin1();
    return r;
}

//bool CRFIDComm::MakeCommandString(int CmdCode, char *CommandLine, bool retry)
//{
//    return true;
//}
