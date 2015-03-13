#include <QuantKit/Event/Bid.h>
#include <QuantKit/Event/Tick_p.h>

namespace QuantKit {

class BidPrivate Q_DECL_FINAL : public TickPrivate
{
public:

    BidPrivate(const QDateTime& dateTime, unsigned char providerId, unsigned char instrumentId, double price, int size)
        : TickPrivate(dateTime, providerId, instrumentId, price, size) {}

    BidPrivate(const QDateTime& dateTime, const QDateTime& exchangeDateTime, unsigned char providerId, unsigned char instrumentId, double price, int size)
        : TickPrivate(dateTime, exchangeDateTime, providerId, instrumentId, price, size) {}

    virtual ~BidPrivate() {}

public:
    virtual unsigned char typeId() const Q_DECL_OVERRIDE { return EventType::Bid; }
    virtual BidPrivate* clone() Q_DECL_OVERRIDE { return new BidPrivate(*this); }
};

} // namespace QuantKit

using namespace QuantKit;

// public API

Bid::Bid(const QDateTime& dateTime, unsigned char providerId, unsigned char instrumentId, double price, int size)
    : Tick(*new BidPrivate(dateTime, providerId, instrumentId, price, size))
{
}

Bid::Bid(const QDateTime& dateTime, const QDateTime& exchangeDateTime, unsigned char providerId, unsigned char instrumentId, double price, int size)
    : Tick(*new BidPrivate(dateTime, exchangeDateTime, providerId, instrumentId, price, size))
{
}
