#include <QuantKit/EventQueuePriority.h>


namespace QuantKit {

class EventQueuePriorityPrivate : public QSharedData
{
public:
	unsigned char Highest;
	unsigned char High;
	unsigned char Normal;
	unsigned char Low;
	unsigned char Lowest;

public:
	EventQueuePriorityPrivate();
	virtual ~EventQueuePriorityPrivate();

};

} // namepsace QuantKit


using namespace QuantKit;

EventQueuePriorityPrivate::EventQueuePriorityPrivate()
{
}

EventQueuePriorityPrivate::~EventQueuePriorityPrivate ()
{
}


// Pubic API 

EventQueuePriority::EventQueuePriority()
	: d_ptr(new EventQueuePriorityPrivate)
{
}

EventQueuePriority::~EventQueuePriority()
{
}

EventQueuePriority::EventQueuePriority (const EventQueuePriority &other)
	: d_ptr(other.d_ptr)
{
}

EventQueuePriority& EventQueuePriority::operator=(const EventQueuePriority &other)
{
	d_ptr = other.d_ptr;
	return *this;
}

bool EventQueuePriority::operator==(const EventQueuePriority &other) const
{
	if(d_ptr && other.d_ptr)
		return (*d_ptr == *other.d_ptr);
	else
		return (d_ptr==other.d_ptr);
}

QDebug operator<<(QDebug dbg, const EventQueuePriority& eventqueuepriority)
{
	return dbg << eventqueuepriority.toString();
}

