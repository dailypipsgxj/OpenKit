#ifndef __QUANTKIT_EVENTQUEUETYPE_H__
#define __QUANTKIT_EVENTQUEUETYPE_H__

#include <QuantKit/quantkit_global.h>
#include <QDebug>
#include <QSharedDataPointer>

namespace QuantKit {

class EventQueueTypePrivate;

class QUANTKIT_EXPORT EventQueueType
{
public:
	EventQueueType();
	~EventQueueType();

	EventQueueType(const EventQueueType &other);
	EventQueueType& operator=(const EventQueueType &other);
	bool operator==(const EventQueueType &other) const;
	inline bool operator!=(const EventQueueType &other) const { return !(this->operator==(other));  }

private:
	QSharedDataPointer<EventQueueTypePrivate> d_ptr;

	friend QDebug operator<<(QDebug dbg, const EventQueueType& eventqueuetype);
};

QUANTKIT_EXPORT QDebug operator<<(QDebug dbg, const EventQueueType& eventqueuetype);

} // namespace QuantKit

Q_DECLARE_SHARED(QuantKit::EventQueueType)

#endif // __QUANTKIT_EVENTQUEUETYPE_H__
