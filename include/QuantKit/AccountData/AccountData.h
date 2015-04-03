#ifndef __QUANTKIT_ACCOUNTDATA_H__
#define __QUANTKIT_ACCOUNTDATA_H__

#include <QuantKit/quantkit_global.h>
#include <QList>
#include <QuantKit/AccountData/AccountDataType.h>
#include <QuantKit/AccountData/AccountDataField.h>

namespace QuantKit {

class QUANTKIT_EXPORT AccountData Q_DECL_FINAL
{
public:
    AccountData(AccountDataType type, const QString& account, unsigned char providerId, unsigned char route)
        : m_type(type), m_account(account), m_providerId(providerId), m_route(route)
    {}

    AccountData(const AccountData &other)
        : m_type(other.m_type)
        , m_account(other.m_account)
        , m_providerId(other.m_providerId)
        , m_route(other.m_route)
        , m_fields(other.m_fields)
    {}

    ~AccountData() {}

    AccountData& operator=(const AccountData &other)
    {
        m_type = other.m_type;
        m_account = other.m_account;
        m_providerId = other.m_providerId;
        m_route = other.m_route;
        m_fields = other.m_fields;
        return *this;
    }

public:
    AccountDataType type() const { return m_type; }
    QString account() const { return m_account; }
    unsigned char providerId() const { return m_providerId; }
    unsigned char route() const { return m_route; }
    QList<AccountDataField> fields() const { return m_fields; }
    QList<AccountDataField> fields() { return m_fields; }

private:
    AccountDataType m_type;
    QString m_account;
    unsigned char m_providerId;
    unsigned char m_route;
    QList<AccountDataField> m_fields;
};

} // namespace QuantKit

Q_DECLARE_TYPEINFO(QuantKit::AccountData, Q_MOVABLE_TYPE)

#endif // __QUANTKIT_ACCOUNTDATA_H__
