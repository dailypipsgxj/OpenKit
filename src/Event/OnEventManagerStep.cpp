#include <QuantKit/Event/OnEventManagerStep.h>

#include "Event_p.h"
#include <QuantKit/EventType.h>

namespace QuantKit {

class OnEventManagerStepPrivate : public EventPrivate
{
public:
	OnEventManagerStepPrivate();
	virtual ~OnEventManagerStepPrivate();

public:
	virtual unsigned char typeId() const Q_DECL_OVERRIDE
	{
		return EventType::OnEventManagerStep;
	}

	virtual QString toString() const Q_DECL_OVERRIDE { return "OnEventManagerStep"; }
	virtual OnEventManagerStepPrivate* clone() Q_DECL_OVERRIDE { return new OnEventManagerStepPrivate(*this); }
};

} // namepsace QuantKit


using namespace QuantKit;

OnEventManagerStepPrivate::OnEventManagerStepPrivate()
{
}

OnEventManagerStepPrivate::~OnEventManagerStepPrivate ()
{
}


// Pubic API 

OnEventManagerStep::OnEventManagerStep()
	: Event(*new OnEventManagerStepPrivate)
{
}

OnEventManagerStep::~OnEventManagerStep()
{
}


