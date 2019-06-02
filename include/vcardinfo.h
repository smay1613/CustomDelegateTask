#ifndef VCARDINFO_H
#define VCARDINFO_H
#include <QString>
#include <QImage>

struct VCardInfo
{
    QString name;
    QString surname;
    QVector<QString> phoneNumbers;
    QString sourceIcon;
};

#endif // VCARDINFO_H
