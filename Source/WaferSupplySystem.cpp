#include "WaferSupplySystem.h"

CWaferSupplySystem::CWaferSupplySystem(QObject *parent)
    :QObject(parent)
{
    m_pAlignerInfo      = new CAlignerInfo();
    m_pWfStageInfo      = new CWfStageInfo();
    m_pRobotCtrl        = new CRobotController(&m_logModel);
    m_pAlignerCtrl      = new CAlignerController(&m_logModel);
    m_pLPCtrl           = new CLoadPortController(&m_logModel);
    m_pRFIDCtrl         = new CRFIDController(&m_logModel);
    m_pOCRCtrl          = new COCRIDController(&m_logModel);
    for(int i = 0; i < MAX_WAFER_SLOT; i++){
        if(i < 13){
            g_listInfo.addSlot(CSlotInfo(ENUMS::SLOT_HAS_WAFER));
        }
        else {
            g_listInfo.addSlot(CSlotInfo(ENUMS::SLOT_NO_WAFER));
        }
    }

    m_pRobotCtrl->SetSettingData(&m_settingData);
    m_pAlignerCtrl->SetSettingData(&m_settingData);
    m_pLPCtrl->SetSettingData(&m_settingData);
    m_pRFIDCtrl->SetSettingData(&m_settingData);
    m_pOCRCtrl->SetSettingData(&m_settingData);
}

CWaferSupplySystem::~CWaferSupplySystem()
{
    if(m_pAlignerInfo != 0){
        delete m_pAlignerInfo;
        m_pAlignerInfo = 0;
    }
    if(m_pWfStageInfo != 0){
        delete m_pWfStageInfo;
        m_pWfStageInfo = 0;
    }
    if(m_pRobotCtrl != 0){
        delete m_pRobotCtrl;
        m_pRobotCtrl = 0;
    }
    if(m_pAlignerCtrl != 0){
        delete m_pAlignerCtrl;
        m_pAlignerCtrl = 0;
    }
}

void CWaferSupplySystem::OnUpdateUI(/*int type*/)
{
    m_logModel.addLogView("Start Application", "Info", "green");
}

void CWaferSupplySystem::OnUpdateRBLog(QString msg, QString dir)
{
    m_logModel.addLogView(msg, dir);
}

void CWaferSupplySystem::OnUpdateAlignerLog(QString msg, QString dir)
{
    m_logModel.addLogView(msg, dir);
}

void CWaferSupplySystem::OnUpdateLPLog(QString msg, QString dir)
{
    m_logModel.addLogView(msg, dir);
}

void CWaferSupplySystem::OnUpdateRFIDLog(QString msg, QString dir)
{
    m_logModel.addLogView(msg, dir);
}

void CWaferSupplySystem::OnUpdateOCRIDLog(QString msg, QString dir)
{
    m_logModel.addLogView(msg, dir);
}

void CWaferSupplySystem::OnChangedScreen()
{
    QObject *settingScreen = m_pEngine->rootObjects().first()->findChild<QObject*>("settingScreen");
    if(settingScreen){
        QObject::connect(settingScreen, SIGNAL(saveSettingData()), this, SLOT(OnSaveSetting()));
    }
    QObject *lpCommandScreen = m_pEngine->rootObjects().first()->findChild<QObject*>("lpCommandScreen");
    if(lpCommandScreen){
        QObject::connect(lpCommandScreen, SIGNAL(sendLPEvent(QString)), this, SLOT(OnSendLPEvent(QString)));

        QObject::connect(lpCommandScreen, SIGNAL(setAllSlotStatus(int)), this, SLOT(OnChangeAllSlotStatus(int)));
        QObject::connect(lpCommandScreen, SIGNAL(setSlotStatus(int, int)), this, SLOT(OnChangeSlotStatus(int, int)));
        QObject::connect(lpCommandScreen, SIGNAL(changeWaferSize(int)), this, SLOT(OnChangeWaferSize(int)));

    }
}

