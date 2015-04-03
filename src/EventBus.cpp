#include <QuantKit/EventBus.h>

#include <QuantKit/EventPipe.h>
#include <QuantKit/Framework.h>
#include "Event_p.h"
#include <QuantKit/EventQueue.h>

namespace QuantKit {

class EventBusPrivate : public QSharedData
{
public:
	Framework m_framework;
	EventPipe m_dataPipe;
	EventPipe m_executionPipe;
	EventPipe m_servicePipe;
	EventPipe m_historicalPipe;
	IEventQueue ieventQueue_0;
	IEventQueue ieventQueue_1;
	EventBusMode m_mode;
	int int_0;
	EventQueue eventQueue_0;
	EventBusIdleMode m_idleMode;
	ManualResetEventSlim manualResetEventSlim_0;
	Event event_0;

public:
	explicit EventBusPrivate(const Framework& framework);
	virtual ~EventBusPrivate();

public:
	IEventQueue getIeventQueue_0() const;
	void setIeventQueue_0(IEventQueue value);

	IEventQueue getIeventQueue_1() const;
	void setIeventQueue_1(IEventQueue value);
	ManualResetEventSlim getManualResetEventSlim_0() const;
	EventBusMode mode() const { return m_mode; }
	void setMode(EventBusMode value);
	EventPipe dataPipe() const { return m_dataPipe; }
	EventPipe executionPipe() const { return m_executionPipe; }
	EventPipe servicePipe() const { return m_servicePipe; }
	EventPipe historicalPipe() const { return m_historicalPipe; }
	EventBusIdleMode idleMode() const { return m_idleMode; }
	void setIdleMode(EventBusIdleMode value) { m_idleMode = value; }
	void attach(const EventBus& bus);
	void clear();
	Event dequeue();
	void detach(const EventBus& bus);
	void resetCounts();
	virtual EventBusPrivate* clone() Q_DECL_OVERRIDE { return new EventBusPrivate(*this); }
};

} // namepsace QuantKit


using namespace QuantKit;

EventBusPrivate::EventBusPrivate(const Framework& framework)
	: m_framework(framework)
	, m_dataPipe(new EventPipe(framework))
	, m_executionPipe(new EventPipe(framework))
	, m_servicePipe(new EventPipe(framework))
	, m_historicalPipe(new EventPipe(framework))
	, m_mode(EventBusMode.Simulation)
	, m_mode(EventBusMode.Realtime)
	, m_mode(EventBusMode.Simulation)
	, eventQueue_0(new EventQueue[1024])
	, m_idleMode(EventBusIdleMode.Wait)
	, manualResetEventSlim_0(new ManualResetEventSlim(false))
{
		if (framework.mode() == FrameworkMode.Realtime)
		{
		}
		else
		{
		}
}

EventBusPrivate::~EventBusPrivate ()
{
}

IEventQueue getIeventQueue_0() const
{
	return null;
}
void setIeventQueue_0(IEventQueue value)
{
}

IEventQueue getIeventQueue_1() const
{
	return null;
}
void setIeventQueue_1(IEventQueue value)
{
}

ManualResetEventSlim getManualResetEventSlim_0() const
{
	return null;
}
void EventBusPrivate::setMode(EventBusMode value)
{
	if (m_mode != value)
	{
		m_mode = value;
	}
}

void EventBusPrivate::attach(const EventBus& bus)
{
	EventQueue eventQueue = new EventQueue(1, 0, 2, 25000, null);
	eventQueue.setIsSynched() = true;
	eventQueue.setName() = "attached " + bus.framework().name();
	eventQueue.Enqueue(new OnQueueOpened(eventQueue));
	bus.dataPipe().Add(eventQueue);
	eventQueue_0[int_0++] = eventQueue;
}

void EventBusPrivate::clear()
{
	event_0 = null;
	ieventQueue_0.Clear();
	m_servicePipe.Clear();
	m_dataPipe.Clear();
	m_executionPipe.Clear();
	m_historicalPipe.Clear();
	for (int i = 0; i < int_0; i++)
	{
		eventQueue_0[i] = null;
	}
	int_0 = 0;
}

