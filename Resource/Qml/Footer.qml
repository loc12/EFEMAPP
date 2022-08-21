import QtQuick 2.0
import "./Common"

Item {
    id: footer
    width: 800
    height: 50
    signal requestChangeScreen(var screenNum)
    Button {
        id: btnAuto
        height: 40
        radius: 5
        anchors.verticalCenterOffset: 0
        nameButton: qsTr("Auto") + appTrans.emptyString
        anchors.verticalCenter: parent.verticalCenter
        anchors.left: parent.left
        anchors.leftMargin: 7
        isActive: true
        onChangeStatus: {
            btnAuto.isActive    = true;
            btnManual.isActive  = false;
            btnSetting.isActive = false;
            requestChangeScreen(0);
        }
    }

    Button {
        id: btnManual
        height: 40
        radius: 5
        anchors.verticalCenterOffset: 0
        anchors.leftMargin: 15
        nameButton: qsTr("Command") + appTrans.emptyString
        anchors.verticalCenter: parent.verticalCenter
        anchors.left: btnAuto.right
        isActive: false
        onChangeStatus: {
            btnAuto.isActive    = false;
            btnManual.isActive  = true;
            btnSetting.isActive = false;
            requestChangeScreen(1);
        }
    }

    Button {
        id: btnSetting
        height: 40
        radius: 5
        anchors.leftMargin: 15
        nameButton: qsTr("Setting") + appTrans.emptyString
        anchors.verticalCenter: parent.verticalCenter
        anchors.left: btnManual.right
        isActive: false
        anchors.verticalCenterOffset: 0
        onChangeStatus: {
            btnAuto.isActive    = false;
            btnManual.isActive  = false;
            btnSetting.isActive = true;
            requestChangeScreen(2);
        }
    }
}
