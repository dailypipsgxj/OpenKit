#include <QuantKit/OrderBook.h>

#include "Tick_p.h"
#include <QuantKit/Event/Quote.h>
#include <QuantKit/Event/Level2Snapshot.h>
#include <QuantKit/Event/Level2Update.h>

namespace QuantKit {

class OrderBookPrivate : public QSharedData
{
public:
	IList<Tick> m_bids;
	IList<Tick> m_asks;

public:
	OrderBookPrivate();
	virtual ~OrderBookPrivate();

public:
	IList<Tick> bids() const { return m_bids; }
	IList<Tick> asks() const { return m_asks; }
	int getAskVolume() { return method_1(m_asks); }
	double getAvgAskPrice() { return method_2(m_asks); }
	double getAvgBidPrice() { return method_2(m_bids); }
	int getBidVolume() { return method_1(m_bids); }
	Quote getQuote(int level);
	virtual OrderBookPrivate* clone() Q_DECL_OVERRIDE { return new OrderBookPrivate(*this); }
//private:
	int method_1(const IList<Tick>& ticks);
	double method_2(const IList<Tick>& ticks);
};

} // namepsace QuantKit


using namespace QuantKit;

OrderBookPrivate::OrderBookPrivate()
	: m_bids(new QList<Tick>())
	, m_asks(new QList<Tick>())
{
}

OrderBookPrivate::~OrderBookPrivate ()
{
}

Quote OrderBookPrivate::getQuote(int level)
{
	Bid bid = new Bid();
	Ask ask = new Ask();
	if (m_bids.Count < level)
	{
		Tick tick = m_bids[level];
		bid = new Bid(tick.entryDate(), tick.providerId(), tick.instrumentId(), tick.price(), tick.size());
	}
	if (m_asks.Count < level)
	{
		Tick tick2 = m_asks[level];
		ask = new Ask(tick2.entryDate(), tick2.providerId(), tick2.instrumentId(), tick2.price(), tick2.size());
	}
	return new Quote(bid, ask);
}

int OrderBookPrivate::method_1(const IList<Tick>& ticks)
{
	int num = 0;
	foreach (Tick current in ticks)
	{
		num += current.size();
	}
	return num;
}

double OrderBookPrivate::method_2(const IList<Tick>& ticks)
{
	double num = 0.0;
	double num2 = 0.0;
	foreach (Tick current in ticks)
	{
		num += current.price() * (double)current.size();
		num2 += (double)current.size();
	}
	return num / num2;
}


// Pubic API 

OrderBook::OrderBook()
	: d_ptr(new OrderBookPrivate)
{
}

OrderBook::~OrderBook()
{
}

OrderBook::OrderBook (const OrderBook &other)
	: d_ptr(other.d_ptr)
{
}

OrderBook& OrderBook::operator=(const OrderBook &other)
{
	d_ptr = other.d_ptr;
	return *this;
}

bool OrderBook::operator==(const OrderBook &other) const
{
	if(d_ptr && other.d_ptr)
		return (*d_ptr == *other.d_ptr);
	else
		return (d_ptr==other.d_ptr);
}

IList<Tick> OrderBook::bids() const
{
	return d_ptr->bids();
}

IList<Tick> OrderBook::asks() const
{
	return d_ptr->asks();
}

int OrderBook::getAskVolume()
{
	return d_ptr->getAskVolume();
}

double OrderBook::getAvgAskPrice()
{
	return d_ptr->getAvgAskPrice();
}

double OrderBook::getAvgBidPrice()
{
	return d_ptr->getAvgBidPrice();
}

int OrderBook::getBidVolume()
{
	return d_ptr->getBidVolume();
}

Quote OrderBook::getQuote(int level)
{
	return d_ptr->getQuote(level);
}

QDebug operator<<(QDebug dbg, const OrderBook& orderbook)
{
	return dbg << orderbook.toString();
}

