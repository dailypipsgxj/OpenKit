#include <QuantKit/Event.h>

#include <QuantKit/EventType.h>
#include "Event_p.h"

using namespace QuantKit;

EventPrivate::EventPrivate()
{
}

EventPrivate::EventPrivate(const QDateTime& dateTime)
	: m_entryDate(dateTime)
{
}

EventPrivate::~EventPrivate ()
{
}


// Pubic API 

Event::Event()
	: d_ptr(new EventPrivate)
{
}

Event::Event(const QDateTime& dateTime)
	: d_ptr(new EventPrivate(dateTime))
{
}

Event::~Event()
{
}

Event::Event (EventPrivate &dd)
	: d_ptr(&dd)
{
}

Event::Event (const Event &other)
	: d_ptr(other.d_ptr)
{
}

Event& Event::operator=(const Event &other)
{
	d_ptr = other.d_ptr;
	return *this;
}

bool Event::operator==(const Event &other) const
{
	if(d_ptr && other.d_ptr)
		return (*d_ptr == *other.d_ptr);
	else
		return (d_ptr==other.d_ptr);
}

QDateTime Event::dateTime() const
{
	return d_ptr->dateTime();
}

void Event::setDateTime(const QDateTime& value)
{
	d_ptr->setDateTime(value);
}

unsigned char Event::typeId() const
{
	return d_ptr->typeId();
}

QString Event::toString() const
{
	return d_ptr->toString();
}

QDebug operator<<(QDebug dbg, const Event& event)
{
	return dbg << event.toString();
}

