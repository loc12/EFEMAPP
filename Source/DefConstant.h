#ifndef DEFCONSTANT_H
#define DEFCONSTANT_H

#include <QMap>
#include "enums.h"

#define START_CHAR_1    0x24       // $
#define END_CHAR_1      0x0d
#define START_CHAR_LP   0x01
#define START_END_LP    0x03
#define START_CHAR_RFID 0x53
#define START_END_RFID  0x0d
#define START_END_OCRID 0x0d
#define CONFIG_FILE "/Setting.ini"
#define MAX_WAFER_SLOT  30

#define STR_INI_LANG            "Language(0: EN, 1: JP, 2: CN, 3: KR, 4: VI)"
#define STR_INI_RB_PORTNO       "Robot Port No"
#define STR_INI_ALIGNER_PORTNO  "Aligner Port No"
#define STR_INI_OCR_COMNO       "OCR Com No"
#define STR_INI_OCR_BAUD        "OCR BaudRate"
#define STR_INI_OCR_DATA_SIZE   "OCR Data Size"
#define STR_INI_OCR_PARITY      "OCR Parity"
#define STR_INI_LP_COMNO        "Load Port Com No"
#define STR_INI_LP_BAUD         "Load Port BaudRate"
#define STR_INI_LP_DATA_SIZE    "Load Port Data Size"
#define STR_INI_LP_PARITY       "Load Port Parity"
#define STR_INI_RFID_COMNO      "RFID Com No"
#define STR_INI_RFID_BAUD       "RFID BaudRate"
#define STR_INI_RFID_DATA_SIZE  "RFID Data Size"
#define STR_INI_RFID_PARITY     "RFID Parity"
#define STR_INI_RFID_8_COMNO    "RFID 8 inch Com No"
#define STR_INI_RFID_8_BAUD     "RFID 8 inch BaudRate"
#define STR_INI_RFID_8_DATA_SIZE "RFID 8 inch Data Size"
#define STR_INI_RFID_8_PARITY   "RFID 8 inch Parity"
#define STR_INI_LP_RES_MODE     "Load Port Response Mode (0: ACK, 1: NAK)"
#define STR_INI_LP_TER_MODE     "Load Port Terminate Mode (0: INF, 1: ABS)"
#define STR_INI_EFEM_TYPE       "EFEM Type(0: Top, 1: Bottom)"
#define STR_INI_ALIGNER_TYPE    "Aligner Type(0: Yaskawa Aligner, 1: Other)"

static const QMap<QString, int> mapComName = {
    { "COM1", ENUMS::COM1},
    { "COM2", ENUMS::COM2},
    { "COM3", ENUMS::COM3},
    { "COM4", ENUMS::COM4},
    { "COM5", ENUMS::COM5},
    { "COM6", ENUMS::COM6},
    { "COM7", ENUMS::COM7},
    { "COM8", ENUMS::COM8},
    { "COM9", ENUMS::COM9},
    { "COM10", ENUMS::COM10},
    { "COM11", ENUMS::COM11},
    { "COM12", ENUMS::COM12},
    { "COM13", ENUMS::COM13},
    { "COM14", ENUMS::COM14},
    { "COM15", ENUMS::COM15},
    { "COM16", ENUMS::COM16},
    { "COM17", ENUMS::COM17},
    { "COM18", ENUMS::COM18},
    { "COM19", ENUMS::COM19},
    { "COM20", ENUMS::COM20},
};

static const QMap<int, QString> reverse_mapComName = {
    {ENUMS::COM1, "COM1"},
    {ENUMS::COM2, "COM2"},
    {ENUMS::COM3, "COM3"},
    {ENUMS::COM4, "COM4"},
    {ENUMS::COM5, "COM5"},
    {ENUMS::COM6, "COM6"},
    {ENUMS::COM7, "COM7"},
    {ENUMS::COM8, "COM8"},
    {ENUMS::COM9, "COM9"},
    {ENUMS::COM10, "COM10"},
    {ENUMS::COM11, "COM11"},
    {ENUMS::COM12, "COM12"},
    {ENUMS::COM13, "COM13"},
    {ENUMS::COM14, "COM14"},
    {ENUMS::COM15, "COM15"},
    {ENUMS::COM16, "COM16"},
    {ENUMS::COM17, "COM17"},
    {ENUMS::COM18, "COM18"},
    {ENUMS::COM19, "COM19"},
    {ENUMS::COM20, "COM20"}
};


