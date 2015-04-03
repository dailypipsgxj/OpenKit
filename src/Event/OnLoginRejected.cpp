#include <QuantKit/Event/OnLoginRejected.h>

#include "Event_p.h"
#include <QuantKit/EventType.h>

namespace QuantKit {

class OnLoginRejectedPrivate : public EventPrivate
{
public:
	OnLoginRejectedPrivate();
	explicit OnLoginRejectedPrivate(const QDateTime& dateTime);
	virtual ~OnLoginRejectedPrivate();

public:
	virtual unsigned char typeId() const Q_DECL_OVERRIDE
	{
		return EventType::OnLoginRejected;
	}

	virtual OnLoginRejectedPrivate* clone() Q_DECL_OVERRIDE { return new OnLoginRejectedPrivate(*this); }
};

} // namepsace QuantKit


using namespace QuantKit;

OnLoginRejectedPrivate::OnLoginRejectedPrivate()
{
}

OnLoginRejectedPrivate::OnLoginRejectedPrivate(const QDateTime& dateTime)
	: EventPrivate (dateTime)
{
}

OnLoginRejectedPrivate::~OnLoginRejectedPrivate ()
{
}


// Pubic API 

OnLoginRejected::OnLoginRejected()
	: Event(*new OnLoginRejectedPrivate)
{
}

OnLoginRejected::OnLoginRejected(const QDateTime& dateTime)
	: Event(*new OnLoginRejectedPrivate(dateTime))
{
}

OnLoginRejected::~OnLoginRejected()
{
}


