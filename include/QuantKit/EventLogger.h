#ifndef __QUANTKIT_EVENTLOGGER_H__
#define __QUANTKIT_EVENTLOGGER_H__

#include <QuantKit/quantkit_global.h>
#include <QDebug>
#include <QString>
#include <QSharedDataPointer>

namespace QuantKit {

class EventLoggerPrivate;

class Framework;
class Event;

class QUANTKIT_EXPORT EventLogger
{
public:
	EventLogger(const Framework& framework, const QString& name);
	~EventLogger();

	EventLogger(const EventLogger &other);
	EventLogger& operator=(const EventLogger &other);
	bool operator==(const EventLogger &other) const;
	inline bool operator!=(const EventLogger &other) const { return !(this->operator==(other));  }
public:
	Framework framework() const;
	void setFramework(Framework value);
	QString name() const;
	void onEvent(const Event& e);

protected:
	EventLogger(EventLoggerPrivate& dd);
	QSharedDataPointer<EventLoggerPrivate> d_ptr;

private:
	friend QDebug operator<<(QDebug dbg, const EventLogger& eventlogger);
};

QUANTKIT_EXPORT QDebug operator<<(QDebug dbg, const EventLogger& eventlogger);

} // namespace QuantKit

Q_DECLARE_SHARED(QuantKit::EventLogger)

#endif // __QUANTKIT_EVENTLOGGER_H__
