import QtQuick 2.2
import QtQuick.Controls 1.1
//import QtQuick.Window 2.0

Rectangle {
    id: page
    property string currentText: "Valor Introducido"

    width: 320; height: 480
    color: "white"

//    TextInput {
//        id: edit
//    }

    Text {
        id: helloText
        text: currentText

        y: 30
        anchors.horizontalCenter: page.horizontalCenter
        font.pointSize: 24; font.bold: true
    }



}
