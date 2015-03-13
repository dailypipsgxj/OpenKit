#ifndef TICK_P_H
#define TICK_P_H

#include <QuantKit/Event/Tick.h>
#include <QuantKit/Event_p.h>

namespace QuantKit {

class QUANTKIT_EXPORT TickPrivate : public DataObjectPrivate
{
public:
    QDateTime m_exchangeDateTime;
    unsigned char m_providerId;
    unsigned char m_instrumentId;
    double m_price;
    int m_size;

public:
    TickPrivate(const QDateTime& dateTime, unsigned char providerId, unsigned char instrumentId, double price, int size)
        : DataObjectPrivate(dateTime)
        , m_providerId(providerId)
        , m_instrumentId(instrumentId)
        , m_price(price)
        , m_size(size)
    {
    }

    TickPrivate(const QDateTime& dateTime, const QDateTime& exchangeDateTime, unsigned char providerId, unsigned char instrumentId, double price, int size)
        : DataObjectPrivate(dateTime)
        , m_exchangeDateTime(exchangeDateTime)
        , m_providerId(providerId)
        , m_instrumentId(instrumentId)
        , m_price(price)
        , m_size(size)
    {
    }

    TickPrivate(const TickPrivate& other)
        : DataObjectPrivate(other)
        , m_exchangeDateTime(other.m_exchangeDateTime)
        , m_providerId(other.m_providerId)
        , m_instrumentId(other.m_instrumentId)
        , m_price(other.m_price)
        , m_size(other.m_size)
    {
    }

    virtual ~TickPrivate() {}

public:
    QDateTime exchangeDateTime() const { return m_exchangeDateTime; }
    void setExchangeDateTime(const QDateTime& dateTime) { m_exchangeDateTime = dateTime; }

    unsigned char providerId() const { return m_providerId; }
    void setProviderId(unsigned char providerId) { m_providerId = providerId; }

    unsigned char instrumentId() const { return m_instrumentId; }
    void setInstrumentId(unsigned char instrumentId) { m_instrumentId = instrumentId; }

    double price() const { return m_price; }
    void setPrice(double price) { m_price = price; }

    int size() const { return m_size; }
    void setSize(int size) { m_size = size; }
};

} // namespace QuantKit

#endif // TICK_P_H

