import QtQuick 2.12
import Contacts 1.0

TableView {
    id: root
    columnSpacing: 5
    rowSpacing: 5

    clip: true
    interactive: false

    model: ContactsModel {}

    delegate: Component {
        Loader {
            property int row: index % root.model.rowCount()
            property int column: index / root.model.rowCount()
            source: {
                var entryType = root.model.getEntryType(row)

                // with 5.12 tableview we can't operate with columns/roles so easy....
                switch (column) {
                case 0:
                    return _delegateFactory.getIconDelegate(entryType);
                case 1:
                    return _delegateFactory.getTitleDelegate(entryType);
                case 2:
                    return _delegateFactory.getSubtitleDelegate(entryType);
                case 3:
                    return _delegateFactory.getDataDelegate(entryType);
                case 4:
                    return _delegateFactory.getActionDelegate(entryType);
                }
            }
        }
    }

    ContactsDelegateFactory {
        id: _delegateFactory
    }
}
