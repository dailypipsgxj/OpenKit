#include <QuantKit/Event/Quote.h>

#include <QuantKit/Event/Bid.h>
#include <QuantKit/Event/Ask.h>

#include "DataObject_p.h"
#include <QuantKit/EventType.h>

namespace QuantKit {

class QuotePrivate : public DataObjectPrivate
{
public:
	Bid m_bid;
	Ask m_ask;

public:
	QuotePrivate(const Bid& bid, const Ask& ask);
	QuotePrivate(const QDateTime& dateTime, unsigned char providerId, int instrumentId, double bidPrice, int bidSize, double askPrice, int askSize);
	virtual ~QuotePrivate();

public:
	virtual unsigned char typeId() const Q_DECL_OVERRIDE { return EventType::Quote; }
	Bid bid() const { return m_bid; }
	Ask ask() const { return m_ask; }
	virtual QuotePrivate* clone() Q_DECL_OVERRIDE { return new QuotePrivate(*this); }
};

} // namepsace QuantKit


using namespace QuantKit;

QuotePrivate::QuotePrivate(const Bid& bid, const Ask& ask)
	: m_bid(bid)
	, m_ask(ask)
{
		if (bid.entryDate() > ask.dateTime())
		{
			m_entryDate = bid.entryDate();
			return;
		}
		m_entryDate = ask.entryDate();
}

QuotePrivate::QuotePrivate(const QDateTime& dateTime, unsigned char providerId, int instrumentId, double bidPrice, int bidSize, double askPrice, int askSize)
{
		Class81.pxBq5K7zXLUvm();
		.ctor(new Bid(dateTime, providerId, instrumentId, bidPrice, bidSize), new Ask(dateTime, providerId, instrumentId, askPrice, askSize));
}

QuotePrivate::~QuotePrivate ()
{
}


// Pubic API 

QK_IMPLEMENTATION_PRIVATE(Quote)

Quote::Quote(const Bid& bid, const Ask& ask)
	: DataObject(*new QuotePrivate(bid, ask))
{
}

Quote::Quote(const QDateTime& dateTime, unsigned char providerId, int instrumentId, double bidPrice, int bidSize, double askPrice, int askSize)
	: DataObject(*new QuotePrivate(dateTime, providerId, instrumentId, bidPrice, bidSize, askPrice, askSize))
{
}

Quote::~Quote()
{
}

Bid Quote::bid() const
{
	Q_D(const Quote);
	return d->bid();
}

Ask Quote::ask() const
{
	Q_D(const Quote);
	return d->ask();
}


