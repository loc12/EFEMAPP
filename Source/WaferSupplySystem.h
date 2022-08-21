#ifndef CWAFERSUPPLYSYSTEM_H
#define CWAFERSUPPLYSYSTEM_H
#include <QObject>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include <QSettings>
#include <QCoreApplication>
#include <QFile>
#include <QMap>
#include <QFontDatabase>
#include <QGuiApplication>
#include "Model/AlignerInfo.h"
#include "Model/WfStageInfo.h"
#include "Model/LogModel.h"
#include "Model/SettingData.h"
#include "Model/ListSlot.h"
#include "RobotModule/RobotController.h"
#include "LoadPortModule/LoadPortController.h"
#include "RFIDModule/RFIDController.h"
#include "OCRIDModule/OCRIDController.h"
#include "AlignerModule/AlignerController.h"
#include "enums.h"
#include "Util.h"
#include "Global.h"

class CWaferSupplySystem : public QObject
{
    Q_OBJECT
public:
    CWaferSupplySystem(QObject* parent = 0);
    ~CWaferSupplySystem();

signals:

public slots:
    void OnUpdateUI(/*int type*/);
    void OnUpdateRBLog(QString msg, QString dir);
    void OnUpdateAlignerLog(QString msg, QString dir);
    void OnUpdateLPLog(QString msg, QString dir);
    void OnUpdateRFIDLog(QString msg, QString dir);
    void OnUpdateOCRIDLog(QString msg, QString dir);
    void OnChangedScreen();
    void OnSaveSetting();
    void OnSendLPEvent(QString msg);
    void OnChangeWaferSize(int size);
    void OnChangeAllSlotStatus(int status);
    void OnChangeSlotStatus(int slotNo, int status);

private:
    QQmlApplicationEngine*  m_pEngine;
    QQmlContext*            m_pContext;
    CAlignerInfo*           m_pAlignerInfo;
    CWfStageInfo*           m_pWfStageInfo;
    CRobotController*       m_pRobotCtrl;
    CAlignerController*     m_pAlignerCtrl;
    CLoadPortController*    m_pLPCtrl;
    CRFIDController*        m_pRFIDCtrl;
    COCRIDController*       m_pOCRCtrl;
    CLogModel               m_logModel;
    CSettingData            m_settingData;
    QList<QObject*>         m_cassetteInfo;
public:
    void    InitApplication();
    void    InitFont();
    void    SetQmlAppEngine(QQmlApplicationEngine* engine);
    void    ReadConfigFile();
    void    SaveConfigFile();
    void    InitConnection();
    int     GetSettingLanguage();
};

#endif // CWAFERSUPPLYSYSTEM_H
