import QtQuick 2.0
import QtGraphicalEffects 1.0

Rectangle {
    id: root
    implicitHeight: 40
    implicitWidth: 40
    radius: implicitHeight / 2

    Image {
        anchors.centerIn: root
        source: iconRole
        sourceSize.width: 25
        sourceSize.height: 25

        fillMode: Image.PreserveAspectCrop
        layer.enabled: true
        layer.effect: OpacityMask {
            maskSource: root
        }
    }
}
