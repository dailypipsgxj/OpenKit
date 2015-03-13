#ifndef BID_H
#define BID_H

#include <QuantKit/Event/Tick.h>

namespace QuantKit {

class BidPrivate;

class QUANTKIT_EXPORT Bid Q_DECL_FINAL : public Tick
{
public:
    Bid(const QDateTime& dateTime, unsigned char providerId, unsigned char instrumentId, double price, int size);
    Bid(const QDateTime& dateTime, const QDateTime& exchangeDateTime, unsigned char providerId, unsigned char instrumentId, double price, int size);
};

} // namespace QuantKit

Q_DECLARE_SHARED(QuantKit::Bid)

#endif // BID_H
