import QtQuick 2.0
import Enum 1.3
import "./Common"

Rectangle {
    id: commandScreen
    color: "#e0e0e0"
    radius: 5

    Text {
        id: txtRobotCommandScreen
        text: qsTr("Setting default command for Robot:") + appTrans.emptyString
        font.bold: true
        anchors.left: parent.left
        anchors.leftMargin: 14
        anchors.top: parent.top
        anchors.topMargin: 8
        font.pixelSize: 14
    }

    GroupBoxCustom {
        id: grSettingResponseMsg
        x: 14
        y: 29
        width: 553
        height: 70
        textSize: 14
        groupName: qsTr("Setting default for Response Message") + appTrans.emptyString
        Text {
            id: labelResStatus
            x: 8
            y: 39
            width: 106
            height: 15
            text: qsTr("Response Status:") + appTrans.emptyString
            font.pixelSize: 14
        }
        TextEdit {
            id: txtResStatus
            x: 120
            y: 37
            width: 85
            height: 26
            maxLenght: 2
            content: "00"
            isReadOnly: true
        }

        TextEdit {
            id: txtResAckcd
            x: 438
            y: 37
            width: 85
            height: 26
            maxLenght: 4
            isReadOnly: true
            content: "0000"
        }

        Text {
            id: labelResCode
            x: 336
            y: 39
            width: 98
            height: 15
            text: qsTr("Response Code:") + appTrans.emptyString
            font.pixelSize: 14
        }
    }

    GroupBoxCustom {
        id: grSettingTerminateMsg
        x: 14
        y: 113
        width: 553
        height: 116
        groupName: qsTr("Setting default for End of Execution Message") + appTrans.emptyString
        Text {
            id: labelTerStatus
            x: 8
            y: 39
            width: 106
            height: 15
            text: qsTr("Terminate Status:") + appTrans.emptyString
            font.pixelSize: 14
        }

        TextEdit {
            id: txtTerStatus
            x: 120
            y: 37
            width: 85
            height: 26
            isReadOnly: true
            maxLenght: 2
            content: "00"
        }

        TextEdit {
            id: txtTerAckcd
            x: 438
            y: 37
            width: 85
            height: 26
            isReadOnly: true
            maxLenght: 4
            content: "0000"
        }

        Text {
            id: labelTerCode
            x: 336
            y: 39
            width: 98
            height: 15
            text: qsTr("Error Code:") + appTrans.emptyString
            font.pixelSize: 14
        }

        Text {
            id: labelExecutionTime
            x: 8
            y: 82
            width: 106
            height: 15
            text: qsTr("Execution Time:") + appTrans.emptyString
            font.pixelSize: 14
        }

        TextEdit {
            id: txtTerStatus1
            x: 120
            y: 76
            width: 85
            height: 26
            isReadOnly: true
            maxLenght: 6
            content: "001000"
        }
        textSize: 14
    }
}