void CWaferSupplySystem::OnSaveSetting()
{
    // Save the current setting to config file
    this->SaveConfigFile();
}

void CWaferSupplySystem::OnSendLPEvent(QString msg)
{
    m_pLPCtrl->AddMessageToQueue(msg);
}

void CWaferSupplySystem::OnChangeWaferSize(int size)
{
    m_pLPCtrl->ChangeWaferSize(size);
}

void CWaferSupplySystem::OnChangeAllSlotStatus(int status)
{
    for(int i = 0; i < MAX_WAFER_SLOT; i++){
        if(status == ENUMS::SLOT_HAS_WAFER || status == ENUMS::SLOT_NO_WAFER){        // Has Wafer
            g_listInfo.changeSlotInfo(i, status);
        }
    }
}

void CWaferSupplySystem::OnChangeSlotStatus(int slotNo, int status)
{
    g_listInfo.changeSlotInfo(slotNo, status);
}

void CWaferSupplySystem::InitApplication()
{
    qmlRegisterUncreatableType<ENUMS>("Enum", 1, 3, "Enum", "");
    m_pContext = m_pEngine->rootContext();

    // Set the model to qml
    m_pContext->setContextProperty("AlignerInfo", m_pAlignerInfo);
    m_pContext->setContextProperty("WfStageInfo", m_pWfStageInfo);
    m_logModel.addLogView("Start Application", "Info", "green");
    m_pContext->setContextProperty("logModel", &m_logModel);
    m_pContext->setContextProperty("listSlot", &g_listInfo);
    m_pContext->setContextProperty("settingData", &m_settingData);

    m_pContext->setContextProperty("cassetteInfo", QVariant::fromValue(m_cassetteInfo));
    //    QObject::connect(m_pRobotCtrl, SIGNAL(updateGUI()), this, SLOT(OnUpdateUI()));
    QObject::connect(m_pRobotCtrl, SIGNAL(updateRBLog(QString, QString)), this, SLOT(OnUpdateRBLog(QString, QString)));
    QObject::connect(m_pAlignerCtrl, SIGNAL(updateAlignerLog(QString, QString)), this, SLOT(OnUpdateAlignerLog(QString, QString)));
    QObject::connect(m_pLPCtrl, SIGNAL(updateLPLog(QString, QString)), this, SLOT(OnUpdateLPLog(QString, QString)));
    QObject::connect(m_pRFIDCtrl, SIGNAL(updateRFIDLog(QString, QString)), this, SLOT(OnUpdateRFIDLog(QString, QString)));
    QObject::connect(m_pOCRCtrl, SIGNAL(updateOCRIDLog(QString, QString)), this, SLOT(OnUpdateOCRIDLog(QString, QString)));


    const QUrl url(QStringLiteral("qrc:/Main.qml"));
    m_pEngine->load(url);
    if(m_pEngine->rootObjects().isEmpty())
        return;
    QObject *rootObject = m_pEngine->rootObjects().first();
    QObject::connect(rootObject, SIGNAL(changedScreen()), this, SLOT(OnChangedScreen()));
}

void CWaferSupplySystem::InitFont()
{
    qint32 fontId = QFontDatabase::addApplicationFont(":/Font/ZenKakuGothicNew-Medium.ttf");
    if(fontId >= 0){
        QStringList fontList = QFontDatabase::applicationFontFamilies(fontId);
        QString family = fontList.at(0);
        QGuiApplication::setFont(QFont(family));
    }
}

void CWaferSupplySystem::SetQmlAppEngine(QQmlApplicationEngine *engine)
{
    this->m_pEngine = engine;
}

