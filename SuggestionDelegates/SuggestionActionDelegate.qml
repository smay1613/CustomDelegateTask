import QtQuick 2.0

Item {
    id: root
    implicitWidth: 60
    implicitHeight: 40
    property string icon1Source: "qrc:/icons/call.svg"
    property string icon2Source: "qrc:/icons/chat.svg"

    Row {
        anchors.centerIn: root
        anchors.horizontalCenter: root.horizontalCenter
        spacing: 10

        Image {
            source: icon1Source
            sourceSize.height: 25
            sourceSize.width: 25
        }
        Image {
            source: icon2Source
            sourceSize.height: 25
            sourceSize.width: 25
        }
    }
}
