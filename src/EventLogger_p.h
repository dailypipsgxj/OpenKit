#ifndef __QUANTKIT_EVENTLOGGER_PRIVATE_H__
#define __QUANTKIT_EVENTLOGGER_PRIVATE_H__

#include <QuantKit/EventLogger.h>

#include <QSharedData>

#include "Framework_p.h"
#include "Event_p.h"

namespace QuantKit {

class EventLoggerPrivate : public QSharedData
{
public:
	Framework framework;
	QString m_name;

public:
	EventLoggerPrivate(const Framework& framework, const QString& name)
	{
		framework.eventLoggerManager().Add(this);
	}

	virtual ~EventLoggerPrivate();

public:
	Framework getFramework() const;
	void setFramework(Framework value);
	QString name() const { return m_name; }
	virtual void onEvent(const Event& e) Q_DECL_OVERRIDE;
//private:
	void setName(const QString& value) { m_name = value; }
};

} // namepsace QuantKit

#endif // __QUANTKIT_EVENTLOGGER_PRIVATE_H__
