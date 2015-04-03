#include <QuantKit/Event/OnEventManagerPaused.h>

#include "Event_p.h"
#include <QuantKit/EventType.h>

namespace QuantKit {

class OnEventManagerPausedPrivate : public EventPrivate
{
public:
	OnEventManagerPausedPrivate();
	virtual ~OnEventManagerPausedPrivate();

public:
	virtual unsigned char typeId() const Q_DECL_OVERRIDE
	{
		return EventType::OnEventManagerPaused;
	}

	virtual OnEventManagerPausedPrivate* clone() Q_DECL_OVERRIDE { return new OnEventManagerPausedPrivate(*this); }
};

} // namepsace QuantKit


using namespace QuantKit;

OnEventManagerPausedPrivate::OnEventManagerPausedPrivate()
{
}

OnEventManagerPausedPrivate::~OnEventManagerPausedPrivate ()
{
}


// Pubic API 

OnEventManagerPaused::OnEventManagerPaused()
	: Event(*new OnEventManagerPausedPrivate)
{
}

OnEventManagerPaused::~OnEventManagerPaused()
{
}


