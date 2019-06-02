#ifndef BASICCONTACT_H
#define BASICCONTACT_H
#include "icontact.h"
#include "vcardinfo.h"

class BasicContact : public IContact
{
public:
    explicit BasicContact(VCardInfo vcard);

    QString title() const override;
    QString subTitle() const override;
    QVariant data() const override;
    QString iconSource() const override;

private:
    VCardInfo m_info;
};

#endif // BASICCONTACT_H
