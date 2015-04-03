#include <QuantKit/EventQueueType.h>


namespace QuantKit {

class EventQueueTypePrivate : public QSharedData
{
public:
	unsigned char Master;
	unsigned char Slave;

public:
	EventQueueTypePrivate();
	virtual ~EventQueueTypePrivate();

};

} // namepsace QuantKit


using namespace QuantKit;

EventQueueTypePrivate::EventQueueTypePrivate()
{
}

EventQueueTypePrivate::~EventQueueTypePrivate ()
{
}


// Pubic API 

EventQueueType::EventQueueType()
	: d_ptr(new EventQueueTypePrivate)
{
}

EventQueueType::~EventQueueType()
{
}

EventQueueType::EventQueueType (const EventQueueType &other)
	: d_ptr(other.d_ptr)
{
}

EventQueueType& EventQueueType::operator=(const EventQueueType &other)
{
	d_ptr = other.d_ptr;
	return *this;
}

bool EventQueueType::operator==(const EventQueueType &other) const
{
	if(d_ptr && other.d_ptr)
		return (*d_ptr == *other.d_ptr);
	else
		return (d_ptr==other.d_ptr);
}

QDebug operator<<(QDebug dbg, const EventQueueType& eventqueuetype)
{
	return dbg << eventqueuetype.toString();
}

