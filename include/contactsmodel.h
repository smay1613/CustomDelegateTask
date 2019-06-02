#ifndef CONTACTSMODEL_H
#define CONTACTSMODEL_H
#include <QAbstractTableModel>
#include <memory>
#include <vector>
#include "icontact.h"

class ContactsModel : public QAbstractTableModel
{
    Q_OBJECT

public:
    ContactsModel();
    enum ContactRoles {
        IconRole = Qt::UserRole + 1,
        TitleRole,
        SubTitleRole,
        DataRole,
        MIN = IconRole,
        MAX = DataRole
    };

    enum class EntryType
    {
        Invalid,
        Contact,
        ContactSuggestion
    };
    Q_ENUM (EntryType)

    static void registerSelf(const std::string& uri);

    int rowCount(const QModelIndex& = {}) const override;
    int columnCount(const QModelIndex& = {}) const override;

    QVariant data(const QModelIndex& index, int role) const override;
    Q_INVOKABLE EntryType getEntryType(const int index) const;

    QHash<int, QByteArray> roleNames() const override;

private:
    std::vector<std::unique_ptr<IContact>> m_contacts;

    void requestData();
};

#endif
