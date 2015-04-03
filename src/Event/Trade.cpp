#include <QuantKit/Event/Trade.h>


#include "Tick_p.h"
#include <QuantKit/EventType.h>

namespace QuantKit {

class TradePrivate : public TickPrivate
{
public:
	TradePrivate();
	TradePrivate(const QDateTime& dateTime, unsigned char providerId, int instrumentId, double price, int size);
	TradePrivate(const QDateTime& dateTime, const QDateTime& exchangeDateTime, unsigned char providerId, int instrumentId, double price, int size);
	virtual ~TradePrivate();

public:
	virtual unsigned char typeId() const Q_DECL_OVERRIDE { return EventType::Trade; }
	virtual QString toString() const Q_DECL_OVERRIDE { return "Trade"; }
	virtual TradePrivate* clone() Q_DECL_OVERRIDE { return new TradePrivate(*this); }
};

} // namepsace QuantKit


using namespace QuantKit;

TradePrivate::TradePrivate()
{
}

TradePrivate::TradePrivate(const QDateTime& dateTime, unsigned char providerId, int instrumentId, double price, int size)
	: TickPrivate (dateTime, providerId, instrumentId, price, size)
{
}

TradePrivate::TradePrivate(const QDateTime& dateTime, const QDateTime& exchangeDateTime, unsigned char providerId, int instrumentId, double price, int size)
	: TickPrivate (dateTime, exchangeDateTime, providerId, instrumentId, price, size)
{
}

TradePrivate::~TradePrivate ()
{
}


// Pubic API 

Trade::Trade()
	: Tick(*new TradePrivate)
{
}

Trade::Trade(const QDateTime& dateTime, unsigned char providerId, int instrumentId, double price, int size)
	: Tick(*new TradePrivate(dateTime, providerId, instrumentId, price, size))
{
}

Trade::Trade(const QDateTime& dateTime, const QDateTime& exchangeDateTime, unsigned char providerId, int instrumentId, double price, int size)
	: Tick(*new TradePrivate(dateTime, exchangeDateTime, providerId, instrumentId, price, size))
{
}

Trade::~Trade()
{
}


