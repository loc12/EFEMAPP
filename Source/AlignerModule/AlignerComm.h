#ifndef CALIGNERINTERFACE_H
#define CALIGNERINTERFACE_H

#include <QObject>
#include <QTimer>
#include <QQueue>
#include <QThread>
#include <QMutex>
#include <QDebug>       // TNN-TODO: Need to remove this line
#include "../Common/LanConnection.h"
#include "../Model/LogModel.h"
#include "../Model/SettingData.h"

#define	MP_RECEIVE_MIN_SIZE	10
#define	MP_COMMANDLINE_MAX	1000

class CAlignerComm : public QObject
{
    Q_OBJECT
public:
    CAlignerComm(CLogModel* log, QObject* parent = 0);
    ~CAlignerComm();
    void    InitLanConnection();

    void    InitializeCommunication();
    void    SetQueueRMessage(QQueue<QByteArray> *queue);
    void    SetSettingData(CSettingData* settingData);

public slots:
    // slot handle from CommunicationSocket class
    void    OnReceiveData(QByteArray data);
    void    OnParserCommand(QByteArray data);

private:
    // private variable
    CLanConnection*         m_pLanConnection;
    QThread*                m_pCommThread;
    QTimer                  m_pTimer;
    QQueue<QByteArray>*     m_pQueueReceiveCmd;
    QMutex                  m_mutexReceive;
    bool                    m_bWaitToCommand;
    CLogModel*              m_pLogModel;
    CSettingData*           m_pSettingData;

    // private function
    void    SendAlignerCommand_INIT(QByteArray receiveCommand);
    void    SendAlignerCommand_MTRS(QByteArray receiveCommand);
    void    SendAlignerCommand_MPNT(QByteArray receiveCommand);
    void    SendAlignerCommand_CSRV(QByteArray receiveCommand);
    void    SendAlignerCommand_CCLR(QByteArray receiveCommand);
    void    SendAlignerCommand_CSOL(QByteArray receiveCommand);
    void    SendAlignerCommand_RPOS(QByteArray receiveCommand);
    void    SendAlignerCommand_SSPD(QByteArray receiveCommand);
    void    SendAlignerCommand_RSTS(/*QByteArray receiveCommand*/);
    void    SendAlignerCommand_MALN(QByteArray receiveCommand);
    void    SendAlignerCommand_CCPS(QByteArray receiveCommand);
    int     MakeCheckSum(char* P, int n);
    int     MakeCheckSum(QByteArray bArray);
signals:
    void    handleReceiveMsg();
    void    updateGUI(int type);
    void    sendCommand(int cmdNo, QByteArray data);
    void    SendData(QByteArray data);          // Send Data to via socket
    void    addOperationLog(QString msg, QString dir);

private:
    // private data type
    union MP_COMMAND_PARA {
        struct INIT {
            int UNo;            // 1: Manipulator, 2: Pre-aligner
            int ErrClr;         // 0: No error clear, 1: Error clear
            int SrvOn;          // 0: No Serve ON, 1: Servo ON
            char Home;           // G: All axes, A: Arm axes only, N: No axes move to home position
        }init;
        struct MTRS {
            int UNo;            // 1: Manipulator
            char Mtn;           // G: Get motion, P: Put motion, E: Exchange motion
            char TrsSt[3];      // Transfer station "C01" - "C08", "S01" - "S12", "P01"
            char Slot[2];       // <Cassette stage>: "01" - "30"; <Transfer stage, Pre-aligner stage>: "00"
            char Posture;       // L: Left elbow, R: Right elbow, A: Automatic
            char Hand;          // 1: Blade 1, 2: Blade 2, F: Blade 1 + Blade 2
            char TrsPnt[2];     // Transfer point "G1" - "G8", "P1" - "P8"
        }mtrs;
        struct MPNT {
            int UNo;            // 1: Manipulator
            char TrsPnt[2];     // Transfer point "G1" - "G8", "P1" - "P8", "AL", "ST"
        }mpnt;
        struct MCTR {
            int UNo;            // 1: Manipulator
            char Mtn;           // G: Get motion, P: Put motion, E: Exchange motion
            char TrsSt[3];      // Transfer station "C01" - "C08", "S01" - "S12", "P01"
            char Slot[2];       // <Cassette stage>: "01" - "30"; <Transfer stage, Pre-aligner stage>: "00"
            char Posture;       // L: Left elbow, R: Right elbow, A: Automatic
            char Hand;          // 1: Blade 1, 2: Blade 2, F: Blade 1 + Blade 2
            char TrsPnt[2];     // Transfer point "G1" - "G8", "P1" - "P8"
        }mctr;
        struct MTCH {
            int UNo;            // 1: Manipulator
            char TrsSt[3];      // Transfer station "C01" - "C08", "S01" - "S12", "P01"
            char Slot[2];       // <Cassette stage>: "01" - "30"; <Transfer stage, Pre-aligner stage>: "00"
            char Posture;       // L: Left elbow, R: Right elbow, A: Automatic
            char Hand;          // 1: Blade 1, 2: Blade 2, F: Blade 1 + Blade 2
            char PMode;         // M, R, O, S, B, E
        }mtch;
        struct MABS {
            int UNo;            // 1: Manipulator, 2: Edge grip type pre-aligner
            char Axis;          // S: Rotation axis, A: Extension axis, H: Wrist axis 1, I: Wrist axis 2, Z: Elevation axis
            char Hand;          // 1: Blade 1, 2: Blade 2
            char Mode;          // C: Maintain passive blade posture, H: Passive blade fixed to wafer center
            char Value[8];
        }mabs;
        struct MREL{

        }mrel;
        struct MMAP {

        }mmap;

