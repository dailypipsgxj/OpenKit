#include <QuantKit/Event/OnInstrumentDeleted.h>

#include <QuantKit/Instrument.h>

#include "Event_p.h"
#include <QuantKit/EventType.h>

namespace QuantKit {

class OnInstrumentDeletedPrivate : public EventPrivate
{
public:
	Instrument m_instrument;

public:
	explicit OnInstrumentDeletedPrivate(const Instrument& instrument);
	virtual ~OnInstrumentDeletedPrivate();

public:
	Instrument getInstrument() const;
	virtual unsigned char typeId() const Q_DECL_OVERRIDE
	{
		return EventType::OnInstrumentDeleted;
	}

	virtual OnInstrumentDeletedPrivate* clone() Q_DECL_OVERRIDE { return new OnInstrumentDeletedPrivate(*this); }
};

} // namepsace QuantKit


using namespace QuantKit;

OnInstrumentDeletedPrivate::OnInstrumentDeletedPrivate(const Instrument& instrument)
	: m_instrument(instrument)
{
}

OnInstrumentDeletedPrivate::~OnInstrumentDeletedPrivate ()
{
}

Instrument getInstrument() const
{
	return null;
}

// Pubic API 

QK_IMPLEMENTATION_PRIVATE(OnInstrumentDeleted)

OnInstrumentDeleted::OnInstrumentDeleted(const Instrument& instrument)
	: Event(*new OnInstrumentDeletedPrivate(instrument))
{
}

OnInstrumentDeleted::~OnInstrumentDeleted()
{
}

Instrument instrument() const
{
	return d_ptr->
	setInstrument()
}


