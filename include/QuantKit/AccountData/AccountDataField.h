#ifndef __QUANTKIT_ACCOUNTDATAFIELD_H__
#define __QUANTKIT_ACCOUNTDATAFIELD_H__

#include <QuantKit/quantkit_global.h>
#include <QString>
#include <QList>
#include <QVariant>

namespace QuantKit {

typedef QList<AccountDataField> AccountDataFieldList;

class QUANTKIT_EXPORT AccountDataField
{
public:
    // predefine name const
    static const QString SYMBOL         = "Symbol";
    static const QString EXCHANGE       = "Exchange";
    static const QString SECURITY_TYPE  = "SecurityType";
    static const QString CURRENCY       = "Currency";
    static const QString MATURITY       = "Maturity";
    static const QString PUT_OR_CALL    = "PutOrCall";
    static const QString STRIKE         = "Strike";
    static const QString QTY            = "Qty";
    static const QString LONG_QTY       = "LongQty";
    static const QString SHORT_QTY      = "ShortQty";
    static const QString ORDER_ID       = "OrderID";
    static const QString ORDER_TYPE     = "OrderType";
    static const QString ORDER_SIDE     = "OrderSide";
    static const QString ORDER_STATUS   = "OrderStatus";
    static const QString PRICE          = "Price";
    static const QString STOP_PX        = "StopPx";
public:
    AccountDataField(const QString& name, const QString& currency, const QVariant& value)
        : m_name(name), m_currency(currency), m_value(value)
    {}

    AccountDataField(const QString& name, const QVariant& value)
        : AccountDataField(name, "", value)
    {}

    AccountDataField(const AccountDataField &other)
        : m_name(other.m_name)
        , m_currency(other.m_currency)
        , m_value(other.m_value)
    {}

    ~AccountDataField() {}

    AccountDataField& operator=(const AccountDataField &other)
    {
        m_name = other.m_name;
        m_currency = other.m_currency;
        m_value = other.m_value;
        return *this;
    }

    bool operator==(const AccountDataField &other) const
    {
        return m_name == other.m_name
            && m_currency == other.m_currency
            && m_value == other.m_value;
    }

	inline bool operator!=(const AccountDataField &other) const { return !(this->operator==(other));  }

public:
	QString name() const;
	QString currency() const;
	QVariant value() const;

private:
    QString m_name;
    QString m_currency;
    QVariant m_value;
};

} // namespace QuantKit

Q_DECLARE_TYPEINFO(QuantKit::AccountDataField, Q_MOVABLE_TYPE)

#endif // __QUANTKIT_ACCOUNTDATAFIELD_H__
