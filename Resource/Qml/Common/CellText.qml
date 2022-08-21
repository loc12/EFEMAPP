import QtQuick 2.4

Item {
    id: element
    width: 200
    height: 25
    property string content
    property bool isReadOnly: true

    Rectangle {
        id: rectangle
        anchors.top: parent.top
        anchors.left: parent.left
        width: parent.width
        height: parent.height
        color: isReadOnly ? "#fff2cc" : "#c8fffa"
        border.color: "#7a7a7a"
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.verticalCenter: parent.verticalCenter

        TextEdit {
            id: element1
            anchors.verticalCenter: parent.verticalCenter
            anchors.left: parent.left
            anchors.leftMargin: 5
            text: content
            font.pixelSize: 14
        }
    }
}
