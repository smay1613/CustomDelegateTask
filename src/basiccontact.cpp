#include "basiccontact.h"
#include <QVariant>

BasicContact::BasicContact(VCardInfo vcard)
    : m_info {std::move (vcard)}
{
}

QString BasicContact::title() const
{
    return m_info.name.isEmpty() ? "Unknown" : m_info.name;
}

QString BasicContact::subTitle() const
{
    return m_info.surname;
}

QVariant BasicContact::data() const
{
    return QVariant::fromValue(m_info.phoneNumbers);
}

QString BasicContact::iconSource() const
{
    return m_info.sourceIcon;
}
