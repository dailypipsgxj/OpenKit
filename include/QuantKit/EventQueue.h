#ifndef __QUANTKIT_EVENTQUEUE_H__
#define __QUANTKIT_EVENTQUEUE_H__

#include <QuantKit/quantkit_global.h>
#include <QDebug>
#include <QString>
#include <QDateTime>
#include <QSharedDataPointer>

#include <QuantKit/IEventQueue.h>

namespace QuantKit {

class EventQueuePrivate;

class EventBus;
class Event;

class QUANTKIT_EXPORT EventQueue : public IEventQueue
{
public:
	EventQueue(unsigned char id = 0, unsigned char type = 0, unsigned char priority = 2, int size = 100000, const EventBus& bus = 0);
	~EventQueue();

	EventQueue(const EventQueue &other);
	EventQueue& operator=(const EventQueue &other);
	bool operator==(const EventQueue &other) const;
	inline bool operator!=(const EventQueue &other) const { return !(this->operator==(other));  }
public:
	unsigned char id() const;
	unsigned char type() const;
	QString name() const;
	unsigned char priority() const;
	bool isSynched() const;
	void setIsSynched(bool value);
	long count() const;
	long enqueueCount() const;
	long dequeueCount() const;
	long fullCount() const;
	long emptyCount() const;
	int size() const;
	void clear();
	Event dequeue();
	void enqueue(const Event& obj);
	bool isEmpty();
	bool isFull();
	Event peek();
	QDateTime peekDateTime();
	Event read();
	void resetCounts();
	QString toString() const;
	void write(const Event& obj);

private:
	QSharedDataPointer<EventQueuePrivate> d_ptr;

	friend QDebug operator<<(QDebug dbg, const EventQueue& eventqueue);
};

QUANTKIT_EXPORT QDebug operator<<(QDebug dbg, const EventQueue& eventqueue);

} // namespace QuantKit

Q_DECLARE_SHARED(QuantKit::EventQueue)

#endif // __QUANTKIT_EVENTQUEUE_H__
