#include "LoadPortComm.h"

typedef std::map<QString, int> MAPCMD;
typedef std::map<int, QString> MAPCMDNAME;
MAPCMD MapLoadPortCmd = {
    {"SET:RESET", Cmd_SET_RESET},
    {"SET:INITL", Cmd_SET_INITL},
    {"SET:LPLOD", Cmd_SET_LPLOD},
    {"SET:BLLOD", Cmd_SET_BLLOD},
    {"SET:LOLOD", Cmd_SET_LOLOD},
    {"SET:LPULD", Cmd_SET_LPULD},
    {"SET:BLULD", Cmd_SET_BLULD},
    {"SET:LOULD", Cmd_SET_LOULD},
    {"SET:LPMSW", Cmd_SET_LPMSW},
    {"SET:BLMSW", Cmd_SET_BLMSW},
    {"SET:LOMSW", Cmd_SET_LOMSW},
    {"SET:LPCON", Cmd_SET_LPCON},
    {"SET:BLCON", Cmd_SET_BLCON},
    {"SET:LOCON", Cmd_SET_LOCON},
    {"SET:LPCST", Cmd_SET_LPCST},
    {"SET:BLCST", Cmd_SET_BLCST},
    {"SET:LOCST", Cmd_SET_LOCST},
    {"SET:LON07", Cmd_SET_LON07},
    {"SET:LBL07", Cmd_SET_LBL07},
    {"SET:LOF07", Cmd_SET_LOF07},
    {"SET:LON08", Cmd_SET_LON08},
    {"SET:LBL08", Cmd_SET_LBL08},
    {"SET:LOF08", Cmd_SET_LOF08},
    {"SET:LPLD1", Cmd_SET_LPLD1},
    {"SET:BLLD1", Cmd_SET_BLLD1},
    {"SET:LOLD1", Cmd_SET_LOLD1},
    {"SET:LPLD2", Cmd_SET_LPLD2},
    {"SET:BLLD2", Cmd_SET_BLLD2},
    {"SET:LOLD2", Cmd_SET_LOLD2},
    {"SET:LPLD3", Cmd_SET_LPLD3},
    {"SET:BLLD3", Cmd_SET_BLLD3},
    {"SET:LOLD3", Cmd_SET_LOLD3},
    {"SET:LPLD4", Cmd_SET_LPLD4},
    {"SET:BLLD4", Cmd_SET_BLLD4},
    {"SET:LOLD4", Cmd_SET_LOLD4},
    {"SET:LON01", Cmd_SET_LON01},
    {"SET:LBL01", Cmd_SET_LBL01},
    {"SET:LOF01", Cmd_SET_LOF01},
    {"SET:LON02", Cmd_SET_LON02},
    {"SET:LBL02", Cmd_SET_LBL02},
    {"SET:LOF02", Cmd_SET_LOF02},
    {"SET:LON03", Cmd_SET_LON03},
    {"SET:LBL03", Cmd_SET_LBL03},
    {"SET:LOF03", Cmd_SET_LOF03},
    {"SET:LON04", Cmd_SET_LON04},
    {"SET:LBL04", Cmd_SET_LBL04},
    {"SET:LOF04", Cmd_SET_LOF04},
    {"SET:LON05", Cmd_SET_LON05},
    {"SET:LBL05", Cmd_SET_LBL05},
    {"SET:LOF05", Cmd_SET_LOF05},
    {"SET:LON06", Cmd_SET_LON06},
    {"SET:LBL06", Cmd_SET_LBL06},
    {"SET:LOF06", Cmd_SET_LOF06},
    {"SET:LON09", Cmd_SET_LON09},
    {"SET:LBL09", Cmd_SET_LBL09},
    {"SET:LOF09", Cmd_SET_LOF09},
    {"SET:PARAM", Cmd_SET_PARAM},
    {"SET:SAVE1", Cmd_SET_SAVE1},
    {"SET:CLCNT", Cmd_SET_CLCNT},
    {"MOD:ONMGV", Cmd_MOD_ONMGV},
    {"MOD:MENTE", Cmd_MOD_MENTE},
    {"MOD:TEACH", Cmd_MOD_TEACH},
    {"GET:STATE", Cmd_GET_STATE},
    {"GET:VERSN", Cmd_GET_VERSN},
    {"GET:LEDST", Cmd_GET_LEDST},
    {"GET:MAPDT", Cmd_GET_MAPDT},
    {"GET:MAPRD", Cmd_GET_MAPRD},
    {"GET:WFCNT", Cmd_GET_WFCNT},
    {"GET:SELOP", Cmd_GET_SELOP},
    {"GET:LOGID", Cmd_GET_LOGID},
    {"GET:LOGDT", Cmd_GET_LOGDT},
    {"GET:TOCNT", Cmd_GET_TOCNT},
    {"GET:TRCNT", Cmd_GET_TRCNT},
    {"MOV:ORGSH", Cmd_MOV_ORGSH},
    {"MOV:ABORG", Cmd_MOV_ABORG},
    {"MOV:CLOAD", Cmd_MOV_CLOAD},
    {"MOV:CLDDK", Cmd_MOV_CLDDK},
    {"MOV:CLDYD", Cmd_MOV_CLDYD},
    {"MOV:CLDOP", Cmd_MOV_CLDOP},
    {"MOV:CLDMP", Cmd_MOV_CLDMP},
    {"MOV:CLMPO", Cmd_MOV_CLMPO},
    {"MOV:CULOD", Cmd_MOV_CULOD},
    {"MOV:CULDK", Cmd_MOV_CULDK},
    {"MOV:CUDCL", Cmd_MOV_CUDCL},
    {"MOV:CUDNC", Cmd_MOV_CUDNC},
    {"MOV:CULYD", Cmd_MOV_CULYD},
    {"MOV:CULFC", Cmd_MOV_CULFC},
    {"MOV:CUDMP", Cmd_MOV_CUDMP},
    {"MOV:CUMDK", Cmd_MOV_CUMDK},
    {"MOV:CUMFC", Cmd_MOV_CUMFC},
    {"MOV:MAPD1", Cmd_MOV_MAPD1},
    {"MOV:MAPD2", Cmd_MOV_MAPD2},
    {"MOV:MAPDO", Cmd_MOV_MAPDO},
    {"MOV:REMAP", Cmd_MOV_REMAP},
    {"MOV:PODOP", Cmd_MOV_PODOP},
    {"MOV:PODCL", Cmd_MOV_PODCL},
    {"MOV:VACON", Cmd_MOV_VACON},
    {"MOV:VACOF", Cmd_MOV_VACOF},
    {"MOV:DOROP", Cmd_MOV_DOROP},
    {"MOV:DORCL", Cmd_MOV_DORCL},
    {"MOV:MAPOP", Cmd_MOV_MAPOP},
    {"MOV:MAPCL", Cmd_MOV_MAPCL},
    {"MOV:ZMPUP", Cmd_MOV_ZMPUP},
    {"MOV:ZMPDW", Cmd_MOV_ZMPDW},
    {"MOV:ZDRUP", Cmd_MOV_ZDRUP},
    {"MOV:ZDRDW", Cmd_MOV_ZDRDW},
    {"MOV:ZDRMP", Cmd_MOV_ZDRMP},
    {"MOV:ZMDMP", Cmd_MOV_ZMDMP},
    {"MOV:ZORGN", Cmd_MOV_ZORGN},
    {"MOV:ZMPST", Cmd_MOV_ZMPST},
    {"MOV:ZMPED", Cmd_MOV_ZMPED},
    {"MOV:MSTON", Cmd_MOV_MSTON},
    {"MOV:MSTOF", Cmd_MOV_MSTOF},
    {"MOV:YWAIT", Cmd_MOV_YWAIT},
    {"MOV:YDOOR", Cmd_MOV_YDOOR},
    {"MOV:DORBK", Cmd_MOV_DORBK},
    {"MOV:DORFW", Cmd_MOV_DORFW},
    {"MOV:RETRY", Cmd_MOV_RETRY},
    {"MOV:STOP_", Cmd_MOV_STOP_},
    {"MOV:PAUSE", Cmd_MOV_PAUSE},
    {"MOV:ABORT", Cmd_MOV_ABORT},
    {"MOV:RESUM", Cmd_MOV_RESUM},
    {"MOV:N2STA", Cmd_MOV_N2STA},
    {"MOV:N2STP", Cmd_MOV_N2STP},
    {"MOV:N2OPN", Cmd_MOV_N2OPN},
    {"MOV:N2CLO", Cmd_MOV_N2CLO},
    {"MOV:NZLUP", Cmd_MOV_NZLUP},
    {"MOV:NZLDW", Cmd_MOV_NZLDW},
    {"MOV:N2FPR", Cmd_MOV_N2FPR},
    {"MOV:N2RPR", Cmd_MOV_N2RPR},
    {"MOV:N2OP1", Cmd_MOV_N2OP1},
    {"MOV:N2OP2", Cmd_MOV_N2OP2},
    {"MOV:N2OP3", Cmd_MOV_N2OP3},
    {"MOV:N2CL1", Cmd_MOV_N2CL1},
    {"MOV:N2CL2", Cmd_MOV_N2CL2},
    {"MOV:N2CL3", Cmd_MOV_N2CL3},
    {"MOV:FNZUP", Cmd_MOV_FNZUP},
    {"MOV:FNZDW", Cmd_MOV_FNZDW},
    {"MOV:RDID1", Cmd_MOV_RDID1},
};

