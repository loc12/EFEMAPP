import QtQuick 2.0

Item {
    id: header
    width: 450
    height: 24
    property int sttWidth: stt.width
    property int timeWidth: time.width
    property int dirWidth: dir.width
    property int contentWidth: content.width

    Rectangle {
        id: stt
        x: 0
        y: 0
        width: 30
        height: parent.height
        color: "#e0e0e0"
        border.color: "#909090"
    }

    Rectangle {
        id: time
        y: 0
        width: 115
        height: parent.height
        color: "#e0e0e0"
        anchors.left: stt.right
        anchors.leftMargin: -1
        anchors.verticalCenter: parent.verticalCenter
        border.color: "#909090"

        Text {
            id: txtTime
            y: 5
            text: qsTr("Time") + appTrans.emptyString
            anchors.left: parent.left
            anchors.leftMargin: 8
            anchors.verticalCenter: parent.verticalCenter
            font.pixelSize: 14
            font.bold: true
        }
    }

    Rectangle {
        id: dir
        y: 5
        width: 65
        height: parent.height
        color: "#e0e0e0"
        anchors.left: time.right
        anchors.leftMargin: -1
        anchors.verticalCenterOffset: 0
        anchors.verticalCenter: parent.verticalCenter
        Text {
            id: txtDir
            y: 5
            text: qsTr("Dir") + appTrans.emptyString
            anchors.leftMargin: 8
            anchors.verticalCenter: parent.verticalCenter
            anchors.left: parent.left
            font.pixelSize: 14
            font.bold: true
        }
        border.color: "#909090"
    }

    Rectangle {
        id: content
        x: 5
        y: 9
        width: parent.width - stt.width - time.width - dir.width
        height: parent.height
        color: "#e0e0e0"
        anchors.left: dir.right
        anchors.leftMargin: -1
        anchors.verticalCenter: parent.verticalCenter
        anchors.verticalCenterOffset: 0
        Text {
            id: txtContent
            y: 5
            text: qsTr("Content") + appTrans.emptyString
            anchors.leftMargin: 8
            anchors.verticalCenter: parent.verticalCenter
            anchors.left: parent.left
            font.pixelSize: 14
            font.bold: true
        }
        border.color: "#909090"
    }

}

/*##^##
Designer {
    D{i:3;anchors_x:8}D{i:2;anchors_x:24}D{i:5;anchors_x:8}D{i:4;anchors_x:24}D{i:7;anchors_x:8}
D{i:6;anchors_x:24}
}
##^##*/
