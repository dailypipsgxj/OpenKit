#ifndef __QUANTKIT_BID_H__
#define __QUANTKIT_BID_H__

#include <QuantKit/quantkit_global.h>
#include <QDateTime>
#include <QString>

#include <QuantKit/Tick.h>

namespace QuantKit {

class BidPrivate;


class QUANTKIT_EXPORT Bid Q_DECL_FINAL : public Tick
{
public:
	Bid();
	Bid(const QDateTime& dateTime, unsigned char providerId, int instrumentId, double price, int size);
	Bid(const QDateTime& dateTime, const QDateTime& exchangeDateTime, unsigned char providerId, int instrumentId, double price, int size);
	~Bid();

public:

private:
};

} // namespace QuantKit

Q_DECLARE_SHARED(QuantKit::Bid)

#endif // __QUANTKIT_BID_H__
