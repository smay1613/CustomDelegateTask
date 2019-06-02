import QtQuick 2.0

Rectangle {
    id: root
    implicitWidth: 100

    Text {
        anchors.fill: root
        text: titleRole
        font.bold: true
        verticalAlignment: Text.AlignVCenter
        horizontalAlignment: Text.AlignHCenter
    }
}
