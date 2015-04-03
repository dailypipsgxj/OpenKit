#ifndef __QUANTKIT_EVENTLOGGERMANAGER_H__
#define __QUANTKIT_EVENTLOGGERMANAGER_H__

#include <QuantKit/quantkit_global.h>
#include <QDebug>
#include <QString>
#include <Dictionary>
#include <QSharedDataPointer>

namespace QuantKit {

class EventLoggerManagerPrivate;

class EventLogger;

class QUANTKIT_EXPORT EventLoggerManager
{
public:
	EventLoggerManager();
	~EventLoggerManager();

	EventLoggerManager(const EventLoggerManager &other);
	EventLoggerManager& operator=(const EventLoggerManager &other);
	bool operator==(const EventLoggerManager &other) const;
	inline bool operator!=(const EventLoggerManager &other) const { return !(this->operator==(other));  }
public:
	void add(const EventLogger& logger);
	EventLogger getLogger(const QString& name);

private:
	QSharedDataPointer<EventLoggerManagerPrivate> d_ptr;

	friend QDebug operator<<(QDebug dbg, const EventLoggerManager& eventloggermanager);
};

QUANTKIT_EXPORT QDebug operator<<(QDebug dbg, const EventLoggerManager& eventloggermanager);

} // namespace QuantKit

Q_DECLARE_SHARED(QuantKit::EventLoggerManager)

#endif // __QUANTKIT_EVENTLOGGERMANAGER_H__
