#include <QuantKit/Event/OnEventManagerResumed.h>

#include "Event_p.h"
#include <QuantKit/EventType.h>

namespace QuantKit {

class OnEventManagerResumedPrivate : public EventPrivate
{
public:
	OnEventManagerResumedPrivate();
	virtual ~OnEventManagerResumedPrivate();

public:
	virtual unsigned char typeId() const Q_DECL_OVERRIDE
	{
		return EventType::OnEventManagerResumed;
	}

	virtual OnEventManagerResumedPrivate* clone() Q_DECL_OVERRIDE { return new OnEventManagerResumedPrivate(*this); }
};

} // namepsace QuantKit


using namespace QuantKit;

OnEventManagerResumedPrivate::OnEventManagerResumedPrivate()
{
}

OnEventManagerResumedPrivate::~OnEventManagerResumedPrivate ()
{
}


// Pubic API 

OnEventManagerResumed::OnEventManagerResumed()
	: Event(*new OnEventManagerResumedPrivate)
{
}

OnEventManagerResumed::~OnEventManagerResumed()
{
}


