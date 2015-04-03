#include <QuantKit/Event/OnLoggedIn.h>

#include "Event_p.h"
#include <QuantKit/EventType.h>

namespace QuantKit {

class OnLoggedInPrivate : public EventPrivate
{
public:
	OnLoggedInPrivate();
	explicit OnLoggedInPrivate(const QDateTime& dateTime);
	virtual ~OnLoggedInPrivate();

public:
	virtual unsigned char typeId() const Q_DECL_OVERRIDE { return EventType::OnLoggedIn; }
	virtual OnLoggedInPrivate* clone() Q_DECL_OVERRIDE { return new OnLoggedInPrivate(*this); }
};

} // namepsace QuantKit


using namespace QuantKit;

OnLoggedInPrivate::OnLoggedInPrivate()
{
}

OnLoggedInPrivate::OnLoggedInPrivate(const QDateTime& dateTime)
	: EventPrivate (dateTime)
{
}

OnLoggedInPrivate::~OnLoggedInPrivate ()
{
}


// Pubic API 

OnLoggedIn::OnLoggedIn()
	: Event(*new OnLoggedInPrivate)
{
}

OnLoggedIn::OnLoggedIn(const QDateTime& dateTime)
	: Event(*new OnLoggedInPrivate(dateTime))
{
}

OnLoggedIn::~OnLoggedIn()
{
}


