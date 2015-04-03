#include <QuantKit/Event/OnLogin.h>

#include "Event_p.h"
#include <QuantKit/EventType.h>

namespace QuantKit {

class OnLoginPrivate : public EventPrivate
{
public:
	OnLoginPrivate();
	explicit OnLoginPrivate(const QDateTime& dateTime);
	virtual ~OnLoginPrivate();

public:
	virtual unsigned char typeId() const Q_DECL_OVERRIDE { return EventType::OnLogin; }
	virtual OnLoginPrivate* clone() Q_DECL_OVERRIDE { return new OnLoginPrivate(*this); }
};

} // namepsace QuantKit


using namespace QuantKit;

OnLoginPrivate::OnLoginPrivate()
{
}

OnLoginPrivate::OnLoginPrivate(const QDateTime& dateTime)
	: EventPrivate (dateTime)
{
}

OnLoginPrivate::~OnLoginPrivate ()
{
}


// Pubic API 

OnLogin::OnLogin()
	: Event(*new OnLoginPrivate)
{
}

OnLogin::OnLogin(const QDateTime& dateTime)
	: Event(*new OnLoginPrivate(dateTime))
{
}

OnLogin::~OnLogin()
{
}


