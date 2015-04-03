#include <QuantKit/Event/Ask.h>


#include "Tick_p.h"
#include <QuantKit/EventType.h>

namespace QuantKit {

class AskPrivate : public TickPrivate
{
public:
	AskPrivate();
	AskPrivate(const QDateTime& dateTime, unsigned char providerId, int instrument, double price, int size);
	AskPrivate(const QDateTime& dateTime, const QDateTime& exchangeDateTime, unsigned char providerId, int instrument, double price, int size);
	virtual ~AskPrivate();

public:
	virtual unsigned char typeId() const Q_DECL_OVERRIDE { return EventType::Ask; }
	virtual QString toString() const Q_DECL_OVERRIDE { return "Ask"; }
	virtual AskPrivate* clone() Q_DECL_OVERRIDE { return new AskPrivate(*this); }
};

} // namepsace QuantKit


using namespace QuantKit;

AskPrivate::AskPrivate()
{
}

AskPrivate::AskPrivate(const QDateTime& dateTime, unsigned char providerId, int instrument, double price, int size)
	: TickPrivate (dateTime, providerId, instrument, price, size)
{
}

AskPrivate::AskPrivate(const QDateTime& dateTime, const QDateTime& exchangeDateTime, unsigned char providerId, int instrument, double price, int size)
	: TickPrivate (dateTime, exchangeDateTime, providerId, instrument, price, size)
{
}

AskPrivate::~AskPrivate ()
{
}


// Pubic API 

Ask::Ask()
	: Tick(*new AskPrivate)
{
}

Ask::Ask(const QDateTime& dateTime, unsigned char providerId, int instrument, double price, int size)
	: Tick(*new AskPrivate(dateTime, providerId, instrument, price, size))
{
}

Ask::Ask(const QDateTime& dateTime, const QDateTime& exchangeDateTime, unsigned char providerId, int instrument, double price, int size)
	: Tick(*new AskPrivate(dateTime, exchangeDateTime, providerId, instrument, price, size))
{
}

Ask::~Ask()
{
}