void CWaferSupplySystem::ReadConfigFile()
{
    QString projectPath = QCoreApplication::applicationDirPath();
    projectPath += CONFIG_FILE;
    if(QFile(projectPath).exists()){
        QSettings settings(projectPath, QSettings::IniFormat);
        settings.sync();
        settings.beginGroup("Setting");
        // Get value for language
        int language = settings.value(STR_INI_LANG, 0).toInt();
        if(language >= 0 && language < ENUMS::LANG_MAX){
            m_settingData.setLanguage(language);
        }
        // Get value for Robot Port No
        int lanPortNo = settings.value(STR_INI_RB_PORTNO, 0).toInt();
        if(lanPortNo > 0 && lanPortNo < 999999){
            m_settingData.setLanPortNo(lanPortNo);
        }
        // Get value for Aligner Port No
        int alignerPortNo = settings.value(STR_INI_ALIGNER_PORTNO, 0).toInt();
        if(alignerPortNo > 0 && alignerPortNo < 999999){
            m_settingData.setAlignerPortNo(alignerPortNo);
        }

        // Get value for OCR COM Name
        QString strOCRComName = settings.value(STR_INI_OCR_COMNO, "").toString();
        int ocrComName = mapComName[strOCRComName];
        if(ocrComName >= ENUMS::COM1 && ocrComName < ENUMS::COM_MAX){
            m_settingData.setOcrComName(ocrComName);
        }
        // Get value for OCR BaudRate
        QString strOCRBaudRate = settings.value(STR_INI_OCR_BAUD, "").toString();
        int ocrBaudRate = mapBaudRate[strOCRBaudRate];
        if(ocrBaudRate >= ENUMS::BAUD4800 && ocrBaudRate < ENUMS::BAUD_MAX){
            m_settingData.setOcrBaudRate(ocrBaudRate);
        }
        // Get value for OCR Data Size
        QString strOCRDataSize = settings.value(STR_INI_OCR_DATA_SIZE, "").toString();
        int ocrDataSize = mapDataSize[strOCRDataSize];
        if(ocrDataSize >= ENUMS::DATA_SIZE_7 && ocrDataSize < ENUMS::DATA_SIZE_MAX){
            m_settingData.setOcrDataSize(ocrDataSize);
        }
        // Get value for OCR Parity
        QString strOCRParity = settings.value(STR_INI_OCR_PARITY, "").toString();
        int ocrParity = mapParity[strOCRParity];
        if(ocrParity >= ENUMS::PARITY_NONE && ocrParity < ENUMS::PARITY_MAX){
            m_settingData.setOcrParity(ocrParity);
        }

        // Get value for LP COM Name
        QString strLPComName = settings.value(STR_INI_LP_COMNO, "").toString();
        int lpComName = mapComName[strLPComName];
        if(lpComName >= ENUMS::COM1 && lpComName < ENUMS::COM_MAX){
            m_settingData.setLpComName(lpComName);
        }
        // Get value for LP BaudRate
        QString strBaudRate = settings.value(STR_INI_LP_BAUD, "").toString();
        int lpBaudRate = mapBaudRate[strBaudRate];
        if(lpBaudRate >= ENUMS::BAUD4800 && lpBaudRate < ENUMS::BAUD_MAX){
            m_settingData.setLpBaudRate(lpBaudRate);
        }
        // Get value for LP Data Size
        QString strLPDataSize = settings.value(STR_INI_LP_DATA_SIZE, "").toString();
        int lpDataSize = mapDataSize[strLPDataSize];
        if(lpDataSize >= ENUMS::DATA_SIZE_7 && lpDataSize < ENUMS::DATA_SIZE_MAX){
            m_settingData.setLpDataSize(lpDataSize);
        }
        // Get value for LP Parity
        QString strLPParity = settings.value(STR_INI_LP_PARITY, "").toString();
        int lpParity = mapParity[strLPParity];
        if(lpParity >= ENUMS::PARITY_NONE && lpParity < ENUMS::PARITY_MAX){
            m_settingData.setLpParity(lpParity);
        }

        // Get value for RFID COM Name
        QString strRFIDComName = settings.value(STR_INI_RFID_COMNO, "").toString();
        int rfidComName = mapComName[strRFIDComName];
        if(rfidComName >= ENUMS::COM1 && rfidComName < ENUMS::COM_MAX){
            m_settingData.setRfidComName(rfidComName);
        }
        // Get value for RFID BaudRate
        QString strRFIDBaudRate = settings.value(STR_INI_RFID_BAUD, "").toString();
        int rfidBaudRate = mapBaudRate[strRFIDBaudRate];
        if(rfidBaudRate >= ENUMS::BAUD4800 && rfidBaudRate < ENUMS::BAUD_MAX){
            m_settingData.setRfidBaudRate(rfidBaudRate);
        }
        // Get value for RFID Data Size
        QString strRFIDDataSize = settings.value(STR_INI_RFID_DATA_SIZE, "").toString();
        int rfidDataSize = mapDataSize[strRFIDDataSize];
        if(rfidDataSize >= ENUMS::DATA_SIZE_7 && rfidDataSize < ENUMS::DATA_SIZE_MAX){
            m_settingData.setRfidDataSize(rfidDataSize);
        }
        // Get value for RFID Parity
        QString strRFIDParity = settings.value(STR_INI_RFID_PARITY, "").toString();
        int rfidParity = mapParity[strRFIDParity];
        if(rfidParity >= ENUMS::PARITY_NONE && rfidParity < ENUMS::PARITY_MAX){
            m_settingData.setRfidParity(rfidParity);
        }

        // Get value for RFID COM Name
        QString strRFID8ComName = settings.value(STR_INI_RFID_8_COMNO, "").toString();
        int rfid8ComName = mapComName[strRFID8ComName];
        if(rfid8ComName >= ENUMS::COM1 && rfid8ComName < ENUMS::COM_MAX){
            m_settingData.setRfid8ComName(rfid8ComName);
        }
        // Get value for RFID BaudRate
        QString strRFID8BaudRate = settings.value(STR_INI_RFID_8_BAUD, "").toString();
        int rfid8BaudRate = mapBaudRate[strRFID8BaudRate];
        if(rfid8BaudRate >= ENUMS::BAUD4800 && rfid8BaudRate < ENUMS::BAUD_MAX){
            m_settingData.setRfid8BaudRate(rfid8BaudRate);
        }
        // Get value for RFID Data Size
        QString strRFID8DataSize = settings.value(STR_INI_RFID_8_DATA_SIZE, "").toString();
        int rfid8DataSize = mapDataSize[strRFID8DataSize];
        if(rfid8DataSize >= ENUMS::DATA_SIZE_7 && rfid8DataSize < ENUMS::DATA_SIZE_MAX){
            m_settingData.setRfid8DataSize(rfid8DataSize);
        }
        // Get value for RFID Parity
        QString strRFID8Parity = settings.value(STR_INI_RFID_8_PARITY, "").toString();
        int rfid8Parity = mapParity[strRFID8Parity];
        if(rfid8Parity >= ENUMS::PARITY_NONE && rfid8Parity < ENUMS::PARITY_MAX){
            m_settingData.setRfid8Parity(rfid8Parity);
        }

        // Get value for Load Port Response mode (ACK or NAK)
        int lpResponseMode = settings.value(STR_INI_LP_RES_MODE, 0).toInt();
        if(lpResponseMode == ENUMS::LP_RES_ACK || lpResponseMode == ENUMS::LP_RES_NAK){
            m_settingData.setLpResponseMode(lpResponseMode);
        }
        // Get value for Load Port Response mode (ACK or NAK)
        int lpTerminateMode = settings.value(STR_INI_LP_TER_MODE, 0).toInt();
        if(lpTerminateMode == ENUMS::LP_TER_INF || lpTerminateMode == ENUMS::LP_TER_ABS){
            m_settingData.setLpTerminateMode(lpTerminateMode);
        }
        // Get value for EFEM Type (0: Top, 1: Bottom)
        int efemType = settings.value(STR_INI_EFEM_TYPE, 0).toInt();
        if(efemType == ENUMS::TOP_TYPE || efemType == ENUMS::BOTTOM_TYPE){
            m_settingData.setEfemType(efemType);
        }
        // Get value for Load Port Response mode (ACK or NAK)
        int alignerType = settings.value(STR_INI_ALIGNER_TYPE, 0).toInt();
        if(alignerType == ENUMS::ALIGNER_YASKAWA || alignerType == ENUMS::ALIGNER_SM){
            m_settingData.setAlignerType(alignerType);
        }
        settings.endGroup();
    }
}

