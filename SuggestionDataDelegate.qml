import QtQuick 2.0

Item {
    id: root
    implicitWidth: 250

    Text {
        anchors.centerIn: root
        text: dataRole
        color: "gray"
        font.bold: true
    }
}
