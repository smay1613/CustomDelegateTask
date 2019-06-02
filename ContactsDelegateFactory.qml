import QtQuick 2.0
import Contacts 1.0

QtObject {
    function getIconDelegate(entryType) {
        return "SuggestionIcon.qml"
    }

    function getTitleDelegate(entryType) {
        return "TitleDelegate.qml";
    }

    function getSubtitleDelegate(entryType) {
        return "ContactSubTitleDelegate.qml"
    }

    function getDataDelegate(entryType) {
        switch (entryType)
        {
        case ContactsModel.Contact:
            return "ContactDataDelegate.qml";
        case ContactsModel.ContactSuggestion:
            return "SuggestionDataDelegate.qml";
        default:
            return "";
        }
    }

    function getActionDelegate(entryType) {
        switch (entryType)
        {
        case ContactsModel.Contact:
            return "ContactActionDelegate.qml";
        case ContactsModel.ContactSuggestion:
            return "SuggestionActionDelegate.qml";
        default:
            return "";
        }
    }
}
