QT += quick
QT += serialport

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0
RC_ICONS = Resource/Images/Wf.ico

SOURCES += \
    Source/Common/LanConnection.cpp \
    Source/Common/SerialConnection.cpp \
    Source/LoadPortModule/LoadPortComm.cpp \
    Source/RFIDModule/RFIDComm.cpp \
    Source/RobotModule/RobotComm.cpp \
    Source/main.cpp \
    Source/Model/AlignerInfo.cpp \
    Source/Model/LoadPortInfo.cpp \
    Source/Model/LogModel.cpp \
    Source/Model/RobotArmInfo.cpp \
    Source/Model/WfStageInfo.cpp \
    Source/RobotModule/RobotController.cpp \
    Source/WaferSupplySystem.cpp \
    Source/LoadPortModule/LoadPortController.cpp \
    Source/RFIDModule/RFIDController.cpp \
    Source/Model/SettingData.cpp \
    Source/Global.cpp \
    Source/Model/ListSlot.cpp \
    Source/AlignerModule/AlignerComm.cpp \
    Source/AlignerModule/AlignerController.cpp \
    Source/OCRIDModule/OCRIDComm.cpp \
    Source/OCRIDModule/OCRIDController.cpp

RESOURCES += \
    Resource/Qml/qml.qrc \
    Resource/Language/language.qrc \
    Resource/font.qrc \
    Resource/images.qrc


TRANSLATIONS = Resource/Language/SettingLanguage_en.ts \
               Resource/Language/SettingLanguage_jp.ts \
               Resource/Language/SettingLanguage_cn.ts \
               Resource/Language/SettingLanguage_kr.ts \
               Resource/Language/SettingLanguage_vi.ts

# Additional import path used to resolve QML modules in Qt Creator's code model
QML_IMPORT_PATH =

# Additional import path used to resolve QML modules just for Qt Quick Designer
QML_DESIGNER_IMPORT_PATH =

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

HEADERS += \
    Source/Common/LanConnection.h \
    Source/Common/SerialConnection.h \
    Source/DefConstant.h \
    Source/LoadPortModule/LoadPortComm.h \
    Source/Model/AlignerInfo.h \
    Source/Model/LoadPortInfo.h \
    Source/Model/LogModel.h \
    Source/Model/RobotArmInfo.h \
    Source/Model/WfStageInfo.h \
    Source/RFIDModule/RFIDComm.h \
    Source/RobotModule/RobotComm.h \
    Source/RobotModule/RobotController.h \
    Source/Util.h \
    Source/WaferSupplySystem.h \
    Source/LoadPortModule/LoadPortController.h \
    Source/RFIDModule/RFIDController.h \
    Source/Model/SettingData.h \
    Source/enums.h \
    Source/AppTranslator.h \
    Source/Global.h \
    Source/Model/ListSlot.h \
    Source/AlignerModule/AlignerComm.h \
    Source/AlignerModule/AlignerController.h \
    Source/OCRIDModule/OCRIDComm.h \
    Source/OCRIDModule/OCRIDController.h

DISTFILES += \
    Source/Note.txt
