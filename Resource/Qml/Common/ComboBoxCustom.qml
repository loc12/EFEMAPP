import QtQuick 2.0
import QtQuick.Controls 2.1

Rectangle{
    id: id_combobox
    property var models: ["combobox1","combobox2","combobox3"]
    property int radiusNum: 3
    property int activeIndex
    border.color: "#7a7a7a"
    width: 140
    height: 27
    ComboBox {
        id: lpComName
        width: parent.width - 2
        height: parent.height - 2
        anchors.top: parent.top
        anchors.topMargin: 1
        anchors.left: parent.left
        anchors.leftMargin: 1
        model: models
        currentIndex: activeIndex
        onCurrentIndexChanged: {
            activeIndex = currentIndex
        }
        font.pixelSize: 14
    }
}

