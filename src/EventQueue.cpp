#include <QuantKit/EventQueue.h>

#include <QuantKit/EventBus.h>
#include "Event_p.h"

namespace QuantKit {

class EventQueuePrivate : public QSharedData
{
public:
	unsigned char m_id;
	unsigned char m_type;
	unsigned char m_priority;
	QString m_name;
	int m_size;
	bool m_isSynched;
	EventBus ugktpPhTx2;
	Event event_0;
	Int32 modreq(System.Runtime.CompilerServices.IsVolatile) int_1;
	Int32 modreq(System.Runtime.CompilerServices.IsVolatile) int_2;
	long m_fullCount;
	long m_emptyCount;
	long m_enqueueCount;
	long m_dequeueCount;

public:
	EventQueuePrivate(unsigned char id, unsigned char type, unsigned char priority, int size, const EventBus& bus);
	virtual ~EventQueuePrivate();

public:
	unsigned char id() const { return m_id; }
	unsigned char type() const { return m_type; }
	QString name() const { return m_name; }
	unsigned char priority() const { return m_priority; }
	bool isSynched() const { return m_isSynched; }
	void setIsSynched(bool value) { m_isSynched = value; }
	long count() const
	{
		return m_enqueueCount - m_dequeueCount;
	}

	long enqueueCount() const { return m_enqueueCount; }
	long dequeueCount() const { return m_dequeueCount; }
	long fullCount() const { return m_fullCount; }
	long emptyCount() const { return m_emptyCount; }
	int size() const { return m_size; }
	void clear();
	Event dequeue();
	void enqueue(const Event& obj);
	bool isEmpty() { return int_1 == int_2; }
	bool isFull()
	{
		return (int_2 + 1) % m_size == int_1;
	}

	Event peek() { return event_0[int_1]; }
	QDateTime peekDateTime()
	{
		return event_0[int_1].entryDate();
	}

	Event read();
	void resetCounts();
	virtual QString toString() const Q_DECL_OVERRIDE { return "EventQueue"; }
	void write(const Event& obj);
	virtual EventQueuePrivate* clone() Q_DECL_OVERRIDE { return new EventQueuePrivate(*this); }
};

} // namepsace QuantKit


using namespace QuantKit;

EventQueuePrivate::EventQueuePrivate(unsigned char id, unsigned char type, unsigned char priority, int size, EventBus bus)
	: m_id(id)
	, m_type(type)
	, m_priority(priority)
	, m_size(size)
	, ugktpPhTx2(bus)
	, event_0(new Event[size])
	, int_1(0)
	, int_2(0)
	, m_fullCount(0L)
	, m_emptyCount(0L)
	, m_enqueueCount(0L)
	, m_dequeueCount(0L)
{
}

EventQueuePrivate::~EventQueuePrivate ()
{
}

void EventQueuePrivate::clear()
{
	int_1 = 0;
	int_2 = 0;
	m_enqueueCount = 0L;
	m_dequeueCount = 0L;
	m_fullCount = 0L;
	m_emptyCount = 0L;
}

Event EventQueuePrivate::dequeue()
{
	while (IsEmpty())
	{
		m_emptyCount += 1L;
		Thread.Sleep(1);
	}
	Event result = event_0[int_1];
	int_1 = (int_1 + 1) % m_size;
	m_dequeueCount += 1L;
	return result;
}

void EventQueuePrivate::enqueue(const Event& obj)
{
	while (IsFull())
	{
		m_fullCount += 1L;
		Thread.Sleep(1);
	}
	event_0[int_2] = obj;
	int_2 = (int_2 + 1) % m_size;
	m_enqueueCount += 1L;
	if (m_dequeueCount == 1L && ugktpPhTx2 != null && ugktpPhTx2.idleMode() == EventBusIdleMode.Wait)
	{
		ugktpPhTx2.manualResetEventSlim_0().Set();
	}
}

Event EventQueuePrivate::read()
{
	Event result = event_0[int_1];
	int_1 = (int_1 + 1) % m_size;
	m_dequeueCount += 1L;
	return result;
}

void EventQueuePrivate::resetCounts()
{
	m_fullCount = 0L;
	m_emptyCount = 0L;
}

void EventQueuePrivate::write(const Event& obj)
{
	event_0[int_2] = obj;
	int_2 = (int_2 + 1) % m_size;
	m_enqueueCount += 1L;
	if (m_dequeueCount == 1L && ugktpPhTx2 != null && ugktpPhTx2.idleMode() == EventBusIdleMode.Wait)
	{
		ugktpPhTx2.manualResetEventSlim_0().Set();
	}
}


// Pubic API 

EventQueue::EventQueue(unsigned char id, unsigned char type, unsigned char priority, int size, EventBus bus)
	: d_ptr(new EventQueuePrivate(id, type, priority, size, bus))
{
}

EventQueue::~EventQueue()
{
}

EventQueue::EventQueue (const EventQueue &other)
	: d_ptr(other.d_ptr)
{
}

EventQueue& EventQueue::operator=(const EventQueue &other)
{
	d_ptr = other.d_ptr;
	return *this;
}

bool EventQueue::operator==(const EventQueue &other) const
{
	if(d_ptr && other.d_ptr)
		return (*d_ptr == *other.d_ptr);
	else
		return (d_ptr==other.d_ptr);
}

unsigned char EventQueue::id() const
{
	return d_ptr->id();
}

unsigned char EventQueue::type() const
{
	return d_ptr->type();
}

QString EventQueue::name() const
{
	return d_ptr->name();
}

unsigned char EventQueue::priority() const
{
	return d_ptr->priority();
}

bool EventQueue::isSynched() const
{
	return d_ptr->isSynched();
}

void EventQueue::setIsSynched(bool value)
{
	d_ptr->setIsSynched(value);
}

long EventQueue::count() const
{
	return d_ptr->count();
}

long EventQueue::enqueueCount() const
{
	return d_ptr->enqueueCount();
}

long EventQueue::dequeueCount() const
{
	return d_ptr->dequeueCount();
}

long EventQueue::fullCount() const
{
	return d_ptr->fullCount();
}

long EventQueue::emptyCount() const
{
	return d_ptr->emptyCount();
}

int EventQueue::size() const
{
	return d_ptr->size();
}

void EventQueue::clear()
{
	d_ptr->clear();
}

Event EventQueue::dequeue()
{
	return d_ptr->dequeue();
}

void EventQueue::enqueue(const Event& obj)
{
	d_ptr->enqueue(obj);
}

bool EventQueue::isEmpty()
{
	return d_ptr->isEmpty();
}

bool EventQueue::isFull()
{
	return d_ptr->isFull();
}

Event EventQueue::peek()
{
	return d_ptr->peek();
}

QDateTime EventQueue::peekDateTime()
{
	return d_ptr->peekDateTime();
}

Event EventQueue::read()
{
	return d_ptr->read();
}

void EventQueue::resetCounts()
{
	d_ptr->resetCounts();
}

QString EventQueue::toString() const
{
	return d_ptr->toString();
}

void EventQueue::write(const Event& obj)
{
	d_ptr->write(obj);
}

QDebug operator<<(QDebug dbg, const EventQueue& eventqueue)
{
	return dbg << eventqueue.toString();
}