static const QMap<QString, int> mapBaudRate = {
    { "4800",   ENUMS::BAUD4800 },
    { "9600",   ENUMS::BAUD9600 },
    { "14400",  ENUMS::BAUD14400},
    { "19200",  ENUMS::BAUD19200},
    { "38400",  ENUMS::BAUD38400},
};

static const QMap<int, QString> reverse_mapBaudRate = {
    { ENUMS::BAUD4800 , "4800"   },
    { ENUMS::BAUD9600 , "9600"   },
    { ENUMS::BAUD14400, "14400"  },
    { ENUMS::BAUD19200, "19200"  },
    { ENUMS::BAUD38400, "38400"  },
};

static const QMap<QString, int> mapDataSize = {
    //    { "4",   ENUMS:: },
    //    { "5",   ENUMS:: },
    //    { "6",   ENUMS:: },
    { "7",   ENUMS::DATA_SIZE_7 },
    { "8",   ENUMS::DATA_SIZE_8 },
};

static const QMap<int, QString> reverse_mapDataSize = {
    {ENUMS::DATA_SIZE_7, "7"},
    {ENUMS::DATA_SIZE_8, "8"},
};

static const QMap<QString, int> mapParity = {
    { "None",   ENUMS::PARITY_NONE  },
    { "Yes",    ENUMS::PARITY_YES   },
};

static const QMap<int, QString> reverse_mapParity = {
    { ENUMS::PARITY_NONE,   "None"},
    { ENUMS::PARITY_YES,    "Yes" },
};


// Define the command for Robot
enum RobotCmd {
    eRBCmd_INIT,
    eRBCmd_MTRS,
    eRBCmd_MPNT,
    eRBCmd_MCTR,
    eRBCmd_MTCH,
    eRBCmd_MABS,
    eRBCmd_MREL,
    eRBCmd_MMAP,
    eRBCmd_MMCA,
    eRBCmd_MALN,
    eRBCmd_MACA,
    eRBCmd_CSTP,
    eRBCmd_CRSM,
    eRBCmd_CSRV,
    eRBCmd_CCLR,
    eRBCmd_CSOL,
    eRBCmd_SSPD,
    eRBCmd_SSLV,
    eRBCmd_SPOS,
    eRBCmd_SABS,
    eRBCmd_SAPS,
    eRBCmd_SPDL,
    eRBCmd_SPSV,
    eRBCmd_SPLD,
    eRBCmd_SSTR,
    eRBCmd_SPRM,
    eRBCmd_SMSK,
    eRBCmd_SSTD,
    eRBCmd_SSTN,
    eRBCmd_RSPD,
    eRBCmd_RSLV,
    eRBCmd_RPOS,
    eRBCmd_RSTP,
    eRBCmd_RSTR,
    eRBCmd_RPRM,
    eRBCmd_RSTS,
    eRBCmd_RERR,
    eRBCmd_RMSK,
    eRBCmd_RVER,
    eRBCmd_RMAP,
    eRBCmd_RMPD,
    eRBCmd_RMCA,
    eRBCmd_RALN,
    eRBCmd_RACA,
    eRBCmd_RCCD,
    eRBCmd_RLOG,
    eRBCmd_RSTN,
    eRBCmd_ACKN,
    eRBCmd_CCPS,
    eRBCmd_Max,
};


enum LoadPortCommand {
    Cmd_SET_RESET	 = 1,
    Cmd_SET_INITL,
    Cmd_SET_LPLOD,
    Cmd_SET_BLLOD,
    Cmd_SET_LOLOD,
    Cmd_SET_LPULD,
    Cmd_SET_BLULD,
    Cmd_SET_LOULD,
    Cmd_SET_LPMSW,
    Cmd_SET_BLMSW,
    Cmd_SET_LOMSW,
    Cmd_SET_LPCON,
    Cmd_SET_BLCON,
    Cmd_SET_LOCON,
    Cmd_SET_LPCST,
    Cmd_SET_BLCST,
    Cmd_SET_LOCST,
    Cmd_SET_LON07,
    Cmd_SET_LBL07,
    Cmd_SET_LOF07,
    Cmd_SET_LON08,
    Cmd_SET_LBL08,
    Cmd_SET_LOF08,
    Cmd_SET_LPLD1,
    Cmd_SET_BLLD1,
    Cmd_SET_LOLD1,
    Cmd_SET_LPLD2,
    Cmd_SET_BLLD2,
    Cmd_SET_LOLD2,
    Cmd_SET_LPLD3,
    Cmd_SET_BLLD3,
    Cmd_SET_LOLD3,
    Cmd_SET_LPLD4,
    Cmd_SET_BLLD4,
    Cmd_SET_LOLD4,
    Cmd_SET_LON01,
    Cmd_SET_LBL01,
    Cmd_SET_LOF01,
    Cmd_SET_LON02,
    Cmd_SET_LBL02,
    Cmd_SET_LOF02,
    Cmd_SET_LON03,
    Cmd_SET_LBL03,
    Cmd_SET_LOF03,
    Cmd_SET_LON04,
    Cmd_SET_LBL04,
    Cmd_SET_LOF04,
    Cmd_SET_LON05,
    Cmd_SET_LBL05,
    Cmd_SET_LOF05,
    Cmd_SET_LON06,
    Cmd_SET_LBL06,
    Cmd_SET_LOF06,
    Cmd_SET_LON09,
    Cmd_SET_LBL09,
    Cmd_SET_LOF09,
    Cmd_SET_PARAM,
    Cmd_SET_SAVE1,
    Cmd_SET_CLCNT,

