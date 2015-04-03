#include <QuantKit/Event/OnQueueOpened.h>

#include <QuantKit/EventQueue.h>

#include "Event_p.h"
#include <QuantKit/EventType.h>

namespace QuantKit {

class OnQueueOpenedPrivate : public EventPrivate
{
public:
	EventQueue eventQueue_0;

public:
	explicit OnQueueOpenedPrivate(const EventQueue& queue)
	{
		m_entryDate = DateTime.MinValue;
	}

	virtual ~OnQueueOpenedPrivate();

public:
	virtual unsigned char typeId() const Q_DECL_OVERRIDE
	{
		return EventType::OnQueueOpened;
	}

	virtual QString toString() const Q_DECL_OVERRIDE { return "OnQueueOpened"; }
	virtual OnQueueOpenedPrivate* clone() Q_DECL_OVERRIDE { return new OnQueueOpenedPrivate(*this); }
};

} // namepsace QuantKit


using namespace QuantKit;

OnQueueOpenedPrivate::~OnQueueOpenedPrivate ()
{
}


// Pubic API 

QK_IMPLEMENTATION_PRIVATE(OnQueueOpened)

OnQueueOpened::OnQueueOpened(const EventQueue& queue)
	: Event(*new OnQueueOpenedPrivate(queue))
{
}

OnQueueOpened::~OnQueueOpened()
{
}