void CWaferSupplySystem::SaveConfigFile()
{
    QString projectPath = QCoreApplication::applicationDirPath();
    projectPath += CONFIG_FILE;
    if(QFile(projectPath).exists()){
        QSettings settings(projectPath, QSettings::IniFormat);
        settings.sync();
        settings.beginGroup("Setting");
        settings.setValue(STR_INI_LANG,             m_settingData.language());
        settings.setValue(STR_INI_RB_PORTNO,        m_settingData.lanPortNo());
        settings.setValue(STR_INI_ALIGNER_PORTNO,   m_settingData.alignerPortNo());
        settings.setValue(STR_INI_LP_COMNO,         reverse_mapComName[m_settingData.lpComName()]);
        settings.setValue(STR_INI_LP_BAUD,          reverse_mapBaudRate[m_settingData.lpBaudRate()]);
        settings.setValue(STR_INI_LP_DATA_SIZE,     reverse_mapDataSize[m_settingData.lpDataSize()]);
        settings.setValue(STR_INI_LP_PARITY,        reverse_mapParity[m_settingData.lpParity()]);

        settings.setValue(STR_INI_OCR_COMNO,        reverse_mapComName[m_settingData.ocrComName()]);
        settings.setValue(STR_INI_OCR_BAUD,         reverse_mapBaudRate[m_settingData.ocrBaudRate()]);
        settings.setValue(STR_INI_OCR_DATA_SIZE,    reverse_mapDataSize[m_settingData.ocrDataSize()]);
        settings.setValue(STR_INI_OCR_PARITY,       reverse_mapParity[m_settingData.ocrParity()]);

        settings.setValue(STR_INI_RFID_COMNO,           reverse_mapComName[m_settingData.rfidComName()]);
        settings.setValue(STR_INI_RFID_BAUD,            reverse_mapBaudRate[m_settingData.rfidBaudRate()]);
        settings.setValue(STR_INI_RFID_DATA_SIZE,       reverse_mapDataSize[m_settingData.rfidDataSize()]);
        settings.setValue(STR_INI_RFID_PARITY,          reverse_mapParity[m_settingData.rfidParity()]);

        settings.setValue(STR_INI_RFID_8_COMNO,           reverse_mapComName[m_settingData.rfid8ComName()]);
        settings.setValue(STR_INI_RFID_8_BAUD,            reverse_mapBaudRate[m_settingData.rfid8BaudRate()]);
        settings.setValue(STR_INI_RFID_8_DATA_SIZE,       reverse_mapDataSize[m_settingData.rfid8DataSize()]);
        settings.setValue(STR_INI_RFID_8_PARITY,          reverse_mapParity[m_settingData.rfid8Parity()]);

        settings.setValue(STR_INI_LP_RES_MODE,          m_settingData.lpResponseMode());
        settings.setValue(STR_INI_LP_TER_MODE,          m_settingData.lpTerminateMode());
        settings.setValue(STR_INI_EFEM_TYPE,            m_settingData.efemType());
        settings.setValue(STR_INI_ALIGNER_TYPE,         m_settingData.alignerType());
        settings.endGroup();
    }
}

void CWaferSupplySystem::InitConnection()
{
    m_pRobotCtrl->OpenPortServer();
    m_pAlignerCtrl->OpenPortServer();
    m_pLPCtrl->OpenSerialCom();
    m_pRFIDCtrl->OpenSerialCom();
    m_pOCRCtrl->OpenSerialCom();
}

int CWaferSupplySystem::GetSettingLanguage()
{
    return m_settingData.language();
}
