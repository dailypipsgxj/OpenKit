#ifndef __QUANTKIT_ACCOUNTPOSITION_H__
#define __QUANTKIT_ACCOUNTPOSITION_H__

#include <QuantKit/quantkit_global.h>

namespace QuantKit {

class QUANTKIT_EXPORT AccountPosition
{
public:
    AccountPosition(unsigned char currencyId, double value)
        : m_currencyId(currencyId), m_value(value)
    {}

    AccountPosition(const AccountPosition &other)
        : m_currencyId(other.m_currencyId)
        , m_value(other.m_value)
    {}

    ~AccountPosition() {}

    AccountPosition& operator=(const AccountPosition &other)
    {
        m_currencyId = other.m_currencyId;
        m_value = other.m_value;
        return *this;
    }

    bool operator==(const AccountPosition &other) const
    {
        return m_currencyId == other.m_currencyId && m_value == other.m_value;
    }

    inline bool operator!=(const AccountPosition &other) const { return !(this->operator==(other));  }

public:
    unsigned char currencyId() const;
    double value() const;

private:
    unsigned char m_currencyId;
    double m_value;
};

} // namespace QuantKit

Q_DECLARE_TYPEINFO(QuantKit::AccountPosition, Q_MOVABLE_TYPE)

#endif // __QUANTKIT_ACCOUNTPOSITION_H__
