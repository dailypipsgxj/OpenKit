#ifndef __QUANTKIT_TICK_H__
#define __QUANTKIT_TICK_H__

#include <QuantKit/quantkit_global.h>
#include <QDateTime>

namespace QuantKit {

class Tick
{
protected:
    Tick() {}
    Tick(const QDateTime& dateTime, unsigned char providerId, int instrumentId, double price, int size)
        : m_dateTime(dateTime)
        , m_providerId(providerId)
        , m_instrumentId(instrumentId)
        , m_price(price)
        , m_size(size)
    {}

    Tick(const QDateTime& dateTime, const QDateTime& exchangeDateTime, unsigned char providerId, int instrumentId, double price, int size)
        : m_dateTime(dateTime)
        , m_exchangeDateTime(exchangeDateTime)
        , m_providerId(providerId)
        , m_instrumentId(instrumentId)
        , m_price(price), m_size(size)
    {}

    Tick(const Tick& other)
        : m_dateTime(other.m_dateTime)
        , m_exchangeDateTime(other.m_exchangeDateTime)
        , m_providerId(other.m_providerId)
        , m_instrumentId(other.m_instrumentId)
        , m_price(other.m_price)
        , m_size(other.m_size)
    {}

    Tick& operator=(const Tick& other)
    {
        m_dateTime = other.m_dateTime;
        m_exchangeDateTime = other.m_exchangeDateTime;
        m_providerId = other.m_providerId;
        m_instrumentId = other.m_instrumentId;
        m_price = other.m_price;
        m_size = other.m_size;
        return *this;
    }

public:
    inline QDateTime dateTime() const { return m_dateTime; }

    inline QDateTime exchangeDateTime() const { return m_exchangeDateTime; }
    inline void setExchangeDateTime(const QDateTime& exchangeDateTime) { m_exchangeDateTime = exchangeDateTime; }

    inline unsigned char providerId() const { return m_providerId; }
    inline void setProviderId(unsigned int id) { m_providerId = id; }

    inline unsigned char instrumentId() const { return m_instrumentId; }
    inline void setInstrumentId(unsigned char id) { m_instrumentId = id; }

    inline double price() const { return m_price; }
    inline void setPrice(double price) { m_price = price; }

    inline double size() const { return m_size; }
    inline void setSize(double size) { m_size = size; }

protected:
    QDateTime m_dateTime;
    QDateTime m_exchangeDateTime;
    unsigned char m_providerId;
    int m_instrumentId;
    double m_price;
    int m_size;
    friend bool operator==(const Tick& lhs, const Tick& rhs);
};

bool operator==(const Tick& lhs, const Tick& rhs)
{
    return     lhs.m_dateTime == rhs.m_dateTime
            && lhs.m_exchangeDateTime == rhs.m_exchangeDateTime
            && lhs.m_providerId == rhs.m_providerId
            && lhs.m_instrumentId == rhs.m_instrumentId
            && lhs.m_price == rhs.m_price
            && lhs.m_size == rhs.m_size;
}

class QUANTKIT_EXPORT Ask : public Tick
{
public:
    Ask(const QDateTime& dateTime, unsigned char providerId, int instrumentId, double price, int size)
        : Tick(dateTime, providerId, instrumentId, price, size)
    {}

    Ask(const QDateTime& dateTime, const QDateTime& exchangeDateTime, unsigned char providerId, int instrumentId, double price, int size)
        : Tick(dateTime, exchangeDateTime, providerId, instrumentId, price, size)
    {}

    Ask() : Tick() {}

    Ask(const Ask& other) : Tick(other) {}
};

class QUANTKIT_EXPORT Bid : public Tick
{
public:
    Bid(const QDateTime& dateTime, unsigned char providerId, int instrumentId, double price, int size)
        : Tick(dateTime, providerId, instrumentId, price, size)
    {}

    Bid(const QDateTime& dateTime, const QDateTime& exchangeDateTime, unsigned char providerId, int instrumentId, double price, int size)
        : Tick(dateTime, exchangeDateTime, providerId, instrumentId, price, size)
    {}

    Bid() : Tick() {}

    Bid(const Bid& other) : Tick(other) {}
};

class QUANTKIT_EXPORT Trade : public Tick
{
public:
    Trade(const QDateTime& dateTime, unsigned char providerId, int instrumentId, double price, int size)
        : Tick(dateTime, providerId, instrumentId, price, size)
    {}

    Trade(const QDateTime& dateTime, const QDateTime& exchangeDateTime, unsigned char providerId, int instrumentId, double price, int size)
        : Tick(dateTime, exchangeDateTime, providerId, instrumentId, price, size)
    {}

    Trade() : Tick() {}

    Trade(const Trade& other) : Tick(other) {}
};

} // namespace QuantKit

#endif // __QUANTKIT_TICK_H__
