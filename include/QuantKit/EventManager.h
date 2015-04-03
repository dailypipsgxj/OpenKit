#ifndef __QUANTKIT_EVENTMANAGER_H__
#define __QUANTKIT_EVENTMANAGER_H__

#include <QuantKit/quantkit_global.h>
#include <QDebug>
#include <QDateTime>
#include <QVariant>
#include <Thread>
#include <Stopwatch>
#include <Delegate6>
#include <QSharedDataPointer>

#include <QuantKit/EventManagerStatus.h>

namespace QuantKit {

class EventManagerPrivate;

class EventFilter;
class EventLogger;
class BarFactory;
class BarSliceFactory;
class EventDispatcher;
class Framework;
class EventBus;
class Event;
class IdArray;

class QUANTKIT_EXPORT EventManager
{
public:
	EventManager(const Framework& framework, const EventBus& bus);
	~EventManager();

	EventManager(const EventManager &other);
	EventManager& operator=(const EventManager &other);
	bool operator==(const EventManager &other) const;
	inline bool operator!=(const EventManager &other) const { return !(this->operator==(other));  }
public:
	EventManagerStatus status() const;
	EventFilter filter() const;
	void setFilter(const EventFilter& value);
	EventLogger logger() const;
	void setLogger(const EventLogger& value);
	BarFactory barFactory() const;
	void setBarFactory(const BarFactory& value);
	BarSliceFactory barSliceFactory() const;
	void setBarSliceFactory(const BarSliceFactory& value);
	EventDispatcher dispatcher() const;
	void setDispatcher(const EventDispatcher& value);
	long eventCount() const;
	long dataEventCount() const;
	void clear();
	void dispose();
	void onEvent(const Event& e);
	void pause();
	void pause(const QDateTime& dateTime);
	void resume();
	void start();
	void step(unsigned char typeId = 0);
	void stop();

private:
	QSharedDataPointer<EventManagerPrivate> d_ptr;

	friend QDebug operator<<(QDebug dbg, const EventManager& eventmanager);
};

QUANTKIT_EXPORT QDebug operator<<(QDebug dbg, const EventManager& eventmanager);

} // namespace QuantKit

Q_DECLARE_SHARED(QuantKit::EventManager)

#endif // __QUANTKIT_EVENTMANAGER_H__
