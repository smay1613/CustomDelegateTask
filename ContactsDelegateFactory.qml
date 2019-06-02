import QtQuick 2.0
import Contacts 1.0

QtObject {
    function getIconDelegate(entryType) {
        return "ContactDelegates/ContactIcon.qml"
    }

    function getTitleDelegate(entryType) {
        return "ContactDelegates/ContactTitleDelegate.qml";
    }

    function getSubtitleDelegate(entryType) {
        return "ContactDelegates/ContactSubTitleDelegate.qml"
    }

    function getDataDelegate(entryType) {
        switch (entryType)
        {
        case ContactsModel.Contact:
            return "ContactDelegates/ContactDataDelegate.qml";
        case ContactsModel.ContactSuggestion:
            return "SuggestionDelegates/SuggestionDataDelegate.qml";
        default:
            return "";
        }
    }

    function getActionDelegate(entryType) {
        switch (entryType)
        {
        case ContactsModel.Contact:
            return "ContactDelegates/ContactActionDelegate.qml";
        case ContactsModel.ContactSuggestion:
            return "SuggestionDelegates/SuggestionActionDelegate.qml";
        default:
            return "";
        }
    }
}
