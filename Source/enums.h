#ifndef ENUMS_H
#define ENUMS_H

#include <QObject>
#include <QMap>

class ENUMS : public QObject
{
    Q_OBJECT
    Q_ENUMS(E_LANGUAGE)
    Q_ENUMS(E_COM_NO)
    Q_ENUMS(E_COM_BAUD)
    Q_ENUMS(E_COM_SIZE)
    Q_ENUMS(E_COM_PARITY)
    Q_ENUMS(E_LP_RES_TYPE)
    Q_ENUMS(E_LP_TER_TYPE)
    Q_ENUMS(E_SLOT_STS)
    Q_ENUMS(E_ALIGNER_TYPE)
    Q_ENUMS(E_EFEM_TYPE)
public:
    enum E_LANGUAGE
    {
        EN = 0,
        JP = 1,
        CN = 2,
        KR = 3,
        VI = 4,
        LANG_MAX,
    };
    enum E_SLOT_STS
    {
        SLOT_HAS_WAFER  = 0,
        SLOT_NO_WAFER   = 1,
    };
    enum E_COM_NO
    {
        COM1 = 0,
        COM2,
        COM3,
        COM4,
        COM5,
        COM6,
        COM7,
        COM8,
        COM9,
        COM10,
        COM11,
        COM12,
        COM13,
        COM14,
        COM15,
        COM16,
        COM17,
        COM18,
        COM19,
        COM20,
        COM_MAX
    };
    enum E_COM_BAUD
    {
        BAUD4800 = 0,
        BAUD9600,
        BAUD14400,
        BAUD19200,
        BAUD38400,
        BAUD_MAX,
    };
    enum E_COM_SIZE
    {
        DATA_SIZE_7 = 0,
        DATA_SIZE_8,
        DATA_SIZE_MAX,
    };
    enum E_COM_PARITY
    {
        PARITY_NONE = 0,
        PARITY_YES,
        PARITY_MAX,
    };
    enum E_LP_RES_TYPE
    {
        LP_RES_ACK = 0,
        LP_RES_NAK = 1,
        LP_RES_MAX,
    };
    enum E_LP_TER_TYPE
    {
        LP_TER_INF = 0,
        LP_TER_ABS = 1,
        LP_TER_MAX,
    };
    enum E_ALIGNER_TYPE
    {
        ALIGNER_YASKAWA,
        ALIGNER_SM,
    };
    enum E_EFEM_TYPE
    {
        TOP_TYPE,
        BOTTOM_TYPE,
    };
};
//Q_DECLARE_METATYPE(ENUMS::E_LANGUAGE)

#endif // ENUMS_H
