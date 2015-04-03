#include <QuantKit/Event/OnInstrumentDefinitionEnd.h>

#include <QuantKit/InstrumentDefinitionEnd.h>

#include "Event_p.h"
#include <QuantKit/EventType.h>

namespace QuantKit {

class OnInstrumentDefinitionEndPrivate : public EventPrivate
{
public:
	InstrumentDefinitionEnd m_instrumentDefinitionEnd;

public:
	explicit OnInstrumentDefinitionEndPrivate(const InstrumentDefinitionEnd& end);
	virtual ~OnInstrumentDefinitionEndPrivate();

public:
	InstrumentDefinitionEnd getInstrumentDefinitionEnd() const;
	virtual unsigned char typeId() const Q_DECL_OVERRIDE
	{
		return EventType::OnInstrumentDefinitionEnd;
	}

	virtual OnInstrumentDefinitionEndPrivate* clone() Q_DECL_OVERRIDE { return new OnInstrumentDefinitionEndPrivate(*this); }
};

} // namepsace QuantKit


using namespace QuantKit;

OnInstrumentDefinitionEndPrivate::OnInstrumentDefinitionEndPrivate(const InstrumentDefinitionEnd& end)
	: m_instrumentDefinitionEnd(end)
{
}

OnInstrumentDefinitionEndPrivate::~OnInstrumentDefinitionEndPrivate ()
{
}

InstrumentDefinitionEnd getInstrumentDefinitionEnd() const
{
	return null;
}

// Pubic API 

QK_IMPLEMENTATION_PRIVATE(OnInstrumentDefinitionEnd)

OnInstrumentDefinitionEnd::OnInstrumentDefinitionEnd(const InstrumentDefinitionEnd& end)
	: Event(*new OnInstrumentDefinitionEndPrivate(end))
{
}

OnInstrumentDefinitionEnd::~OnInstrumentDefinitionEnd()
{
}

InstrumentDefinitionEnd instrumentDefinitionEnd() const
{
	return d_ptr->
	setInstrumentDefinitionEnd()
}


