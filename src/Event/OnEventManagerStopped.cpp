#include <QuantKit/Event/OnEventManagerStopped.h>

#include "Event_p.h"
#include <QuantKit/EventType.h>

namespace QuantKit {

class OnEventManagerStoppedPrivate : public EventPrivate
{
public:
	OnEventManagerStoppedPrivate();
	virtual ~OnEventManagerStoppedPrivate();

public:
	virtual unsigned char typeId() const Q_DECL_OVERRIDE
	{
		return EventType::OnEventManagerStopped;
	}

	virtual OnEventManagerStoppedPrivate* clone() Q_DECL_OVERRIDE { return new OnEventManagerStoppedPrivate(*this); }
};

} // namepsace QuantKit


using namespace QuantKit;

OnEventManagerStoppedPrivate::OnEventManagerStoppedPrivate()
{
}

OnEventManagerStoppedPrivate::~OnEventManagerStoppedPrivate ()
{
}


// Pubic API 

OnEventManagerStopped::OnEventManagerStopped()
	: Event(*new OnEventManagerStoppedPrivate)
{
}

OnEventManagerStopped::~OnEventManagerStopped()
{
}


