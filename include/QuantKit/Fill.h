#ifndef __QUANTKIT_FILL_H__
#define __QUANTKIT_FILL_H__

#include <QuantKit/quantkit_global.h>
#include <QString>
#include <QDateTime>
#include <QSharedPointer>

#include <QuantKit/OrderSide.h>

namespace QuantKit {

class Order;
class Instrument;
class ExecutionReport;

class QUANTKIT_EXPORT Fill
{
public:
    Fill(const QDateTime& dateTime, QSharedPointer<Order> order, QSharedPointer<Instrument> instrument,
         unsigned char currencyId, OrderSide side, double qty, double price, const QString& text = "")
        : m_entryDate(dateTime), m_order(order), m_instrument(instrument)
        , m_currencyId(currencyId), m_orderSide(side), m_entryQty(qty), m_entryPrice(price), m_text(text)
    {}

    Fill(const ExecutionReport& report)
        : m_entryDate(report.entryDate())
        , m_order(report.order())
        , m_instrument(report.instrument())
        , m_currencyId(report.currencyId())
        , m_orderSide(report.orderSide())
        , m_entryQty(report.lastQty())
        , m_entryPrice(report.lastPrice())
        , m_commission(report.commission())
        , m_text(report.text())
    {}

    Fill(const Fill& other)
        : m_fillDateTime(other.m_fillDateTime)
        , m_order(other.m_order)
        , m_instrument(other.m_instrument)
        , m_currencyId(other.m_currencyId)
        , m_orderSide(other.m_orderSide)
        , m_entryQty(other.m_entryQty)
        , m_entryPrice(other.m_entryPrice)
        , m_commission(other.m_commission)
        , m_text(other.m_text)
    {
    }

public:
    QSharedPointer<Order> order() const;
    QSharedPointer<Instrument> instrument() const;
    unsigned char currencyId() const;
    OrderSide orderSide() const;
    double qty() const;
    double price() const;
    double value() const;
    double netCashFlow() const;
    double cashFlow() const;
    QString text() const;
    double commission() const;

private:
    QDateTime m_entryDate;
    QSharedPointer<Order> m_order;
    QSharedPointer<Instrument> m_instrument;
    unsigned char m_currencyId;
    OrderSide m_orderSide;
    double m_entryQty;
    double m_entryPrice;
    double m_commission;
    QString m_text;
};

} // namespace QuantKit

Q_DECLARE_TYPEINFO(QuantKit::Fill, Q_MOVABLE_TYPE)

#endif // __QUANTKIT_FILL_H__
