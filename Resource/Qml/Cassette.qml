import QtQuick 2.4
import Enum 1.3

Rectangle {
    id: recCassette
    width: 60
    height: 252
    color: "#606060"
    border.color: "#303030"
    radius: 5
    ListView {
        id: listWafer
        width: 50
        height: parent.height - 10
        anchors.verticalCenter: parent.verticalCenter
        anchors.horizontalCenter: parent.horizontalCenter
        spacing: 2
        model: listSlot
        delegate: Rectangle {
            width: 50
            height: 6
            color: (status === Enum.SLOT_HAS_WAFER) ? "#35CB49" : "gray"
            border.color: "#707070"
            radius: 5
        }
        verticalLayoutDirection: ListView.BottomToTop
        enabled: false
    }
}
