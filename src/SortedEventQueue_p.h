#ifndef __QUANTKIT_SORTEDEVENTQUEUE_PRIVATE_H__
#define __QUANTKIT_SORTEDEVENTQUEUE_PRIVATE_H__

#include <QuantKit/SortedEventQueue.h>

#include <QSharedData>

#include "Event_p.h"
#include "EventSortedSet_p.h"

namespace QuantKit {

class SortedEventQueuePrivate : public QSharedData
{
public:
	EventSortedSet m_count;
	unsigned char m_id;
	unsigned char m_type;
	unsigned char m_priority;
	QString m_name;
	bool m_isSynched;
	QDateTime m_dateTime;

public:
	SortedEventQueuePrivate(unsigned char id, unsigned char type, unsigned char priority);
	virtual ~SortedEventQueuePrivate();

public:
	QDateTime getDateTime() const;
	void setDateTime(QDateTime value);
	unsigned char id() const { return m_id; }
	unsigned char type() const { return m_type; }
	unsigned char priority() const { return m_priority; }
	bool isSynched() const { return m_isSynched; }
	void setIsSynched(bool value) { m_isSynched = value; }
	QString name() const { return m_name; }
	long count() const { return (long)m_count.count(); }
	long emptyCount() const
	{
		throw new NotImplementedException("Not implemented in SortedEventQueue");
	}

	long fullCount() const
	{
		throw new NotImplementedException("Not implemented in SortedEventQueue");
	}

	void clear() { m_count.Clear(); }
	Event dequeue();
	void enqueue(const Event& e);
	bool isEmpty() { return m_count.count() == 0; }
	bool isFull() { return false; }
	Event peek();
	QDateTime peekDateTime() { return m_dateTime; }
	Event read();
	void resetCounts();
	void write(const Event& e)
	{
		throw new NotImplementedException("Not implemented in SortedEventQueue");
	}

};

} // namepsace QuantKit

#endif // __QUANTKIT_SORTEDEVENTQUEUE_PRIVATE_H__
