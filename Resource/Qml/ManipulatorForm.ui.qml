import QtQuick 2.4

Item {
    id: element
    width: 92
    height: 188
    property int lenghtRobot: 100
    property int angleArm: 0
    Rectangle {
        id: robotCircle
        x: 274
        y: 135
        width: 90
        height: 90
        color: "#9f9f9f"
        radius: 100
        anchors.bottom: parent.bottom
        anchors.bottomMargin: 0
        border.color: "#707070"
        anchors.horizontalCenterOffset: 0
        anchors.horizontalCenter: parent.horizontalCenter
    }

    RobotArm {
        id: robotArmForm
        x: 257
        y: 53
        width: 51
        height: 152
        anchors.bottom: robotCircle.top
        anchors.bottomMargin: -55
        anchors.horizontalCenter: robotCircle.horizontalCenter
        lenghtArm: lenghtRobot
        rotation: angleArm
    }
}

/*##^##
Designer {
    D{i:0;formeditorZoom:0.9}
}
##^##*/

