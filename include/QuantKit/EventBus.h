#ifndef __QUANTKIT_EVENTBUS_H__
#define __QUANTKIT_EVENTBUS_H__

#include <QuantKit/quantkit_global.h>
#include <QDebug>
#include <ManualResetEventSlim>
#include <QSharedDataPointer>

#include <QuantKit/EventBusMode.h>
#include <QuantKit/EventBusIdleMode.h>
#include <QuantKit/IEventQueue.h>

namespace QuantKit {

class EventBusPrivate;

class EventPipe;
class Framework;
class Event;
class EventQueue;

class QUANTKIT_EXPORT EventBus
{
public:
	explicit EventBus(const Framework& framework);
	~EventBus();

	EventBus(const EventBus &other);
	EventBus& operator=(const EventBus &other);
	bool operator==(const EventBus &other) const;
	inline bool operator!=(const EventBus &other) const { return !(this->operator==(other));  }
public:
	IEventQueue ieventQueue_0() const;
	void setIeventQueue_0(IEventQueue value);

	IEventQueue ieventQueue_1() const;
	void setIeventQueue_1(IEventQueue value);
	ManualResetEventSlim manualResetEventSlim_0() const;
	EventBusMode mode() const;
	void setMode(EventBusMode value);
	EventPipe dataPipe() const;
	EventPipe executionPipe() const;
	EventPipe servicePipe() const;
	EventPipe historicalPipe() const;
	EventBusIdleMode idleMode() const;
	void setIdleMode(EventBusIdleMode value);
	void attach(const EventBus& bus);
	void clear();
	Event dequeue();
	void detach(const EventBus& bus);
	void resetCounts();

private:
	QSharedDataPointer<EventBusPrivate> d_ptr;

	friend QDebug operator<<(QDebug dbg, const EventBus& eventbus);
};

QUANTKIT_EXPORT QDebug operator<<(QDebug dbg, const EventBus& eventbus);

} // namespace QuantKit

Q_DECLARE_SHARED(QuantKit::EventBus)

#endif // __QUANTKIT_EVENTBUS_H__
