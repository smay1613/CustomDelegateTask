import QtQuick 2.12
import QtQuick.Window 2.2

Window {
    id: root
    visible: true
    width: 640
    height: 480

    ContactsTable {
        anchors.fill: parent
    }
}
