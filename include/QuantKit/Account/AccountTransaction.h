#ifndef __QUANTKIT_ACCOUNTTRANSACTION_H__
#define __QUANTKIT_ACCOUNTTRANSACTION_H__

#include <QuantKit/quantkit_global.h>
#include <QDateTime>
#include <QString>

namespace QuantKit {

class QUANTKIT_EXPORT AccountTransaction
{
public:
    AccountTransaction(const QDateTime& dateTime, unsigned char currencyId, double value, const QString& text)
        : m_dateTime(dateTime), m_currencyId(currencyId), m_value(value), m_text(text)
    {}

    AccountTransaction(const AccountTransaction &other)
        : m_dateTime(other.m_dateTime)
        , m_currencyId(other.m_currencyId)
        , m_value(other.m_value)
        , m_text(other.m_text)
    {}

    ~AccountTransaction() {}

    AccountTransaction& operator=(const AccountTransaction &other)
    {
        m_dateTime = other.m_dateTime;
        m_currencyId = other.m_currencyId;
        m_value = other.m_value;
        m_text = other.m_text;
        return *this;
    }

    bool operator==(const AccountTransaction &other) const
    {
        return m_dateTime == other.m_dateTime
            && m_currencyId == other.m_currencyId
            && m_value == other.m_value
            && m_text == other.m_text;
    }

    inline bool operator!=(const AccountTransaction &other) const { return !(this->operator==(other));  }

public:
    QDateTime dateTime() const;
    unsigned char currencyId() const;
    double value() const;
    QString text() const;

private:
    QDateTime m_dateTime;
    unsigned char m_currencyId;
    double m_value;
    QString m_text;
};

} // namespace QuantKit

Q_DECLARE_TYPEINFO(QuantKit::AccountTransaction, Q_MOVABLE_TYPE)

#endif // __QUANTKIT_ACCOUNTTRANSACTION_H__