MAPCMDNAME MapLPNameCmd = {
    {Cmd_SET_RESET, "RESET"},
    {Cmd_SET_INITL, "INITL"},
    {Cmd_SET_LPLOD, "LPLOD"},
    {Cmd_SET_BLLOD, "BLLOD"},
    {Cmd_SET_LOLOD, "LOLOD"},
    {Cmd_SET_LPULD, "LPULD"},
    {Cmd_SET_BLULD, "BLULD"},
    {Cmd_SET_LOULD, "LOULD"},
    {Cmd_SET_LPMSW, "LPMSW"},
    {Cmd_SET_BLMSW, "BLMSW"},
    {Cmd_SET_LOMSW, "LOMSW"},
    {Cmd_SET_LPCON, "LPCON"},
    {Cmd_SET_BLCON, "BLCON"},
    {Cmd_SET_LOCON, "LOCON"},
    {Cmd_SET_LPCST, "LPCST"},
    {Cmd_SET_BLCST, "BLCST"},
    {Cmd_SET_LOCST, "LOCST"},
    {Cmd_SET_LON07, "LON07"},
    {Cmd_SET_LBL07, "LBL07"},
    {Cmd_SET_LOF07, "LOF07"},
    {Cmd_SET_LON08, "LON08"},
    {Cmd_SET_LBL08, "LBL08"},
    {Cmd_SET_LOF08, "LOF08"},
    {Cmd_SET_LPLD1, "LPLD1"},
    {Cmd_SET_BLLD1, "BLLD1"},
    {Cmd_SET_LOLD1, "LOLD1"},
    {Cmd_SET_LPLD2, "LPLD2"},
    {Cmd_SET_BLLD2, "BLLD2"},
    {Cmd_SET_LOLD2, "LOLD2"},
    {Cmd_SET_LPLD3, "LPLD3"},
    {Cmd_SET_BLLD3, "BLLD3"},
    {Cmd_SET_LOLD3, "LOLD3"},
    {Cmd_SET_LPLD4, "LPLD4"},
    {Cmd_SET_BLLD4, "BLLD4"},
    {Cmd_SET_LOLD4, "LOLD4"},
    {Cmd_SET_LON01, "LON01"},
    {Cmd_SET_LBL01, "LBL01"},
    {Cmd_SET_LOF01, "LOF01"},
    {Cmd_SET_LON02, "LON02"},
    {Cmd_SET_LBL02, "LBL02"},
    {Cmd_SET_LOF02, "LOF02"},
    {Cmd_SET_LON03, "LON03"},
    {Cmd_SET_LBL03, "LBL03"},
    {Cmd_SET_LOF03, "LOF03"},
    {Cmd_SET_LON04, "LON04"},
    {Cmd_SET_LBL04, "LBL04"},
    {Cmd_SET_LOF04, "LOF04"},
    {Cmd_SET_LON05, "LON05"},
    {Cmd_SET_LBL05, "LBL05"},
    {Cmd_SET_LOF05, "LOF05"},
    {Cmd_SET_LON06, "LON06"},
    {Cmd_SET_LBL06, "LBL06"},
    {Cmd_SET_LOF06, "LOF06"},
    {Cmd_SET_LON09, "LON09"},
    {Cmd_SET_LBL09, "LBL09"},
    {Cmd_SET_LOF09, "LOF09"},
    {Cmd_SET_PARAM, "PARAM"},
    {Cmd_SET_SAVE1, "SAVE1"},
    {Cmd_SET_CLCNT, "CLCNT"},
    {Cmd_MOD_ONMGV, "ONMGV"},
    {Cmd_MOD_MENTE, "MENTE"},
    {Cmd_MOD_TEACH, "TEACH"},
    {Cmd_GET_STATE, "STATE"},
    {Cmd_GET_VERSN, "VERSN"},
    {Cmd_GET_LEDST, "LEDST"},
    {Cmd_GET_MAPDT, "MAPDT"},
    {Cmd_GET_MAPRD, "MAPRD"},
    {Cmd_GET_WFCNT, "WFCNT"},
    {Cmd_GET_SELOP, "SELOP"},
    {Cmd_GET_LOGID, "LOGID"},
    {Cmd_GET_LOGDT, "LOGDT"},
    {Cmd_GET_TOCNT, "TOCNT"},
    {Cmd_GET_TRCNT, "TRCNT"},
    {Cmd_MOV_ORGSH, "ORGSH"},
    {Cmd_MOV_ABORG, "ABORG"},
    {Cmd_MOV_CLOAD, "CLOAD"},
    {Cmd_MOV_CLDDK, "CLDDK"},
    {Cmd_MOV_CLDYD, "CLDYD"},
    {Cmd_MOV_CLDOP, "CLDOP"},
    {Cmd_MOV_CLDMP, "CLDMP"},
    {Cmd_MOV_CLMPO, "CLMPO"},
    {Cmd_MOV_CULOD, "CULOD"},
    {Cmd_MOV_CULDK, "CULDK"},
    {Cmd_MOV_CUDCL, "CUDCL"},
    {Cmd_MOV_CUDNC, "CUDNC"},
    {Cmd_MOV_CULYD, "CULYD"},
    {Cmd_MOV_CULFC, "CULFC"},
    {Cmd_MOV_CUDMP, "CUDMP"},
    {Cmd_MOV_CUMDK, "CUMDK"},
    {Cmd_MOV_CUMFC, "CUMFC"},
    {Cmd_MOV_MAPD1, "MAPD1"},
    {Cmd_MOV_MAPD2, "MAPD2"},
    {Cmd_MOV_MAPDO, "MAPDO"},
    {Cmd_MOV_REMAP, "REMAP"},
    {Cmd_MOV_PODOP, "PODOP"},
    {Cmd_MOV_PODCL, "PODCL"},
    {Cmd_MOV_VACON, "VACON"},
    {Cmd_MOV_VACOF, "VACOF"},
    {Cmd_MOV_DOROP, "DOROP"},
    {Cmd_MOV_DORCL, "DORCL"},
    {Cmd_MOV_MAPOP, "MAPOP"},
    {Cmd_MOV_MAPCL, "MAPCL"},
    {Cmd_MOV_ZMPUP, "ZMPUP"},
    {Cmd_MOV_ZMPDW, "ZMPDW"},
    {Cmd_MOV_ZDRUP, "ZDRUP"},
    {Cmd_MOV_ZDRDW, "ZDRDW"},
    {Cmd_MOV_ZDRMP, "ZDRMP"},
    {Cmd_MOV_ZMDMP, "ZMDMP"},
    {Cmd_MOV_ZORGN, "ZORGN"},
    {Cmd_MOV_ZMPST, "ZMPST"},
    {Cmd_MOV_ZMPED, "ZMPED"},
    {Cmd_MOV_MSTON, "MSTON"},
    {Cmd_MOV_MSTOF, "MSTOF"},
    {Cmd_MOV_YWAIT, "YWAIT"},
    {Cmd_MOV_YDOOR, "YDOOR"},
    {Cmd_MOV_DORBK, "DORBK"},
    {Cmd_MOV_DORFW, "DORFW"},
    {Cmd_MOV_RETRY, "RETRY"},
    {Cmd_MOV_STOP_, "STOP_"},
    {Cmd_MOV_PAUSE, "PAUSE"},
    {Cmd_MOV_ABORT, "ABORT"},
    {Cmd_MOV_RESUM, "RESUM"},
    {Cmd_MOV_N2STA, "N2STA"},
    {Cmd_MOV_N2STP, "N2STP"},
    {Cmd_MOV_N2OPN, "N2OPN"},
    {Cmd_MOV_N2CLO, "N2CLO"},
    {Cmd_MOV_NZLUP, "NZLUP"},
    {Cmd_MOV_NZLDW, "NZLDW"},
    {Cmd_MOV_N2FPR, "N2FPR"},
    {Cmd_MOV_N2RPR, "N2RPR"},
    {Cmd_MOV_N2OP1, "N2OP1"},
    {Cmd_MOV_N2OP2, "N2OP2"},
    {Cmd_MOV_N2OP3, "N2OP3"},
    {Cmd_MOV_N2CL1, "N2CL1"},
    {Cmd_MOV_N2CL2, "N2CL2"},
    {Cmd_MOV_N2CL3, "N2CL3"},
    {Cmd_MOV_FNZUP, "FNZUP"},
    {Cmd_MOV_FNZDW, "FNZDW"},
    {Cmd_MOV_RDID1, "RDID1"},
    {Cmd_EVE_MANSW, "MANSW"},
    {Cmd_EVE_MANOF, "MANOF"},
};


