#ifndef __QUANTKIT_CLOCK_H__
#define __QUANTKIT_CLOCK_H__

#include <QuantKit/quantkit_global.h>
#include <QDebug>
#include <QDateTime>
#include <QVariant>
#include <QString>
#include <Thread>
#include <QSharedDataPointer>

#include <QuantKit/ClockMode.h>
#include <QuantKit/ClockResolution.h>
#include <QuantKit/ClockType.h>
#include <QuantKit/IEventQueue.h>

namespace QuantKit {

class ClockPrivate;

class Framework;
class Reminder;
class ReminderCallback;

class QUANTKIT_EXPORT Clock
{
public:
	Clock(const Framework& framework, ClockType type = ClockType::Local, bool isStandalone = false);
	~Clock();

	Clock(const Clock &other);
	Clock& operator=(const Clock &other);

#ifdef Q_COMPILER_RVALUE_REFS
    Clock &operator=(Clock &&other) { swap(other); return *this; }
#endif

    void swap(Clock& other) { d.swap(other.d); }

	bool operator==(const Clock &other) const;
	inline bool operator!=(const Clock &other) const { return !(this->operator==(other));  }
public:
    ClockType clockType() const;

	IEventQueue ieventQueue_0() const;
	long ticks() const;
	QDateTime dateTime() const;
	ClockMode mode() const;
	void setMode(ClockMode value);
	ClockResolution resolution() const;
	void setResolution(ClockResolution value);
	bool addReminder(const Reminder& reminder);
	bool addReminder(const ReminderCallback& callback, const QDateTime& dateTime, const QVariant& data = 0);
	void clear();
	QString getModeAsString();
	void removeReminder(const ReminderCallback& callback, const QDateTime& dateTime);

private:
    QSharedDataPointer<ClockPrivate> d;

	friend QDebug operator<<(QDebug dbg, const Clock& clock);
};

QUANTKIT_EXPORT QDebug operator<<(QDebug dbg, const Clock& clock);

} // namespace QuantKit

Q_DECLARE_SHARED(QuantKit::Clock)

#endif // __QUANTKIT_CLOCK_H__
