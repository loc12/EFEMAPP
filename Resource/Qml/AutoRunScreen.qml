import QtQuick 2.4
import Enum 1.3

Rectangle {
    id: mainScreen
    width: 788
    height: 543
    color: "#e0e0e0"
    radius: 5

    Manipulator {
        id: manipulator
        x: 107
        y: 123
    }

    AlignerStage {
        id: alignerStage
        x: 102
        y: 7
    }

    LoadPort {
        id: loadPort
        x: 102
        y: 395
    }

    WaferStage {
        id: waferStage
        x: 258
        y: 232
    }
    Cassette {
        id: cassette
        x: 10
        y: 226
        width: 76
        height: 252
    }
    Rectangle {
        id: recLogArea
        x: 334
        y: 4
        width: 447
        height: 535
        color: "#ffffff"

        HeaderLog {
            id: headerLog
            anchors.top: parent.top
            anchors.topMargin: 0
            anchors.left: parent.left
            anchors.leftMargin: 0
        }
        ListView {
            id: listLogView
            width: parent.width
            height: parent.height-headerLog.height-1
            anchors.horizontalCenter: parent.horizontalCenter
            anchors.top: headerLog.bottom
            anchors.topMargin: -1
            clip: true
            focus: true
            snapMode: ListView.SnapOneItem
            model: logModel
            smooth: true
            spacing: -1
            cacheBuffer: 10000
            delegate: Rectangle {
                width: headerLog.width
                height: headerLog.height
                Rectangle {
                    id: stt
                    width: headerLog.sttWidth
                    height: headerLog.height
                    anchors.left: parent.left
                    anchors.verticalCenter: parent.verticalCenter
                    color: "#fff2cc"
                    border.color: "#909090"
                    Text {
                        text: index + 1
                        anchors.verticalCenter: parent.verticalCenter
                        anchors.left: parent.left
                        anchors.leftMargin: 3
                        font.pixelSize: 13
                    }
                }
                Rectangle {
                    id: time
                    width: headerLog.timeWidth
                    height: headerLog.height
                    anchors.left: stt.right
                    anchors.leftMargin: -1
                    anchors.verticalCenter: parent.verticalCenter
                    color: "#fefffe"
                    border.color: "#909090"
                    Text {
                        text: datetime
                        anchors.verticalCenter: parent.verticalCenter
                        anchors.left: parent.left
                        anchors.leftMargin: 3
                        color: colorlog
                        font.pixelSize: 13
                    }
                }
                Rectangle {
                    id: dir
                    width: headerLog.dirWidth
                    height: headerLog.height
                    anchors.left: time.right
                    anchors.leftMargin: -1
                    anchors.verticalCenter: parent.verticalCenter
                    color: "#fefffe"
                    border.color: "#909090"
                    Text {
                        text: dirlog
                        anchors.verticalCenter: parent.verticalCenter
                        anchors.left: parent.left
                        anchors.leftMargin: 3
                        color: colorlog
                        font.pixelSize: 13
                    }
                }
                Rectangle {
                    id: ctent
                    width: headerLog.contentWidth
                    height: headerLog.height
                    anchors.left: dir.right
                    anchors.leftMargin: -1
                    anchors.verticalCenter: parent.verticalCenter
                    color: "#fefffe"
                    border.color: "#909090"
                    Text {
                        text: content
                        anchors.verticalCenter: parent.verticalCenter
                        anchors.left: parent.left
                        anchors.leftMargin: 3
                        color: colorlog
                        font.pixelSize: 13
                    }
                }
            }
        }
    }

    Rectangle {
        id: rectangle
        width: (settingData.efemType === Enum.BOTTOM_TYPE) ? 95: 70
        height: 29
        color: "#1c8008"
        anchors.bottom: recLogArea.bottom
        anchors.bottomMargin: 0
        anchors.right: recLogArea.left
        anchors.rightMargin: 2
        Text {
            id: txtSupplyType
            x: 4
            width: (settingData.efemType === Enum.BOTTOM_TYPE) ? 87 : 65
            height: 19
            color: "#ffffff"
            text: (settingData.efemType === Enum.BOTTOM_TYPE) ? qsTr("Bottom Supply") :qsTr("Top Supply")
            anchors.centerIn: parent
            font.pixelSize: 13
        }
    }
}
