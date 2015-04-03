#include <QuantKit/EventFilter.h>

#include <QuantKit/Framework.h>
#include "Event_p.h"

namespace QuantKit {

class EventFilterPrivate : public QSharedData
{
public:
	Framework m_framework;

public:
	explicit EventFilterPrivate(const Framework& framework);
	virtual ~EventFilterPrivate();

public:
	virtual Event filter(const Event& e) Q_DECL_OVERRIDE { return e; }
	virtual EventFilterPrivate* clone() Q_DECL_OVERRIDE { return new EventFilterPrivate(*this); }
};

} // namepsace QuantKit


using namespace QuantKit;

EventFilterPrivate::EventFilterPrivate(const Framework& framework)
	: m_framework(framework)
{
}

EventFilterPrivate::~EventFilterPrivate ()
{
}


// Pubic API 

EventFilter::EventFilter(const Framework& framework)
	: d_ptr(new EventFilterPrivate(framework))
{
}

EventFilter::~EventFilter()
{
}

EventFilter::EventFilter (const EventFilter &other)
	: d_ptr(other.d_ptr)
{
}

EventFilter& EventFilter::operator=(const EventFilter &other)
{
	d_ptr = other.d_ptr;
	return *this;
}

bool EventFilter::operator==(const EventFilter &other) const
{
	if(d_ptr && other.d_ptr)
		return (*d_ptr == *other.d_ptr);
	else
		return (d_ptr==other.d_ptr);
}

Event EventFilter::filter(const Event& e)
{
	return d_ptr->filter(e);
}

QDebug operator<<(QDebug dbg, const EventFilter& eventfilter)
{
	return dbg << eventfilter.toString();
}

