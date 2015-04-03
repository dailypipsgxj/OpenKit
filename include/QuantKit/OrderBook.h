#ifndef __QUANTKIT_ORDERBOOK_H__
#define __QUANTKIT_ORDERBOOK_H__

#include <QuantKit/quantkit_global.h>
#include <QDebug>
#include <QSharedDataPointer>
#include <QList>

namespace QuantKit {

class OrderBookPrivate;

class Tick;
class Quote;
class Level2Snapshot;
class Level2Update;

class QUANTKIT_EXPORT OrderBook
{
public:
	OrderBook();
	~OrderBook();

	OrderBook(const OrderBook &other);
	OrderBook& operator=(const OrderBook &other);
	bool operator==(const OrderBook &other) const;
	inline bool operator!=(const OrderBook &other) const { return !(this->operator==(other));  }
public:
    QList<Tick> bids() const;
    QList<Tick> asks() const;
	int getAskVolume();
	double getAvgAskPrice();
	double getAvgBidPrice();
	int getBidVolume();
	Quote getQuote(int level);

private:
	QSharedDataPointer<OrderBookPrivate> d_ptr;

	friend QDebug operator<<(QDebug dbg, const OrderBook& orderbook);
};

QUANTKIT_EXPORT QDebug operator<<(QDebug dbg, const OrderBook& orderbook);

} // namespace QuantKit

Q_DECLARE_SHARED(QuantKit::OrderBook)

#endif // __QUANTKIT_ORDERBOOK_H__
