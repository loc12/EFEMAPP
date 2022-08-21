import QtQuick 2.0
import "./Common"

Item {
    id: element
    width: 80
    height: 540
    signal requestChangeScreen(var screenNum)
    Button {
        id: btnLPCmdSetting
        nameButton:  qsTr("Load Port") + appTrans.emptyString
        isActive: true
        height: 40
        radius: 5
        anchors.top: parent.top
        anchors.topMargin: 0
        anchors.horizontalCenter: parent.horizontalCenter
        onChangeStatus: {
            btnLPCmdSetting.isActive    = true;
            btnRobotCmdSetting.isActive = false;
            btnRFIDCmdSetting.isActive  = false;
            requestChangeScreen(0);
        }
    }

    Button {
        id: btnRobotCmdSetting
        x: 0
        nameButton: qsTr("Robot") + appTrans.emptyString
        height: 40
        radius: 5
        anchors.top: btnLPCmdSetting.bottom
        anchors.topMargin: 10
        anchors.horizontalCenter: parent.horizontalCenter
        onChangeStatus: {
            btnLPCmdSetting.isActive    = false;
            btnRobotCmdSetting.isActive = true;
            btnRFIDCmdSetting.isActive  = false;
            requestChangeScreen(1);
        }
    }

    Button {
        id: btnRFIDCmdSetting
        x: 0
        nameButton: qsTr("RFID") + appTrans.emptyString
        height: 40
        radius: 5
        anchors.top: btnRobotCmdSetting.bottom
        anchors.topMargin: 10
        anchors.horizontalCenter: parent.horizontalCenter
        onChangeStatus: {
            btnLPCmdSetting.isActive    = false;
            btnRobotCmdSetting.isActive = false;
            btnRFIDCmdSetting.isActive  = true;
            requestChangeScreen(2);
        }
    }
}

/*##^##
Designer {
    D{i:2;anchors_y:56}D{i:3;anchors_y:131}
}
##^##*/
