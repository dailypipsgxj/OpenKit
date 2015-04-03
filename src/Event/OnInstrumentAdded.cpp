#include <QuantKit/Event/OnInstrumentAdded.h>

#include <QuantKit/Instrument.h>

#include "Event_p.h"
#include <QuantKit/EventType.h>

namespace QuantKit {

class OnInstrumentAddedPrivate : public EventPrivate
{
public:
	Instrument m_instrument;

public:
	explicit OnInstrumentAddedPrivate(const Instrument& instrument);
	virtual ~OnInstrumentAddedPrivate();

public:
	Instrument getInstrument() const;
	virtual unsigned char typeId() const Q_DECL_OVERRIDE
	{
		return EventType::OnInstrumentAdded;
	}

	virtual OnInstrumentAddedPrivate* clone() Q_DECL_OVERRIDE { return new OnInstrumentAddedPrivate(*this); }
};

} // namepsace QuantKit


using namespace QuantKit;

OnInstrumentAddedPrivate::OnInstrumentAddedPrivate(const Instrument& instrument)
	: m_instrument(instrument)
{
}

OnInstrumentAddedPrivate::~OnInstrumentAddedPrivate ()
{
}

Instrument getInstrument() const
{
	return null;
}

// Pubic API 

QK_IMPLEMENTATION_PRIVATE(OnInstrumentAdded)

OnInstrumentAdded::OnInstrumentAdded(const Instrument& instrument)
	: Event(*new OnInstrumentAddedPrivate(instrument))
{
}

OnInstrumentAdded::~OnInstrumentAdded()
{
}

Instrument instrument() const
{
	return d_ptr->
	setInstrument()
}