Event EventBusPrivate::dequeue()
{
	if (m_mode == EventBusMode.Simulation)
	{
		while (true)
		{
			if (!m_dataPipe.IsEmpty() && event_0 == null)
			{
				Event @event = m_dataPipe.Read();
				if (@event.entryDate() < m_framework.clock().dateTime())
				{
					if (@event.typeId() != 205 && @event.typeId() != 206 && @event.typeId() != 229)
					{
						if (@event.typeId() != 230)
						{
							Console.WriteLine(string.Concat(new object[]
							{
								"EventBus::Dequeue Skipping: ",
								@event,
								" ",
								@event.entryDate(),
								" <> ",
								m_framework.clock().dateTime()
							}));
							continue;
						}
					}
					@event.setEntryDate() = m_framework.clock().dateTime();
					event_0 = @event;
				}
				else
				{
					event_0 = @event;
				}
			}
			if (!m_executionPipe.IsEmpty())
			{
				break;
			}
			if (!ieventQueue_0.IsEmpty() && event_0 != null && ieventQueue_0.PeekDateTime() <= event_0.dateTime())
			{
				goto IL_1FD;
			}
			if (!ieventQueue_1.IsEmpty() && event_0 != null && (event_0.typeId() == 2 || event_0.typeId() == 3 || event_0.typeId() == 4) && ieventQueue_1.PeekDateTime() <= ((Tick)event_0).exchangeDateTime())
			{
				goto IL_209;
			}
			if (!m_servicePipe.IsEmpty())
			{
				goto IL_215;
			}
			if (event_0 != null)
			{
				goto IL_221;
			}
			Thread.Sleep(1);
		}
		return m_executionPipe.Read();
		IL_1FD:
		return ieventQueue_0.Read();
		IL_209:
		return ieventQueue_1.Read();
		IL_215:
		return m_servicePipe.Read();
		IL_221:
		Event event2 = event_0;
		event_0 = null;
		for (int i = 0; i < int_0; i++)
		{
			eventQueue_0[i].Enqueue(event2);
		}
		return event2;
	}
	while (true)
	{
		if (!m_dataPipe.IsEmpty() && event_0 == null)
		{
			event_0 = m_dataPipe.Read();
		}
		if (!ieventQueue_0.IsEmpty() && ieventQueue_0.PeekDateTime() <= m_framework.clock().dateTime())
		{
			break;
		}
		if (!ieventQueue_1.IsEmpty() && event_0 != null && (event_0.typeId() == 2 || event_0.typeId() == 3 || event_0.typeId() == 4) && ieventQueue_1.PeekDateTime() <= ((Tick)event_0).exchangeDateTime())
		{
			goto IL_394;
		}
		if (!m_executionPipe.IsEmpty())
		{
			goto IL_3A0;
		}
		if (!m_servicePipe.IsEmpty())
		{
			goto IL_3AC;
		}
		if (event_0 != null)
		{
			goto IL_3B8;
		}
		switch (m_idleMode)
		{
			case EventBusIdleMode.Sleep:
				Thread.Sleep(1);
				break;
			case EventBusIdleMode.Wait:
				manualResetEventSlim_0.Reset();
				manualResetEventSlim_0.Wait(1);
				break;
		}
	}
	return ieventQueue_0.Read();
	IL_394:
	return ieventQueue_1.Read();
	IL_3A0:
	return m_executionPipe.Read();
	IL_3AC:
	return m_servicePipe.Read();
	IL_3B8:
	Event result = event_0;
	event_0 = null;
	return result;
}

void EventBusPrivate::detach(const EventBus& bus)
{
	EventQueue eventQueue = null;
	string b = "attached " + bus.framework().name();
	int i = 0;
	while (i < int_0)
	{
		if (!(eventQueue_0[i].name() == b))
		{
			i++;
		}
		else
		{
			eventQueue = eventQueue_0[i];
			for (int j = i; j < int_0 - 1; j++)
			{
				eventQueue_0[j] = eventQueue_0[j + 1];
			}
			int_0--;
			IL_7C:
			if (eventQueue != null)
			{
				bus.dataPipe().Remove(eventQueue);
				return;
			}
			Console.WriteLine("EventBus::Detach Can not find attached bus queue : " + bus.framework().name());
			return;
		}
	}
	goto IL_7C;
}

void EventBusPrivate::resetCounts()
{
}


// Pubic API 

EventBus::EventBus(const Framework& framework)
	: d_ptr(new EventBusPrivate(framework))
{
}

EventBus::~EventBus()
{
}

EventBus::EventBus (const EventBus &other)
	: d_ptr(other.d_ptr)
{
}

EventBus& EventBus::operator=(const EventBus &other)
{
	d_ptr = other.d_ptr;
	return *this;
}

bool EventBus::operator==(const EventBus &other) const
{
	if(d_ptr && other.d_ptr)
		return (*d_ptr == *other.d_ptr);
	else
		return (d_ptr==other.d_ptr);
}

IEventQueue ieventQueue_0() const
{
	return d_ptr->
	setIeventQueue_0()
}

void setIeventQueue_0(IEventQueue value)
{
	d_ptr->ieventQueue_0(value);
}

IEventQueue ieventQueue_1() const
{
	return d_ptr->
	setIeventQueue_1()
}

void setIeventQueue_1(IEventQueue value)
{
	d_ptr->ieventQueue_1(value);
}

ManualResetEventSlim manualResetEventSlim_0() const
{
	return d_ptr->
	setManualResetEventSlim_0()
}

EventBusMode EventBus::mode() const
{
	return d_ptr->mode();
}

void EventBus::setMode(EventBusMode value)
{
	d_ptr->setMode(value);
}

EventPipe EventBus::dataPipe() const
{
	return d_ptr->dataPipe();
}

EventPipe EventBus::executionPipe() const
{
	return d_ptr->executionPipe();
}

EventPipe EventBus::servicePipe() const
{
	return d_ptr->servicePipe();
}

EventPipe EventBus::historicalPipe() const
{
	return d_ptr->historicalPipe();
}

EventBusIdleMode EventBus::idleMode() const
{
	return d_ptr->idleMode();
}

void EventBus::setIdleMode(EventBusIdleMode value)
{
	d_ptr->setIdleMode(value);
}

void EventBus::attach(const EventBus& bus)
{
	d_ptr->attach(bus);
}

void EventBus::clear()
{
	d_ptr->clear();
}

Event EventBus::dequeue()
{
	return d_ptr->dequeue();
}

void EventBus::detach(const EventBus& bus)
{
	d_ptr->detach(bus);
}

void EventBus::resetCounts()
{
	d_ptr->resetCounts();
}

QDebug operator<<(QDebug dbg, const EventBus& eventbus)
{
	return dbg << eventbus.toString();
}

