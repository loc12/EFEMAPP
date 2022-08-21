import QtQuick 2.4

Item {
    id: item1
    width: 70
    height: 80

    Rectangle {
        id: recWaferStage
        x: 100
        y: 100
        width: 70
        height: 70
        border.color: "#808080"
        color: "#c0c0c0"
        radius: 5
        anchors.bottom: recName.top
        anchors.bottomMargin: -10
        anchors.horizontalCenter: parent.horizontalCenter

        Rectangle {
            id: recWafer
            width: 50
            height: 50
            color: "#f66666"
            radius: 100
            anchors.verticalCenterOffset: -3
            anchors.horizontalCenterOffset: 0
            anchors.verticalCenter: parent.verticalCenter
            anchors.horizontalCenter: parent.horizontalCenter
        }
    }

    Rectangle {
        id: recName
        x: 426
        y: 367
        width: 70
        height: 19
        color: "#d8cece"
        anchors.bottom: parent.bottom
        anchors.bottomMargin: 0
        anchors.horizontalCenter: parent.horizontalCenter
        border.color: "#707070"

        Text {
            id: txtName
            x: 41
            y: 11
            text: qsTr("Aligner") + appTrans.emptyString
            anchors.verticalCenter: parent.verticalCenter
            anchors.horizontalCenter: parent.horizontalCenter
            font.pixelSize: 14
        }
    }
    state: "HASWAFER"

    states: [
        State {
            name: "HASWAFER"
            PropertyChanges {
                target: recWafer
                color: "#35cb49"
                border.color: "gray"
            }
        },
        State {
            name: "HASNOWAFER"
            PropertyChanges {
                target: recWafer
                color: "gray"
                border.color: "red"
            }
        }
    ]
}
