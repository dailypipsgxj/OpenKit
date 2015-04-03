#ifndef __QUANTKIT_EVENTPIPE_H__
#define __QUANTKIT_EVENTPIPE_H__

#include <QuantKit/quantkit_global.h>
#include <QDebug>
#include <QSharedDataPointer>

#include <QuantKit/IEventQueue.h>

namespace QuantKit {

class EventPipePrivate;

class Framework;
class Event;
class LinkedList;

class QUANTKIT_EXPORT EventPipe
{
public:
	explicit EventPipe(const Framework& framework);
	~EventPipe();

	EventPipe(const EventPipe &other);
	EventPipe& operator=(const EventPipe &other);
	bool operator==(const EventPipe &other) const;
	inline bool operator!=(const EventPipe &other) const { return !(this->operator==(other));  }
public:
	int count() const;
	void add(const IEventQueue& queue);
	void clear();
	Event dequeue();
	bool isEmpty();
	Event read();
	void remove(const IEventQueue& queue);

private:
	QSharedDataPointer<EventPipePrivate> d_ptr;

	friend QDebug operator<<(QDebug dbg, const EventPipe& eventpipe);
};

QUANTKIT_EXPORT QDebug operator<<(QDebug dbg, const EventPipe& eventpipe);

} // namespace QuantKit

Q_DECLARE_SHARED(QuantKit::EventPipe)

#endif // __QUANTKIT_EVENTPIPE_H__
