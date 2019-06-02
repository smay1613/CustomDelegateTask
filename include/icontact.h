#ifndef ICONTACT_H
#define ICONTACT_H
#include <QString>
#include <QImage>

class IContact
{
public:
    virtual ~IContact() = default;
    virtual QString title() const = 0;
    virtual QString subTitle() const = 0;
    virtual QVariant data() const = 0;
    virtual QString iconSource() const = 0;
};

#endif // ICONTACT_H
