import QtQuick 2.0

Item {
    id: root
    implicitHeight: 40
    implicitWidth: 70
    property string iconSource: "qrc:/icons/chevron-right.svg"

    Image {
        anchors.centerIn: root
        source: iconSource
        sourceSize.height: 25
        sourceSize.width: 25
    }
}
