import QtQuick 2.2
import QtQuick.Controls 1.1
//import QtQuick.Window 2.0

Rectangle {
    id: page
    width: 320; height: 480
    color: "white"

    Text {
        id: helloText
        text: "Hello RN4020!"+
              "\n\nw:"+page.width + "  h:"+page.height

        y: 30
        anchors.horizontalCenter: page.horizontalCenter
        font.pointSize: 24; font.bold: true
    }



}
