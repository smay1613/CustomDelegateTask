#include "contactsuggestion.h"
#include <QVariant>

ContactSuggestion::ContactSuggestion(VCardInfo vcard)
    : m_info {std::move (vcard)}
{
}

QString ContactSuggestion::title() const
{
    return m_info.name + " " + m_info.surname;
}

QString ContactSuggestion::subTitle() const
{
    return {};
}

QVariant ContactSuggestion::data() const
{
    return m_info.phoneNumbers.empty() ? QVariant {} : m_info.phoneNumbers.at(0);
}

QString ContactSuggestion::iconSource() const
{
    static const QString suggestionIcon {"qrc:/icons/contact.svg"};
    return suggestionIcon;
}
