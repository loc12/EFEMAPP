import QtQuick 2.0

Item {
    id: commandScreen
    width: 788
    height: 543
    Loader {
        id: cmdSettingScreen
        width: 702
        height: parent.height
        anchors.verticalCenter: parent.verticalCenter
        anchors.left: parent.left
        anchors.leftMargin: 0
        sourceComponent: lpCmdSettingComponent
    }

    Component {
        id: lpCmdSettingComponent
        LPCommandScreen {
            width: cmdSettingScreen.width
            height: cmdSettingScreen.height
            onOpenChgLPStateScreen: {
                cmdSettingScreen.sourceComponent = lpStateSettingComponent;
            }
        }
    }
    Component {
        id: robotCmdSettingComponent
        RobotCommandScreen {
            width: cmdSettingScreen.width
            height: cmdSettingScreen.height
        }
    }
    Component {
        id: rfidCmdSettingComponent
        RFIDCommandScreen {
            width: cmdSettingScreen.width
            height: cmdSettingScreen.height
        }
    }

    Component{
        id: lpStateSettingComponent
        LPStateSettingScreen {
            width: cmdSettingScreen.width
            height: cmdSettingScreen.height
            onCloseSettingLPState: {
                cmdSettingScreen.sourceComponent = lpCmdSettingComponent;
            }
        }
    }

    PanelRightCommandScreen{
        x: 708
        width: 80
        height: parent.height
        anchors.top: parent.top
        anchors.topMargin: 0
        anchors.right: parent.right
        anchors.rightMargin: 0
        onRequestChangeScreen:  {
            if(screenNum === 0){
                cmdSettingScreen.sourceComponent = lpCmdSettingComponent;
            }
            else if(screenNum === 1){
                cmdSettingScreen.sourceComponent = robotCmdSettingComponent;
            }
            else if(screenNum === 2){
                cmdSettingScreen.sourceComponent = rfidCmdSettingComponent;
            }
        }
    }
}
