#ifndef __QUANTKIT_EVENTQUEUEPRIORITY_H__
#define __QUANTKIT_EVENTQUEUEPRIORITY_H__

#include <QuantKit/quantkit_global.h>
#include <QDebug>
#include <QSharedDataPointer>

namespace QuantKit {

class EventQueuePriorityPrivate;

class QUANTKIT_EXPORT EventQueuePriority
{
public:
	EventQueuePriority();
	~EventQueuePriority();

	EventQueuePriority(const EventQueuePriority &other);
	EventQueuePriority& operator=(const EventQueuePriority &other);
	bool operator==(const EventQueuePriority &other) const;
	inline bool operator!=(const EventQueuePriority &other) const { return !(this->operator==(other));  }

private:
	QSharedDataPointer<EventQueuePriorityPrivate> d_ptr;

	friend QDebug operator<<(QDebug dbg, const EventQueuePriority& eventqueuepriority);
};

QUANTKIT_EXPORT QDebug operator<<(QDebug dbg, const EventQueuePriority& eventqueuepriority);

} // namespace QuantKit

Q_DECLARE_SHARED(QuantKit::EventQueuePriority)

#endif // __QUANTKIT_EVENTQUEUEPRIORITY_H__