CLoadPortComm::CLoadPortComm(CLogModel *model, QObject *parent)
    :QObject(parent)
{
    m_pLogModel = model;
    m_waferSize = 0; // 0: 12 inch, 1: 8 inch
}

CLoadPortComm::~CLoadPortComm()
{

}

void CLoadPortComm::SetQueueRMessage(QQueue<QByteArray> *queue)
{
    this->m_pQueueReceiveCmd = queue;
}

void CLoadPortComm::SetWaferSize(int size)
{
    this->m_waferSize = size;
}

void CLoadPortComm::SetSettingData(CSettingData *data)
{
    this->m_pSettingData = data;
}

bool CLoadPortComm::OpenComPort()
{
    bool r = true;
    m_pSerialConnection = new CSerialConnection();
    QString comName = reverse_mapComName[m_pSettingData->lpComName()];
    QString strBaudRate = reverse_mapComName[m_pSettingData->lpBaudRate()];
    int iBaudRate = strBaudRate.toUInt();
    r = m_pSerialConnection->OpenPortCom(comName, iBaudRate);
    connect(m_pSerialConnection, SIGNAL(RecieveData(QByteArray)), this, SLOT(OnReceiveData(QByteArray)));
    connect(this, SIGNAL(SendData(QByteArray)), m_pSerialConnection, SLOT(OnSendData(QByteArray)));
    return r;
}

void CLoadPortComm::OnReceiveData(QByteArray data)
{
    m_pQueueReceiveCmd->push_back(data);
    emit handleLPMsg();            // emit to Load Port Controller thread
}

