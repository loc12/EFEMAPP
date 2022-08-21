import QtQuick 2.0
Rectangle {
    id: groupBox
    width: 350
    height: 50
    border.color: "#000000"
    property string groupName: "Name of Group"
    property int textSize: 14

    Text {
        id: txtNameGR
        x: 4
        y: 2
        text: groupName
        font.pixelSize: textSize
        font.bold: true
    }

    Rectangle {
        id: botShadow
        x: 2
        width: groupBox.width
        height: 2
        color: "#646464"
        anchors.top: parent.bottom
        anchors.topMargin: 0
        anchors.right: parent.right
        anchors.rightMargin: -2
        border.color: "#646464"
    }

    Rectangle {
        id: rectangle
        y: 0
        width: 2
        height: groupBox.height
        color: "#646464"
        anchors.bottom: parent.bottom
        anchors.bottomMargin: -2
        anchors.left: botShadow.right
        anchors.leftMargin: -2
        border.color: "#646464"
    }
}
