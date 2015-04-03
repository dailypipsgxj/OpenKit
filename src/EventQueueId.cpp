#include <QuantKit/EventQueueId.h>


namespace QuantKit {

class EventQueueIdPrivate : public QSharedData
{
public:
	unsigned char All;
	unsigned char Data;
	unsigned char Execution;
	unsigned char Reminder;
	unsigned char Service;

public:
	EventQueueIdPrivate();
	virtual ~EventQueueIdPrivate();

};

} // namepsace QuantKit


using namespace QuantKit;

EventQueueIdPrivate::EventQueueIdPrivate()
{
}

EventQueueIdPrivate::~EventQueueIdPrivate ()
{
}


// Pubic API 

EventQueueId::EventQueueId()
	: d_ptr(new EventQueueIdPrivate)
{
}

EventQueueId::~EventQueueId()
{
}

EventQueueId::EventQueueId (const EventQueueId &other)
	: d_ptr(other.d_ptr)
{
}

EventQueueId& EventQueueId::operator=(const EventQueueId &other)
{
	d_ptr = other.d_ptr;
	return *this;
}

bool EventQueueId::operator==(const EventQueueId &other) const
{
	if(d_ptr && other.d_ptr)
		return (*d_ptr == *other.d_ptr);
	else
		return (d_ptr==other.d_ptr);
}

QDebug operator<<(QDebug dbg, const EventQueueId& eventqueueid)
{
	return dbg << eventqueueid.toString();
}

