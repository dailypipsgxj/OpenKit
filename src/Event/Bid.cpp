#include <QuantKit/Event/Bid.h>


#include "Tick_p.h"
#include <QuantKit/EventType.h>

namespace QuantKit {

class BidPrivate : public TickPrivate
{
public:
	BidPrivate();
	BidPrivate(const QDateTime& dateTime, unsigned char providerId, int instrumentId, double price, int size);
	BidPrivate(const QDateTime& dateTime, const QDateTime& exchangeDateTime, unsigned char providerId, int instrumentId, double price, int size);
	virtual ~BidPrivate();

public:
	virtual unsigned char typeId() const Q_DECL_OVERRIDE { return EventType::Bid; }
	virtual QString toString() const Q_DECL_OVERRIDE { return "Bid"; }
	virtual BidPrivate* clone() Q_DECL_OVERRIDE { return new BidPrivate(*this); }
};

} // namepsace QuantKit


using namespace QuantKit;

BidPrivate::BidPrivate()
{
}

BidPrivate::BidPrivate(const QDateTime& dateTime, unsigned char providerId, int instrumentId, double price, int size)
	: TickPrivate (dateTime, providerId, instrumentId, price, size)
{
}

BidPrivate::BidPrivate(const QDateTime& dateTime, const QDateTime& exchangeDateTime, unsigned char providerId, int instrumentId, double price, int size)
	: TickPrivate (dateTime, exchangeDateTime, providerId, instrumentId, price, size)
{
}

BidPrivate::~BidPrivate ()
{
}


// Pubic API 

Bid::Bid()
	: Tick(*new BidPrivate)
{
}

Bid::Bid(const QDateTime& dateTime, unsigned char providerId, int instrumentId, double price, int size)
	: Tick(*new BidPrivate(dateTime, providerId, instrumentId, price, size))
{
}

Bid::Bid(const QDateTime& dateTime, const QDateTime& exchangeDateTime, unsigned char providerId, int instrumentId, double price, int size)
	: Tick(*new BidPrivate(dateTime, exchangeDateTime, providerId, instrumentId, price, size))
{
}

Bid::~Bid()
{
}


