#include <QuantKit/Event/OnQueueClosed.h>

#include <QuantKit/EventQueue.h>

#include "Event_p.h"
#include <QuantKit/EventType.h>

namespace QuantKit {

class OnQueueClosedPrivate : public EventPrivate
{
public:
	EventQueue eventQueue_0;

public:
	explicit OnQueueClosedPrivate(const EventQueue& queue)
	{
		m_entryDate = DateTime.MinValue;
	}

	virtual ~OnQueueClosedPrivate();

public:
	EventQueue getEventQueue_0() const;
	virtual unsigned char typeId() const Q_DECL_OVERRIDE
	{
		return EventType::OnQueueClosed;
	}

	virtual QString toString() const Q_DECL_OVERRIDE { return "OnQueueClosed"; }
	virtual OnQueueClosedPrivate* clone() Q_DECL_OVERRIDE { return new OnQueueClosedPrivate(*this); }
};

} // namepsace QuantKit


using namespace QuantKit;

OnQueueClosedPrivate::~OnQueueClosedPrivate ()
{
}

EventQueue getEventQueue_0() const
{
	return null;
}

// Pubic API 

QK_IMPLEMENTATION_PRIVATE(OnQueueClosed)

OnQueueClosed::OnQueueClosed(const EventQueue& queue)
	: Event(*new OnQueueClosedPrivate(queue))
{
}

OnQueueClosed::~OnQueueClosed()
{
}

EventQueue eventQueue_0() const
{
	return d_ptr->
	setEventQueue_0()
}


