import QtQuick 2.0
import Enum 1.3
import "Common"

Rectangle {
    id: chgLPStateScreen
    height: 543
    color: "#e0e0e0"
    radius: 5
    objectName: "chgLPStateScreen"
    signal closeSettingLPState()

    Text {
        id: txtLPCommandScreen
        text: qsTr("Setting for Load Port State:")
        font.bold: true
        anchors.left: parent.left
        anchors.leftMargin: 14
        anchors.top: parent.top
        anchors.topMargin: 8
        font.pixelSize: 14
    }

    GroupBoxCustom {
        id: gbEQStatus
        x: 14
        y: 31
        width: 198
        height: 72
        groupName: "EQ Status"

        RadioButtonCustom {
            id: rdEQStateNoErr
            x: 15
            y: 42
            nameRadio: "No Err"
        }

        RadioButtonCustom {
            id: rdEQStateErrRetryOK
            x: 76
            y: 42
            nameRadio: "Err(Retry OK)"
        }

        RadioButtonCustom {
            id: rdEQStateErrRetryNG
            x: 151
            y: 42
            nameRadio: "Err(Retry NG)"
        }
    }

    GroupBoxCustom {
        id: gbMode
        x: 219
        y: 31
        width: 198
        height: 72
        RadioButtonCustom {
            id: rdModeHost
            x: 15
            y: 42
            nameRadio: "Host"
        }

        RadioButtonCustom {
            id: rdModeManual
            x: 74
            y: 42
            nameRadio: "Manual"
        }
        groupName: "Mode"
    }

    GroupBoxCustom {
        id: gbIniPosShift
        x: 423
        y: 31
        width: 198
        height: 72
        RadioButtonCustom {
            id: rdIniPosShiftNotExe
            x: 15
            y: 42
            nameRadio: "Not exe"
        }

        RadioButtonCustom {
            id: rdIniPosShiftExe
            x: 74
            y: 42
            nameRadio: "Executed"
        }
        groupName: "Ini Pos Shift"
    }

    GroupBoxCustom {
        id: gbOpeStatus
        x: 14
        y: 109
        width: 198
        height: 72
        RadioButtonCustom {
            id: rdOpeStsStopped
            x: 15
            y: 42
            nameRadio: "Stopped"
        }

        RadioButtonCustom {
            id: rdOpeStsBusy
            x: 78
            y: 42
            nameRadio: "Busy"
        }
        groupName: "Ope Status"
    }

    GroupBoxCustom {
        id: gbErrorCode
        x: 219
        y: 109
        width: 198
        height: 72
        groupName: "Error Code"

        CellText {
            id: cellText
            x: 14
            y: 31
            width: 45
            height: 25
            content: "Upper"
            isReadOnly: true
        }

        TextEdit {
            id: txtErrCodeUpper
            x: 59
            y: 31
            width: 22
            height: 26
            content: "0"
            isReadOnly: false
            maxLenght: 1
        }

        CellText {
            id: cellText2
            x: 123
            y: 31
            width: 45
            height: 25
            content: "Lower"
            isReadOnly: true
        }
        TextEdit {
            id: txtRBPortNo
            x: 168
            y: 31
            width: 22
            height: 26
            content: "0"
            isReadOnly: false
            maxLenght: 1
        }
    }
    Button1State {
        id: btnClose
        x: 552
        y: 504
        width: 80
        height: 31
        color: "#009dff"
        radius: 3
        nameButton: qsTr("Close")
        border.color: "#009dff"
        onClick: {
            closeSettingLPState()
        }
    }
}

/*##^##
Designer {
    D{i:1;anchors_x:14;anchors_y:8}
}
##^##*/
