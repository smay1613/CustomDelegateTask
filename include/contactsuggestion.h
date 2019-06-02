#ifndef CONTACTSUGGESTION_H
#define CONTACTSUGGESTION_H
#include "icontact.h"
#include "vcardinfo.h"

class ContactSuggestion : public IContact
{
public:
    explicit ContactSuggestion(VCardInfo vcard);
    QString title() const override;
    QString subTitle() const override;
    QVariant data() const override;
    QString iconSource() const override;

private:
    VCardInfo m_info;
};

#endif // CONTACTSUGGESTION_H
