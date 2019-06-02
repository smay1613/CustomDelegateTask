#include "contactsmodel.h"
#include <typeindex>
#include <unordered_map>
#include <QQmlEngine>
#include "basiccontact.h"
#include "contactsuggestion.h"
#include "cachestorage.h"

ContactsModel::ContactsModel()
{
    requestData();
}

void ContactsModel::registerSelf(const std::string& uri)
{
    qmlRegisterType<ContactsModel>(uri.c_str(), 1, 0, "ContactsModel");
}

int ContactsModel::rowCount(const QModelIndex& /*parent*/) const
{
    return static_cast<int>(m_contacts.size());
}

int ContactsModel::columnCount(const QModelIndex& /*parent*/) const
{
    static constexpr size_t columnsCount {5}; // icon, title, subtitle, data, action
    return columnsCount;
}

QVariant ContactsModel::data(const QModelIndex& index, int role) const
{
    int row = index.row();
    if (row < 0 || row > rowCount()) {
        return {};
    }

    const auto& entry = m_contacts.at(row);

    switch (role)
    {
    case ContactRoles::IconRole:
        return entry->iconSource();
    case ContactRoles::TitleRole:
        return entry->title();
    case ContactRoles::SubTitleRole:
        return entry->subTitle();
    case ContactRoles::DataRole:
        return entry->data();
    }

    return {};
}

// this is not neccessary, but more general
// we'll resolve type based on RTTI
// alternatively, we can make a virtual function getType for IContact
// or member "type" for basic contact class
static const std::unordered_map<std::type_index,
                      ContactsModel::EntryType> typeMap {
    {typeid(BasicContact), ContactsModel::EntryType::Contact},
    {typeid(ContactSuggestion), ContactsModel::EntryType::ContactSuggestion}
};

ContactsModel::EntryType ContactsModel::getEntryType(const int index) const
{
    if (index > m_contacts.size()) {
        return EntryType::Invalid;
    }

    return typeMap.at(typeid(*m_contacts.at(index)));
}

QHash<int, QByteArray> ContactsModel::roleNames() const
{
    return {
        {ContactRoles::IconRole, "iconRole"},
        {ContactRoles::TitleRole, "titleRole"},
        {ContactRoles::SubTitleRole, "subtitleRole"},
        {ContactRoles::DataRole, "dataRole"}
    };
}

void ContactsModel::requestData()
{
    const auto& contacts = CacheStorage::basicContacts();
    const auto& suggestions = CacheStorage::suggestions();

    m_contacts.reserve(contacts.size() + suggestions.size());

    for (const auto& suggestion : suggestions) {
        m_contacts.push_back(std::unique_ptr<ContactSuggestion> {
                                 new ContactSuggestion {suggestion}
                             });
    }

    for (const auto& contact : contacts) {
        m_contacts.push_back(std::unique_ptr<BasicContact> {
                                 new BasicContact {contact}
                             });
    }
}
