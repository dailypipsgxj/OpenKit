#include <QuantKit/Event/OnHeartbeat.h>

#include "Event_p.h"
#include <QuantKit/EventType.h>

namespace QuantKit {

class OnHeartbeatPrivate : public EventPrivate
{
public:
	OnHeartbeatPrivate();
	explicit OnHeartbeatPrivate(const QDateTime& dateTime);
	virtual ~OnHeartbeatPrivate();

public:
	virtual unsigned char typeId() const Q_DECL_OVERRIDE { return EventType::OnHeartbeat; }
	virtual OnHeartbeatPrivate* clone() Q_DECL_OVERRIDE { return new OnHeartbeatPrivate(*this); }
};

} // namepsace QuantKit


using namespace QuantKit;

OnHeartbeatPrivate::OnHeartbeatPrivate()
{
}

OnHeartbeatPrivate::OnHeartbeatPrivate(const QDateTime& dateTime)
	: EventPrivate (dateTime)
{
}

OnHeartbeatPrivate::~OnHeartbeatPrivate ()
{
}


// Pubic API 

OnHeartbeat::OnHeartbeat()
	: Event(*new OnHeartbeatPrivate)
{
}

OnHeartbeat::OnHeartbeat(const QDateTime& dateTime)
	: Event(*new OnHeartbeatPrivate(dateTime))
{
}

OnHeartbeat::~OnHeartbeat()
{
}


