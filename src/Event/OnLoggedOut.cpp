#include <QuantKit/Event/OnLoggedOut.h>

#include "Event_p.h"
#include <QuantKit/EventType.h>

namespace QuantKit {

class OnLoggedOutPrivate : public EventPrivate
{
public:
	OnLoggedOutPrivate();
	explicit OnLoggedOutPrivate(const QDateTime& dateTime);
	virtual ~OnLoggedOutPrivate();

public:
	virtual unsigned char typeId() const Q_DECL_OVERRIDE { return EventType::OnLoggedOut; }
	virtual OnLoggedOutPrivate* clone() Q_DECL_OVERRIDE { return new OnLoggedOutPrivate(*this); }
};

} // namepsace QuantKit


using namespace QuantKit;

OnLoggedOutPrivate::OnLoggedOutPrivate()
{
}

OnLoggedOutPrivate::OnLoggedOutPrivate(const QDateTime& dateTime)
	: EventPrivate (dateTime)
{
}

OnLoggedOutPrivate::~OnLoggedOutPrivate ()
{
}


// Pubic API 

OnLoggedOut::OnLoggedOut()
	: Event(*new OnLoggedOutPrivate)
{
}

OnLoggedOut::OnLoggedOut(const QDateTime& dateTime)
	: Event(*new OnLoggedOutPrivate(dateTime))
{
}

OnLoggedOut::~OnLoggedOut()
{
}


