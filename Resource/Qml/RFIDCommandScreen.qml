import QtQuick 2.0
import Enum 1.3
import "./Common"

Rectangle {
    id: commandScreen
    color: "#e0e0e0"
    radius: 5

    Text {
        id: txtRFIDCommandScreen
        text: qsTr("Setting default command for RFID:") + appTrans.emptyString
        font.bold: true
        anchors.left: parent.left
        anchors.leftMargin: 14
        anchors.top: parent.top
        anchors.topMargin: 8
        font.pixelSize: 14
    }

    GroupBoxCustom {
        id: grSettingReadRFID
        x: 14
        y: 39
        width: 553
        height: 70
        groupName: qsTr("Setting default response for Read RFID command") + appTrans.emptyString
        textSize: 14

        TextEdit {
            id: txtRFIDResult
            x: 142
            y: 36
            width: 101
            height: 26
            isReadOnly: true
            maxLenght: 8
            content: "2345ABCD"
        }

        Text {
            id: labelReadRFIDResult
            x: 8
            y: 39
            width: 106
            height: 15
            text: qsTr("Read RFID Result:") + appTrans.emptyString
            font.pixelSize: 14
        }
    }
}
