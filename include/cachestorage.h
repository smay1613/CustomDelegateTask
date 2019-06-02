#ifndef CACHESTORAGE_H
#define CACHESTORAGE_H
#include <vector>
#include "basiccontact.h"
#include "contactsuggestion.h"

class CacheStorage
{
public:
    CacheStorage();

    static std::vector<BasicContact> basicContacts();
    static std::vector<ContactSuggestion> suggestions();

private:
    static std::vector<BasicContact> m_basicContacts;
    static std::vector<ContactSuggestion> m_suggestions;
};

#endif // CACHESTORAGE_H
