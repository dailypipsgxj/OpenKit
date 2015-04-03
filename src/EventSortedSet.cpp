#include <QuantKit/EventSortedSet.h>

#include "Event_p.h"

namespace QuantKit {

class EventSortedSetPrivate : public QSharedData
{
public:
	QList<Event> m_item;
	QString m_name;
	QString m_description;

public:
	EventSortedSetPrivate();
	virtual ~EventSortedSetPrivate();

public:
	QString name() const { return m_name; }
	void setName(const QString& value) { m_name = value; }
	QString description() const { return m_description; }
	void setDescription(const QString& value) { m_description = value; }
	int count() const { return m_item.Count; }
	Event item(int index) const { return m_item[index]; }
	void add(const Event& e);
	void clear() { m_item.Clear(); }
	virtual EventSortedSetPrivate* clone() Q_DECL_OVERRIDE { return new EventSortedSetPrivate(*this); }
//private:
	int method_0(const QDateTime& dateTime);
};

} // namepsace QuantKit


using namespace QuantKit;

EventSortedSetPrivate::EventSortedSetPrivate()
	: m_item(new QList<Event>())
{
}

EventSortedSetPrivate::~EventSortedSetPrivate ()
{
}

void EventSortedSetPrivate::add(const Event& e)
{
	int index = method_0(e.entryDate());
	m_item.Insert(index, e);
}

int EventSortedSetPrivate::method_0(const QDateTime& dateTime)
{
	if (m_item.Count == 0)
	{
		return 0;
	}
	if (m_item[0].entryDate() > dateTime)
	{
		return 0;
	}
	if (m_item[m_item.Count - 1].entryDate() <= dateTime)
	{
		return m_item.Count;
	}
	int num = 0;
	int num2 = m_item.Count - 1;
	while (num != num2)
	{
		int num3 = (num + num2 + 1) / 2;
		if (m_item[num3].entryDate() <= dateTime)
		{
			if (m_item[num3 + 1].entryDate() > dateTime)
			{
				return num3 + 1;
			}
			num = num3;
		}
		else
		{
			num2 = num3 - 1;
		}
	}
	return num + 1;
}


// Pubic API 

EventSortedSet::EventSortedSet()
	: d_ptr(new EventSortedSetPrivate)
{
}

EventSortedSet::~EventSortedSet()
{
}

EventSortedSet::EventSortedSet (const EventSortedSet &other)
	: d_ptr(other.d_ptr)
{
}

EventSortedSet& EventSortedSet::operator=(const EventSortedSet &other)
{
	d_ptr = other.d_ptr;
	return *this;
}

bool EventSortedSet::operator==(const EventSortedSet &other) const
{
	if(d_ptr && other.d_ptr)
		return (*d_ptr == *other.d_ptr);
	else
		return (d_ptr==other.d_ptr);
}

QString EventSortedSet::name() const
{
	return d_ptr->name();
}

void EventSortedSet::setName(const QString& value)
{
	d_ptr->setName(value);
}

QString EventSortedSet::description() const
{
	return d_ptr->description();
}

void EventSortedSet::setDescription(const QString& value)
{
	d_ptr->setDescription(value);
}

int EventSortedSet::count() const
{
	return d_ptr->count();
}

Event EventSortedSet::item(int index) const
{
	return d_ptr->item(index);
}

void EventSortedSet::add(const Event& e)
{
	d_ptr->add(e);
}

void EventSortedSet::clear()
{
	d_ptr->clear();
}

QDebug operator<<(QDebug dbg, const EventSortedSet& eventsortedset)
{
	return dbg << eventsortedset.toString();
}

