#ifndef TRADE_H
#define TRADE_H

#include <QuantKit/Event/Tick.h>

namespace QuantKit {

class TradePrivate;

class QUANTKIT_EXPORT Trade Q_DECL_FINAL : public Tick
{
public:
    Trade(const QDateTime& dateTime, unsigned char providerId, unsigned char instrumentId, double price, int size);
    Trade(const QDateTime& dateTime, const QDateTime& exchangeDateTime, unsigned char providerId, unsigned char instrumentId, double price, int size);
};

} // namespace QuantKit

Q_DECLARE_SHARED(QuantKit::Trade)

#endif // TRADE_H
