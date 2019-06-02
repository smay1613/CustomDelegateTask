#include "cachestorage.h"
#include "vcardinfo.h"

static const std::vector<VCardInfo> vcards {
    {"John", "Doe", {"+758 435 321 34", "+758 435 321 35"}, "mockavatars/johndoe.png"},
    {"Johnny", "Doyer", {"+585 522 123 12"}, "mockavatars/johndoe.png"},
    {"Jenny", "Dose", {"+444 444 444 44", "+555 555 555 55", "+666 666 666 66"}, "mockavatars/jennydoe.png"}
};

std::vector<BasicContact> CacheStorage::m_basicContacts {
    BasicContact {vcards.at(0)},
    BasicContact {vcards.at(1)},
    BasicContact {vcards.at(2)}
};
std::vector<ContactSuggestion> CacheStorage::m_suggestions {
    ContactSuggestion {vcards.at(0)},
    ContactSuggestion {vcards.at(2)}
};

std::vector<BasicContact> CacheStorage::basicContacts()
{
    return m_basicContacts;
}

std::vector<ContactSuggestion> CacheStorage::suggestions()
{
    return m_suggestions;
}
