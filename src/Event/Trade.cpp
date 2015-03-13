#include <QuantKit/Event/Trade.h>
#include <QuantKit/Event/Tick_p.h>

namespace QuantKit {

class TradePrivate Q_DECL_FINAL : public TickPrivate
{
public:
    TradePrivate(const QDateTime& dateTime, unsigned char providerId, unsigned char instrumentId, double price, int size)
        : TickPrivate(dateTime, providerId, instrumentId, price, size) {}

    TradePrivate(const QDateTime& dateTime, const QDateTime& exchangeDateTime, unsigned char providerId, unsigned char instrumentId, double price, int size)
        : TickPrivate(dateTime, exchangeDateTime, providerId, instrumentId, price, size) {}

    virtual ~TradePrivate() {}

public:
    virtual unsigned char typeId() const Q_DECL_OVERRIDE { return EventType::Trade; }
    virtual TradePrivate* clone() Q_DECL_OVERRIDE { return new TradePrivate(*this); }
};

} // namespace QuantKit

using namespace QuantKit;

// public API

Trade::Trade(const QDateTime& dateTime, unsigned char providerId, unsigned char instrumentId, double price, int size)
    : Tick(*new TradePrivate(dateTime, providerId, instrumentId, price, size))
{
}

Trade::Trade(const QDateTime& dateTime, const QDateTime& exchangeDateTime, unsigned char providerId, unsigned char instrumentId, double price, int size)
    : Tick(*new TradePrivate(dateTime, exchangeDateTime, providerId, instrumentId, price, size))
{
}
