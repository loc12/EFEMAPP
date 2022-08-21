#include "OCRIDComm.h"

COCRIDComm::COCRIDComm(CLogModel *model, QObject *parent)
    :QObject(parent)
{
    m_pLogModel = model;
}

COCRIDComm::~COCRIDComm()
{

}

void COCRIDComm::SetQueueRMessage(QQueue<QByteArray> *queue)
{
    this->m_pQueueReceiveCmd = queue;
}

void COCRIDComm::SetSettingData(CSettingData *data)
{
    this->m_pSettingData = data;
}

bool COCRIDComm::OpenSerialCom()
{
    bool r = true;
    m_pSerialConnection = new CSerialConnection();
    QString comName = reverse_mapComName[m_pSettingData->ocrComName()];
    QString strBaudRate = reverse_mapComName[m_pSettingData->ocrBaudRate()];
    int iBaudRate = strBaudRate.toUInt();
    r = m_pSerialConnection->OpenPortCom(comName, iBaudRate);
    connect(m_pSerialConnection, SIGNAL(RecieveData(QByteArray)), this, SLOT(OnReceiveData(QByteArray)));
    connect(this, SIGNAL(SendData(QByteArray)), m_pSerialConnection, SLOT(OnSendData(QByteArray)));
    qDebug() << "COCRIDComm::OpenSerialCom() " << r;
    qDebug() << comName;
    return r;
}

void COCRIDComm::OnReceiveData(QByteArray data)
{
    qDebug() << "COCRIDComm::OnReceiveData()";
    m_pQueueReceiveCmd->push_back(data);
    emit handleOCRIDMsg();            // emit to OCRID Controller thread
}

void COCRIDComm::OnParserCommand(QByteArray data)
{
    //    int len = data.size();
    qDebug() << data;
    QString cmdName = "Read OCRID";
    emit addOperationLog(cmdName, "App->OCR");

    char 	CommandLine[1000] = {0};
    // Clear command buffer
    memset(CommandLine, 0, sizeof(CommandLine));
    // Make command string
    char Terminate[3] = {0};
    Terminate[0] = 0x0d;
    Terminate[1] = 0x00;

    QString cmd = "ABCDEFG,1";
    // Build sending command
    for (int i = 0; i < cmd.length(); i++) {
        CommandLine[i] = (char)cmd[i].toLatin1();
    }
    CommandLine[9] = Terminate[0];
    CommandLine[10] = 1;
    // Send command to Load port
    QByteArray br = QByteArray(reinterpret_cast<char*>(CommandLine), 10);
    emit addOperationLog(cmd, "OCR->App");
    emit SendData(br);
}

bool COCRIDComm::RecvChecksumCalculator(QByteArray data, int length)
{
    const char* tempData = data.constData();
    bool result = true;
    int sum = 0;
    QString chkSum;
    for (int i = 1; i < length - 3; i++) {
        sum += (int)tempData[i];
    }
    chkSum.sprintf("%3X", sum);
    chkSum = chkSum.right(2);
    char char1Sum = (char)chkSum.at(0).toLatin1();
    char char2Sum = (char)chkSum.at(1).toLatin1();
    if(char1Sum != tempData[length - 3] || char2Sum != tempData[length - 2])
    {
        result = false;
    }
    return result;
}

bool COCRIDComm::SendChecksumCalculator(QString data, char &CSH, char &CSI)
{
    bool r = true;
    QString chkSum;
    int length = data.length();
    int sum = 0;
    for (int i = 0; i < length; i++) {
        sum += (int)data.at(i).toLatin1();
    }
    chkSum.sprintf("%3X", sum);
    chkSum = chkSum.right(2);
    qDebug() << "Send Sum: " + chkSum;
    CSH = chkSum.at(0).toLatin1();
    CSI = chkSum.at(1).toLatin1();
    return r;
}

//bool COCRIDComm::MakeCommandString(int CmdCode, char *CommandLine, bool retry)
//{
//    return true;
//}
