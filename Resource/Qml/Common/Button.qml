import QtQuick 2.0

Rectangle {
    property string nameButton
    property bool isActive
    signal changeStatus()
    id: rec
    width: 80
    height: 45
    radius: 10
    border.color: "#000000"

    Text {
        anchors.centerIn: parent
        text: nameButton
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.verticalCenter: parent.verticalCenter
        font.pixelSize: 14
    }
    Rectangle{
        id: subRec
        anchors.fill: parent
        radius: rec.radius
        color: "transparent"
        opacity: 0.6
    }

    MouseArea {
        anchors.fill: parent
        onClicked: {
            changeStatus();
        }
        onPressed: {
            subRec.color = "#CCCCFF"
        }
        onReleased: {
            subRec.color = "transparent"
        }
        onCanceled: {
            subRec.color = "transparent"
        }

    }

    state: isActive ? "ON" : "OFF"
    states: [
        State {
            name: "ON"
            PropertyChanges {
                target: rec
                color: "#feffa0"
            }
        },
        State {
            name: "OFF"
            PropertyChanges {
                target: rec
                color: "#e0e0e0"
            }
        }
    ]
}
