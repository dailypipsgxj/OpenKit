#ifndef __QUANTKIT_TRADE_H__
#define __QUANTKIT_TRADE_H__

#include <QuantKit/quantkit_global.h>
#include <QDateTime>
#include <QString>

#include <QuantKit/Tick.h>

namespace QuantKit {

class TradePrivate;


class QUANTKIT_EXPORT Trade Q_DECL_FINAL : public Tick
{
public:
	Trade();
	Trade(const QDateTime& dateTime, unsigned char providerId, int instrumentId, double price, int size);
	Trade(const QDateTime& dateTime, const QDateTime& exchangeDateTime, unsigned char providerId, int instrumentId, double price, int size);
	~Trade();

public:

private:
};

} // namespace QuantKit

Q_DECLARE_SHARED(QuantKit::Trade)

#endif // __QUANTKIT_TRADE_H__
