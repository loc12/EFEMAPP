import QtQuick 2.4

Item {
    id: element
    width: 61
    height: 153
    property int lenghtArm: 100
    Rectangle {
        id: rootArm
        y: 192
        width: 22
        height: 22
        color: "#4c8beb"
        radius: 11
        anchors.bottom: parent.bottom
        anchors.bottomMargin: 0
        anchors.horizontalCenterOffset: 0
        border.color: "white"
        anchors.horizontalCenter: parent.horizontalCenter
        z: 1
    }

    Rectangle {
        id: robotArm
        y: 86
        width: rootArm.width
        height: lenghtArm
        color: "#4c8beb"
        anchors.bottom: rootArm.top
        anchors.bottomMargin: -10
        anchors.horizontalCenterOffset: 0
        anchors.horizontalCenter: rootArm.horizontalCenter
    }

    Rectangle {
        id: rectangle
        width: 60
        height: 10
        color: "#4c8beb"
        anchors.horizontalCenter: robotArm.horizontalCenter
        anchors.bottom: robotArm.top
        anchors.bottomMargin: 0
        visible: true
    }

    Rectangle {
        id: rectangle1
        width: 7
        height: 30
        color: "#4c8beb"
        anchors.left: rectangle.left
        anchors.leftMargin: 0
        anchors.bottom: rectangle.top
        anchors.bottomMargin: 0
    }

    Rectangle {
        id: rectangle2
        width: 7
        height: 30
        color: "#4c8beb"
        anchors.right: rectangle.right
        anchors.rightMargin: 0
        anchors.verticalCenter: rectangle1.verticalCenter
    }
}
