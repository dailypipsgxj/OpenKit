#include <QuantKit/Event/OnLogout.h>

#include "Event_p.h"
#include <QuantKit/EventType.h>

namespace QuantKit {

class OnLogoutPrivate : public EventPrivate
{
public:
	OnLogoutPrivate();
	explicit OnLogoutPrivate(const QDateTime& dateTime);
	virtual ~OnLogoutPrivate();

public:
	virtual unsigned char typeId() const Q_DECL_OVERRIDE { return EventType::OnLogout; }
	virtual OnLogoutPrivate* clone() Q_DECL_OVERRIDE { return new OnLogoutPrivate(*this); }
};

} // namepsace QuantKit


using namespace QuantKit;

OnLogoutPrivate::OnLogoutPrivate()
{
}

OnLogoutPrivate::OnLogoutPrivate(const QDateTime& dateTime)
	: EventPrivate (dateTime)
{
}

OnLogoutPrivate::~OnLogoutPrivate ()
{
}


// Pubic API 

OnLogout::OnLogout()
	: Event(*new OnLogoutPrivate)
{
}

OnLogout::OnLogout(const QDateTime& dateTime)
	: Event(*new OnLogoutPrivate(dateTime))
{
}

OnLogout::~OnLogout()
{
}


