#include <QuantKit/Event/OnInstrumentDefinition.h>

#include <QuantKit/InstrumentDefinition.h>

#include "Event_p.h"
#include <QuantKit/EventType.h>

namespace QuantKit {

class OnInstrumentDefinitionPrivate : public EventPrivate
{
public:
	InstrumentDefinition m_instrumentDefinition;

public:
	explicit OnInstrumentDefinitionPrivate(const InstrumentDefinition& definition);
	virtual ~OnInstrumentDefinitionPrivate();

public:
	InstrumentDefinition getInstrumentDefinition() const;
	virtual unsigned char typeId() const Q_DECL_OVERRIDE
	{
		return EventType::OnInstrumentDefinition;
	}

	virtual OnInstrumentDefinitionPrivate* clone() Q_DECL_OVERRIDE { return new OnInstrumentDefinitionPrivate(*this); }
};

} // namepsace QuantKit


using namespace QuantKit;

OnInstrumentDefinitionPrivate::OnInstrumentDefinitionPrivate(const InstrumentDefinition& definition)
	: m_instrumentDefinition(definition)
{
}

OnInstrumentDefinitionPrivate::~OnInstrumentDefinitionPrivate ()
{
}

InstrumentDefinition getInstrumentDefinition() const
{
	return null;
}

// Pubic API 

QK_IMPLEMENTATION_PRIVATE(OnInstrumentDefinition)

OnInstrumentDefinition::OnInstrumentDefinition(const InstrumentDefinition& definition)
	: Event(*new OnInstrumentDefinitionPrivate(definition))
{
}

OnInstrumentDefinition::~OnInstrumentDefinition()
{
}

InstrumentDefinition instrumentDefinition() const
{
	return d_ptr->
	setInstrumentDefinition()
}


