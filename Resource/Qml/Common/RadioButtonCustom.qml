import QtQuick 2.0

Item {
    id: item1
    property bool isActive
    property string nameRadio: "Text"
    signal changeStatus()
    width: 20
    height: 20
    Rectangle {
        id: rec1
        width: parent.width
        height: parent.height
        anchors.verticalCenter: parent.verticalCenter
        anchors.horizontalCenter: parent.horizontalCenter
        color: "#4285f4"
        radius: 30
    }

    Rectangle {
        id: rec2
        anchors.verticalCenter: parent.verticalCenter
        anchors.horizontalCenter: parent.horizontalCenter
        width: parent.width - 4
        height: parent.height - 4
        color: "#ffffff"
        radius: 30
        z: 1
    }

    Rectangle {
        id: rec3
        anchors.verticalCenter: parent.verticalCenter
        anchors.horizontalCenter: parent.horizontalCenter
        width: parent.width - 8
        height: parent.height - 8
        color: "#4285f4"
        radius: 13
        z: 2
    }

    Text {
        id: txtName
        text: nameRadio
        anchors.bottom: parent.top
        anchors.bottomMargin: 5
        anchors.horizontalCenter: parent.horizontalCenter
        font.pixelSize: 12
    }
    MouseArea {
        anchors.fill: parent
        onClicked: {
            changeStatus();
        }
    }

    state: isActive ? "ON" : "OFF"
    states: [
        State {
            name: "ON"
            PropertyChanges {
                target: rec1
                color: "#4285f4"
            }
            PropertyChanges {
                target: rec2
                color: "#ffffff"
            }

            PropertyChanges {
                target: rec3
                color: "#4285f4"
            }
        },
        State {
            name: "OFF"
            PropertyChanges {
                target: rec1
                color: "#757575"
            }
            PropertyChanges {
                target: rec2
                color: "#ffffff"
            }

            PropertyChanges {
                target: rec3
                color: "#ffffff"
            }
        }
    ]
}