    Cmd_MOD_ONMGV,
    Cmd_MOD_MENTE,
    Cmd_MOD_TEACH,

    Cmd_GET_STATE,
    Cmd_GET_VERSN,
    Cmd_GET_LEDST,
    Cmd_GET_MAPDT,
    Cmd_GET_MAPRD,
    Cmd_GET_WFCNT,
    Cmd_GET_SELOP,
    Cmd_GET_LOGID,
    Cmd_GET_LOGDT,
    Cmd_GET_TOCNT,
    Cmd_GET_TRCNT,

    Cmd_MOV_ORGSH,
    Cmd_MOV_ABORG,
    Cmd_MOV_CLOAD,
    Cmd_MOV_CLDDK,
    Cmd_MOV_CLDYD,
    Cmd_MOV_CLDOP,
    Cmd_MOV_CLDMP,
    Cmd_MOV_CLMPO,
    Cmd_MOV_CULOD,
    Cmd_MOV_CULDK,
    Cmd_MOV_CUDCL,
    Cmd_MOV_CUDNC,
    Cmd_MOV_CULYD,
    Cmd_MOV_CULFC,
    Cmd_MOV_CUDMP,
    Cmd_MOV_CUMDK,
    Cmd_MOV_CUMFC,
    Cmd_MOV_MAPD1,
    Cmd_MOV_MAPD2,
    Cmd_MOV_MAPDO,
    Cmd_MOV_REMAP,

    Cmd_MOV_PODOP,
    Cmd_MOV_PODCL,
    Cmd_MOV_VACON,
    Cmd_MOV_VACOF,
    Cmd_MOV_DOROP,
    Cmd_MOV_DORCL,
    Cmd_MOV_MAPOP,
    Cmd_MOV_MAPCL,
    Cmd_MOV_ZMPUP,
    Cmd_MOV_ZMPDW,
    Cmd_MOV_ZDRUP,
    Cmd_MOV_ZDRDW,
    Cmd_MOV_ZDRMP,
    Cmd_MOV_ZMDMP,
    Cmd_MOV_ZORGN,
    Cmd_MOV_ZMPST,
    Cmd_MOV_ZMPED,
    Cmd_MOV_MSTON,
    Cmd_MOV_MSTOF,
    Cmd_MOV_YWAIT,
    Cmd_MOV_YDOOR,
    Cmd_MOV_DORBK,
    Cmd_MOV_DORFW,

    Cmd_MOV_RETRY,
    Cmd_MOV_STOP_,
    Cmd_MOV_PAUSE,
    Cmd_MOV_ABORT,
    Cmd_MOV_RESUM,

    Cmd_MOV_N2STA,
    Cmd_MOV_N2STP,
    Cmd_MOV_N2OPN,
    Cmd_MOV_N2CLO,
    Cmd_MOV_NZLUP,
    Cmd_MOV_NZLDW,
    Cmd_MOV_N2FPR,
    Cmd_MOV_N2RPR,
    Cmd_MOV_N2OP1,
    Cmd_MOV_N2OP2,
    Cmd_MOV_N2OP3,
    Cmd_MOV_N2CL1,
    Cmd_MOV_N2CL2,
    Cmd_MOV_N2CL3,
    Cmd_MOV_FNZUP,
    Cmd_MOV_FNZDW,
    Cmd_MOV_RDID1,
    Cmd_MOV_RDID2,
    Cmd_MOV_WRID1,
    Cmd_MOV_WRID2,
    Cmd_EVE_MANSW,
    Cmd_EVE_MANOF,
};

enum {
    eWaferSize12inch    = 0,
    eWaferSize8inch     = 1,
    eWaferSizeMax          ,
};

#endif // DEFCONSTANT_H
