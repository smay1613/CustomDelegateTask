import QtQuick 2.0
import QtQuick.Controls 2.5

Item {
    id: root
    implicitWidth: 300
    implicitHeight: 40

    ComboBox {
        id: _phoneNumbersBox
        anchors.fill: root
        // FIXME: ComboBox doesn't show the QVariant<QVector<QString>> model
        // should be investigated why, maybe the correct role is needed
        model: dataRole.length
        displayText: dataRole[currentIndex]
        delegate: ItemDelegate {
            implicitWidth: _phoneNumbersBox.width
            text: dataRole[index]
        }
        background: Rectangle {border.color: "black"; border.width: 1}
    }
}
