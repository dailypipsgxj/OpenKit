#include <QuantKit/EventLoggerManager.h>

#include "EventLogger_p.h"

namespace QuantKit {

class EventLoggerManagerPrivate : public QSharedData
{
public:
	Dictionary<QString,EventLogger> m_dictionary;

public:
	EventLoggerManagerPrivate();
	virtual ~EventLoggerManagerPrivate();

public:
	void add(const EventLogger& logger)
	{
		m_dictionary[logger.name()] = logger;
	}

	EventLogger getLogger(const QString& name);
	virtual EventLoggerManagerPrivate* clone() Q_DECL_OVERRIDE { return new EventLoggerManagerPrivate(*this); }
};

} // namepsace QuantKit


using namespace QuantKit;

EventLoggerManagerPrivate::EventLoggerManagerPrivate()
	: m_dictionary(new Dictionary<string, EventLogger>())
{
}

EventLoggerManagerPrivate::~EventLoggerManagerPrivate ()
{
}

EventLogger EventLoggerManagerPrivate::getLogger(const QString& name)
{
	EventLogger result = null;
	m_dictionary.TryGetValue(name, out result);
	return result;
}


// Pubic API 

EventLoggerManager::EventLoggerManager()
	: d_ptr(new EventLoggerManagerPrivate)
{
}

EventLoggerManager::~EventLoggerManager()
{
}

EventLoggerManager::EventLoggerManager (const EventLoggerManager &other)
	: d_ptr(other.d_ptr)
{
}

EventLoggerManager& EventLoggerManager::operator=(const EventLoggerManager &other)
{
	d_ptr = other.d_ptr;
	return *this;
}

bool EventLoggerManager::operator==(const EventLoggerManager &other) const
{
	if(d_ptr && other.d_ptr)
		return (*d_ptr == *other.d_ptr);
	else
		return (d_ptr==other.d_ptr);
}

void EventLoggerManager::add(const EventLogger& logger)
{
	d_ptr->add(logger);
}

EventLogger EventLoggerManager::getLogger(const QString& name)
{
	return d_ptr->getLogger(name);
}

QDebug operator<<(QDebug dbg, const EventLoggerManager& eventloggermanager)
{
	return dbg << eventloggermanager.toString();
}

