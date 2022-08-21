import QtQuick 2.0

// Author: thinhnn
// Description: qml text edit component
// Date modify: 2021/10/25

Rectangle {
    id: recPortNo
    border.color: "#7cb481"
    radius: 0
    color: isReadOnly ? "#fff2cc" : "#c8fffa"
    signal textChanged()
    property bool isReadOnly: false
    property string content: ""
    property int maxLenght: 5
    property string updatedContent: ""
    property bool isNumber: true
    TextInput{
        id: textEdit
        clip: true
        width: parent.width/* - 35*/
        height: parent.height
        anchors.top: parent.top
        anchors.topMargin: 3
        anchors.left: parent.left
        anchors.leftMargin: 10
        font.pixelSize: 14
        wrapMode: TextInput.WordWrap
        mouseSelectionMode: TextInput.SelectCharacters
        readOnly: isReadOnly
        text: content
        color: isReadOnly ? "gray" : "black"
        selectByMouse: true
        onTextChanged: {
            if(updatedContent !== getText(0, maxLenght)){
                updatedContent = getText(0, maxLenght)
                textChanged();
            }
        }
        validator: IntValidator { bottom: 1; top: 999999}
    }

    Rectangle{
        id: subRec
        anchors.fill: parent
        color: "transparent"
        opacity: 0.6
    }
}