void CLoadPortComm::OnParserCommand(QByteArray data)
{
    int len = data.size();
    QString cmdName;
    Char2CommandString(data,cmdName,len);
    qDebug() << "Data:" + cmdName;
    if(MapLoadPortCmd.find(cmdName) == MapLoadPortCmd.end()){
        return;
    }

    emit addOperationLog(cmdName, "App->LP");
    // Checksum calculator
    if (!RecvChecksumCalculator(data, data.size())) {
        qDebug() << "Check SUM NG";
        emit addOperationLog("Check SUM NG", "Error");
        return;
    }
    else {
        qDebug() << "Check SUM OK";
        int cmdNo = MapLoadPortCmd[cmdName];
        switch (cmdNo) {
        case Cmd_SET_RESET:
            this->SendLPCommand_SET_RESET();
            break;
        case Cmd_SET_INITL:
            break;
        case Cmd_SET_LPLOD:
            this->SendLPCommand_SET_LPLOD();
            break;
        case Cmd_SET_BLLOD:
            this->SendLPCommand_SET_BLLOD();
            break;
        case Cmd_SET_LOLOD:
            this->SendLPCommand_SET_LOLOD();
            break;
        case Cmd_SET_LPULD:
            this->SendLPCommand_SET_LPULD();
            break;
        case Cmd_SET_BLULD:
            this->SendLPCommand_SET_BLULD();
            break;
        case Cmd_SET_LOULD:
            this->SendLPCommand_SET_LOULD();
            break;
        case Cmd_SET_LPMSW:
            break;
        case Cmd_SET_BLMSW:
            break;
        case Cmd_SET_LOMSW:
            break;
        case Cmd_SET_LPCON:
            break;
        case Cmd_SET_BLCON:
            break;
        case Cmd_SET_LOCON:
            break;
        case Cmd_SET_LPCST:
            break;
        case Cmd_SET_BLCST:
            break;
        case Cmd_SET_LOCST:
            break;
        case Cmd_SET_LON07:
            break;
        case Cmd_SET_LBL07:
            break;
        case Cmd_SET_LOF07:
            break;
        case Cmd_SET_LON08:
            break;
        case Cmd_SET_LBL08:
            break;
        case Cmd_SET_LOF08:
            break;
        case Cmd_SET_LPLD1:
            break;
        case Cmd_SET_BLLD1:
            break;
        case Cmd_SET_LOLD1:
            break;
        case Cmd_SET_LPLD2:
            break;
        case Cmd_SET_BLLD2:
            break;
        case Cmd_SET_LOLD2:
            break;
        case Cmd_SET_LPLD3:
            break;
        case Cmd_SET_BLLD3:
            break;
        case Cmd_SET_LOLD3:
            break;
        case Cmd_SET_LPLD4:
            break;
        case Cmd_SET_BLLD4:
            break;
        case Cmd_SET_LOLD4:
            break;
        case Cmd_SET_LON01:
            break;
        case Cmd_SET_LBL01:
            break;
        case Cmd_SET_LOF01:
            break;
        case Cmd_SET_LON02:
            break;
        case Cmd_SET_LBL02:
            break;
        case Cmd_SET_LOF02:
            break;
        case Cmd_SET_LON03:
            break;
        case Cmd_SET_LBL03:
            break;
        case Cmd_SET_LOF03:
            break;
        case Cmd_SET_LON04:
            break;
        case Cmd_SET_LBL04:
            break;
        case Cmd_SET_LOF04:
            break;
        case Cmd_SET_LON05:
            break;
        case Cmd_SET_LBL05:
            break;
        case Cmd_SET_LOF05:
            break;
        case Cmd_SET_LON06:
            break;
        case Cmd_SET_LBL06:
            break;
        case Cmd_SET_LOF06:
            break;
        case Cmd_SET_LON09:
            break;
        case Cmd_SET_LBL09:
            break;
        case Cmd_SET_LOF09:
            break;
        case Cmd_SET_PARAM:
            break;
        case Cmd_SET_SAVE1:
            break;
        case Cmd_SET_CLCNT:
            break;
        case Cmd_MOD_ONMGV:
            break;
        case Cmd_MOD_MENTE:
            break;
        case Cmd_MOD_TEACH:
            break;
        case Cmd_GET_STATE:
            this->SendLPCommand_GET_STATE();
            break;
        case Cmd_GET_VERSN:
            this->SendLPCommand_GET_VERSN();
            break;
        case Cmd_GET_LEDST:
            break;
        case Cmd_GET_MAPDT:
            break;
        case Cmd_GET_MAPRD:
            this->SendLPCommand_GET_MAPRD();
            break;
        case Cmd_GET_WFCNT:
            break;
        case Cmd_GET_SELOP:
            break;
        case Cmd_GET_LOGID:
            break;
        case Cmd_GET_LOGDT:
            break;
        case Cmd_GET_TOCNT:
            break;
        case Cmd_GET_TRCNT:
            break;
        case Cmd_MOV_ORGSH:
            break;
        case Cmd_MOV_ABORG:
            this->SendLPCommand_MOV_ABORG();
            break;
        case Cmd_MOV_CLOAD:
            this->SendLPCommand_MOV_CLOAD();
            break;
        case Cmd_MOV_CLDDK:
            break;
        case Cmd_MOV_CLDYD:
            break;
        case Cmd_MOV_CLDOP:
            break;
        case Cmd_MOV_CLDMP:
            this->SendLPCommand_MOV_CLDMP();
            break;
        case Cmd_MOV_CLMPO:
            break;
        case Cmd_MOV_CULOD:
            this->SendLPCommand_MOV_CULOD();
            break;
        case Cmd_MOV_CULDK:
            break;
        case Cmd_MOV_CUDCL:
            break;
        case Cmd_MOV_CUDNC:
            break;
        case Cmd_MOV_CULYD:
            this->SendLPCommand_MOV_CULYD();
            break;
        case Cmd_MOV_CULFC:
            break;
        case Cmd_MOV_CUDMP:
            break;
        case Cmd_MOV_CUMDK:
            break;
        case Cmd_MOV_CUMFC:
            break;
        case Cmd_MOV_MAPD1:
            break;
        case Cmd_MOV_MAPD2:
            break;
        case Cmd_MOV_MAPDO:
            break;
        case Cmd_MOV_REMAP:
            break;
        case Cmd_MOV_PODOP:
            break;
        case Cmd_MOV_PODCL:
            this->SendLPCommand_MOV_PODCL();
            break;
        case Cmd_MOV_VACON:
            break;
        case Cmd_MOV_VACOF:
            break;
        case Cmd_MOV_DOROP:
            break;
        case Cmd_MOV_DORCL:
            break;
        case Cmd_MOV_MAPOP:
            break;
        case Cmd_MOV_MAPCL:
            break;
        case Cmd_MOV_ZMPUP:
            break;
        case Cmd_MOV_ZMPDW:
            break;
        case Cmd_MOV_ZDRUP:
            break;
        case Cmd_MOV_ZDRDW:
            break;
        case Cmd_MOV_ZDRMP:
            break;
        case Cmd_MOV_ZMDMP:
            break;
        case Cmd_MOV_ZORGN:
            break;
        case Cmd_MOV_ZMPST:
            break;
        case Cmd_MOV_ZMPED:
            break;
        case Cmd_MOV_MSTON:
            break;
        case Cmd_MOV_MSTOF:
            break;
        case Cmd_MOV_YWAIT:
            break;
        case Cmd_MOV_YDOOR:
            this->SendLPCommand_MOV_YDOOR();
            break;
        case Cmd_MOV_DORBK:
            break;
        case Cmd_MOV_DORFW:
            break;
        case Cmd_MOV_RETRY:
            break;
        case Cmd_MOV_STOP_:
            break;
        case Cmd_MOV_PAUSE:
            break;
        case Cmd_MOV_ABORT:
            break;
        case Cmd_MOV_RESUM:
            break;
        case Cmd_MOV_N2STA:
            break;
        case Cmd_MOV_N2STP:
            break;
        case Cmd_MOV_N2OPN:
            break;
        case Cmd_MOV_N2CLO:
            break;
        case Cmd_MOV_NZLUP:
            break;
        case Cmd_MOV_NZLDW:
            break;
        case Cmd_MOV_N2FPR:
            break;
        case Cmd_MOV_N2RPR:
            break;
        case Cmd_MOV_N2OP1:
            break;
        case Cmd_MOV_N2OP2:
            break;
        case Cmd_MOV_N2OP3:
            break;
        case Cmd_MOV_N2CL1:
            break;
        case Cmd_MOV_N2CL2:
            break;
        case Cmd_MOV_N2CL3:
            break;
        default:
            break;
        }
    }

}

