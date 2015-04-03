#include <QuantKit/SortedEventQueue.h>

#include "Event_p.h"
#include <QuantKit/EventSortedSet.h>
#include "SortedEventQueue_p.h"

using namespace QuantKit;

SortedEventQueuePrivate::SortedEventQueuePrivate(unsigned char id, unsigned char type, unsigned char priority)
	: m_count(new EventSortedSet())
	, m_id(id)
	, m_type(type)
	, m_priority(priority)
{
}

SortedEventQueuePrivate::~SortedEventQueuePrivate ()
{
}

QDateTime getDateTime() const
{
	return null;
}
void setDateTime(QDateTime value)
{
}
Event SortedEventQueuePrivate::dequeue()
{
	bool flag = false;
	Event result;
	try
	{
		Monitor.Enter(this, ref flag);
		result = m_count[0];
		m_count.method_1(0);
		if (m_count.count() != 0)
		{
			m_dateTime = m_count[0].entryDate();
		}
	}
	finally
	{
		if (flag)
		{
			Monitor.Exit(this);
		}
	}
	return result;
}

void SortedEventQueuePrivate::enqueue(const Event& e)
{
	bool flag = false;
	try
	{
		Monitor.Enter(this, ref flag);
		m_count.Add(e);
		m_dateTime = m_count[0].entryDate();
	}
	finally
	{
		if (flag)
		{
			Monitor.Exit(this);
		}
	}
}

Event SortedEventQueuePrivate::peek()
{
	bool flag = false;
	Event result;
	try
	{
		Monitor.Enter(this, ref flag);
		result = m_count[0];
	}
	finally
	{
		if (flag)
		{
			Monitor.Exit(this);
		}
	}
	return result;
}

Event SortedEventQueuePrivate::read()
{
	bool flag = false;
	Event result;
	try
	{
		Monitor.Enter(this, ref flag);
		result = m_count[0];
		m_count.method_1(0);
		if (m_count.count() > 0)
		{
			m_dateTime = m_count[0].entryDate();
		}
	}
	finally
	{
		if (flag)
		{
			Monitor.Exit(this);
		}
	}
	return result;
}

void SortedEventQueuePrivate::resetCounts()
{
}


// Pubic API 

SortedEventQueue::SortedEventQueue(unsigned char id, unsigned char type, unsigned char priority)
	: d_ptr(new SortedEventQueuePrivate(id, type, priority))
{
}

SortedEventQueue::~SortedEventQueue()
{
}

SortedEventQueue::SortedEventQueue (SortedEventQueuePrivate &dd)
	: d_ptr(&dd)
{
}

SortedEventQueue::SortedEventQueue (const SortedEventQueue &other)
	: d_ptr(other.d_ptr)
{
}

SortedEventQueue& SortedEventQueue::operator=(const SortedEventQueue &other)
{
	d_ptr = other.d_ptr;
	return *this;
}

bool SortedEventQueue::operator==(const SortedEventQueue &other) const
{
	if(d_ptr && other.d_ptr)
		return (*d_ptr == *other.d_ptr);
	else
		return (d_ptr==other.d_ptr);
}

QDateTime dateTime() const
{
	return d_ptr->
	setDateTime()
}

void setDateTime(QDateTime value)
{
	d_ptr->dateTime(value);
}

unsigned char SortedEventQueue::id() const
{
	return d_ptr->id();
}

unsigned char SortedEventQueue::type() const
{
	return d_ptr->type();
}

unsigned char SortedEventQueue::priority() const
{
	return d_ptr->priority();
}

bool SortedEventQueue::isSynched() const
{
	return d_ptr->isSynched();
}

void SortedEventQueue::setIsSynched(bool value)
{
	d_ptr->setIsSynched(value);
}

QString SortedEventQueue::name() const
{
	return d_ptr->name();
}

long SortedEventQueue::count() const
{
	return d_ptr->count();
}

long SortedEventQueue::emptyCount() const
{
	return d_ptr->emptyCount();
}

long SortedEventQueue::fullCount() const
{
	return d_ptr->fullCount();
}

void SortedEventQueue::clear()
{
	d_ptr->clear();
}

Event SortedEventQueue::dequeue()
{
	return d_ptr->dequeue();
}

void SortedEventQueue::enqueue(const Event& e)
{
	d_ptr->enqueue(e);
}

bool SortedEventQueue::isEmpty()
{
	return d_ptr->isEmpty();
}

bool SortedEventQueue::isFull()
{
	return d_ptr->isFull();
}

Event SortedEventQueue::peek()
{
	return d_ptr->peek();
}

QDateTime SortedEventQueue::peekDateTime()
{
	return d_ptr->peekDateTime();
}

Event SortedEventQueue::read()
{
	return d_ptr->read();
}

void SortedEventQueue::resetCounts()
{
	d_ptr->resetCounts();
}

void SortedEventQueue::write(const Event& e)
{
	d_ptr->write(e);
}

QDebug operator<<(QDebug dbg, const SortedEventQueue& sortedeventqueue)
{
	return dbg << sortedeventqueue.toString();
}

