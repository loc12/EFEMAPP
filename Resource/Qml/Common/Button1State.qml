import QtQuick 2.0

Rectangle {
    property string nameButton: "Button"
    signal click()
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
        font.pixelSize: 15
        color: "white"
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
            click();
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
}