void CLoadPortComm::OnSendCommand(QByteArray data)
{
    if(data == "MANSW"){
        SendTerminationMessage(Cmd_EVE_MANSW);
    }
    else if(data == "MANOF"){
        SendTerminationMessage(Cmd_EVE_MANOF);
    }
}

bool CLoadPortComm::RecvChecksumCalculator(QByteArray data, int length)
{
    const char* tempData = data.constData();
    bool result = true;
    int sum = 0;
    QString chkSum;
    for (int i = 1; i < length - 3; i++) {
        sum += (int)tempData[i];
    }
    chkSum.asprintf("%3x", sum);
    chkSum = chkSum.right(2);
    char char1Sum = (char)chkSum.at(0).toLatin1();
    char char2Sum = (char)chkSum.at(1).toLatin1();
    if(char1Sum != tempData[length - 3] || char2Sum != tempData[length - 2])
    {
        result = false;
    }
    return result;
}

bool CLoadPortComm::SendChecksumCalculator(QString data, char &CSH, char &CSI)
{
    bool r = true;
    QString chkSum;
    int length = data.length();
    int sum = 0;
    for (int i = 0; i < length; i++) {
        sum += (int)data.at(i).toLatin1();
    }
    sum += 0x0E;
    chkSum.asprintf("%3X", sum);
    chkSum = chkSum.right(2);
    qDebug() << "Send Sum: " + chkSum;
    CSH = chkSum.at(0).toLatin1();
    CSI = chkSum.at(1).toLatin1();
    return r;
}

