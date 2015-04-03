#ifndef __QUANTKIT_SORTEDEVENTQUEUE_H__
#define __QUANTKIT_SORTEDEVENTQUEUE_H__

#include <QuantKit/quantkit_global.h>
#include <QDebug>
#include <QString>
#include <QDateTime>
#include <QSharedDataPointer>

#include <QuantKit/IEventQueue.h>

namespace QuantKit {

class SortedEventQueuePrivate;

class Event;
class EventSortedSet;

class QUANTKIT_EXPORT SortedEventQueue : public IEventQueue
{
public:
	SortedEventQueue(unsigned char id, unsigned char type = 0, unsigned char priority = 2);
	~SortedEventQueue();

	SortedEventQueue(const SortedEventQueue &other);
	SortedEventQueue& operator=(const SortedEventQueue &other);
	bool operator==(const SortedEventQueue &other) const;
	inline bool operator!=(const SortedEventQueue &other) const { return !(this->operator==(other));  }
public:
	QDateTime dateTime() const;
	void setDateTime(QDateTime value);
	unsigned char id() const;
	unsigned char type() const;
	unsigned char priority() const;
	bool isSynched() const;
	void setIsSynched(bool value);
	QString name() const;
	long count() const;
	long emptyCount() const;
	long fullCount() const;
	void clear();
	Event dequeue();
	void enqueue(const Event& e);
	bool isEmpty();
	bool isFull();
	Event peek();
	QDateTime peekDateTime();
	Event read();
	void resetCounts();
	void write(const Event& e);

protected:
	SortedEventQueue(SortedEventQueuePrivate& dd);
	QSharedDataPointer<SortedEventQueuePrivate> d_ptr;

private:
	friend QDebug operator<<(QDebug dbg, const SortedEventQueue& sortedeventqueue);
};

QUANTKIT_EXPORT QDebug operator<<(QDebug dbg, const SortedEventQueue& sortedeventqueue);

} // namespace QuantKit

Q_DECLARE_SHARED(QuantKit::SortedEventQueue)

#endif // __QUANTKIT_SORTEDEVENTQUEUE_H__