        struct MMCA {

        }mmca;
        struct MALN {

        }maln;
        struct MACA {

        }maca;
        struct CSTP {

        }cstp;
        struct CRSM {

        }crsm;
        struct CSRV {

        }csrv;
        struct CCLR {
            int UNo;            // 1: Manipulator, 2: Pre-Aligner
            char CMode;         // E: Clears the error status, H: Clears the error history
        }cclr;
        struct CSOL {
            int UNo;            // 1: Manipulator, 2: Pre-Aligner
            char Sol;           // 1: Blade1, 2: Blade2, F: Blade1 + Blade2
            int Sw;             // 0: Wafer release, 1: Wafer hold
            int Wait;           // 0: No wait time, 1: With wait time
        }csol;
        struct SSPD {
            int UNo;            // 1: Manipulator, 2: Pre-Aligner
            int Level;          // 0: Current set speed level, 1: Speed level 1, 2: Level 2, 3: Level 3
            char Type;          // H: No-wafer, 1: with Wafer, L: Low speed, O: Home speed, B: Speed in low-speed-area
            char Axis;          // S: Rotation, A: Extension, H: Wrist1, I: Wrist2, Z: Elevation, R: Linear, G: All axes
            char Speed[8];      //
        }sspd;
        struct SSLV {

        }sslv;
        struct SPOS {

        }spos;
        struct SABS {

        }sabs;
        struct SAPS {

        }saps;
        struct SPDL {

        }spdl;
        struct SPSV {

        }spsv;
        struct SPLD {

        }spld;
        struct SSTR {

        }sstr;
        struct SPRM {

        }sprm;
        struct SMSK {

        }smsk;
        struct SSTD {

        }sstd;
        struct SSTN {

        }sstn;
        struct RSPD {
            int UNo;            // 1: Manipulator, 2: Pre-aligner
            int Level;          // 0: Current, 1: Level 1, 2: Level 2, 3: Level 3
            char Type;          // Speed type: H, M, L, O, B
            char Axis;          // S, A, H, I, Z, R
        }rspd;
        struct RSLV {

        }rslv;
        struct RPOS {
            int UNo;            // 1: Manipulator, 2: Edge grip type pre-aligner
            char PType;         // R: Command position, F: Feedback position
        };
        struct RSTP {

        }rstp;
        struct RSTR {

        }rstr;
        struct RPRM {

        }rprm;
        struct RSTS {
            int UNo;            // 1: Manipulator, 2: Pre-aligner
        }rsts;
        struct RERR {

        }rerr;
        struct RMSK {

        }rmsk;
        struct RVER {

        }rver;
        struct RMAP {

        }rmap;

        struct RMPD {

        }rmpd;
        struct RMCA {

        }rmca;
        struct RALN {

        }raln;
        struct RACA {

        }raca;
        struct RCCD {

        }rccd;
        struct RLOG {

        }rlog;
        struct RSTN {

        }rstn;
        struct ACKN {

        }ackn;
    };
};

#endif // CALIGNERINTERFACE_H
