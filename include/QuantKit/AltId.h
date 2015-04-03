#ifndef __QUANTKIT_ACCOUNTDATAFIELD_H__
#define __QUANTKIT_ACCOUNTDATAFIELD_H__

#include <QuantKit/quantkit_global.h>
#include <QString>
#include <QList>

namespace QuantKit {

typedef QList<AltId> AltIdList;

class QUANTKIT_EXPORT AltId
{
public:
    AltId() {}
    AltId(unsigned char provider, const QString& symbol, const QString& exchange)
        : m_providerId(provider), m_symbol(symbol), m_exchange(exchange)
    {}

    AltId(const AltId &other)
        : m_providerId(other.m_providerId)
        , m_symbol(other.m_symbol)
        , m_exchange(other.m_exchange)
    {}

    ~AltId() {}

    AltId& operator=(const AltId &other)
    {
        m_providerId = other.m_providerId;
        m_symbol = other.m_symbol;
        m_exchange = other.m_exchange;
        return *this;
    }

    bool operator==(const AltId &other) const
    {
        return m_providerId == other.m_providerId
            && m_symbol = other.m_symbol
            && m_exchange = other.m_exchange;
    }

    inline bool operator!=(const AltId &other) const { return !(this->operator==(other));  }

public:
    unsigned char providerId() const  { return m_providerId; }
    QString symbol() const { return m_symbol; }
    QString exchange() const { return m_exchange; }

    void setProviderId(unsigned char providerId) { m_providerId = providerId; }
    void setSymbol(const QString& symbol) { m_symbol = symbol; }
    void setExchange(const QString& exchange) { m_exchange = exchange; }

private:
    unsigned char m_providerId;
    QString m_symbol;
    QString m_exchange;
};

} // namespace QuantKit

Q_DECLARE_TYPEINFO(QuantKit::AltId, Q_MOVABLE_TYPE)

#endif // __QUANTKIT_ACCOUNTDATAFIELD_H__
