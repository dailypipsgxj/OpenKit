#include <QuantKit/EventPipe.h>

#include <QuantKit/Framework.h>
#include "Event_p.h"
#include <QuantKit/LinkedList.h>

namespace QuantKit {

class EventPipePrivate : public QSharedData
{
public:
	Framework m_framework;
	LinkedList<IEventQueue> m_count;
	LinkedList<IEventQueue> MemgAoqvpT;

public:
	explicit EventPipePrivate(const Framework& framework);
	virtual ~EventPipePrivate();

public:
	int count() const { return m_count.Count; }
	void add(const IEventQueue& queue);
	void clear();
	Event dequeue() { return null; }
	bool isEmpty();
	Event read();
	void remove(const IEventQueue& queue);
	virtual EventPipePrivate* clone() Q_DECL_OVERRIDE { return new EventPipePrivate(*this); }
};

} // namepsace QuantKit


using namespace QuantKit;

EventPipePrivate::EventPipePrivate(const Framework& framework)
	: m_framework(framework)
	, m_count(new LinkedQList<IEventQueue>())
	, MemgAoqvpT(new LinkedQList<IEventQueue>())
{
}

EventPipePrivate::~EventPipePrivate ()
{
}

void EventPipePrivate::add(const IEventQueue& queue)
{
	if (queue.isSynched())
	{
		MemgAoqvpT.Add(queue);
		return;
	}
	m_count.Add(queue);
}

void EventPipePrivate::clear()
{
	m_count.Clear();
	MemgAoqvpT.Clear();
}

bool EventPipePrivate::isEmpty()
{
	if (m_count.Count != 0)
	{
		for (LinkedListNode<IEventQueue> linkedListNode = m_count.First; linkedListNode != null; linkedListNode = linkedListNode.Next)
		{
			if (!linkedListNode.Data.IsEmpty())
			{
				return false;
			}
		}
	}
	if (MemgAoqvpT.Count != 0)
	{
		for (LinkedListNode<IEventQueue> linkedListNode2 = MemgAoqvpT.First; linkedListNode2 != null; linkedListNode2 = linkedListNode2.Next)
		{
			if (linkedListNode2.Data.IsEmpty())
			{
				return true;
			}
		}
		return false;
	}
	return true;
}

Event EventPipePrivate::read()
{
	if (m_count.Count != 0)
	{
		LinkedListNode<IEventQueue> linkedListNode = m_count.First;
		LinkedListNode<IEventQueue> linkedListNode2 = null;
		while (linkedListNode != null)
		{
			if (!linkedListNode.Data.IsEmpty())
			{
				Event @event = linkedListNode.Data.Read();
				if (@event.typeId() == 206)
				{
					if (linkedListNode2 == null)
					{
						m_count.First = linkedListNode.Next;
					}
					else
					{
						linkedListNode2.Next = linkedListNode.Next;
					}
					m_count.Count--;
				}
				return @event;
			}
			linkedListNode2 = linkedListNode;
			linkedListNode = linkedListNode.Next;
		}
	}
	if (MemgAoqvpT.Count != 0)
	{
		DateTime t = DateTime.MaxValue;
		LinkedListNode<IEventQueue> linkedListNode3 = MemgAoqvpT.First;
		LinkedListNode<IEventQueue> linkedListNode4 = null;
		LinkedListNode<IEventQueue> linkedListNode5 = null;
		while (linkedListNode3 != null)
		{
			Event event2 = linkedListNode3.Data.Peek();
			if (event2.typeId() == 206 && ((OnQueueClosed)event2).eventQueue_0() == linkedListNode3.Data)
			{
				if (linkedListNode4 == null)
				{
					MemgAoqvpT.First = linkedListNode3.Next;
				}
				else
				{
					linkedListNode4.Next = linkedListNode3.Next;
				}
				MemgAoqvpT.Count--;
				if (MemgAoqvpT.Count == 0 && m_framework.mode() == FrameworkMode.Simulation && linkedListNode3.Data.name() != "Simulator stop queue")
				{
					EventQueue eventQueue = new EventQueue(1, 0, 2, 10, null);
					eventQueue.setIsSynched() = true;
					eventQueue.setName() = "Simulator stop queue";
					eventQueue.Enqueue(new OnQueueOpened(eventQueue));
					eventQueue.Enqueue(new OnSimulatorStop());
					eventQueue.Enqueue(new OnQueueClosed(eventQueue));
					Add(eventQueue);
				}
				linkedListNode5 = linkedListNode3;
				IL_1D5:
				return linkedListNode5.Data.Read();
			}
			DateTime entryDate = event2.entryDate();
			if (entryDate <= t)
			{
				linkedListNode5 = linkedListNode3;
				t = entryDate;
			}
			linkedListNode4 = linkedListNode3;
			linkedListNode3 = linkedListNode3.Next;
		}
		goto IL_1D5;
	}
	return null;
}

void EventPipePrivate::remove(const IEventQueue& queue)
{
	if (queue.isSynched())
	{
		MemgAoqvpT.Remove(queue);
		return;
	}
	m_count.Remove(queue);
}


// Pubic API 

EventPipe::EventPipe(const Framework& framework)
	: d_ptr(new EventPipePrivate(framework))
{
}

EventPipe::~EventPipe()
{
}

EventPipe::EventPipe (const EventPipe &other)
	: d_ptr(other.d_ptr)
{
}

EventPipe& EventPipe::operator=(const EventPipe &other)
{
	d_ptr = other.d_ptr;
	return *this;
}

bool EventPipe::operator==(const EventPipe &other) const
{
	if(d_ptr && other.d_ptr)
		return (*d_ptr == *other.d_ptr);
	else
		return (d_ptr==other.d_ptr);
}

int EventPipe::count() const
{
	return d_ptr->count();
}

void EventPipe::add(const IEventQueue& queue)
{
	d_ptr->add(queue);
}

void EventPipe::clear()
{
	d_ptr->clear();
}

Event EventPipe::dequeue()
{
	return d_ptr->dequeue();
}

bool EventPipe::isEmpty()
{
	return d_ptr->isEmpty();
}

Event EventPipe::read()
{
	return d_ptr->read();
}

void EventPipe::remove(const IEventQueue& queue)
{
	d_ptr->remove(queue);
}

QDebug operator<<(QDebug dbg, const EventPipe& eventpipe)
{
	return dbg << eventpipe.toString();
}