QString CLoadPortComm::GetCommandString(int CmdCode)
{
    QString cmdName;
    bool retry = false;
    switch(CmdCode) {
    case Cmd_SET_RESET:
        if (!retry) {
            cmdName = "ACK:STATE/A0100110001100000110;";
        } else {
            cmdName = "RST:RESET;";
        }
        break;
    case Cmd_SET_INITL:
        if (!retry) {
            cmdName = "SET:INITL;";
        } else {
            cmdName = "RST:INITL;";
        }
        break;
    case Cmd_SET_LPLOD:
        if (!retry) {
            cmdName = "SET:LPLOD;";
        } else {
            cmdName = "RST:LPLOD;";
        }
        break;
    case Cmd_SET_BLLOD:
        if (!retry) {
            cmdName = "SET:BLLOD;";
        } else {
            cmdName = "RST:BLLOD;";
        }
        break;
    case Cmd_SET_LOLOD:
        if (!retry) {
            cmdName = "SET:LOLOD;";
        } else {
            cmdName = "RST:LOLOD;";
        }
        break;
    case Cmd_SET_LPULD:
        if (!retry) {
            cmdName = "SET:LPULD;";
        } else {
            cmdName = "RST:LPULD;";
        }
        break;
    case Cmd_SET_BLULD:
        if (!retry) {
            cmdName = "SET:BLULD;";
        } else {
            cmdName = "RST:BLULD;";
        }
        break;
    case Cmd_SET_LOULD:
        if (!retry) {
            cmdName = "SET:LOULD;";
        } else {
            cmdName = "RST:LOULD;";
        }
        break;
    case Cmd_SET_LPMSW:
        if (!retry) {
            cmdName = "SET:LPMSW;";
        } else {
            cmdName = "RST:LPMSW;";
        }
        break;
    case Cmd_SET_BLMSW:
        if (!retry) {
            cmdName = "SET:BLMSW;";
        } else {
            cmdName = "RST:BLMSW;";
        }
        break;
    case Cmd_SET_LOMSW:
        if (!retry) {
            cmdName = "SET:LOMSW;";
        } else {
            cmdName = "RST:LOMSW;";
        }
        break;
    case Cmd_SET_LPCON:
        if (!retry) {
            cmdName = "SET:LPCON;";
        } else {
            cmdName = "RST:LPCON;";
        }
        break;
    case Cmd_SET_BLCON:
        if (!retry) {
            cmdName = "SET:BLCON;";
        } else {
            cmdName = "RST:BLCON;";
        }
        break;
    case Cmd_SET_LOCON:
        if (!retry) {
            cmdName = "SET:LOCON;";
        } else {
            cmdName = "RST:LOCON;";
        }
        break;
    case Cmd_SET_LPCST:
        if (!retry) {
            cmdName = "SET:LPCST;";
        } else {
            cmdName = "RST:LPCST;";
        }
        break;
    case Cmd_SET_BLCST:
        if (!retry) {
            cmdName = "SET:BLCST;";
        } else {
            cmdName = "RST:BLCST;";
        }
        break;
    case Cmd_SET_LOCST:
        if (!retry) {
            cmdName = "SET:LOCST;";
        } else {
            cmdName = "RST:LOCST;";
        }
        break;
    case Cmd_SET_LON07:
        if (!retry) {
            cmdName = "SET:LON07;";
        } else {
            cmdName = "RST:LON07;";
        }
        break;
    case Cmd_SET_LBL07:
        if (!retry) {
            cmdName = "SET:LBL07;";
        } else {
            cmdName = "RST:LBL07;";
        }
        break;
    case Cmd_SET_LOF07:
        if (!retry) {
            cmdName = "SET:LOF07;";
        } else {
            cmdName = "RST:LOF07;";
        }
        break;
    case Cmd_SET_LON08:
        if (!retry) {
            cmdName = "SET:LON08;";
        } else {
            cmdName = "RST:LON08;";
        }
        break;
    case Cmd_SET_LBL08:
        if (!retry) {
            cmdName = "SET:LBL08;";
        } else {
            cmdName = "RST:LBL08;";
        }
        break;
    case Cmd_SET_LOF08:
        if (!retry) {
            cmdName = "SET:LOF08;";
        } else {
            cmdName = "RST:LOF08;";
        }
        break;
    case Cmd_SET_LPLD1:
        if (!retry) {
            cmdName = "SET:LPLD1;";
        } else {
            cmdName = "RST:LPLD1;";
        }
        break;
    case Cmd_SET_BLLD1:
        if (!retry) {
            cmdName = "SET:BLLD1;";
        } else {
            cmdName = "RST:BLLD1;";
        }
        break;
    case Cmd_SET_LOLD1:
        if (!retry) {
            cmdName = "SET:LOLD1;";
        } else {
            cmdName = "RST:LOLD1;";
        }
        break;
    case Cmd_SET_LPLD2:
        if (!retry) {
            cmdName = "SET:LPLD2;";
        } else {
            cmdName = "RST:LPLD2;";
        }
        break;
    case Cmd_SET_BLLD2:
        if (!retry) {
            cmdName = "SET:BLLD2;";
        } else {
            cmdName = "RST:BLLD2;";
        }
        break;
    case Cmd_SET_LOLD2:
        if (!retry) {
            cmdName = "SET:LOLD2;";
        } else {
            cmdName = "RST:LOLD2;";
        }
        break;
    case Cmd_SET_LPLD3:
        if (!retry) {
            cmdName = "SET:LPLD3;";
        } else {
            cmdName = "RST:LPLD3;";
        }
        break;
    case Cmd_SET_BLLD3:
        if (!retry) {
            cmdName = "SET:BLLD3;";
        } else {
            cmdName = "RST:BLLD3;";
        }
        break;
    case Cmd_SET_LOLD3:
        if (!retry) {
            cmdName = "SET:LOLD3;";
        } else {
            cmdName = "RST:LOLD3;";
        }
        break;
    case Cmd_SET_LPLD4:
        if (!retry) {
            cmdName = "SET:LPLD4;";
        } else {
            cmdName = "RST:LPLD4;";
        }
        break;
    case Cmd_SET_BLLD4:
        if (!retry) {
            cmdName = "SET:BLLD4;";
        } else {
            cmdName = "RST:BLLD4;";
        }
        break;
    case Cmd_SET_LOLD4:
        if (!retry) {
            cmdName = "SET:LOLD4;";
        } else {
            cmdName = "RST:LOLD4;";
        }
        break;
    case Cmd_SET_SAVE1:
        if (!retry) {
            cmdName = "SET:SAVE1;";
        } else {
            cmdName = "RST:SAVE1;";
        }
        break;
    case Cmd_MOD_ONMGV:
        cmdName = "MOD:ONMGV;";
        break;
    case Cmd_MOD_MENTE:
        cmdName = "MOD:MENTE;";
        break;
    case Cmd_MOD_TEACH:
        cmdName = "MOD:TEACH;";
        break;
    case Cmd_GET_STATE:
        cmdName = "GET:STATE;";
        break;
    case Cmd_GET_VERSN:
        cmdName = "GET:VERSN;";
        break;
    case Cmd_GET_LEDST:
        cmdName = "GET:LEDST;";
        break;
    case Cmd_GET_MAPDT:
        cmdName = "GET:MAPDT;";
        break;
    case Cmd_GET_MAPRD:
        cmdName = "GET:MAPRD;";
        break;
    case Cmd_GET_WFCNT:
        cmdName = "GET:WFCNT;";
        break;
    case Cmd_MOV_ORGSH:
        if (!retry) {
            cmdName = "MOV:ORGSH;";
        } else {
            cmdName = "RMV:ORGSH;";
        }
        break;
    case Cmd_MOV_ABORG:
        if (!retry) {
            cmdName = "MOV:ABORG;";
        } else {
            cmdName = "RMV:ABORG;";
        }
        break;
    case Cmd_MOV_CLOAD:
        if (!retry) {
            cmdName = "MOV:CLOAD;";
        } else {
            cmdName = "RMV:CLOAD;";
        }
        break;
    case Cmd_MOV_CLDDK:
        if (!retry) {
            cmdName = "MOV:CLDDK;";
        } else {
            cmdName = "RMV:CLDDK;";
        }
        break;
    case Cmd_MOV_CLDYD:
        if (!retry) {
            cmdName = "MOV:CLDYD;";
        } else {
            cmdName = "RMV:CLDYD;";
        }
        break;
    case Cmd_MOV_CLDOP:
        if (!retry) {
            cmdName = "MOV:CLDOP;";
        } else {
            cmdName = "RMV:CLDOP;";
        }
        break;
    case Cmd_MOV_CLDMP:
        if (!retry) {
            cmdName = "MOV:CLDMP;";
        } else {
            cmdName = "RMV:CLDMP;";
        }
        break;
    case Cmd_MOV_CLMPO:
        if (!retry) {
            cmdName = "MOV:CLMPO;";
        } else {
            cmdName = "RMV:CLMPO;";
        }
        break;
    case Cmd_MOV_CULOD:
        if (!retry) {
            cmdName = "MOV:CULOD;";
        } else {
            cmdName = "RMV:CULOD;";
        }
        break;
    case Cmd_MOV_CULDK:
        if (!retry) {
            cmdName = "MOV:CULDK;";
        } else {
            cmdName = "RMV:CULDK;";
        }
        break;
    case Cmd_MOV_CUDCL:
        if (!retry) {
            cmdName = "MOV:CUDCL;";
        } else {
            cmdName = "RMV:CUDCL;";
        }
        break;
    case Cmd_MOV_CUDNC:
        if (!retry) {
            cmdName = "MOV:CUDNC;";
        } else {
            cmdName = "RMV:CUDNC;";
        }
        break;
    case Cmd_MOV_CULYD:
        if (!retry) {
            cmdName = "MOV:CULYD;";
        } else {
            cmdName = "RMV:CULYD;";
        }
        break;
    case Cmd_MOV_CULFC:
        if (!retry) {
            cmdName = "MOV:CULFC;";
        } else {
            cmdName = "RMV:CULFC;";
        }
        break;
    case Cmd_MOV_CUDMP:
        if (!retry) {
            cmdName = "MOV:CUDMP;";
        } else {
            cmdName = "RMV:CUDMP;";
        }
        break;
    case Cmd_MOV_CUMDK:
        if (!retry) {
            cmdName = "MOV:CUMDK;";
        } else {
            cmdName = "RMV:CUMDK;";
        }
        break;
    case Cmd_MOV_CUMFC:
        if (!retry) {
            cmdName = "MOV:CUMFC;";
        } else {
            cmdName = "RMV:CUMFC;";
        }
        break;
    case Cmd_MOV_MAPD1:
        if (!retry) {
            cmdName = "MOV:MAPD1;";
        } else {
            cmdName = "RMV:MAPD1;";
        }
        break;
    case Cmd_MOV_MAPD2:
        if (!retry) {
            cmdName = "MOV:MAPD2;";
        } else {
            cmdName = "RMV:MAPD2;";
        }
        break;
    case Cmd_MOV_MAPDO:
        if (!retry) {
            cmdName = "MOV:MAPDO;";
        } else {
            cmdName = "RMV:MAPDO;";
        }
        break;
    case Cmd_MOV_REMAP:
        if (!retry) {
            cmdName = "MOV:REMAP;";
        } else {
            cmdName = "RMV:REMAP;";
        }
        break;
    case Cmd_MOV_PODOP:
        if (!retry) {
            cmdName = "MOV:PODOP;";
        } else {
            cmdName = "RMV:PODOP;";
        }
        break;
    case Cmd_MOV_PODCL:
        if (!retry) {
            cmdName = "MOV:PODCL;";
        } else {
            cmdName = "RMV:PODCL;";
        }
        break;
    case Cmd_MOV_VACON:
        if (!retry) {
            cmdName = "MOV:VACON;";
        } else {
            cmdName = "RMV:VACON;";
        }
        break;
    case Cmd_MOV_VACOF:
        if (!retry) {
            cmdName = "MOV:VACOF;";
        } else {
            cmdName = "RMV:VACOF;";
        }
        break;
    case Cmd_MOV_DOROP:
        if (!retry) {
            cmdName = "MOV:DOROP;";
        } else {
            cmdName = "RMV:DOROP;";
        }
        break;
    case Cmd_MOV_DORCL:
        if (!retry) {
            cmdName = "MOV:DORCL;";
        } else {
            cmdName = "RMV:DORCL;";
        }
        break;
    case Cmd_MOV_MAPOP:
        if (!retry) {
            cmdName = "MOV:MAPOP;";
        } else {
            cmdName = "RMV:MAPOP;";
        }
        break;
    case Cmd_MOV_MAPCL:
        if (!retry) {
            cmdName = "MOV:MAPCL;";
        } else {
            cmdName = "RMV:MAPCL;";
        }
        break;
    case Cmd_MOV_ZMPUP:
        if (!retry) {
            cmdName = "MOV:ZMPUP;";
        } else {
            cmdName = "RMV:ZMPUP;";
        }
        break;
    case Cmd_MOV_ZMPDW:
        if (!retry) {
            cmdName = "MOV:ZMPDW;";
        } else {
            cmdName = "RMV:ZMPDW;";
        }
        break;
    case Cmd_MOV_ZDRUP:
        if (!retry) {
            cmdName = "MOV:ZDRUP;";
        } else {
            cmdName = "RMV:ZDRUP;";
        }
        break;
    case Cmd_MOV_ZDRDW:
        if (!retry) {
            cmdName = "MOV:ZDRDW;";
        } else {
            cmdName = "RMV:ZDRDW;";
        }
        break;
    case Cmd_MOV_ZDRMP:
        if (!retry) {
            cmdName = "MOV:ZDRMP;";
        } else {
            cmdName = "RMV:ZDRMP;";
        }
        break;
    case Cmd_MOV_ZMDMP:
        if (!retry) {
            cmdName = "MOV:ZMDMP;";
        } else {
            cmdName = "RMV:ZMDMP;";
        }
        break;
    case Cmd_MOV_ZORGN:
        if (!retry) {
            cmdName = "MOV:ZORGN;";
        } else {
            cmdName = "RMV:ZORGN;";
        }
        break;
    case Cmd_MOV_ZMPST:
        if (!retry) {
            cmdName = "MOV:ZMPST;";
        } else {
            cmdName = "RMV:ZMPST;";
        }
        break;
    case Cmd_MOV_YWAIT:
        if (!retry) {
            cmdName = "MOV:YWAIT;";
        } else {
            cmdName = "RMV:YWAIT;";
        }
        break;
    case Cmd_MOV_YDOOR:
        if (!retry) {
            cmdName = "MOV:YDOOR;";
        } else {
            cmdName = "RMV:YDOOR;";
        }
        break;
    case Cmd_MOV_DORBK:
        if (!retry) {
            cmdName = "MOV:DORBK;";
        } else {
            cmdName = "RMV:DORBK;";
        }
        break;
    case Cmd_MOV_DORFW:
        if (!retry) {
            cmdName = "MOV:DORFW;";
        } else {
            cmdName = "RMV:DORFW;";
        }
        break;
    case Cmd_MOV_RETRY:
        cmdName = "MOV:RETRY;";
        break;
    case Cmd_MOV_STOP_:
        cmdName = "MOV:STOP_;";
        break;
    case Cmd_MOV_PAUSE:
        cmdName = "MOV:PAUSE;";
        break;
    case Cmd_MOV_ABORT:
        cmdName = "MOV:ABORT;";
        break;
    case Cmd_MOV_RESUM:
        cmdName = "MOV:RESUM;";
        break;
    }
    return cmdName;
}

