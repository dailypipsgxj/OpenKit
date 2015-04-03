#include <QuantKit/Event/OnDisconnect.h>

#include "Event_p.h"
#include <QuantKit/EventType.h>

namespace QuantKit {

class OnDisconnectPrivate : public EventPrivate
{
public:
	OnDisconnectPrivate();
	virtual ~OnDisconnectPrivate();

public:
	virtual unsigned char typeId() const Q_DECL_OVERRIDE
	{
		return EventType::OnDisconnect;
	}

	virtual OnDisconnectPrivate* clone() Q_DECL_OVERRIDE { return new OnDisconnectPrivate(*this); }
};

} // namepsace QuantKit


using namespace QuantKit;

OnDisconnectPrivate::OnDisconnectPrivate()
{
}

OnDisconnectPrivate::~OnDisconnectPrivate ()
{
}


// Pubic API 

OnDisconnect::OnDisconnect()
	: Event(*new OnDisconnectPrivate)
{
}

OnDisconnect::~OnDisconnect()
{
}


