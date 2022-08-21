import QtQuick 2.0
import QtQuick.Window 2.0

Window {
    width: 800
    maximumWidth: 800
    minimumWidth: 800
    height: 600
    maximumHeight: 600
    minimumHeight: 600
    visible: true
    title: qsTr("Wafer Supply System Simulator") + appTrans.emptyString
    color: "#C0C0C0"
    signal changedScreen()

    Loader{
        id: loadScreen
        width: 788
        height: 543
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.top: parent.top
        anchors.topMargin: 6
        sourceComponent: mainScreenComponent
    }

    Component {
        id: mainScreenComponent
        AutoRunScreen {
            width: loadScreen.width
            height: loadScreen.height
        }
    }

    Component {
        id: manualScreenComponent
        CommandScreen {
            width: loadScreen.width
            height: loadScreen.height
        }
    }

    Component {
        id: settingScreenComponent
        SettingScreen {
            width: loadScreen.width
            height: loadScreen.height
        }
    }

    Footer {
        id: footer
        width: parent.width
        height: 50
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.bottom: parent.bottom
        anchors.bottomMargin: 0
        onRequestChangeScreen: {
            if(screenNum === 0){
                loadScreen.sourceComponent = mainScreenComponent;
            }
            else if(screenNum === 1){
                loadScreen.sourceComponent = manualScreenComponent;
            }
            else if(screenNum === 2){
                loadScreen.sourceComponent = settingScreenComponent;
            }
            changedScreen();
        }
    }
}

/*##^##
Designer {
    D{i:7;anchors_x:0;anchors_y:0}
}
##^##*/