bool CLoadPortComm::SendResponseMessage(int cmdNo, int typeMsg)
{
    bool r = true;
    int typeResponse = m_pSettingData->lpResponseMode();
    char 	CommandLine[1000] = {0};
    // Clear command buffer
    memset(CommandLine, 0, sizeof(CommandLine));
    // Make command string
    char StartHeader[2] = {0};
    char checksum[3] = {0};
    char length[3] = {0};
    char Address[3] = {0};
    char Terminate[3] = {0};
    StartHeader[0] = 0x01;
    length[0] = 0x00;
    length[1] = 0x0E;	// Send command of TDK-A have length of 14 bytes
    Address[0] = '0';
    Address[1] = '0';
    Terminate[0] = 0x03;
    Terminate[1] = 0x00;

    QString headMessage;
    QString cmdResponse;
    if(typeMsg != eGetMessage){
        headMessage = (typeResponse == ENUMS::LP_RES_ACK) ? "ACK:" : "NAK:";
        cmdResponse = headMessage + MapLPNameCmd[cmdNo] + ";";
    }
    else {
        headMessage = (typeResponse == ENUMS::LP_RES_ACK) ? "ACK:" : "NAK:";
        if(cmdNo == Cmd_GET_VERSN){
            cmdResponse = headMessage + MapLPNameCmd[cmdNo] + "/SDK_VER7-1-4;";
        }
        else if(cmdNo == Cmd_GET_STATE){
            if(m_waferSize == 0){
                cmdResponse = headMessage + MapLPNameCmd[cmdNo] + "/00000010000000011101;";
            }
            else {
                cmdResponse = headMessage + MapLPNameCmd[cmdNo] + "/00000010000000011111;";
            }
        }
        else if(cmdNo == Cmd_GET_MAPRD){
            QString mapInfo = "/";
            for(int i = 0; i < MAX_WAFER_SLOT; i++){
                if(g_listInfo.getSlotSts(i) == ENUMS::SLOT_HAS_WAFER){
                    mapInfo += "1";
                }
                else if (g_listInfo.getSlotSts(i) == ENUMS::SLOT_NO_WAFER){
                    mapInfo += "0";
                }
            }
            mapInfo += ";";
            cmdResponse = headMessage + MapLPNameCmd[cmdNo] + mapInfo;
        }
    }
    // Build sending command
    CommandLine[0] = StartHeader[0];
    CommandLine[1] = length[0];
    CommandLine[2] = length[1];
    CommandLine[3] = Address[0];
    CommandLine[4] = Address[1];
    QString strChecksum;
    strChecksum.append(Address[0]);
    strChecksum.append(Address[1]);
    for (int i = 0; i < cmdResponse.length(); i++) {
        CommandLine[i+5] = (char)cmdResponse[i].toLatin1();
        strChecksum.append((char)cmdResponse[i].toLatin1());
    }
    // Calculate check sum
    SendChecksumCalculator(strChecksum, checksum[0], checksum[1]);
    CommandLine[5 + cmdResponse.length()] = checksum[0];
    CommandLine[6 + cmdResponse.length()] = checksum[1];
    CommandLine[7 + cmdResponse.length()] = Terminate[0];

    // Send command to Load port
    QByteArray br = QByteArray(reinterpret_cast<char*>(CommandLine), 7+ cmdResponse.length()+1);
    emit addOperationLog(cmdResponse, "LP->App");
    emit SendData(br);
    return r;
}

