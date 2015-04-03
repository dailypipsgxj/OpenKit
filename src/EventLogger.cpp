#include <QuantKit/EventLogger.h>

#include <QuantKit/Framework.h>
#include "Event_p.h"
#include "EventLogger_p.h"

using namespace QuantKit;

EventLoggerPrivate::~EventLoggerPrivate ()
{
}

Framework getFramework() const
{
	return null;
}
void setFramework(Framework value)
{
}
void EventLoggerPrivate::onEvent(const Event& e)
{
}


// Pubic API 

EventLogger::EventLogger(const Framework& framework, const QString& name)
	: d_ptr(new EventLoggerPrivate(framework, name))
{
}

EventLogger::~EventLogger()
{
}

EventLogger::EventLogger (EventLoggerPrivate &dd)
	: d_ptr(&dd)
{
}

EventLogger::EventLogger (const EventLogger &other)
	: d_ptr(other.d_ptr)
{
}

EventLogger& EventLogger::operator=(const EventLogger &other)
{
	d_ptr = other.d_ptr;
	return *this;
}

bool EventLogger::operator==(const EventLogger &other) const
{
	if(d_ptr && other.d_ptr)
		return (*d_ptr == *other.d_ptr);
	else
		return (d_ptr==other.d_ptr);
}

Framework framework() const
{
	return d_ptr->
	setFramework()
}

void setFramework(Framework value)
{
	d_ptr->framework(value);
}

QString EventLogger::name() const
{
	return d_ptr->name();
}

void EventLogger::onEvent(const Event& e)
{
	d_ptr->onEvent(e);
}

QDebug operator<<(QDebug dbg, const EventLogger& eventlogger)
{
	return dbg << eventlogger.toString();
}

