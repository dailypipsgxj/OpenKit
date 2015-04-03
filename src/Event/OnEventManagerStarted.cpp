#include <QuantKit/Event/OnEventManagerStarted.h>

#include "Event_p.h"
#include <QuantKit/EventType.h>

namespace QuantKit {

class OnEventManagerStartedPrivate : public EventPrivate
{
public:
	OnEventManagerStartedPrivate();
	virtual ~OnEventManagerStartedPrivate();

public:
	virtual unsigned char typeId() const Q_DECL_OVERRIDE
	{
		return EventType::OnEventManagerStarted;
	}

	virtual OnEventManagerStartedPrivate* clone() Q_DECL_OVERRIDE { return new OnEventManagerStartedPrivate(*this); }
};

} // namepsace QuantKit


using namespace QuantKit;

OnEventManagerStartedPrivate::OnEventManagerStartedPrivate()
{
}

OnEventManagerStartedPrivate::~OnEventManagerStartedPrivate ()
{
}


// Pubic API 

OnEventManagerStarted::OnEventManagerStarted()
	: Event(*new OnEventManagerStartedPrivate)
{
}

OnEventManagerStarted::~OnEventManagerStarted()
{
}