bool CLoadPortComm::SendTerminationMessage(int cmd)
{
    bool r = true;
    int type = m_pSettingData->lpTerminateMode();
    char 	CommandLine[1000] = {0};
    // Clear command buffer
    memset(CommandLine, 0, sizeof(CommandLine));
    // Make command string
    char StartHeader[2] = {0};
    char checksum[3] = {'6', '6', '6'};
    char length[3] = {0};
    char Address[3] = {0};
    char Terminate[3] = {0};
    StartHeader[0] = 0x01;
    length[0] = 0x00;
    length[1] = 0x0E;	// Send command of TDK-A have length of 14 bytes
    Address[0] = '0';
    Address[1] = '0';
    Terminate[0] = 0x03;
    Terminate[1] = 0x00;

    QString headMessage = (type == ENUMS::LP_TER_INF) ? "INF:" : "ABS:";
    QString cmdResponse = headMessage + MapLPNameCmd[cmd] + ";";

    // Build sending command
    CommandLine[0] = StartHeader[0];
    CommandLine[1] = length[0];
    CommandLine[2] = length[1];
    CommandLine[3] = Address[0];
    CommandLine[4] = Address[1];
    QString strChecksum;
    strChecksum.append(Address[0]);
    strChecksum.append(Address[1]);
    for (int i = 0; i < cmdResponse.length(); i++) {
        CommandLine[i+5] = (char)cmdResponse[i].toLatin1();
        strChecksum.append((char)cmdResponse[i].toLatin1());
    }
    // Calculate check sum
    SendChecksumCalculator(strChecksum, checksum[0], checksum[1]);
    CommandLine[5 + cmdResponse.length()]   = checksum[0];
    CommandLine[6+ cmdResponse.length()]    = checksum[1];
    CommandLine[7+ cmdResponse.length()]    = Terminate[0];

    // Send command to Load port
    QByteArray br = QByteArray(reinterpret_cast<char*>(CommandLine), 7+ cmdResponse.length()+1);
    emit addOperationLog(cmdResponse, "LP->App");
    emit SendData(br);
    return r;
}

bool CLoadPortComm::SendLPCommand_SET_RESET()
{
    bool 	ret = true;
    SendResponseMessage(Cmd_SET_RESET, eSetMessage);
    SendTerminationMessage(Cmd_SET_RESET);
    return ret;
}

bool CLoadPortComm::SendLPCommand_SET_BLLOD()
{
    bool 	ret = true;
    SendResponseMessage(Cmd_SET_BLLOD, eSetMessage);
    SendTerminationMessage(Cmd_SET_BLLOD);
    return ret;
}

bool CLoadPortComm::SendLPCommand_SET_BLULD()
{
    bool 	ret = true;
    SendResponseMessage(Cmd_SET_BLULD, eSetMessage);
    SendTerminationMessage(Cmd_SET_BLULD);
    return ret;
}

bool CLoadPortComm::SendLPCommand_SET_LPULD()
{
    bool 	ret = true;
    SendResponseMessage(Cmd_SET_LPULD, eSetMessage);
    SendTerminationMessage(Cmd_SET_LPULD);
    return ret;
}

bool CLoadPortComm::SendLPCommand_SET_LOLOD()
{
    bool 	ret = true;
    SendResponseMessage(Cmd_SET_LOLOD, eSetMessage);
    SendTerminationMessage(Cmd_SET_LOLOD);
    return ret;
}

bool CLoadPortComm::SendLPCommand_SET_LPLOD()
{
    bool 	ret = true;
    SendResponseMessage(Cmd_SET_LPLOD, eSetMessage);
    SendTerminationMessage(Cmd_SET_LPLOD);
    return ret;
}

bool CLoadPortComm::SendLPCommand_SET_LOULD()
{
    bool 	ret = true;
    SendResponseMessage(Cmd_SET_LOULD, eSetMessage);
    SendTerminationMessage(Cmd_SET_LOULD);
    return ret;
}

bool CLoadPortComm::SendLPCommand_GET_VERSN()
{
    bool 	ret = true;
    SendResponseMessage(Cmd_GET_VERSN, eGetMessage);
    return ret;
}

bool CLoadPortComm::SendLPCommand_GET_STATE()
{
    bool 	ret = true;
    SendResponseMessage(Cmd_GET_STATE, eGetMessage);
    return ret;
}

bool CLoadPortComm::SendLPCommand_GET_MAPRD()
{
    bool 	ret = true;
    SendResponseMessage(Cmd_GET_MAPRD, eGetMessage);
    return ret;
}

bool CLoadPortComm::SendLPCommand_MOV_ABORG()
{
    bool 	ret = true;
    SendResponseMessage(Cmd_MOV_ABORG, eMovMessage);
    SendTerminationMessage(Cmd_MOV_ABORG);
    return ret;
}

bool CLoadPortComm::SendLPCommand_MOV_PODCL()
{
    bool 	ret = true;
    SendResponseMessage(Cmd_MOV_PODCL, eMovMessage);
    SendTerminationMessage(Cmd_MOV_PODCL);
    return ret;
}

bool CLoadPortComm::SendLPCommand_MOV_YDOOR()
{
    bool 	ret = true;
    SendResponseMessage(Cmd_MOV_YDOOR, eMovMessage);
    SendTerminationMessage(Cmd_MOV_YDOOR);
    return ret;
}

bool CLoadPortComm::SendLPCommand_MOV_CULYD()
{
    bool 	ret = true;
    SendResponseMessage(Cmd_MOV_CULYD, eMovMessage);
    SendTerminationMessage(Cmd_MOV_CULYD);
    return ret;
}

bool CLoadPortComm::SendLPCommand_MOV_CLDMP()
{
    bool 	ret = true;
    SendResponseMessage(Cmd_MOV_CLDMP, eMovMessage);
    SendTerminationMessage(Cmd_MOV_CLDMP);
    return ret;
}

bool CLoadPortComm::SendLPCommand_MOV_CULOD()
{
    bool 	ret = true;
    SendResponseMessage(Cmd_MOV_CULOD, eMovMessage);
    SendTerminationMessage(Cmd_MOV_CULOD);
    return ret;
}

bool CLoadPortComm::SendLPCommand_MOV_CLOAD()
{
    bool 	ret = true;
    SendResponseMessage(Cmd_MOV_CLOAD, eMovMessage);
    SendTerminationMessage(Cmd_MOV_CLOAD);
    return ret;
}
